/*!
 * \file
 * \brief     nanodbc connection class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

// External library includes
#include <cpporm/backend/nanodbc/nanodbc.h>

// Internal library includes
#include <cpporm/backend/nanodbc/export.h>
#include <cpporm/db/connection.h>

CPPORM_BEGIN_SUB_SUB_NAMESPACE(backend, nanodbc)

/*
 * Forward declarations
 */
class Statement;

/*!
 * \brief Database connection
 */
class CPPORM_NANODBC_EXPORT Connection : public db::Connection
{
public:
    /*!
     * \brief Reconnect
     */
    void Reconnect() override;

    /*!
     * \brief Disconnect
     */
    void Disconnect() override;

    /*!
     * \brief Is connected?
     * \return True, if connected to the database
     */
    bool IsConnected() const override;

    /*!
     * \brief Create query
     * \return The query
     */
    std::unique_ptr<db::Query> CreateQuery() override;

    /*!
     * \brief Create query
     * \return The statement
     */
    std::unique_ptr<db::Statement> CreateStatement() override;

    /*!
     * \brief Just execute
     * \param[in] sql The SQL text
     */
    void JustExecute(const std::string &sql) override;

    /*!
     * \brief Execute query
     * \param[in] sql The SQL text
     * \return The cursor
     */
    std::unique_ptr<db::Cursor> Execute(const std::string &sql) override;

    /*!
     * \brief Execute statement
     * \param[in] statement The statement
     * \return The cursor
     */
    std::unique_ptr<db::Cursor> Execute(db::Statement &statement) override;

protected:
    /*!
     * \brief Inner connect
     */
    void InnerConnect() override;

private:
    /*!
     * \brief Befriend Statement class
     */
    friend class Statement;

    /*!
     * \brief Befriend Transaction class
     */
    friend class Transaction;

    /*!
     * \brief The name of the driver connection option
     */
    static const std::string cDriverOptionName;

    /*!
     * \brief The connection string
     */
    std::string mConnectionString;

    /*!
     * \brief The native connection object
     */
    cpporm::nanodbc::connection mNativeConnection;
};

CPPORM_END_SUB_SUB_NAMESPACE
