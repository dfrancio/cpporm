/*!
 * \file
 * \brief     nanodbc utils
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 * \see http://stackoverflow.com/a/3382894
 */
#include <cpporm/backend/nanodbc/utils.h>

// C++ library includes
#include <regex>

CPPORM_BEGIN_SUB_SUB_NAMESPACE(backend, nanodbc)

// Helper functions
static std::string hex_to_string(const std::string &input);

/*!
 * \details
 */
std::string ProcessValue(std::string &&value)
{
    static const std::regex cDateTimeRegex(
        "[0-9]{4}-[0-9]{2}-[0-9]{2} [0-9]{2}:[0-9]{2}:[0-9]{2}(.[0-9]{3})?");
    static const std::regex cHexStringRegex("[xX]'([0-9a-fA-F]+)'");
    std::smatch match;
    if (std::regex_search(value, match, cDateTimeRegex))
        return match[0];
    else if (std::regex_search(value, match, cHexStringRegex))
        return hex_to_string(match[1]);
    else
        return value;
}

/*!
 * \details
 */
std::string hex_to_string(const std::string &input)
{
    static const char *const lut = "0123456789ABCDEF";
    size_t len = input.length();
    if (len & 1)
        throw std::invalid_argument("odd length");

    std::string output;
    output.reserve(len / 2);
    for (size_t i = 0; i < len; i += 2)
    {
        char a = input[i];
        const char *p = std::lower_bound(lut, lut + 16, a);
        if (*p != a)
            throw std::invalid_argument("not a hex digit");

        char b = input[i + 1];
        const char *q = std::lower_bound(lut, lut + 16, b);
        if (*q != b)
            throw std::invalid_argument("not a hex digit");

        output.push_back(((p - lut) << 4) | (q - lut));
    }
    return output;
}

CPPORM_END_SUB_SUB_NAMESPACE
