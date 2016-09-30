/*!
 * \file
 * \brief     SOCI utils
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

// C library includes
#include <ctime>

// Internal library includes
#include <cpporm/backend/soci/export.h>
#include <cpporm/util/preprocessor.h>

CPPORM_BEGIN_SUB_SUB_NAMESPACE(backend, soci)

/*!
 * \brief Convert to string
 * \param[in] value The value
 * \return The converted value
 */
template <typename T>
std::string Convert(const T &value);

/*!
 * \brief Process parameter names
 * \param[in] sql The SQL text
 * \return The processed SQL string
 */
CPPORM_SOCI_EXPORT std::string ProcessParameterNames(const std::string &sql);

/*!
 * \brief Make parameter name
 * \param[in] param The parameter index
 * \return The parameter name
 */
CPPORM_SOCI_EXPORT std::string MakeParameterName(short param);

CPPORM_END_SUB_SUB_NAMESPACE
