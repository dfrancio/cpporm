/*!
 * \file
 * \brief     SOCI cursor class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

// Internal library includes
#include <cpporm/backend/soci/export.h>
#include <cpporm/backend/soci/statement.h>
#include <cpporm/db/cursor.h>

CPPORM_BEGIN_SUB_SUB_NAMESPACE(backend, soci)

/*!
 * \brief Class that implements a database cursor for the SOCI backend
 */
class CPPORM_SOCI_EXPORT Cursor : public db::Cursor
{
public:
    /*!
     * \brief Go to next record in the result set
     * \return True if the operation succeeded; false otherwise
     */
    bool Next() override;

    /*!
     * \brief Get number of affected rows
     * \return The number of affected rows
     */
    std::size_t GetAffectedRowCount() const override;

    /*!
     * \brief Check whether the result set has a column
     * \param[in] name The column name
     * \return True if the column is in the result set; false otherwise
     */
    bool Has(const std::string &name) const override;

    /*!
     * \brief Check whether a field is null in the current record
     * \param[in] name The column name
     * \return True if the column is null; false otherwise
     */
    bool IsNull(const std::string &name) const override;

    /*!
     * \brief Get the value of a field in the current record (by column index)
     * \param[in] column The column index
     * \return The field value
     */
    std::string Get(short column) const override;

    /*!
     * \brief Get the value of a field in the current record (by column name)
     * \param[in] name The column name
     * \return The field value
     */
    std::string Get(const std::string &name) const override;

private:
    /*!
     * \brief Befriend Connection class
     */
    friend class Connection;

    /*!
     * \brief Construct a new cursor (by pointer)
     * \param[in] statement The prepared statement
     */
    Cursor(Statement *statement);

    /*!
     * \brief Constructor a new cursor (by reference)
     * \param[in] statement The prepared statement
     */
    Cursor(Statement &statement);

    /*!
     * \brief Get field value as string (by column index)
     * \param[in] column The column index
     * \return The column value
     */
    std::string GetString(short column) const;

    /*!
     * \brief Get field value as string (by column name)
     * \param[in] name The column name
     * \return The column value
     */
    std::string GetString(const std::string &name) const;

    /*!
     * \brief The owned statement
     */
    std::unique_ptr<Statement> mOwnedStatement;

    /*!
     * \brief The prepared statement
     */
    Statement &mStatement;

    /*!
     * \brief A flag to indicate whether the first row was fetched
     */
    bool mFirstRowFetched;
};

CPPORM_END_SUB_SUB_NAMESPACE
