#include <cpporm/backend/nanodbc/transaction.h>

// C++ library includes
#include <string>

// External library includes
#include <gtest/gtest.h>

// Internal library includes
#include <cpporm/backend/nanodbc/connection.h>
#include <cpporm/backend/nanodbc/session.h>

// Internal program includes
#include "helpers.h"

// Test fixture
class CppOrm_Unit_Backend_Nanodbc_Transaction : public testing::Test
{
protected:
    CppOrm_Unit_Backend_Nanodbc_Transaction()
    {
        session.GetConnection().SetParameters(
            {{"Driver", ODBC_SQLITE_DRIVER_NAME}, {"Database", "test.db"}});

        session.GetConnection().JustExecute(
            "CREATE TABLE IF NOT EXISTS Test ("
            "id INTEGER PRIMARY KEY,"
            "name TEXT DEFAULT NULL,"
            "date DATE DEFAULT CURRENT_DATE,"
            "time TIME DEFAULT CURRENT_TIME,"
            "datetime DATETIME DEFAULT CURRENT_TIMESTAMP,"
            "value REAL DEFAULT 0.0,"
            "flag TINYINT DEFAULT NULL)");
        session.GetConnection().JustExecute("DELETE FROM Test");
    }
    cpporm::backend::nanodbc::Session session;
};

TEST_F(CppOrm_Unit_Backend_Nanodbc_Transaction, TestSet1)
{
    {
        cpporm::backend::nanodbc::Transaction transaction(session);
        session.GetConnection().Execute("INSERT INTO Test (id) VALUES (1)");
        session.GetConnection().Execute("INSERT INTO Test (id) VALUES (2)");
        ASSERT_TRUE(session.GetConnection().Execute("SELECT * FROM Test WHERE id=1")->Next());
        ASSERT_TRUE(session.GetConnection().Execute("SELECT * FROM Test WHERE id=2")->Next());
        transaction.Rollback();
        ASSERT_FALSE(session.GetConnection().Execute("SELECT * FROM Test WHERE id=1")->Next());
        ASSERT_FALSE(session.GetConnection().Execute("SELECT * FROM Test WHERE id=2")->Next());
        ASSERT_THROW(transaction.Rollback(), cpporm::DatabaseTransactionError);
    }
    ASSERT_FALSE(session.GetConnection().Execute("SELECT * FROM Test WHERE id=1")->Next());
    ASSERT_FALSE(session.GetConnection().Execute("SELECT * FROM Test WHERE id=2")->Next());
    {
        cpporm::backend::nanodbc::Transaction transaction(session);
        session.GetConnection().Execute("INSERT INTO Test (id) VALUES (1)");
        session.GetConnection().Execute("INSERT INTO Test (id) VALUES (2)");
        transaction.Commit();
        ASSERT_THROW(transaction.Commit(), cpporm::DatabaseTransactionError);
    }
    ASSERT_TRUE(session.GetConnection().Execute("SELECT * FROM Test WHERE id=1")->Next());
    ASSERT_TRUE(session.GetConnection().Execute("SELECT * FROM Test WHERE id=2")->Next());
}

TEST_F(CppOrm_Unit_Backend_Nanodbc_Transaction, TestSet2)
{
    cpporm::backend::nanodbc::Transaction transaction(session);

    transaction.AddSavePoint("name");
    session.GetConnection().Execute("INSERT INTO Test (id) VALUES (1)");
    session.GetConnection().Execute("INSERT INTO Test (id) VALUES (2)");
    ASSERT_TRUE(session.GetConnection().Execute("SELECT * FROM Test WHERE id=1")->Next());
    ASSERT_TRUE(session.GetConnection().Execute("SELECT * FROM Test WHERE id=2")->Next());

    transaction.RollbackTo("name");
    ASSERT_FALSE(session.GetConnection().Execute("SELECT * FROM Test WHERE id=1")->Next());
    ASSERT_FALSE(session.GetConnection().Execute("SELECT * FROM Test WHERE id=2")->Next());

    transaction.AddSavePoint("name");
    session.GetConnection().Execute("INSERT INTO Test (id) VALUES (1)");
    session.GetConnection().Execute("INSERT INTO Test (id) VALUES (2)");

    transaction.Release("name");
    ASSERT_TRUE(session.GetConnection().Execute("SELECT * FROM Test WHERE id=1")->Next());
    ASSERT_TRUE(session.GetConnection().Execute("SELECT * FROM Test WHERE id=2")->Next());
}

TEST_F(CppOrm_Unit_Backend_Nanodbc_Transaction, TestSet3)
{
    {
        cpporm::backend::nanodbc::Transaction transaction(session);
        {
            SavePoint savePoint(transaction, "name");
            session.GetConnection().Execute("INSERT INTO Test (id) VALUES (1)");
            session.GetConnection().Execute("INSERT INTO Test (id) VALUES (2)");
            ASSERT_TRUE(session.GetConnection().Execute("SELECT * FROM Test WHERE id=1")->Next());
            ASSERT_TRUE(session.GetConnection().Execute("SELECT * FROM Test WHERE id=2")->Next());
        }
        ASSERT_FALSE(session.GetConnection().Execute("SELECT * FROM Test WHERE id=1")->Next());
        ASSERT_FALSE(session.GetConnection().Execute("SELECT * FROM Test WHERE id=2")->Next());
        {
            SavePoint savePoint(transaction, "name");
            session.GetConnection().Execute("INSERT INTO Test (id) VALUES (1)");
            session.GetConnection().Execute("INSERT INTO Test (id) VALUES (2)");
            savePoint.Release();
            ASSERT_TRUE(session.GetConnection().Execute("SELECT * FROM Test WHERE id=1")->Next());
            ASSERT_TRUE(session.GetConnection().Execute("SELECT * FROM Test WHERE id=2")->Next());
        }
        ASSERT_TRUE(session.GetConnection().Execute("SELECT * FROM Test WHERE id=1")->Next());
        ASSERT_TRUE(session.GetConnection().Execute("SELECT * FROM Test WHERE id=2")->Next());

        transaction.Commit();
    }
    ASSERT_TRUE(session.GetConnection().Execute("SELECT * FROM Test WHERE id=1")->Next());
    ASSERT_TRUE(session.GetConnection().Execute("SELECT * FROM Test WHERE id=2")->Next());
}
