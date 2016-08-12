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
 * \brief Database cursor
 */
class CPPORM_SOCI_EXPORT Cursor : public db::Cursor
{
public:
    /*!
     * \brief Go to next record
     * \return True, if theoperation succeeded; false otherwise
     */
    bool Next() override;

    /*!
     * \brief Get number of affected rows
     * \return The number
     */
    std::size_t GetAffectedRowCount() const override;

    /*!
     * \brief Has column?
     * \param[in] name The column name
     * \return True if the column is in the result set; false otherwise
     */
    bool Has(const std::string &name) const override;

    /*!
     * \brief Is null?
     * \param[in] name The column name
     * \return True if the column is null; false otherwise
     */
    bool IsNull(const std::string &name) const override;

    /*!
     * \brief Get
     * \param[in] column The column index
     * \return The column value
     */
    std::string Get(short column) const override;

    /*!
     * \brief Get
     * \param[in] name The column name
     * \return The column value
     */
    std::string Get(const std::string &name) const override;

private:
    /*!
     * \brief Befriend Connection class
     */
    friend class Connection;

    /*!
     * \brief Constructor
     * \param[in] statement The statement
     */
    Cursor(Statement *statement);

    /*!
     * \brief Constructor
     * \param[in] statement The statement
     */
    Cursor(Statement &statement);

    /*!
     * \brief Get string
     * \param[in] column The column index
     * \return The column value
     */
    std::string GetString(short column) const;

    /*!
     * \brief Get string
     * \param[in] name The column name
     * \return The column value
     */
    std::string GetString(const std::string &name) const;

    /*!
     * \brief The owned statement
     */
    std::unique_ptr<Statement> mOwnedStatement;

    /*!
     * \brief The statement
     */
    Statement &mStatement;

    /*!
     * \brief A flag to indicate whether the first row was fetched
     */
    bool mFirstRowFetched;
};

CPPORM_END_SUB_SUB_NAMESPACE
