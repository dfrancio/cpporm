#include <cpporm/backend/soci/session.h>

// C++ library includes
#include <string>

// External library includes
#include <gtest/gtest.h>

// Internal library includes
#include <cpporm/backend/soci/transaction.h>
#include <cpporm/db/criteria.h>

// Internal program includes
#include "helpers.h"

// Using namespace
using namespace cpporm::util;
using namespace cpporm::db;

// Test fixture
class CppOrm_Unit_Backend_Soci_Session : public testing::Test
{
protected:
    CppOrm_Unit_Backend_Soci_Session()
    {
        session.GetConnection().SetParameters(
            {{"Driver", SOCI_SQLITE_DRIVER_NAME}, {"dbname", "test.db"}});

        session.GetConnection().JustExecute("CREATE TABLE IF NOT EXISTS Test2 ("
                                            "id INTEGER,"
                                            "name TEXT DEFAULT NULL,"
                                            "datetime DATETIME DEFAULT CURRENT_TIMESTAMP,"
                                            "created_by INTEGER NOT NULL,"
                                            "PRIMARY KEY(id),"
                                            "UNIQUE(name),"
                                            "FOREIGN KEY(created_by) REFERENCES Test2(id)"
                                            "   ON DELETE CASCADE DEFERRABLE INITIALLY DEFERRED)");
        session.GetConnection().JustExecute(
            "CREATE TRIGGER IF NOT EXISTS [Test2.UpdateLastTime] "
            "AFTER UPDATE ON Test2 "
            "FOR EACH ROW "
            "WHEN NEW.datetime = OLD.datetime "
            "BEGIN"
            "   UPDATE Test2 SET datetime = CURRENT_TIMESTAMP WHERE id = OLD.id;"
            "END");
        session.GetConnection().JustExecute("DELETE FROM Test2");

        session.GetConnection().Execute(
            "CREATE TABLE IF NOT EXISTS Test3 ("
            "id INTEGER,"
            "name TEXT DEFAULT NULL,"
            "datetime DATETIME DEFAULT CURRENT_TIMESTAMP,"
            "created_by INTEGER DEFAULT NULL,"
            "PRIMARY KEY(id),"
            "UNIQUE(name),"
            "FOREIGN KEY(created_by) REFERENCES Test3(id) ON DELETE SET NULL)");
        session.GetConnection().JustExecute(
            "CREATE TRIGGER IF NOT EXISTS [Test3.UpdateLastTime] "
            "AFTER UPDATE ON Test3 "
            "FOR EACH ROW "
            "WHEN NEW.datetime = OLD.datetime "
            "BEGIN"
            "   UPDATE Test3 SET datetime = CURRENT_TIMESTAMP WHERE id = OLD.id;"
            "END");
        session.GetConnection().JustExecute("DELETE FROM Test3");

        session.GetConnection().Execute("CREATE TABLE IF NOT EXISTS ent3 ("
                                        "name3 CHAR(36))");
        session.GetConnection().JustExecute("DELETE FROM ent3");

        session.GetConnection().Execute("CREATE TABLE IF NOT EXISTS ent4 ("
                                        "name4 BINARY(16))");
        session.GetConnection().JustExecute("DELETE FROM ent4");

        session.GetConnection().JustExecute("PRAGMA foreign_keys = ON");
    }
    cpporm::backend::soci::Session session;
};

TEST_F(CppOrm_Unit_Backend_Soci_Session, TestSet1)
{
    ASSERT_THROW(session.Get("Test21"), cpporm::EntryNonExistentError);
    auto entity1 = std::make_shared<Test2>();
    ASSERT_THROW(session.Add(entity1), cpporm::DatabaseExecuteError);
    auto entity2 = std::make_shared<Test2>();
    {
        cpporm::backend::soci::Transaction transaction(session);
        session.Add(entity1);
        session.Add(entity2);
        entity1->created_by = entity2->id;
        entity2->created_by = entity1->id;
        session.Update(*entity1);
        session.Update(*entity2);
        transaction.Commit();
    }
    ASSERT_EQ(entity1->GetId(), "Test21");
    ASSERT_EQ(entity2->GetId(), "Test22");
    ASSERT_NO_THROW(session.Get(entity1->GetId()));
    ASSERT_NO_THROW(session.Get(entity2->GetId()));
    ASSERT_EQ(entity1, session.Get(entity1->GetId()));
    ASSERT_NE(entity1, session.Get(entity2->GetId()));
    ASSERT_EQ(entity2, session.Get(entity2->GetId()));
    ASSERT_NE(entity2, session.Get(entity1->GetId()));

    ASSERT_TRUE(entity1->created_by_Test2 == entity2);
    ASSERT_TRUE(entity2->created_by_Test2 == entity1);
    ASSERT_TRUE(entity1->created_by_Test2 != entity2->created_by_Test2);

    int count = 0;
    auto lambda1 = [](Test2 &entity, int &count) {
        // ASSERT_EQ(&entity, entity2.get());
        ++count;
        return true;
    };
    ASSERT_TRUE(entity1->all_Test2_created_by.ForEach(lambda1, count));
    ASSERT_EQ(count, 1);

    count = 0;
    auto lambda2 = [&](Test2 &entity) {
        // ASSERT_EQ(&entity, entity1.get());
        ++count;
        return false;
    };
    ASSERT_FALSE(entity2->all_Test2_created_by.ForEach(lambda2));
    ASSERT_EQ(count, 1);

    {
        cpporm::backend::soci::Transaction transaction(session);
        session.Delete(*entity1);
        transaction.Commit();
    }
    ASSERT_THROW(session.Get(entity1->GetId()), cpporm::EntryNonExistentError);
    ASSERT_THROW(session.Get(entity2->GetId()), cpporm::EntryNonExistentError);
}

