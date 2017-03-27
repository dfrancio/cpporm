/*!
 * \file
 * \brief     Cursor class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

#include <cpporm/util/macros.h>

CPPORM_BEGIN_SUB_NAMESPACE(db)

/*!
 * \brief Database cursor
 */
class CPPORM_EXPORT Cursor
{
public:
    /*!
     * \brief Destructor
     */
    virtual ~Cursor()
    {
    }

    /*!
     * \brief Go to next record
     * \return True, if theoperation succeeded; false otherwise
     */
    virtual bool Next() = 0;

    /*!
     * \brief Get number of affected rows
     * \return The number
     */
    virtual std::size_t GetAffectedRowCount() const = 0;

    /*!
     * \brief Has column?
     * \param[in] name The column name
     * \return True if the column is in the result set; false otherwise
     */
    virtual bool Has(const std::string &name) const = 0;

    /*!
     * \brief Is null?
     * \param[in] name The column name
     * \return True if the column is null; false otherwise
     */
    virtual bool IsNull(const std::string &name) const = 0;

    /*!
     * \brief Get
     * \param[in] column The column index
     * \return The column value
     */
    virtual std::string Get(short column) const = 0;

    /*!
     * \brief Get
     * \param[in] name The column name
     * \return The column value
     */
    virtual std::string Get(const std::string &name) const = 0;
};

CPPORM_END_SUB_NAMESPACE
