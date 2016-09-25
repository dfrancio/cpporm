#include <cpporm/db/iudcontext.h>

// C++ library includes
#include <string>

// External library includes
#include <gtest/gtest.h>

// Internal program includes
#include "helpers.h"

// Using namespace
using namespace cpporm::util;

// Test fixture
class CppOrm_Unit_Db_IudContext : public testing::Test
{
protected:
    CppOrm_Unit_Db_IudContext()
    {
        cache.Add("a", std::make_shared<MyEntity>("a", "1"));
        cache.Add("b", std::make_shared<MyEntity>("b", "1"));
        cache.Add("c", std::make_shared<MyEntity>("c", "1"));
        cache.Add("d", std::make_shared<MyEntity>("d", "2"));
        cache.Add("e", std::make_shared<MyEntity>("e", "2"));
        cache.Add("f", std::make_shared<MyEntity>("f", "2"));
        cache.Add("g", std::make_shared<MyEntity>("g", "3"));
        cache.Add("h", std::make_shared<MyEntity>("h", "3"));
        cache.Add("i", std::make_shared<MyEntity>("i", "3"));
        cache.Add("j", std::make_shared<MyEntity>("j", "4"));
        cache.Add("k", std::make_shared<MyEntity>("k", "4"));
        cache.Add("l", std::make_shared<MyEntity>("l", "4"));
        cache1.Add("a", cache.Get("a"));
        cache1.Add("d", cache.Get("d"));
        cache1.Add("g", cache.Get("g"));
        cache1.Add("j", cache.Get("j"));
        cache2.Add("b", cache.Get("b"));
        cache2.Add("e", cache.Get("e"));
        cache2.Add("h", cache.Get("h"));
        cache2.Add("k", cache.Get("k"));
        cache3.Add("c", cache.Get("c"));
        cache3.Add("f", cache.Get("f"));
        cache3.Add("i", cache.Get("i"));
        cache3.Add("l", cache.Get("l"));
        cache4.Add("a", cache.Get("a"));
        cache5.Add("b", cache.Get("b"));
        cache6.Add("c", cache.Get("c"));
        cache7.Add("a", cache.Get("a"));
        cache7.Add("d", cache.Get("d"));
        cache7.Add("g", cache.Get("g"));
        cache8.Add("b", cache.Get("b"));
        cache8.Add("e", cache.Get("e"));
        cache8.Add("h", cache.Get("h"));
        cache9.Add("c", cache.Get("c"));
        cache9.Add("f", cache.Get("f"));
        cache9.Add("i", cache.Get("i"));
        cache10.Add("b", cache.Get("b"));
        cache11.Add("c", cache.Get("c"));
        cache12.Add("a", cache.Get("a"));
        cache13.Add("b", cache.Get("b"));
        cache14.Add("a", cache.Get("a"));
        cache15.Add("b", cache.Get("b"));
    }
    Cache cache;
    Cache cache1;
    Cache cache2;
    Cache cache3;
    Cache cache4;
    Cache cache5;
    Cache cache6;
    Cache cache7;
    Cache cache8;
    Cache cache9;
    Cache cache10;
    Cache cache11;
    Cache cache12;
    Cache cache13;
    Cache cache14;
    Cache cache15;
};

TEST_F(CppOrm_Unit_Db_IudContext, TestSet1)
{
    MyIudContext::insertions.clear();
    MyIudContext::deletions.clear();
    MyIudContext::updates.clear();
    {
        MyIudContext context1(cache);
        context1.Activate();
        context1.AddInsertion("a");
        context1.AddDeletion("b");
        context1.AddUpdate("c", "c");
        ASSERT_TRUE(dynamic_cast<MyIudContext *>(context1.CreateSubcontext()));
        context1.AddInsertion("d");
        context1.AddDeletion("e");
        context1.AddUpdate("f", "f");
        context1.AddInsertion("g");
        context1.AddDeletion("h");
        context1.AddUpdate("i", "i");
        context1.CreateSubcontext();
        context1.AddInsertion("j");
        context1.AddDeletion("k");
        context1.AddUpdate("l", "l");
        context1.Commit();
    }
    ASSERT_EQ(MyIudContext::insertions, cache1);
    ASSERT_EQ(MyIudContext::deletions, cache2);
    ASSERT_EQ(MyIudContext::updates, cache3);
}

TEST_F(CppOrm_Unit_Db_IudContext, TestSet2)
{
    MyIudContext::insertions.clear();
    MyIudContext::deletions.clear();
    MyIudContext::updates.clear();
    {
        MyIudContext context1(cache);
        context1.Activate();
        context1.AddInsertion("a");
        context1.AddDeletion("b");
        context1.AddUpdate("c", "c");
        context1.CreateSubcontext();
        context1.AddInsertion("d");
        context1.AddDeletion("e");
        context1.AddUpdate("f", "f");
        context1.AddInsertion("g");
        context1.AddDeletion("h");
        context1.AddUpdate("i", "i");
        context1.CreateSubcontext();
        context1.AddInsertion("j");
        context1.AddDeletion("k");
        context1.AddUpdate("l", "l");
    }
    ASSERT_TRUE(MyIudContext::insertions.empty());
    ASSERT_TRUE(MyIudContext::deletions.empty());
    ASSERT_TRUE(MyIudContext::updates.empty());
}

