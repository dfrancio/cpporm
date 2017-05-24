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
 * \brief Class that helps build connection strings
 *
 * A connection string is a list of parameters passed to a database driver in the establishment of a
 * connection. The parameters are specified in name-and-value pairs, separated by a separator
 * character.
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
     * \return A reference to *this
     */
    ConnectionString &SetSeparator(char separator);

    /*!
     * \brief Set parameters
     * \param[in] parameters The connection parameters
     * \return A reference to *this
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
     * \brief Get connection string
     * \return The resulting connection string
     */
    const std::string &Get() const;

    /*!
     * \brief Reset connection string
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
