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
 * \brief Process value
 * \param[in] value The value
 * \return The processed value
 */
CPPORM_NANODBC_EXPORT std::string ProcessValue(std::string &&value);

CPPORM_END_SUB_SUB_NAMESPACE
