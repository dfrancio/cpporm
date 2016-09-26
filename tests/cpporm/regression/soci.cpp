// C++ library includes
#include <string>

// External library includes
#include <gtest/gtest.h>

// Internal program includes
#include <cpporm/backend/soci/connection.h>
#include <cpporm/db/cursor.h>
#include <cpporm/db/statement.h>

// Test fixture
class CppOrm_Regression_Soci : public testing::Test
{
protected:
    CppOrm_Regression_Soci()
    {
        connection.SetParameters({{"Driver", SOCI_SQLITE_DRIVER_NAME}, {"dbname", "test.db"}});

        connection.JustExecute(
            "CREATE TABLE IF NOT EXISTS Document ("
            "id INTEGER NOT NULL,"
            "path TEXT NOT NULL,"
            "checksum BINARY(32) NOT NULL,"
            "size_bytes INTEGER NOT NULL,"
            "name TEXT NOT NULL,"
            "PRIMARY KEY (id),"
            "UNIQUE (path))");
        connection.JustExecute("DELETE FROM Document");
    }
    cpporm::backend::soci::Connection connection;
};

TEST_F(CppOrm_Regression_Soci, TestSet1)
{
    auto statement = connection.CreateStatement();
    statement->Prepare("INSERT INTO Document (path,checksum,size_bytes,name) VALUES (?,?,?,?)");
    statement->Bind(0, "a");
    statement->Bind(1, "87b664c7db8fbbc5f12bb3d6fbe5166997e57c19ec37d5670c031185a1b03393");
    statement->Bind(2, "1");
    statement->Bind(3, "a");
    connection.Execute(*statement);
}
