/*!
 * \file
 * \brief     String utils
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 *
 * \see
 * http://stackoverflow.com/a/21806609
 * http://stackoverflow.com/a/28209546
 */
#pragma once

#include <cpporm/util/macros.h>

CPPORM_BEGIN_SUB_NAMESPACE(util)

/*
 * Helper classes
 */
namespace detail
{
template <typename T, class = typename std::is_enum<T>::type>
struct SafeUnderlyingTypeImpl
{
    using type = T;
};

template <typename T>
struct SafeUnderlyingTypeImpl<T, std::true_type>
{
    using type = typename std::underlying_type<T>::type;
};
}

/*!
 * \brief Safely cast a type to its underlying type
 *
 * If the type is an enumeration class, the underlying type will most likely be an integer type.
 * Otherwise the funcion returns the original type.
 */
template <typename T>
using SafeUnderlyingType = typename detail::SafeUnderlyingTypeImpl<T>::type;

/*!
 * \brief Class to store a compile-time character sequence
 *
 * \tparam Seq The character sequence
 */
template <char... Seq>
struct CharSequence
{
    /*!
     * \brief The character sequence (in a std::string)
     */
    static const std::string cSequence;
};

/*!
 * \details
 */
template <char... Seq>
const std::string CharSequence<Seq...>::cSequence = {Seq...};

/*!
 * \brief Convert to string (generic type overload)
 *
 * \tparam T The type of the argument
 *
 * \param[in] arg The argument
 * \return The string
 */
template <typename T>
std::string to_string(const T &arg)
{
    return std::to_string(static_cast<SafeUnderlyingType<T>>(arg));
}

/*!
 * \brief Convert to string (non-const char array overload)
 * \param[in] str The string
 * \return The string
 */
inline std::string to_string(char *str)
{
    return str;
}

/*!
 * \brief Convert to string (const char array overload)
 * \param[in] str The string
 * \return The string
 */
inline std::string to_string(const char *str)
{
    return str;
}

/*!
 * \brief Convert to string (std::string overload)
 * \param[in] str The string
 * \return The string
 */
inline const std::string &to_string(const std::string &str)
{
    return str;
}

/*!
 * \brief Convert to string and concatenate
 *
 * \tparam Sep The separator character
 * \tparam Args The type of the arguments
 *
 * \param[in] args The arguments to be converted
 * \return The resulting string
 */
template <char... Sep, typename... Args>
std::string Stringify(const Args &... args)
{
    std::string result;
    CPPORM_UNPACK(result += to_string(args) + CharSequence<Sep...>::cSequence);
    if (result.size() >= sizeof...(Sep))
        result.resize(result.size() - sizeof...(Sep));
    return result;
}

/*!
 * \brief Compare two strings (case-insensitive)
 * \param[in] lhs The left-hand side of the comparison
 * \param[in] rhs The right-hand side of the comparison
 * \return The result is one of:
 *  - -1 if the first string is less than the second (case insensitive);
 *  - 0 if the strings are equivalent; or
 *  - 1 if the first string is greater than the second (case insensitive)
 */
inline int CaseInsensitiveCompare(const std::string &lhs, const std::string &rhs)
{
    auto *s1 = lhs.c_str();
    auto *s2 = rhs.c_str();
    while (*s2 != 0 && ::toupper(*s1) == ::toupper(*s2))
        s1++, s2++;
    return (int)(::toupper(*s1) - ::toupper(*s2));
}

/*!
 * \brief Functor for case insensitive string comparison
 */
struct CaseInsensitiveLess
{
    /*!
     * \brief Check whether a string is less than another string (case insensitive)
     * \param[in] lhs The left-hand side of the comparison
     * \param[in] rhs The right-hand side of the comparison
     * \return True if the first string is less than the second (case insensitive); false otherwise
     */
    bool operator()(const std::string &lhs, const std::string &rhs) const
    {
        return CaseInsensitiveCompare(lhs, rhs) < 0;
    }
};

CPPORM_END_SUB_NAMESPACE