TEST_F(CppOrm_Unit_Db_IudContext, TestSet3)
{
    MyIudContext::insertions.clear();
    MyIudContext::deletions.clear();
    MyIudContext::updates.clear();
    {
        MyIudContext context1(cache);
        context1.Activate();
        context1.AddInsertion("a");
        context1.AddDeletion("b");
        context1.AddUpdate("c", "c");
        auto context2 = context1.CreateSubcontext();
        context1.AddInsertion("d");
        context1.AddDeletion("e");
        context1.AddUpdate("f", "f");
        context1.AddInsertion("g");
        context1.AddDeletion("h");
        context1.AddUpdate("i", "i");
        context1.CreateSubcontext();
        context1.AddInsertion("j");
        context1.AddDeletion("k");
        context1.AddUpdate("l", "l");
        context2->Commit();
    }
    ASSERT_TRUE(MyIudContext::insertions.empty());
    ASSERT_TRUE(MyIudContext::deletions.empty());
    ASSERT_TRUE(MyIudContext::updates.empty());
}

TEST_F(CppOrm_Unit_Db_IudContext, TestSet4)
{
    MyIudContext::insertions.clear();
    MyIudContext::deletions.clear();
    MyIudContext::updates.clear();
    {
        MyIudContext context1(cache);
        context1.Activate();
        context1.AddInsertion("a");
        context1.AddDeletion("b");
        context1.AddUpdate("c", "c");
        context1.CreateSubcontext();
        context1.AddInsertion("d");
        context1.AddDeletion("e");
        context1.AddUpdate("f", "f");
        context1.AddInsertion("g");
        context1.AddDeletion("h");
        context1.AddUpdate("i", "i");
        auto context3 = context1.CreateSubcontext();
        context1.AddInsertion("j");
        context1.AddDeletion("k");
        context1.AddUpdate("l", "l");
        context3->Commit();
    }
    ASSERT_TRUE(MyIudContext::insertions.empty());
    ASSERT_TRUE(MyIudContext::deletions.empty());
    ASSERT_TRUE(MyIudContext::updates.empty());
}

TEST_F(CppOrm_Unit_Db_IudContext, TestSet5)
{
    MyIudContext::insertions.clear();
    MyIudContext::deletions.clear();
    MyIudContext::updates.clear();
    {
        MyIudContext context1(cache);
        context1.Activate();
        context1.AddInsertion("a");
        context1.AddDeletion("b");
        context1.AddUpdate("c", "c");
        auto context2 = context1.CreateSubcontext();
        context1.AddInsertion("d");
        context1.AddDeletion("e");
        context1.AddUpdate("f", "f");
        context1.AddInsertion("g");
        context1.AddDeletion("h");
        context1.AddUpdate("i", "i");
        context1.CreateSubcontext();
        context1.AddInsertion("j");
        context1.AddDeletion("k");
        context1.AddUpdate("l", "l");
        context2->Rollback();
        context1.Commit();
    }
    ASSERT_EQ(MyIudContext::insertions, cache4);
    ASSERT_EQ(MyIudContext::deletions, cache5);
    ASSERT_EQ(MyIudContext::updates, cache6);
}

TEST_F(CppOrm_Unit_Db_IudContext, TestSet6)
{
    MyIudContext::insertions.clear();
    MyIudContext::deletions.clear();
    MyIudContext::updates.clear();
    {
        MyIudContext context1(cache);
        context1.Activate();
        context1.AddInsertion("a");
        context1.AddDeletion("b");
        context1.AddUpdate("c", "c");
        context1.CreateSubcontext();
        context1.AddInsertion("d");
        context1.AddDeletion("e");
        context1.AddUpdate("f", "f");
        context1.AddInsertion("g");
        context1.AddDeletion("h");
        context1.AddUpdate("i", "i");
        auto context3 = context1.CreateSubcontext();
        context1.AddInsertion("j");
        context1.AddDeletion("k");
        context1.AddUpdate("l", "l");
        context3->Rollback();
        context1.Commit();
    }
    ASSERT_EQ(MyIudContext::insertions, cache7);
    ASSERT_EQ(MyIudContext::deletions, cache8);
    ASSERT_EQ(MyIudContext::updates, cache9);
}

TEST_F(CppOrm_Unit_Db_IudContext, TestSet7)
{
    MyIudContext::insertions.clear();
    MyIudContext::deletions.clear();
    MyIudContext::updates.clear();
    {
        MyIudContext context1(cache);
        context1.Activate();
        context1.AddInsertion("a");
        context1.AddUpdate("b", "b");
        context1.AddDeletion("a");
        context1.AddDeletion("b");
        context1.Commit();
    }
    ASSERT_TRUE(MyIudContext::insertions.empty());
    ASSERT_EQ(MyIudContext::deletions, cache10);
    ASSERT_TRUE(MyIudContext::updates.empty());
}

TEST_F(CppOrm_Unit_Db_IudContext, TestSet8)
{
    MyIudContext::insertions.clear();
    MyIudContext::deletions.clear();
    MyIudContext::updates.clear();
    {
        MyIudContext context1(cache);
        context1.Activate();
        context1.AddUpdate("b", "b");
        context1.AddDeletion("a");
        context1.AddInsertion("c");
        context1.AddInsertion("a");
        context1.AddInsertion("b");
        context1.AddInsertion("c");
        context1.Commit();
    }
    ASSERT_EQ(MyIudContext::insertions, cache11);
    ASSERT_EQ(MyIudContext::deletions, cache12);
    ASSERT_EQ(MyIudContext::updates, cache13);
}

TEST_F(CppOrm_Unit_Db_IudContext, TestSet9)
{
    MyIudContext::insertions.clear();
    MyIudContext::deletions.clear();
    MyIudContext::updates.clear();
    {
        MyIudContext context1(cache);
        context1.Activate();
        context1.AddInsertion("a");
        context1.AddDeletion("b");
        context1.AddUpdate("a", "a");
        context1.AddUpdate("b", "b");
        context1.Commit();
    }
    ASSERT_EQ(MyIudContext::insertions, cache14);
    ASSERT_EQ(MyIudContext::deletions, cache15);
    ASSERT_TRUE(MyIudContext::updates.empty());
}
