#include <cpporm/backend/nanodbc/cursor.h>

// C++ library includes
#include <string>

// External library includes
#include <gtest/gtest.h>

// Internal library includes
#include <cpporm/backend/nanodbc/connection.h>

// Test fixture
class CppOrm_Unit_Backend_Nanodbc_Cursor : public testing::Test
{
protected:
    CppOrm_Unit_Backend_Nanodbc_Cursor()
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

        connection.Execute("INSERT INTO Test (name,date) VALUES (\"ABC\",\"1990-12-14\")");
        connection.Execute("INSERT INTO Test (name,date,flag) VALUES (\"DEF\",\"1989-09-03\",1)");
        connection.Execute("INSERT INTO Test (id,name) VALUES (8294967296,'abc')");
        connection.Execute("INSERT INTO Test (id,name) VALUES (-9223372036854775808,'def')");

        connection.JustExecute(
            "CREATE TABLE IF NOT EXISTS Test5 ("
            "id INTEGER PRIMARY KEY,"
            "hash BINARY)");
        connection.JustExecute("DELETE FROM Test5");

        connection.Execute("INSERT INTO Test5 (hash) VALUES (x'a0b1c2d3')");
    }
    cpporm::backend::nanodbc::Connection connection;
};

TEST_F(CppOrm_Unit_Backend_Nanodbc_Cursor, TestSet1)
{
    auto cursor = connection.Execute("SELECT * FROM Test ORDER BY name");
    ASSERT_EQ(cursor->GetAffectedRowCount(), 0);
    ASSERT_TRUE(cursor->Has("id"));
    ASSERT_TRUE(cursor->Has("name"));
    ASSERT_TRUE(cursor->Has("date"));
    ASSERT_TRUE(cursor->Has("time"));
    ASSERT_TRUE(cursor->Has("datetime"));
    ASSERT_TRUE(cursor->Has("value"));
    ASSERT_TRUE(cursor->Has("flag"));
    ASSERT_FALSE(cursor->Has("xxxx"));

    ASSERT_TRUE(cursor->Next());
    ASSERT_EQ(cursor->Get("id"), "1");
    ASSERT_EQ(cursor->Get("name"), "ABC");
    ASSERT_EQ(cursor->Get("date"), "1990-12-14");
    auto time = cursor->Get("time");
    auto datetime = cursor->Get("datetime");
    ASSERT_EQ(cursor->Get("value"), "0");
    ASSERT_TRUE(cursor->IsNull("flag"));

    ASSERT_TRUE(cursor->Next());
    ASSERT_EQ(cursor->Get("id"), "2");
    ASSERT_EQ(cursor->Get("name"), "DEF");
    ASSERT_EQ(cursor->Get("date"), "1989-09-03");
    time = cursor->Get("time");
    datetime = cursor->Get("datetime");
    ASSERT_EQ(cursor->Get("value"), "0");
    ASSERT_EQ(cursor->Get("flag"), "1");
    ASSERT_FALSE(cursor->IsNull("flag"));

    ASSERT_TRUE(cursor->Next());
    ASSERT_TRUE(cursor->Next());
    ASSERT_FALSE(cursor->Next());
}

TEST_F(CppOrm_Unit_Backend_Nanodbc_Cursor, TestSet2)
{
    auto cursor = connection.Execute("UPDATE Test SET flag=0 WHERE id=1");
    ASSERT_EQ(cursor->GetAffectedRowCount(), 1);
    ASSERT_FALSE(cursor->Next());
    cursor = connection.Execute("SELECT * FROM Test WHERE id=1");
    ASSERT_TRUE(cursor->Next());
    ASSERT_EQ(cursor->Get("flag"), "0");
    ASSERT_FALSE(cursor->Next());

    cursor = connection.Execute("UPDATE Test SET flag=NULL WHERE name=\"ABC\"");
    ASSERT_EQ(cursor->GetAffectedRowCount(), 1);
    ASSERT_FALSE(cursor->Next());
    cursor = connection.Execute("SELECT * FROM Test WHERE name=\"ABC\"");
    ASSERT_TRUE(cursor->Next());
    ASSERT_TRUE(cursor->IsNull("flag"));
    ASSERT_FALSE(cursor->Next());

    cursor = connection.Execute("UPDATE Test SET flag=NULL WHERE id>0 AND id<3 AND flag IS NULL");
    ASSERT_EQ(cursor->GetAffectedRowCount(), 1);
    ASSERT_FALSE(cursor->Next());
    cursor = connection.Execute("SELECT * FROM Test WHERE id BETWEEN 0 AND 3 AND flag IS NULL");
    ASSERT_TRUE(cursor->Next());
    ASSERT_EQ(cursor->Get("id"), "1");
    ASSERT_FALSE(cursor->Next());
}

TEST_F(CppOrm_Unit_Backend_Nanodbc_Cursor, TestSet3)
{
    auto cursor = connection.Execute("SELECT * FROM Test WHERE id=8294967296");
    ASSERT_TRUE(cursor->Next());
    ASSERT_EQ(cursor->Get("id"), "8294967296");

    cursor = connection.Execute("SELECT * FROM Test WHERE id=-9223372036854775808");
    ASSERT_TRUE(cursor->Next());
    ASSERT_EQ(cursor->Get("id"), "-9223372036854775808");
}

TEST_F(CppOrm_Unit_Backend_Nanodbc_Cursor, TestSet4)
{
    auto cursor = connection.Execute("DELETE FROM Test");
    ASSERT_EQ(cursor->GetAffectedRowCount(), 4);
    cursor = connection.Execute("DELETE FROM Test");
    ASSERT_EQ(cursor->GetAffectedRowCount(), 0);

    cursor = connection.Execute("SELECT COUNT(*) FROM Test");
    ASSERT_TRUE(cursor->Next());
    ASSERT_EQ(cursor->Get(0), "0");
}

TEST_F(CppOrm_Unit_Backend_Nanodbc_Cursor, TestSet5)
{
    auto cursor = connection.Execute("SELECT * FROM Test5");
    ASSERT_TRUE(cursor->Next());
    ASSERT_EQ(cursor->Get("hash"), "\xa0\xb1\xc2\xd3");
}
