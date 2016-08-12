/*!
 * \file
 * \brief     SOCI utils
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#include <cpporm/backend/soci/utils.h>

// Internal library includes
#include <cpporm/util/string.h>

CPPORM_BEGIN_SUB_SUB_NAMESPACE(backend, soci)

/*!
 * \details
 */
template <>
std::string Convert(double &&value)
{
    std::ostringstream stream;
    stream << std::setprecision(17) << value;
    return stream.str();
}

/*!
 * \details
 */
template <>
std::string Convert(int &&value)
{
    return util::to_string(value);
}

/*!
 * \details
 */
template <>
std::string Convert(long long &&value)
{
    return util::to_string(value);
}

/*!
 * \details
 */
template <>
std::string Convert(unsigned long long &&value)
{
    return util::to_string(value);
}

/*!
 * \details
 */
template <>
CPPORM_SOCI_EXPORT std::string Convert(std::tm &&value)
{
    char buffer[20];
    if (value.tm_year < 0)
    {
        value.tm_hour = value.tm_year + 1900;
        value.tm_min = value.tm_mon + 1;
        value.tm_sec = value.tm_mday;
        value.tm_year = 0;
        value.tm_mon = 0;
        value.tm_mday = 0;
        std::strftime(buffer, sizeof(buffer), "%H:%M:%S", &value);
    }
    else if (value.tm_hour == 0 && value.tm_min == 0 && value.tm_sec == 0)
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &value);
    else
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &value);
    return buffer;
}

/*!
 * \details
 */
std::string ProcessParameterNames(const std::string &sql)
{
    static const std::string cParameterPrefix = ":";
    short param = 0;
    auto result = sql;
    auto pos = result.find(CPPORM_PLACEHOLDER_MARK);
    while (pos != std::string::npos)
    {
        result.replace(
            pos, std::strlen(CPPORM_PLACEHOLDER_MARK),
            cParameterPrefix + MakeParameterName(param++));
        pos = result.find(CPPORM_PLACEHOLDER_MARK, pos + 1);
    }
    return result;
}

/*!
 * \details
 */
std::string MakeParameterName(short param)
{
    return util::to_string(param);
}

CPPORM_END_SUB_SUB_NAMESPACE
