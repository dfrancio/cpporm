#include <cpporm/backend/soci/connection.h>

// C++ library includes
#include <string>
#include <thread>

// External library includes
#include <gtest/gtest.h>

// Internal library includes
#include <cpporm/backend/soci/statement.h>
#include <cpporm/db/cursor.h>

// Test fixture
class CppOrm_Unit_Backend_Soci_Connection : public testing::Test
{
protected:
    CppOrm_Unit_Backend_Soci_Connection()
    {
        connection.SetParameters({{"Driver", SOCI_SQLITE_DRIVER_NAME}, {"dbname", "test.db"}});
    }
    cpporm::backend::soci::Connection connection;
};

TEST_F(CppOrm_Unit_Backend_Soci_Connection, TestSet1)
{
    connection.Connect();
    ASSERT_TRUE(connection.IsConnected());
    connection.Disconnect();
    ASSERT_FALSE(connection.IsConnected());

    connection.SetParameters({{"Driver", "abc"}, {"Database", "test.db"}});
    ASSERT_THROW(connection.Connect(), cpporm::DatabaseConnectionError);
}

TEST_F(CppOrm_Unit_Backend_Soci_Connection, TestSet2)
{
    connection.JustExecute("CREATE TABLE IF NOT EXISTS Test ("
                           "id INTEGER PRIMARY KEY,"
                           "name TEXT DEFAULT NULL,"
                           "date DATE DEFAULT CURRENT_DATE,"
                           "time TIME DEFAULT CURRENT_TIME,"
                           "datetime DATETIME DEFAULT CURRENT_TIMESTAMP,"
                           "value REAL DEFAULT 0.0,"
                           "flag TINYINT DEFAULT NULL)");

    connection.Connect();
    auto cursor = connection.Execute("SELECT * FROM Test");
    connection.SetReconnectionTimeout(0);
    ASSERT_NO_THROW(connection.Execute("SELECT * FROM Test"));
}

TEST_F(CppOrm_Unit_Backend_Soci_Connection, TestSet3)
{
    auto statement = connection.CreateStatement();
    ASSERT_THROW(connection.Execute(*statement), cpporm::DatabaseExecuteError);
    statement->Prepare("SELECT * FROM Test");
    connection.Execute(*statement);
}
