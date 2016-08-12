#include <cpporm/db/transaction.h>

// C++ library includes
#include <string>

// External library includes
#include <gtest/gtest.h>

// Internal program includes
#include "helpers.h"

// Test fixture
class CppOrm_Unit_Db_Transaction : public testing::Test
{
protected:
    CppOrm_Unit_Db_Transaction()
        : entity1(new MyEntity("a", "1")),
          entity2(new MyEntity("b", "2")),
          entity3(new MyEntity("c", "3")),
          entity4(new MyEntity("d", "4"))
    {
        cache1.Add(entity1->GetId(), entity1);
        cache1.Add(entity2->GetId(), entity2);
        cache2.Add(entity1->GetId(), entity1);
        cache2.Add(entity2->GetId(), entity2);
        cache3.Add(entity1->GetId(), entity1);
        cache3.Add(entity2->GetId(), entity2);
        cache3.Add(entity4->GetId(), entity4);
        cache4.Add(entity1->GetId(), entity1);
        cache4.Add(entity2->GetId(), entity2);
        cache5.Add(entity1->GetId(), entity1);
        cache6.Add(entity1->GetId(), entity1);
        cache7.Add(entity1->GetId(), entity1);
        cache7.Add(entity2->GetId(), entity2);
        cache8.Add(entity1->GetId(), entity1);
        cache8.Add(entity2->GetId(), entity2);
    }
    std::shared_ptr<MyEntity> entity1;
    std::shared_ptr<MyEntity> entity2;
    std::shared_ptr<MyEntity> entity3;
    std::shared_ptr<MyEntity> entity4;
    Cache cache1;
    Cache cache2;
    Cache cache3;
    Cache cache4;
    Cache cache5;
    Cache cache6;
    Cache cache7;
    Cache cache8;
};

TEST_F(CppOrm_Unit_Db_Transaction, TestSet1)
{
    MySession session;
    MyIudContext::insertions.clear();
    {
        Transaction transaction(session);
        session.Add(entity1);
        ASSERT_NO_THROW(session.Get(entity1->GetId()));
        transaction.AddSavePoint("name");
        session.Add(entity2);
        ASSERT_NO_THROW(session.Get(entity2->GetId()));
        transaction.Commit();
    }
    ASSERT_NO_THROW(session.Get(entity1->GetId()));
    ASSERT_NO_THROW(session.Get(entity2->GetId()));
    ASSERT_EQ(MyIudContext::insertions, cache1);
}

TEST_F(CppOrm_Unit_Db_Transaction, TestSet2)
{
    MySession session;
    MyIudContext::insertions.clear();
    {
        Transaction transaction(session);
        session.Add(entity1);
        ASSERT_NO_THROW(session.Get(entity1->GetId()));
        {
            transaction.AddSavePoint("name");
            session.Add(entity2);
            ASSERT_NO_THROW(session.Get(entity2->GetId()));
        }
    }
    ASSERT_THROW(session.Get(entity1->GetId()), cpporm::EntryNonExistentError);
    ASSERT_THROW(session.Get(entity2->GetId()), cpporm::EntryNonExistentError);
    ASSERT_TRUE(MyIudContext::insertions.empty());
}

TEST_F(CppOrm_Unit_Db_Transaction, TestSet3)
{
    MySession session;
    MyIudContext::insertions.clear();
    {
        Transaction transaction(session);
        session.Add(entity1);
        ASSERT_NO_THROW(session.Get(entity1->GetId()));
        {
            transaction.AddSavePoint("name");
            session.Add(entity2);
            ASSERT_NO_THROW(session.Get(entity2->GetId()));
            transaction.RollbackTo("name");
        }
        ASSERT_THROW(session.Get(entity2->GetId()), cpporm::EntryNonExistentError);
        {
            transaction.AddSavePoint("name");
            session.Add(entity2);
            ASSERT_NO_THROW(session.Get(entity2->GetId()));
            transaction.Release("name");
        }
        ASSERT_NO_THROW(session.Get(entity2->GetId()));
        transaction.Commit();
    }
    ASSERT_NO_THROW(session.Get(entity1->GetId()));
    ASSERT_NO_THROW(session.Get(entity2->GetId()));
    ASSERT_EQ(MyIudContext::insertions, cache2);
}

