#include <cpporm/db/savepoint.h>

// C++ library includes
#include <string>

// External library includes
#include <gtest/gtest.h>

// Internal program includes
#include "helpers.h"

// Test fixture
class CppOrm_Unit_Db_SavePoint : public testing::Test
{
protected:
    CppOrm_Unit_Db_SavePoint() : entity1(new MyEntity("a", "1")), entity2(new MyEntity("b", "2"))
    {
        cache1.Add(entity1->GetId(), entity1);
        cache1.Add(entity2->GetId(), entity2);
        cache2.Add(entity1->GetId(), entity1);
        cache2.Add(entity2->GetId(), entity2);
        cache3.Add(entity1->GetId(), entity1);
    }
    std::shared_ptr<MyEntity> entity1;
    std::shared_ptr<MyEntity> entity2;
    Cache cache1;
    Cache cache2;
    Cache cache3;
};

TEST_F(CppOrm_Unit_Db_SavePoint, TestSet1)
{
    MySession session;
    MyIudContext::insertions.clear();
    {
        Transaction transaction(session);
        session.Add(entity1);
        ASSERT_NO_THROW(session.Get(entity1->GetId()));
        SavePoint savePoint(transaction, "name");
        session.Add(entity2);
        ASSERT_NO_THROW(session.Get(entity2->GetId()));
        transaction.Commit();
    }
    ASSERT_NO_THROW(session.Get(entity1->GetId()));
    ASSERT_NO_THROW(session.Get(entity2->GetId()));
    ASSERT_EQ(MyIudContext::insertions, cache1);
}

TEST_F(CppOrm_Unit_Db_SavePoint, TestSet2)
{
    MySession session;
    MyIudContext::insertions.clear();
    {
        Transaction transaction(session);
        session.Add(entity1);
        ASSERT_NO_THROW(session.Get(entity1->GetId()));
        SavePoint savePoint(transaction, "name");
        session.Add(entity2);
        ASSERT_NO_THROW(session.Get(entity2->GetId()));
    }
    ASSERT_THROW(session.Get(entity1->GetId()), cpporm::EntryNonExistentError);
    ASSERT_THROW(session.Get(entity2->GetId()), cpporm::EntryNonExistentError);
    ASSERT_TRUE(MyIudContext::insertions.empty());
}

TEST_F(CppOrm_Unit_Db_SavePoint, TestSet3)
{
    MySession session;
    MyIudContext::insertions.clear();
    {
        Transaction transaction(session);
        session.Add(entity1);
        ASSERT_NO_THROW(session.Get(entity1->GetId()));
        SavePoint savePoint(transaction, "name");
        session.Add(entity2);
        ASSERT_NO_THROW(session.Get(entity2->GetId()));
        savePoint.Release();
    }
    ASSERT_THROW(session.Get(entity1->GetId()), cpporm::EntryNonExistentError);
    ASSERT_THROW(session.Get(entity2->GetId()), cpporm::EntryNonExistentError);
    ASSERT_TRUE(MyIudContext::insertions.empty());
}

TEST_F(CppOrm_Unit_Db_SavePoint, TestSet4)
{
    MySession session;
    MyIudContext::insertions.clear();
    {
        Transaction transaction(session);
        session.Add(entity1);
        ASSERT_NO_THROW(session.Get(entity1->GetId()));
        SavePoint savePoint(transaction, "name");
        session.Add(entity2);
        ASSERT_NO_THROW(session.Get(entity2->GetId()));
        savePoint.Release();
        transaction.Commit();
    }
    ASSERT_NO_THROW(session.Get(entity1->GetId()));
    ASSERT_NO_THROW(session.Get(entity2->GetId()));
    ASSERT_EQ(MyIudContext::insertions, cache2);
}

TEST_F(CppOrm_Unit_Db_SavePoint, TestSet5)
{
    MySession session;
    MyIudContext::insertions.clear();
    {
        Transaction transaction(session);
        session.Add(entity1);
        ASSERT_NO_THROW(session.Get(entity1->GetId()));
        {
            SavePoint savePoint(transaction, "name");
            session.Add(entity2);
            ASSERT_NO_THROW(session.Get(entity2->GetId()));
        }
        ASSERT_THROW(session.Get(entity2->GetId()), cpporm::EntryNonExistentError);
        transaction.Commit();
    }
    ASSERT_NO_THROW(session.Get(entity1->GetId()));
    ASSERT_THROW(session.Get(entity2->GetId()), cpporm::EntryNonExistentError);
    ASSERT_EQ(MyIudContext::insertions, cache3);
}
