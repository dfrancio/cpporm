#include <cpporm/db/context.h>

// C++ library includes
#include <string>

// External library includes
#include <gtest/gtest.h>

// Internal program includes
#include "helpers.h"

// Test fixture
class CppOrm_Unit_Db_Context : public testing::Test
{
protected:
    CppOrm_Unit_Db_Context()
    {
        words1 = {"abc", "def", "123", "456"};
        words2 = {"abc"};
        words3 = {"abc", "def", "123"};
        words4 = {"abc"};
        words5 = {"abc"};
        words6 = {"abc"};
    }
    std::set<std::string> words1;
    std::set<std::string> words2;
    std::set<std::string> words3;
    std::set<std::string> words4;
    std::set<std::string> words5;
    std::set<std::string> words6;
};

TEST_F(CppOrm_Unit_Db_Context, TestSet1)
{
    MyContext::committedWords.clear();
    {
        MyContext context1;
        context1.AddInsertion("abc");
        ASSERT_TRUE(dynamic_cast<MyContext *>(context1.CreateSubcontext()));
        context1.AddInsertion("def");
        context1.AddInsertion("123");
        context1.CreateSubcontext();
        context1.AddInsertion("456");
        context1.Commit();
    }
    ASSERT_EQ(MyContext::committedWords, words1);
}

TEST_F(CppOrm_Unit_Db_Context, TestSet2)
{
    MyContext::committedWords.clear();
    {
        MyContext context1;
        context1.AddInsertion("abc");
        context1.CreateSubcontext();
        context1.AddInsertion("def");
        context1.AddInsertion("123");
        context1.CreateSubcontext();
        context1.AddInsertion("456");
    }
    ASSERT_TRUE(MyContext::committedWords.empty());
}

TEST_F(CppOrm_Unit_Db_Context, TestSet3)
{
    MyContext::committedWords.clear();
    {
        MyContext context1;
        context1.AddInsertion("abc");
        auto context2 = context1.CreateSubcontext();
        context1.AddInsertion("def");
        context1.AddInsertion("123");
        context1.CreateSubcontext();
        context1.AddInsertion("456");
        context2->Commit();
    }
    ASSERT_TRUE(MyContext::committedWords.empty());
}

TEST_F(CppOrm_Unit_Db_Context, TestSet4)
{
    MyContext::committedWords.clear();
    {
        MyContext context1;
        context1.AddInsertion("abc");
        context1.CreateSubcontext();
        context1.AddInsertion("def");
        context1.AddInsertion("123");
        auto context3 = context1.CreateSubcontext();
        context1.AddInsertion("456");
        context3->Commit();
    }
    ASSERT_TRUE(MyContext::committedWords.empty());
}

TEST_F(CppOrm_Unit_Db_Context, TestSet5)
{
    MyContext::committedWords.clear();
    {
        MyContext context1;
        context1.AddInsertion("abc");
        auto context2 = context1.CreateSubcontext();
        context1.AddInsertion("def");
        context1.AddInsertion("123");
        context1.CreateSubcontext();
        context1.AddInsertion("456");
        context2->Rollback();
        context1.Commit();
    }
    ASSERT_EQ(MyContext::committedWords, words2);
}

TEST_F(CppOrm_Unit_Db_Context, TestSet6)
{
    MyContext::committedWords.clear();
    {
        MyContext context1;
        context1.AddInsertion("abc");
        context1.CreateSubcontext();
        context1.AddInsertion("def");
        context1.AddInsertion("123");
        auto context3 = context1.CreateSubcontext();
        context1.AddInsertion("456");
        context3->Rollback();
        context1.Commit();
    }
    ASSERT_EQ(MyContext::committedWords, words3);
}

TEST_F(CppOrm_Unit_Db_Context, TestSet7)
{
    MyContext::committedWords.clear();
    {
        MyContext context1;
        context1.AddInsertion("abc");
        auto context2 = context1.CreateSubcontext();
        context1.AddInsertion("def");
        context1.AddInsertion("123");
        auto context3 = context1.CreateSubcontext();
        context1.AddInsertion("456");
        context3->Rollback();
        context1.AddInsertion("789");
        context2->Rollback();
        context1.Commit();
    }
    ASSERT_EQ(MyContext::committedWords, words4);
}

TEST_F(CppOrm_Unit_Db_Context, TestSet8)
{
    MyContext::committedWords.clear();
    {
        MyContext context1;
        context1.AddInsertion("abc");
        auto context2 = context1.CreateSubcontext();
        context1.AddInsertion("def");
        context1.AddInsertion("123");
        auto context3 = context1.CreateSubcontext();
        context1.AddInsertion("456");
        context3->Commit();
        context2->Rollback();
        context1.Commit();
    }
    ASSERT_EQ(MyContext::committedWords, words5);
}

TEST_F(CppOrm_Unit_Db_Context, TestSet9)
{
    MyContext::committedWords.clear();
    {
        MyContext context1;
        context1.AddInsertion("abc");
        auto context2 = context1.CreateSubcontext();
        context1.AddInsertion("def");
        context1.AddInsertion("123");
        context1.CreateSubcontext();
        context1.AddInsertion("456");
        context2->Rollback();
        context1.Commit();
    }
    ASSERT_EQ(MyContext::committedWords, words6);
}