TEST_F(CppOrm_Unit_Db_Transaction, TestSet4)
{
    MySession session;
    MyIudContext::insertions.clear();
    {
        Transaction transaction(session);
        session.Add(entity1);
        ASSERT_NO_THROW(session.Get(entity1->GetId()));
        transaction.AddSavePoint("name1");
        session.Add(entity2);
        ASSERT_NO_THROW(session.Get(entity2->GetId()));
        transaction.AddSavePoint("name");
        session.Add(entity3);
        ASSERT_NO_THROW(session.Get(entity3->GetId()));
        transaction.RollbackTo("name");
        transaction.AddSavePoint("name");
        session.Add(entity4);
        ASSERT_NO_THROW(session.Get(entity4->GetId()));
        ASSERT_THROW(session.Get(entity3->GetId()), cpporm::EntryNonExistentError);
        ASSERT_NO_THROW(session.Get(entity4->GetId()));
        transaction.Release("name1");
        transaction.Commit();
    }
    ASSERT_NO_THROW(session.Get(entity1->GetId()));
    ASSERT_NO_THROW(session.Get(entity2->GetId()));
    ASSERT_THROW(session.Get(entity3->GetId()), cpporm::EntryNonExistentError);
    ASSERT_NO_THROW(session.Get(entity4->GetId()));
    ASSERT_EQ(MyIudContext::insertions, cache3);
}

TEST_F(CppOrm_Unit_Db_Transaction, TestSet5)
{
    MySession session;
    MyIudContext::insertions.clear();
    {
        Transaction transaction(session);
        session.Add(entity1);
        ASSERT_NO_THROW(session.Get(entity1->GetId()));
        transaction.AddSavePoint("name1");
        session.Add(entity2);
        ASSERT_NO_THROW(session.Get(entity2->GetId()));
        transaction.AddSavePoint("name2");
        session.Add(entity3);
        ASSERT_NO_THROW(session.Get(entity3->GetId()));
        transaction.AddSavePoint("name3");
        session.Add(entity4);
        ASSERT_NO_THROW(session.Get(entity4->GetId()));
        transaction.RollbackTo("name2");
        ASSERT_THROW(session.Get(entity3->GetId()), cpporm::EntryNonExistentError);
        ASSERT_THROW(session.Get(entity4->GetId()), cpporm::EntryNonExistentError);
        transaction.Commit();
    }
    ASSERT_NO_THROW(session.Get(entity1->GetId()));
    ASSERT_NO_THROW(session.Get(entity2->GetId()));
    ASSERT_THROW(session.Get(entity3->GetId()), cpporm::EntryNonExistentError);
    ASSERT_THROW(session.Get(entity4->GetId()), cpporm::EntryNonExistentError);
    ASSERT_EQ(MyIudContext::insertions, cache4);
}

TEST_F(CppOrm_Unit_Db_Transaction, TestSet6)
{
    MySession session;
    MyIudContext::insertions.clear();
    {
        Transaction transaction(session);
        session.Add(entity1);
        ASSERT_NO_THROW(session.Get(entity1->GetId()));
        transaction.AddSavePoint("name1");
        session.Add(entity2);
        ASSERT_NO_THROW(session.Get(entity2->GetId()));
        transaction.AddSavePoint("name2");
        session.Add(entity3);
        ASSERT_NO_THROW(session.Get(entity3->GetId()));
        transaction.AddSavePoint("name3");
        session.Add(entity4);
        ASSERT_NO_THROW(session.Get(entity4->GetId()));
        transaction.Release("name3");
        transaction.Release("name2");
        transaction.Release("name1");
    }
    ASSERT_THROW(session.Get(entity1->GetId()), cpporm::EntryNonExistentError);
    ASSERT_THROW(session.Get(entity2->GetId()), cpporm::EntryNonExistentError);
    ASSERT_TRUE(MyIudContext::insertions.empty());
}

