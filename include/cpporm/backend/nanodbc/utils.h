/*!
 * \file
 * \brief     nanodbc utils
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

// Internal library includes
#include <cpporm/backend/nanodbc/export.h>
#include <cpporm/util/preprocessor.h>

CPPORM_BEGIN_SUB_SUB_NAMESPACE(backend, nanodbc)

/*!
 * \brief Widen narrow-string
 * \param[in] text The text
 * \return The widened text
 */
CPPORM_NANODBC_EXPORT std::u16string Widen16(const std::string &text);

/*!
 * \brief Narrow wide-string
 * \param[in] text The text
 * \return The narrowed text
 */
CPPORM_NANODBC_EXPORT std::string Narrow(const std::u16string &text);

/*!
 * \brief Handle date and time values
 * \param[in] value The value
 * \return The corrected value
 */
CPPORM_NANODBC_EXPORT std::string HandleDateTime(std::string &&value);

CPPORM_END_SUB_SUB_NAMESPACE
