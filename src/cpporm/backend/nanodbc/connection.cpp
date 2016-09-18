/*!
 * \file
 * \brief     nanodbc connection implementation
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#include <cpporm/backend/nanodbc/connection.h>

// Internal library includes
#include <cpporm/backend/nanodbc/cursor.h>
#include <cpporm/backend/nanodbc/statement.h>
#include <cpporm/backend/nanodbc/utils.h>
#include <cpporm/db/connectionstring.h>
#include <cpporm/db/query.h>

CPPORM_BEGIN_SUB_SUB_NAMESPACE(backend, nanodbc)

/*!
 * \details
 */
void Connection::Reconnect()
{
    try
    {
        mNativeConnection.disconnect();
        mNativeConnection.connect(Widen16(mConnectionString));
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
        mNativeConnection.disconnect();
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
    return mNativeConnection.connected();
}

/*!
 * \details
 */
std::unique_ptr<db::Query> Connection::CreateQuery()
{
    Connect();
    return db::QueryFactory::GetInstance().CreateUnique(mVendor);
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
        ::nanodbc::just_execute(mNativeConnection, Widen16(sql));
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
        return std::unique_ptr<db::Cursor>(
            new Cursor(::nanodbc::execute(mNativeConnection, Widen16(sql))));
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
        return std::unique_ptr<db::Cursor>(
            new Cursor(::nanodbc::execute(static_cast<Statement &>(statement).mNativeStatement)));
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
        db::ConnectionString connString;
        connString.SetParameters(mParameters);
        mConnectionString = connString.Get();
        mNativeConnection.connect(Widen16(mConnectionString));
    }
    catch (const std::exception &e)
    {
        throw DatabaseConnectionError(e.what());
    }
}

CPPORM_END_SUB_SUB_NAMESPACE
