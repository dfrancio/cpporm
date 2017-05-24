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
 * \brief Abstract class that represents a database cursor/result set.
 *
 * The cursor holds data fetched from the database as the result of an SQL query. It allows the data
 * to be iterated through and extracted. The information is divided in records, each record being a
 * data row in the result set from the query.
 *
 * One can ask for the next record, the number of affected rows, if a column exists in the result
 * set or if a field is null.
 *
 * Data can only be extracted in string form. Conversions to specific data types must be performed
 * externally.
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
     * \brief Go to the next record
     * \return True, if the operation succeeded; false otherwise
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
