#include <cpporm/entity.h>

// C++ library includes
#include <string>

// External library includes
#include <gmock/gmock.h>
#include <gtest/gtest.h>

// Internal program includes
#include "helpers.h"

// Using namespace
using namespace cpporm::db;

TEST(CppOrm_Unit_Entity, TestSet1)
{
    MyEntity entity;
    ASSERT_EQ(entity.GetId(), "ent");
    ASSERT_FALSE(entity.WasModified());
    entity.attr.Set("1");
    ASSERT_EQ(entity.GetId(), "ent");
    ASSERT_TRUE(entity.WasModified());
    entity.ResetId();
    ASSERT_EQ(entity.GetId(), "ent1");
    entity.Rollback();
    ASSERT_EQ(entity.attr.Get(), "");
    ASSERT_EQ(entity.GetId(), "ent");
    ASSERT_FALSE(entity.WasModified());
    entity["attr"] = "1";
    entity.Commit();
    ASSERT_EQ(entity.attr.Get(), "1");
    ASSERT_EQ(entity.GetId(), "ent");
    ASSERT_FALSE(entity.WasModified());
    MyCursor2 cursor;
    entity.Extract(cursor);
    ASSERT_EQ(entity.GetId(), "entabc");
}

TEST(CppOrm_Unit_Entity, TestSet2)
{
    MyEntity entity;
    Query query;
    SqliteQuery sqliteQuery;
    MyStatement statement;
    entity.Fetch(query);
    ASSERT_EQ(query.GetAndReset(), "SELECT * FROM ent;");
    entity.FetchLastId(query);
    ASSERT_EQ(query.GetAndReset(), "SELECT AS name;");
    entity.FetchLastId(sqliteQuery);
    ASSERT_EQ(sqliteQuery.GetAndReset(), "SELECT last_insert_rowid() AS name;");
    entity.FetchPrimaryKey(query);
    ASSERT_EQ(query.GetAndReset(), "SELECT DISTINCT ent.attr FROM ent;");
    entity.Insert(query);
    ASSERT_EQ(query.GetAndReset(), "INSERT INTO ent DEFAULT VALUES;");
    entity.attr.Set("1");
    entity.Insert(query);
    ASSERT_EQ(query.GetAndReset(), "INSERT INTO ent (name) VALUES (?);");
    entity.Rollback();
    entity.Delete(query);
    ASSERT_EQ(query.GetAndReset(), "DELETE FROM ent;");
    entity.Where(query);
    ASSERT_EQ(query.GetAndReset(), " WHERE name IS NULL;");
    entity.attr.Set("1");
    entity.Where(query);
    ASSERT_EQ(query.GetAndReset(), " WHERE name=?;");
    entity.Rollback();
    entity.Update(query);
    ASSERT_EQ(query.GetAndReset(), "UPDATE ent;");
    entity.Where(query);
    ASSERT_EQ(query.GetAndReset(), " WHERE name IS NULL AND name2 IS NULL;");
    entity.attr.Set("1");
    entity.Update(query);
    ASSERT_EQ(query.GetAndReset(), "UPDATE ent SET name=?;");
    entity.Bind(statement);
    ASSERT_EQ(statement.boundValues, std::vector<std::string>({"1"}));
    ASSERT_EQ(statement.nullCount, 0);
    entity.BindPrimaryKey(statement);
    ASSERT_EQ(statement.boundValues, std::vector<std::string>({"1"}));
    ASSERT_EQ(statement.nullCount, 1);
    entity.SavePrimaryKey();
    entity.attr.Set("2");
    entity.BindPrimaryKey(statement);
    ASSERT_EQ(statement.boundValues, std::vector<std::string>({"1", "2"}));
    ASSERT_EQ(statement.nullCount, 1);
    entity.Update(query);
    entity.BindPrimaryKey(statement);
    ASSERT_EQ(statement.boundValues, std::vector<std::string>({"1", "2", "1"}));
    ASSERT_EQ(statement.nullCount, 1);
    entity.Update(query);
    query.Reset();
    entity.Where(query);
    ASSERT_EQ(query.GetAndReset(), " WHERE name=? AND name2 IS NULL;");
    ASSERT_FALSE(entity.MarkForRemoval());
    ASSERT_TRUE(entity.MarkForRemoval());
    ASSERT_TRUE(entity.MarkForRemoval());
    entity.Rollback();
    ASSERT_FALSE(entity.MarkForRemoval());
}

TEST(CppOrm_Unit_Entity, TestSet3)
{
    static const std::string cCreateTableQuery1
        = "CREATE TABLE Test2 ("
          "created_by INTEGER NOT NULL,"
          "name TEXT DEFAULT NULL,"
          "datetime DATETIME DEFAULT CURRENT_TIMESTAMP NOT NULL,"
          "id INTEGER NOT NULL AUTO_INCREMENT,"
          "UNIQUE (name),"
          "PRIMARY KEY (id));";
    static const std::string cCreateTableQuery2
        = "CREATE TABLE Test2 ("
          "datetime DATETIME DEFAULT CURRENT_TIMESTAMP NOT NULL,"
          "name TEXT DEFAULT NULL,"
          "created_by INTEGER NOT NULL,"
          "id INTEGER NOT NULL AUTO_INCREMENT,"
          "UNIQUE (name),"
          "PRIMARY KEY (id));";
    static const std::string cCreateTableQuery3
        = "CREATE TABLE Test2 ("
          "created_by INTEGER NOT NULL,"
          "datetime DATETIME DEFAULT CURRENT_TIMESTAMP NOT NULL,"
          "name TEXT DEFAULT NULL,"
          "id INTEGER NOT NULL AUTO_INCREMENT,"
          "UNIQUE (name),"
          "PRIMARY KEY (id));";
    Test2 entity;
    Query query;
    entity.InsertIntoTemp(query);
    ASSERT_EQ(query.GetAndReset(), "INSERT INTO Test2Temp DEFAULT VALUES;");
    entity.id = "1";
    entity.name = "a";
    entity.InsertIntoTemp(query);
    ASSERT_EQ(query.GetAndReset(), "INSERT INTO Test2Temp (id) VALUES (?);");
    entity.JoinTemp(query);
    ASSERT_EQ(query.GetAndReset(), " NATURAL JOIN Test2Temp;");
    entity.CreateSchema(query);
    ASSERT_THAT(
        query.GetAndReset(),
        ::testing::AnyOf(cCreateTableQuery1, cCreateTableQuery2, cCreateTableQuery3));
    entity.CreateTempSchema(query);
    ASSERT_EQ(
        query.GetAndReset(), "CREATE TEMPORARY TABLE IF NOT EXISTS Test2Temp ("
                             "id INTEGER NOT NULL AUTO_INCREMENT,"
                             "PRIMARY KEY (id));");
    entity.EraseTable(query);
    ASSERT_EQ(query.GetAndReset(), "DELETE FROM Test2;");
    entity.EraseTempTable(query);
    ASSERT_EQ(query.GetAndReset(), "DELETE FROM Test2Temp;");
    entity.DropSchema(query);
    ASSERT_EQ(query.GetAndReset(), "DROP TABLE Test2;");
    entity.DropTempSchema(query);
    ASSERT_EQ(query.GetAndReset(), "DROP TEMPORARY TABLE Test2Temp;");
}
