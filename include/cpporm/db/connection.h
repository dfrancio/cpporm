/*!
 * \file
 * \brief     Connection class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

#include <cpporm/util/factory.h>

CPPORM_BEGIN_SUB_NAMESPACE(db)

/*
 * Forward declarations
 */
class Cursor;
class Query;
class Statement;

/*!
 * \brief Database vendor
 */
enum class Vendor
{
    unknown, /*!< unknown vendor */
    sqlite, /*!< SQLite */
    mssql, /*!< Microsoft SQL Server */
    mysql, /*!< MySQL */
    postgresql /*!< PostgreSQL */
};

/*!
 * \brief Database connection
 */
class CPPORM_EXPORT Connection
{
public:
    /*!
     * \brief Destructor
     */
    virtual ~Connection();

    /*!
     * \brief Connect
     */
    void Connect();

    /*!
     * \brief Set parameters
     * \param[in] parameters The connection parameters
     */
    void SetParameters(const std::map<std::string, std::string> &parameters);

    /*!
     * \brief Set reconnection timeout
     * \param[in] minutes The number of minutes to wait before a reconnection is triggered
     */
    void SetReconnectionTimeout(double minutes);

    /*!
     * \brief Reconnect
     */
    virtual void Reconnect() = 0;

    /*!
     * \brief Disconnect
     */
    virtual void Disconnect() = 0;

    /*!
     * \brief Is connected?
     * \return True, if connected to the database
     */
    virtual bool IsConnected() const = 0;

    /*!
     * \brief Create query
     * \return The query
     */
    virtual std::unique_ptr<Query> CreateQuery() = 0;

    /*!
     * \brief Create statement
     * \return The statement
     */
    virtual std::unique_ptr<Statement> CreateStatement() = 0;

    /*!
     * \brief Just execute
     * \param[in] sql The SQL text
     */
    virtual void JustExecute(const std::string &sql) = 0;

    /*!
     * \brief Execute query
     * \param[in] sql The SQL text
     * \return The cursor
     */
    virtual std::unique_ptr<Cursor> Execute(const std::string &sql) = 0;

    /*!
     * \brief Execute statement
     * \param[in] statement The statement
     * \return The cursor
     */
    virtual std::unique_ptr<Cursor> Execute(Statement &statement) = 0;

protected:
    /*!
     * \brief Inner connect
     */
    virtual void InnerConnect() = 0;

    /*!
     * \brief Guess database vendor
     * \return The vendor
     */
    virtual Vendor GuessDatabaseVendor() const;

    /*!
     * \brief Get driver option name
     * \return The driver name
     */
    static const std::string &GetDriverOptionName();

    /*!
     * \brief The connection parameters
     */
    std::map<std::string, std::string> mParameters;

    /*!
     * \brief The time of the last check for reconnection
     */
    std::chrono::high_resolution_clock::time_point mLastCheckpoint;

    /*!
     * \brief The reconnection timeout (in minutes)
     */
    double mReconnectionTimeoutMin = 5;

    /*!
     * \brief The database vendor
     */
    Vendor mVendor = Vendor::unknown;
};

/*!
 * \brief Query factory
 */
class CPPORM_EXPORT QueryFactory : public util::Factory<QueryFactory, Query, Vendor>
{
private:
    /*!
     * \brief Befriend class Factory
     */
    friend class Factory;

    /*!
     * \brief Constructor
     */
    QueryFactory();
};

CPPORM_END_SUB_NAMESPACE
