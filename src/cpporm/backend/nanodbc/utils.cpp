/*!
 * \file
 * \brief     nanodbc utils
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#include <cpporm/backend/nanodbc/utils.h>

// C++ library includes
#include <regex>

// External library includes
#include <boost/locale/encoding_utf.hpp>

// Internal library includes
#include <cpporm/error.h>

CPPORM_BEGIN_SUB_SUB_NAMESPACE(backend, nanodbc)

/*!
 * \details
 */
std::u16string Widen16(const std::string &text)
{
    try
    {
        return boost::locale::conv::utf_to_utf<char16_t>(text);
    }
    catch (const std::exception &e)
    {
        throw ConvertError(e.what(), "std::string", "std::u16string");
    }
}

/*!
 * \details
 */
std::string Narrow(const std::u16string &text)
{
    try
    {
        return boost::locale::conv::utf_to_utf<char>(text);
    }
    catch (const std::exception &e)
    {
        throw ConvertError(e.what(), "std::u16string", "std::string");
    }
}

/*!
 * \details
 */
std::string HandleDateTime(std::string &&value)
{
    static const std::regex cDateTimeRegex(
        "[0-9]{4}-[0-9]{2}-[0-9]{2} [0-9]{2}:[0-9]{2}:[0-9]{2}(.[0-9]{3})?");
    std::smatch dateTimeMatch;
    return std::regex_search(value, dateTimeMatch, cDateTimeRegex) ? dateTimeMatch[0] : value;
}

CPPORM_END_SUB_SUB_NAMESPACE
