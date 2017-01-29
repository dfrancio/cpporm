/*!
 * \file
 * \brief     SOCI utils
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#include <cpporm/backend/soci/utils.h>

// C library includes
#include <cmath>

// C++ library includes
#include <limits>

// Internal library includes
#include <cpporm/util/string.h>

CPPORM_BEGIN_SUB_SUB_NAMESPACE(backend, soci)

/*!
 * \details
 */
template <>
CPPORM_SOCI_EXPORT std::string Convert(const double &value)
{
    if (std::isnan(value))
        return "NaN";
    else if (!std::isfinite(value))
        return value < 0 ? "-Inf" : "+Inf";

    std::ostringstream stream;
    stream << std::setprecision(std::numeric_limits<long double>::digits10) << value;
    return stream.str();
}

/*!
 * \details
 */
template <>
CPPORM_SOCI_EXPORT std::string Convert(const int &value)
{
    return util::to_string(value);
}

/*!
 * \details
 */
template <>
CPPORM_SOCI_EXPORT std::string Convert(const long long &value)
{
    return util::to_string(value);
}

/*!
 * \details
 */
template <>
CPPORM_SOCI_EXPORT std::string Convert(const unsigned long long &value)
{
    return util::to_string(value);
}

/*!
 * \details
 */
template <>
CPPORM_SOCI_EXPORT std::string Convert(const std::tm &value)
{
    char buffer[20];
    if (value.tm_year < 0)
    {
        std::tm time{value.tm_mday, value.tm_mon + 1, value.tm_year + 1900};
        std::strftime(buffer, sizeof(buffer), "%H:%M:%S", &time);
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
