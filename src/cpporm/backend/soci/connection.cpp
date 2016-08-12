/*!
 * \file
 * \brief     SOCI connection implementation
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#include <cpporm/backend/soci/connection.h>

// External library includes
#include <boost/algorithm/string.hpp>

// Internal library includes
#include <cpporm/backend/soci/cursor.h>
#include <cpporm/backend/soci/statement.h>
#include <cpporm/db/connectionstring.h>
#include <cpporm/db/query.h>

CPPORM_BEGIN_SUB_SUB_NAMESPACE(backend, soci)

/*!
 * \details
 */
void Connection::Reconnect()
{
    try
    {
        mNativeConnection.reconnect();
    }
    catch (const std::exception &e)
    {
        throw DatabaseConnectionError(e.what());
    }
}

/*!
 * \details
 */
void Connection::Disconnect()
{
    try
    {
        mNativeConnection.close();
        mIsConnected = false;
    }
    catch (const std::exception &e)
    {
        throw DatabaseConnectionError(e.what());
    }
}

/*!
 * \details
 */
bool Connection::IsConnected() const
{
    return mIsConnected;
}

/*!
 * \details
 */
std::unique_ptr<db::Query> Connection::CreateQuery()
{
    Connect();
    return db::QueryFactory::GetInstance().Create(mVendor);
}

/*!
 * \details
 */
std::unique_ptr<db::Statement> Connection::CreateStatement()
{
    Connect();
    return std::unique_ptr<db::Statement>(new Statement(mNativeConnection));
}

/*!
 * \details
 */
void Connection::JustExecute(const std::string &sql)
{
    Connect();
    try
    {
        mNativeConnection << sql;
    }
    catch (const std::exception &e)
    {
        throw DatabaseExecuteError(e.what());
    }
}

/*!
 * \details
 */
std::unique_ptr<db::Cursor> Connection::Execute(const std::string &sql)
{
    Connect();
    try
    {
        std::unique_ptr<Statement> statement(new Statement(mNativeConnection));
        statement->Prepare(sql);
        return std::unique_ptr<db::Cursor>(new Cursor(statement.release()));
    }
    catch (const std::exception &e)
    {
        throw DatabaseExecuteError(e.what());
    }
}

/*!
 * \details
 */
std::unique_ptr<db::Cursor> Connection::Execute(db::Statement &statement)
{
    Connect();
    try
    {
        return std::unique_ptr<db::Cursor>(new Cursor(static_cast<Statement &>(statement)));
    }
    catch (const std::exception &e)
    {
        throw DatabaseExecuteError(e.what());
    }
}

/*!
 * \details
 */
void Connection::InnerConnect()
{
    try
    {
        auto parameters = mParameters;
        auto it = parameters.find(GetDriverOptionName());
        if (it == parameters.end())
            throw DatabaseConnectionError("option not set", GetDriverOptionName());

        auto driver = it->second;
        parameters.erase(it);
        db::ConnectionString connString;
        connString.SetSeparator(' ').SetParameters(parameters);
        mNativeConnection.open(driver, connString.Get());
        mIsConnected = true;
    }
    catch (const std::exception &e)
    {
        throw DatabaseConnectionError(e.what());
    }
}

CPPORM_END_SUB_SUB_NAMESPACE
