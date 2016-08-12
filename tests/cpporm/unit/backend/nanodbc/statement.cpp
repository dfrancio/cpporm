#include <cpporm/backend/nanodbc/statement.h>

// C++ library includes
#include <string>

// External library includes
#include <gtest/gtest.h>

// Internal library includes
#include <cpporm/backend/nanodbc/connection.h>
#include <cpporm/db/cursor.h>
#include <cpporm/db/statement.h>

// Test fixture
class CppOrm_Unit_Backend_Nanodbc_Statement : public testing::Test
{
protected:
    CppOrm_Unit_Backend_Nanodbc_Statement()
    {
        connection.SetParameters({{"Driver", ODBC_SQLITE_DRIVER_NAME}, {"Database", "test.db"}});

        connection.JustExecute(
            "CREATE TABLE IF NOT EXISTS Test ("
            "id INTEGER PRIMARY KEY,"
            "name TEXT DEFAULT NULL,"
            "date DATE DEFAULT CURRENT_DATE,"
            "time TIME DEFAULT CURRENT_TIME,"
            "datetime DATETIME DEFAULT CURRENT_TIMESTAMP,"
            "value REAL DEFAULT 0.0,"
            "flag TINYINT DEFAULT NULL)");
        connection.JustExecute("DELETE FROM Test");
    }
    cpporm::backend::nanodbc::Connection connection;
};

TEST_F(CppOrm_Unit_Backend_Nanodbc_Statement, TestSet1)
{
    auto statement = connection.CreateStatement();
    statement->Prepare("INSERT INTO Test (name) VALUES (?)");
    statement->Bind(0, "abc");
    connection.Execute(*statement);

#ifndef _WIN32
    ASSERT_THROW(statement->Bind(0, "def"), cpporm::DatabaseStatementBindError);
#endif
    statement->Prepare("INSERT INTO Test (name) VALUES (?)");
    statement->Bind(0, "def");
    auto cursor = connection.Execute(*statement);
    ASSERT_FALSE(cursor->Next());

    statement->Prepare("SELECT * FROM Test");
    cursor = connection.Execute(*statement);
    ASSERT_TRUE(cursor->Next());
    ASSERT_EQ(cursor->Get("id"), "1");
    ASSERT_EQ(cursor->Get("name"), "abc");
}
