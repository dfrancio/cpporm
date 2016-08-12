#include <cpporm/attribute.h>

// C++ library includes
#include <string>

// External library includes
#include <gtest/gtest.h>

// Internal program includes
#include "helpers.h"

TEST(CppOrm_Unit_Attribute, TestSet1)
{
    MyAttribute attribute;
    ASSERT_EQ(attribute.Get(), "");
    ASSERT_TRUE(attribute->empty());
    ASSERT_TRUE(attribute.IsNull());
    ASSERT_FALSE(attribute.WasModified());

    attribute.Set("abc");
    ASSERT_EQ(attribute.Get(), "abc");
    ASSERT_FALSE(attribute->empty());
    ASSERT_FALSE(attribute.IsNull());
    ASSERT_TRUE(attribute.WasModified());

    attribute.Commit();
    ASSERT_EQ(attribute.Get(), "abc");
    ASSERT_FALSE(attribute.WasModified());

    attribute.SetNull();
    ASSERT_EQ(attribute.Get(), "");
    ASSERT_TRUE(attribute.IsNull());
    ASSERT_TRUE(attribute.WasModified());

    static_cast<Attribute &>(attribute) = "def";
    ASSERT_EQ(attribute.Get(), "def");
    ASSERT_FALSE(attribute.IsNull());
    ASSERT_TRUE(attribute.WasModified());

    attribute.Rollback();
    ASSERT_EQ(attribute.Get(), "abc");
    ASSERT_FALSE(attribute.IsNull());
    ASSERT_FALSE(attribute.WasModified());
}

TEST(CppOrm_Unit_Attribute, TestSet2)
{
    MyAttribute attribute;
    ASSERT_FALSE(attribute.WasModified());
    attribute.Set("abc");
    attribute.SetNull();
    ASSERT_FALSE(attribute.WasModified());

    attribute.Set("abc");
    attribute.Commit();
    attribute.Set("def");
    attribute.Set("abc");
    ASSERT_FALSE(attribute.WasModified());
}

TEST(CppOrm_Unit_Attribute, TestSet3)
{
    MyAttribute attribute;
    ASSERT_EQ(attribute.Get(), "");
    attribute.Set("abc");
    ASSERT_EQ(attribute.Get(), "abc");
    attribute.PushState();
    attribute.Set("def");
    ASSERT_EQ(attribute.Get(), "def");
    attribute.Rollback();
    ASSERT_EQ(attribute.Get(), "abc");
    attribute.Rollback();
    ASSERT_EQ(attribute.Get(), "");
    ASSERT_NO_THROW(attribute.Rollback());

    attribute.Set("abc");
    attribute.PushState();
    attribute.Set("def");
    attribute.Commit();
    ASSERT_EQ(attribute.Get(), "def");
    attribute.Rollback();
    ASSERT_EQ(attribute.Get(), "def");
}

TEST(CppOrm_Unit_Attribute, TestSet4)
{
    MyAttribute attribute;
    ASSERT_EQ(attribute.Get(), "");
    ASSERT_TRUE(attribute.IsNull());

    MyCursor2 cursor;
    attribute.Extract(cursor);
    ASSERT_EQ(attribute.Get(), "abc");
    ASSERT_FALSE(attribute.IsNull());

    MyCursor3 cursor2;
    attribute.Extract(cursor2);
    ASSERT_EQ(attribute.Get(), "");
    ASSERT_TRUE(attribute.IsNull());
}

TEST(CppOrm_Unit_Attribute, TestSet5)
{
    MyAttribute attribute("abc");

    Query query;
    attribute.Insert(query);
    ASSERT_EQ(query.GetBindingIndex(), 0);
    query.EndIncrementalInsert();
    ASSERT_EQ(query.Get(), " (name) VALUES (?);");

    attribute.Update(query);
    ASSERT_EQ(query.GetBindingIndex(), 0);
    ASSERT_EQ(query.Get(), " (name) VALUES (?);");

    attribute.SetNull();
    attribute.Update(query);
    ASSERT_EQ(query.GetBindingIndex(), 1);
    query.EndIncrementalUpdate();
    ASSERT_EQ(query.Get(), " (name) VALUES (?) SET name=?;");

    MyStatement statement;
    attribute.Bind(statement);
    ASSERT_EQ(statement.boundParams, std::vector<int>{1});
    ASSERT_EQ(statement.boundValues, std::vector<std::string>{});
    ASSERT_EQ(statement.nullCount, 1);

    attribute.Where(query);
    ASSERT_EQ(query.GetBindingIndex(), 1);
    query.EndIncrementalWhere();
    ASSERT_EQ(query.Get(), " (name) VALUES (?) SET name=? WHERE name IS NULL;");

    attribute.Set("def");
    attribute.Where(query);
    ASSERT_EQ(query.GetBindingIndex(), 2);
    query.EndIncrementalWhere();
    ASSERT_EQ(query.Get(), " (name) VALUES (?) SET name=? WHERE name IS NULL WHERE name=?;");

    attribute.Bind(statement);
    ASSERT_EQ(statement.boundParams, std::vector<int>({1, 2}));
    ASSERT_EQ(statement.boundValues, std::vector<std::string>{"def"});
    ASSERT_EQ(statement.nullCount, 1);

    attribute.Bind(statement, true);
    ASSERT_EQ(statement.boundParams, std::vector<int>({1, 2, 0}));
    ASSERT_EQ(statement.boundValues, std::vector<std::string>({"def", "abc"}));
    ASSERT_EQ(statement.nullCount, 1);

    attribute.SaveState();
    attribute.Set("ghi");
    attribute.Where(query);
    attribute.Bind(statement, true);
    ASSERT_EQ(statement.boundParams, std::vector<int>({1, 2, 0, 3}));
    ASSERT_EQ(statement.boundValues, std::vector<std::string>({"def", "abc", "def"}));
    ASSERT_EQ(statement.nullCount, 1);
}
