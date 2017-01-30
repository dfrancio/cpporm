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

TEST(CppOrm_Unit_Entity, TestSet4)
{
    MyEntity3 entity3;
    ASSERT_TRUE(entity3.GetId().empty());
    ASSERT_TRUE(entity3.attr.Get().empty());
    Query query;
    entity3.Insert(query);
    ASSERT_EQ(query.GetAndReset(), "INSERT INTO ent3 (name3) VALUES (?);");
    ASSERT_FALSE(entity3.GetId().empty());
    ASSERT_FALSE(entity3.attr.Get().empty());
    entity3.Rollback();
    ASSERT_TRUE(entity3.GetId().empty());
    ASSERT_TRUE(entity3.attr.Get().empty());
    entity3.InsertIntoTemp(query);
    ASSERT_EQ(query.GetAndReset(), "INSERT INTO ent3Temp (name3) VALUES (?);");
    ASSERT_FALSE(entity3.GetId().empty());
    ASSERT_FALSE(entity3.attr.Get().empty());

    MyEntity4 entity4;
    ASSERT_TRUE(entity4.GetId().empty());
    ASSERT_TRUE(entity4.attr.Get().empty());
    entity4.Insert(query);
    ASSERT_EQ(query.GetAndReset(), "INSERT INTO ent4 (name4) VALUES (?);");
    ASSERT_FALSE(entity4.GetId().empty());
    ASSERT_FALSE(entity4.attr.Get().empty());
    entity4.Rollback();
    ASSERT_TRUE(entity4.GetId().empty());
    ASSERT_TRUE(entity4.attr.Get().empty());
    entity4.InsertIntoTemp(query);
    ASSERT_EQ(query.GetAndReset(), "INSERT INTO ent4Temp (name4) VALUES (?);");
    ASSERT_FALSE(entity4.GetId().empty());
    ASSERT_FALSE(entity4.attr.Get().empty());
}

TEST(CppOrm_Unit_Entity, TestSet5)
{
    Test2 entity1;
    entity1.id.Set("a");
    entity1.name.Set("b");
    entity1.datetime.Set("d");
    entity1.created_by.Set("e");

    Test2 entity2;
    ASSERT_TRUE(entity2.id.Get().empty());
    ASSERT_TRUE(entity2.name.Get().empty());
    ASSERT_TRUE(entity2.datetime.Get().empty());
    ASSERT_TRUE(entity2.created_by.Get().empty());

    entity2.CopyFrom(entity1);
    ASSERT_TRUE(entity2.id.Get().empty());
    ASSERT_FALSE(entity2.name.Get().empty());
    ASSERT_TRUE(entity2.datetime.Get().empty());
    ASSERT_FALSE(entity2.created_by.Get().empty());

    Test2 entity3;
    ASSERT_TRUE(entity3.id.Get().empty());
    ASSERT_TRUE(entity3.name.Get().empty());
    ASSERT_TRUE(entity3.datetime.Get().empty());
    ASSERT_TRUE(entity3.created_by.Get().empty());

    entity3.CopyAllFrom(entity1);
    ASSERT_FALSE(entity3.id.Get().empty());
    ASSERT_FALSE(entity3.name.Get().empty());
    ASSERT_FALSE(entity3.datetime.Get().empty());
    ASSERT_FALSE(entity3.created_by.Get().empty());
}