TEST_F(CppOrm_Unit_Db_Transaction, TestSet7)
{
    MySession session;
    MyIudContext::insertions.clear();
    {
        Transaction transaction(session);
        session.Add(entity1);
        ASSERT_NO_THROW(session.Get(entity1->GetId()));
    }
    ASSERT_THROW(session.Get(entity1->GetId()), cpporm::EntryNonExistentError);
    ASSERT_TRUE(MyIudContext::insertions.empty());
    {
        Transaction transaction(session);
        session.Add(entity1);
        ASSERT_NO_THROW(session.Get(entity1->GetId()));
        transaction.Commit();
    }
    ASSERT_NO_THROW(session.Get(entity1->GetId()));
    ASSERT_EQ(MyIudContext::insertions, cache5);
}

TEST_F(CppOrm_Unit_Db_Transaction, TestSet8)
{
    MySession session;
    MyIudContext::insertions.clear();
    {
        Transaction transaction(session);
        session.Add(entity1);
        ASSERT_NO_THROW(session.Get(entity1->GetId()));
        transaction.AddSavePoint("name1");
        session.Add(entity2);
        ASSERT_NO_THROW(session.Get(entity2->GetId()));
        transaction.AddSavePoint("name2");
        session.Add(entity3);
        ASSERT_NO_THROW(session.Get(entity3->GetId()));
        transaction.RollbackTo("name2");
        ASSERT_NO_THROW(session.Get(entity2->GetId()));
        ASSERT_THROW(session.Get(entity3->GetId()), cpporm::EntryNonExistentError);
        transaction.RollbackTo("name1");
        ASSERT_THROW(session.Get(entity2->GetId()), cpporm::EntryNonExistentError);
        transaction.Commit();
    }
    ASSERT_NO_THROW(session.Get(entity1->GetId()));
    ASSERT_EQ(MyIudContext::insertions, cache6);
}

TEST_F(CppOrm_Unit_Db_Transaction, TestSet9)
{
    MySession session;
    MyIudContext::insertions.clear();
    {
        Transaction transaction(session);
        session.Add(entity1);
        ASSERT_NO_THROW(session.Get(entity1->GetId()));
        transaction.AddSavePoint("name1");
        session.Add(entity2);
        ASSERT_NO_THROW(session.Get(entity2->GetId()));
        transaction.AddSavePoint("name2");
        session.Add(entity3);
        ASSERT_NO_THROW(session.Get(entity3->GetId()));
        transaction.AddSavePoint("name3");
        session.Add(entity4);
        ASSERT_NO_THROW(session.Get(entity4->GetId()));
        transaction.Release("name2");
        ASSERT_NO_THROW(session.Get(entity2->GetId()));
        ASSERT_NO_THROW(session.Get(entity3->GetId()));
        ASSERT_NO_THROW(session.Get(entity4->GetId()));
        transaction.RollbackTo("name1");
        ASSERT_THROW(session.Get(entity2->GetId()), cpporm::EntryNonExistentError);
        ASSERT_THROW(session.Get(entity3->GetId()), cpporm::EntryNonExistentError);
        ASSERT_THROW(session.Get(entity4->GetId()), cpporm::EntryNonExistentError);
        session.Add(entity2);
        ASSERT_NO_THROW(session.Get(entity2->GetId()));
        transaction.Commit();
    }
    ASSERT_NO_THROW(session.Get(entity1->GetId()));
    ASSERT_NO_THROW(session.Get(entity2->GetId()));
    ASSERT_EQ(MyIudContext::insertions, cache7);
}

TEST_F(CppOrm_Unit_Db_Transaction, TestSet10)
{
    MySession session;
    MyIudContext::insertions.clear();
    {
        Transaction transaction(session);
        session.Add(entity1);
        ASSERT_NO_THROW(session.Get(entity1->GetId()));
        transaction.AddSavePoint("name");
        session.Add(entity2);
        ASSERT_NO_THROW(session.Get(entity2->GetId()));
        transaction.AddSavePoint("name");
        session.Add(entity3);
        ASSERT_NO_THROW(session.Get(entity3->GetId()));
        transaction.RollbackTo("name");
        ASSERT_NO_THROW(session.Get(entity2->GetId()));
        ASSERT_THROW(session.Get(entity3->GetId()), cpporm::EntryNonExistentError);
        transaction.Commit();
    }
    ASSERT_NO_THROW(session.Get(entity1->GetId()));
    ASSERT_NO_THROW(session.Get(entity2->GetId()));
    ASSERT_EQ(MyIudContext::insertions, cache8);
}
