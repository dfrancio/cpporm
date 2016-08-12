/*!
 * \file
 * \brief     Connection class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#include <cpporm/db/connection.h>

// Internal library includes
#include <cpporm/db/query.h>

CPPORM_BEGIN_SUB_NAMESPACE(db)

/*!
 * \details
 */
Connection::~Connection()
{
}

/*!
 * \details
 */
void Connection::Connect()
{
    if (IsConnected())
    {
        typedef std::chrono::duration<double, std::ratio<60>> minutes;
        auto end = std::chrono::high_resolution_clock::now();
        auto minutesElapsed = minutes(end - mLastCheckpoint).count();
        mLastCheckpoint = end;
        if (minutesElapsed > mReconnectionTimeoutMin)
        {
            Reconnect();
            mLastCheckpoint = std::chrono::high_resolution_clock::now();
        }
    }
    else
    {
        InnerConnect();
        mVendor = GuessDatabaseVendor();
        mLastCheckpoint = std::chrono::high_resolution_clock::now();
    }
}

/*!
 * \details
 */
void Connection::SetParameters(const std::map<std::string, std::string> &parameters)
{
    if (mParameters != parameters)
    {
        mParameters = parameters;
        Disconnect();
    }
}

/*!
 * \details
 */
void Connection::SetReconnectionTimeout(double minutes)
{
    mReconnectionTimeoutMin = minutes;
}

/*!
 * \details
 */
Vendor Connection::GuessDatabaseVendor() const
{
    const auto it = mParameters.find(GetDriverOptionName());
    if (it == mParameters.end())
        return Vendor::unknown;

    auto driverName = it->second;
    std::transform(driverName.begin(), driverName.end(), driverName.begin(), ::tolower);
    if (driverName.find("sqlite") != std::string::npos)
        return Vendor::sqlite;
    else if (driverName.find("server") != std::string::npos)
        return Vendor::mssql;
    else if (driverName.find("mysql") != std::string::npos)
        return Vendor::mysql;
    else if (driverName.find("postgre") != std::string::npos)
        return Vendor::postgresql;
    else
        return Vendor::unknown;
}

/*!
 * \details
 */
const std::string &Connection::GetDriverOptionName()
{
    static std::string cOptionName = "Driver";
    return cOptionName;
}

/*!
 * \details
 */
QueryFactory::QueryFactory()
{
    Register<Query>(Vendor::unknown);
    Register<SqliteQuery>(Vendor::sqlite);
    Register<SqlServerQuery>(Vendor::mssql);
    Register<MySqlQuery>(Vendor::mysql);
    Register<PostgreSqlQuery>(Vendor::postgresql);
}

CPPORM_END_SUB_NAMESPACE
