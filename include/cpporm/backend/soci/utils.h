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
#include <cpporm/util/macros.h>

CPPORM_BEGIN_SUB_SUB_NAMESPACE(backend, soci)

/*!
 * \brief Convert to string
 * \tparam T The type of the input value
 * \param[in] value The value
 * \return The converted value
 */
template <typename T>
std::string Convert(const T &value);

/*!
 * \brief Process parameter names in an SQL query
 *
 * This function parses the input SQL searching for placeholders (?) and replaces them by
 * parameters, giving each parameter a name corresponding to the order of occurrence in the query.
 *
 * For example:
 * > UPDATE table_name SET column1 = ?, column2 = ? WHERE column1 = ?;
 *
 * Turns into:
 * > UPDATE table_name SET column1 = :0, column2 = :1 WHERE column1 = :2;
 *
 * \param[in] sql The SQL text
 * \return The processed SQL string
 * \see MakeParameterName
 */
CPPORM_SOCI_EXPORT std::string ProcessParameterNames(const std::string &sql);

/*!
 * \brief Make parameter name from parameter index
 * \param[in] param The parameter index
 * \return The parameter name
 */
CPPORM_SOCI_EXPORT std::string MakeParameterName(short param);

CPPORM_END_SUB_SUB_NAMESPACE
