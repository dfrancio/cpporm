/*!
 * \file
 * \brief     String utils
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \see
 * http://stackoverflow.com/a/21806609
 * http://stackoverflow.com/a/28209546
 *
 */
#pragma once

#include <cpporm/util/preprocessor.h>

CPPORM_BEGIN_SUB_NAMESPACE(util)

/*! @cond */
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
/*! @endcond */

/*!
 * \brief Safe underlying type
 */
template <typename T>
using SafeUnderlyingType = typename detail::SafeUnderlyingTypeImpl<T>::type;

/*!
 * \brief Character sequence
 */
template <char... Seq>
struct CharSequence
{
    /*!
     * \brief The sequence
     */
    static const std::string cSequence;
};

/*!
 * \details
 */
template <char... Seq>
const std::string CharSequence<Seq...>::cSequence = {Seq...};

/*!
 * \brief Overload of to_string for the generic case
 * \param[in] arg The argument
 * \return The string
 */
template <typename T>
std::string to_string(const T &arg)
{
    return std::to_string(static_cast<SafeUnderlyingType<T>>(arg));
}

/*!
 * \brief Overload of to_string for the char array case
 * \param[in] str The string
 * \return The string
 */
inline std::string to_string(const char *str)
{
    return str;
}

/*!
 * \brief Overload of to_string for the string case
 * \param[in] str The string
 * \return The string
 */
inline const std::string &to_string(const std::string &str)
{
    return str;
}

/*!
 * \brief Stringify
 * \param[in] args The arguments to be stringified
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
 * \brief Case insensitive compare function
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
 * \brief Case insensitive less function
 */
struct CaseInsensitiveLess
{
    /*!
     * \brief operator()
     */
    bool operator()(const std::string &lhs, const std::string &rhs) const
    {
        return CaseInsensitiveCompare(lhs, rhs) < 0;
    }
};

CPPORM_END_SUB_NAMESPACE
