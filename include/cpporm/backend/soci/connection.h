/*!
 * \file
 * \brief     SOCI connection class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

// External library includes
#include <soci/soci.h>

// Internal library includes
#include <cpporm/backend/soci/export.h>
#include <cpporm/db/connection.h>

CPPORM_BEGIN_SUB_SUB_NAMESPACE(backend, soci)

/*
 * Forward declarations
 */
class Statement;

/*!
 * \brief Class that implements a database connection for the SOCI backend
 */
class CPPORM_SOCI_EXPORT Connection : public db::Connection
{
public:
    /*!
     * \brief Reconnect to database
     */
    void Reconnect() override;

    /*!
     * \brief Disconnect from database
     */
    void Disconnect() override;

    /*!
     * \brief Check whether the connection is opened
     * \return True if the connection is opened; false otherwise
     */
    bool IsConnected() const override;

    /*!
     * \brief Create query to intereact with the connected database
     * \return The query object
     */
    std::unique_ptr<db::Query> CreateQuery() override;

    /*!
     * \brief Create statement to intereact with the connected database
     * \return The statement object
     */
    std::unique_ptr<db::Statement> CreateStatement() override;

    /*!
     * \brief Execute simple query with no expected result
     * \param[in] sql The SQL text
     */
    void JustExecute(const std::string &sql) override;

    /*!
     * \brief Execute query in the connected database
     * \param[in] sql The SQL text
     * \return The result set of the query
     */
    std::unique_ptr<db::Cursor> Execute(const std::string &sql) override;

    /*!
     * \brief Execute statement in the connected database
     * \param[in] statement The prepared statement
     * \return The result set of the statement
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
     * \brief The native connection object
     */
    ::soci::session mNativeConnection;

    /*!
     * \brief A flag to indicate whether the connection is opened
     */
    bool mIsConnected = false;
};

CPPORM_END_SUB_SUB_NAMESPACE
