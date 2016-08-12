/*!
 * \file
 * \brief     nanodbc cursor class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

// External library includes
#include <nanodbc.h>

// Internal library includes
#include <cpporm/backend/nanodbc/export.h>
#include <cpporm/db/cursor.h>

CPPORM_BEGIN_SUB_SUB_NAMESPACE(backend, nanodbc)

/*!
 * \brief Database cursor
 */
class CPPORM_NANODBC_EXPORT Cursor : public db::Cursor
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
     * \param[in] native The native cursor object
     */
    Cursor(::nanodbc::result &&native);

    /*!
     * \brief The native cursor object
     */
    ::nanodbc::result mNativeCursor;
};

CPPORM_END_SUB_SUB_NAMESPACE
