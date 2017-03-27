/*!
 * \file
 * \brief     Connection string class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

#include <cpporm/util/macros.h>

CPPORM_BEGIN_SUB_NAMESPACE(db)

/*!
 * \brief %Connection string
 */
class CPPORM_EXPORT ConnectionString
{
public:
    /*!
     * \brief Constructor
     */
    ConnectionString();

    /*!
     * \brief Set separator
     * \param[in] separator The separator character
     */
    ConnectionString &SetSeparator(char separator);

    /*!
     * \brief Set parameters
     * \param[in] parameters The connection parameters
     */
    ConnectionString &SetParameters(const std::map<std::string, std::string> &parameters);

    /*!
     * \brief Set parameter
     * \param[in] name The parameter name
     * \param[in] value The parameter value
     * \return A reference to *this
     */
    ConnectionString &SetParameter(const std::string &name, const std::string &value);

    /*!
     * \brief Get
     * \return The product
     */
    const std::string &Get() const;

    /*!
     * \brief Reset
     * \return A reference to *this
     */
    ConnectionString &Reset();

private:
    /*!
     * \brief The product
     */
    std::string mProduct;

    /*!
     * \brief The separator character
     */
    char mSeparator = ';';
};

CPPORM_END_SUB_NAMESPACE
