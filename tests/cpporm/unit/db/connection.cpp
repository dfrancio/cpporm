#include <cpporm/db/connection.h>

// C++ library includes
#include <string>
#include <thread>

// External library includes
#include <gtest/gtest.h>

// Internal program includes
#include "helpers.h"

// Using namespace
using namespace cpporm::db;

TEST(CppOrm_Unit_Db_Connection, TestSet1)
{
    MyConnection connection;
    ASSERT_FALSE(connection.IsConnected());
    connection.Connect();
    ASSERT_FALSE(connection.IsConnected());

    connection.SetParameters({{"Driver", ODBC_SQLITE_DRIVER_NAME}, {"Database", "abc"}});
    ASSERT_EQ(connection.mConnectionString, "");
    connection.Connect();
    ASSERT_TRUE(connection.IsConnected());
    ASSERT_EQ(connection.mConnectionString, "Database=abc;Driver=" ODBC_SQLITE_DRIVER_NAME);
    ASSERT_TRUE(dynamic_cast<SqliteQuery *>(connection.CreateQuery().get()));

    connection.Disconnect();
    ASSERT_FALSE(connection.IsConnected());
    connection.Connect();
    ASSERT_TRUE(connection.IsConnected());

    connection.SetParameters({});
    connection.Connect();
    ASSERT_FALSE(connection.IsConnected());
    ASSERT_EQ(connection.mConnectionString, "");
    ASSERT_FALSE(dynamic_cast<SqliteQuery *>(connection.CreateQuery().get()));
}

TEST(CppOrm_Unit_Db_Connection, TestSet2)
{
    MyConnection connection;
    connection.SetParameters({{"Driver", "MySQL"}, {"Database", "abc"}});
    connection.Connect();
    ASSERT_TRUE(connection.IsConnected());
    ASSERT_TRUE(dynamic_cast<MySqlQuery *>(connection.CreateQuery().get()));

    connection.mReconnectCalled = false;
    connection.SetReconnectionTimeout(0.0001);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    connection.Connect();
    ASSERT_TRUE(connection.IsConnected());
    ASSERT_TRUE(connection.mReconnectCalled);
}

TEST(CppOrm_Unit_Db_Connection, TestSet3)
{
    auto &factory = QueryFactory::GetInstance();
    auto query = factory.CreateUnique(Vendor::unknown);
    ASSERT_TRUE(dynamic_cast<Query *>(query.get()));
    query = factory.CreateUnique(Vendor::sqlite);
    ASSERT_TRUE(dynamic_cast<SqliteQuery *>(query.get()));
    query = factory.CreateUnique(Vendor::mssql);
    ASSERT_TRUE(dynamic_cast<SqlServerQuery *>(query.get()));
    query = factory.CreateUnique(Vendor::mysql);
    ASSERT_TRUE(dynamic_cast<MySqlQuery *>(query.get()));
    query = factory.CreateUnique(Vendor::postgresql);
    ASSERT_TRUE(dynamic_cast<PostgreSqlQuery *>(query.get()));
}