TEST_F(CppOrm_Unit_Backend_Soci_Session, TestSet2)
{
    auto entity = std::make_shared<Test2>();
    {
        cpporm::backend::soci::Transaction transaction(session);
        session.Add(entity);
        entity->created_by = entity->id;
        session.Update(*entity);
        transaction.Commit();
    }
    ASSERT_TRUE(entity->created_by_Test2 == entity);
    {
        cpporm::backend::soci::Transaction transaction(session);
        entity->id = "2";
        ASSERT_TRUE(bool(entity->created_by_Test2));
        ASSERT_NO_THROW(session.Update(*entity));
        ASSERT_THROW(entity->created_by_Test2->id.Get(), cpporm::EntityNonExistentError);
        entity->created_by = "2";
        session.Update(*entity);
        entity->id = "3";
        entity->created_by = "3";
        session.Update(*entity);
    }
    ASSERT_EQ(entity->id.Get(), "1");
    {
        cpporm::backend::soci::Transaction transaction(session);
        entity->id = "2";
        entity->created_by = "2";
        session.Update(*entity);
        entity->id = "3";
        entity->created_by = "3";
        session.Update(*entity);
        transaction.Commit();
    }
    ASSERT_EQ(entity->id.Get(), "3");
    {
        cpporm::backend::soci::Transaction transaction(session);
        session.Delete(*entity);
        transaction.Commit();
    }
    ASSERT_THROW(session.Get(entity->GetId()), cpporm::EntryNonExistentError);
}

TEST_F(CppOrm_Unit_Backend_Soci_Session, TestSet3)
{
    auto entity1 = std::make_shared<Test3>();
    auto entity2 = std::make_shared<Test3>();
    {
        cpporm::backend::soci::Transaction transaction(session);
        session.Add(entity1);
        session.Add(entity2);
        entity1->created_by = entity2->id;
        entity2->created_by = entity1->id;
        session.Update(*entity1);
        session.Update(*entity2);
        transaction.Commit();
    }
    ASSERT_TRUE(entity1->created_by_Test3 == entity2);
    ASSERT_TRUE(entity2->created_by_Test3 == entity1);
    {
        cpporm::backend::soci::Transaction transaction(session);
        session.Delete(*entity1);
        transaction.Commit();
    }
    ASSERT_TRUE(entity2->created_by.IsNull());
    ASSERT_FALSE(entity2->created_by_Test3);
}

TEST_F(CppOrm_Unit_Backend_Soci_Session, TestSet4)
{
    auto entity1 = std::make_shared<Test3>();
    auto entity2 = std::make_shared<Test3>();
    Test3 prototype;
    Criteria criteria;
    {
        cpporm::backend::soci::Transaction transaction(session);
        session.Add(entity1);
        session.Add(entity2);
        ASSERT_EQ(session.Find(prototype, {}), std::vector<std::string>({"Test31", "Test32"}));
        criteria.AddCondition("id", Condition::equal, "1");
        ASSERT_EQ(session.Find(prototype, criteria), std::vector<std::string>({"Test31"}));
    }
    ASSERT_TRUE(session.Find(prototype, {}).empty());
}

TEST_F(CppOrm_Unit_Backend_Soci_Session, TestSet5)
{
    cpporm::backend::soci::Session session2;
    session2.GetConnection().SetParameters(
        {{"Driver", SOCI_SQLITE_DRIVER_NAME}, {"dbname", "test.db"}, {"FKSupport", "true"}});
    auto entity1 = std::make_shared<Test2>();
    auto entity2 = std::make_shared<Test2>();
    {
        cpporm::backend::soci::Transaction transaction(session2);
        session2.Add(entity1);
        session2.Add(entity2);
        entity1->created_by = entity2->id;
        entity2->created_by = entity1->id;
        session2.Update(*entity1);
        session2.Update(*entity2);
        transaction.Commit();
    }

    Test2 prototype;
    Criteria criteria;
    auto ids = session.Find(prototype, criteria);
    ASSERT_EQ(ids.size(), 2);
    criteria.AddCondition("id", Condition::equal, "1");
    ids = session.Find(prototype, criteria);
    ASSERT_EQ(ids.size(), 1);
    ASSERT_EQ(ids.back(), "Test21");

    {
        cpporm::backend::soci::Transaction transaction(session2);
        auto entity3 = std::make_shared<Test2>();
        entity3->created_by = entity1->id;
        session2.Add(entity3);
        transaction.Commit();
    }

    criteria.Reset();
    criteria.AddCondition("id", Condition::equal, "3");
    ids = session.Find(prototype, criteria);
    ASSERT_EQ(session.FindOne(prototype, criteria)->GetId(), "Test23");

    session.Delete(*entity1);
    ASSERT_THROW(session.Get(entity1->GetId()), cpporm::EntryNonExistentError);
}

TEST_F(CppOrm_Unit_Backend_Soci_Session, TestSet6)
{
    cpporm::backend::soci::Session session2;
    session2.GetConnection().SetParameters(
        {{"Driver", SOCI_SQLITE_DRIVER_NAME}, {"dbname", "test.db"}, {"FKSupport", "true"}});
    auto entity1 = std::make_shared<Test2>();
    auto entity2 = std::make_shared<Test2>();
    auto entity3 = std::make_shared<Test2>();
    {
        cpporm::backend::soci::Transaction transaction(session2);
        session2.Add(entity1);
        entity2->created_by = entity1->id;
        entity3->created_by = entity1->id;
        session2.Add(entity2);
        session2.Add(entity3);
        entity1->created_by = entity2->id;
        session2.Update(*entity1);
        transaction.Commit();
    }

    std::set<std::string> uniqueIds;
    auto lambda1 = [&](Entity &entity) {
        auto id = entity.GetId();
        auto it = uniqueIds.find(id);
        if (it != uniqueIds.end())
            return Entity::TraverseResult::skip;

        uniqueIds.insert(id);
        if (id == "Test21")
            return Entity::TraverseResult::halt;
        return Entity::TraverseResult::ok;
    };
    ASSERT_EQ(entity3->TraverseRelationships(lambda1), Entity::TraverseResult::halt);
    ASSERT_EQ(uniqueIds.size(), 2);

    uniqueIds.clear();
    auto lambda2 = [&](Entity &entity) {
        auto id = entity.GetId();
        auto it = uniqueIds.find(id);
        if (it != uniqueIds.end())
            return Entity::TraverseResult::skip;

        uniqueIds.insert(id);
        if (id == "Test21")
            return Entity::TraverseResult::skip;
        return Entity::TraverseResult::ok;
    };
    ASSERT_EQ(entity3->TraverseRelationships(lambda2), Entity::TraverseResult::ok);
    ASSERT_EQ(uniqueIds.size(), 2);

    uniqueIds.clear();
    auto lambda3 = [&](Entity &entity) {
        auto id = entity.GetId();
        auto it = uniqueIds.find(id);
        if (it != uniqueIds.end())
            return Entity::TraverseResult::skip;

        uniqueIds.insert(id);
        return Entity::TraverseResult::ok;
    };
    ASSERT_EQ(entity3->TraverseRelationships(lambda3), Entity::TraverseResult::ok);
    ASSERT_EQ(uniqueIds.size(), 3);
}

TEST_F(CppOrm_Unit_Backend_Soci_Session, TestSet7)
{
    cpporm::backend::soci::Session session;
    session.GetConnection().SetParameters(
        {{"Driver", SOCI_SQLITE_DRIVER_NAME}, {"dbname", "test.db"}, {"FKSupport", "true"}});

    auto entity1 = std::make_shared<MyEntity3>();
    ASSERT_TRUE(entity1->attr.Get().empty());
    session.Add(entity1);
    ASSERT_FALSE(entity1->attr.Get().empty());
    ASSERT_NO_THROW(session.Get(entity1->attr.Get()));

    auto entity2 = std::make_shared<MyEntity4>();
    ASSERT_TRUE(entity2->attr.Get().empty());
    session.Add(entity2);
    ASSERT_FALSE(entity2->attr.Get().empty());
    ASSERT_THROW(session.Get(entity2->attr.Get()), std::exception);
    ASSERT_NO_THROW(session.Get(entity2->attr.GetGuid()));
}
