#include <cpporm/db/criteria.h>

// C++ library includes
#include <string>

// External library includes
#include <gtest/gtest.h>

// Using namespace
using namespace cpporm::db;

TEST(CppOrm_Unit_Db_Criteria, TestSet1)
{
    Criteria criteria;
    ASSERT_EQ(criteria.GetLimitCount(), 0);
    ASSERT_EQ(criteria.GetLimitOffset(), 0);
    criteria.SetLimitCount(1);
    criteria.SetLimitOffset(2);
    ASSERT_EQ(criteria.GetLimitCount(), 1);
    ASSERT_EQ(criteria.GetLimitOffset(), 2);
}

TEST(CppOrm_Unit_Db_Criteria, TestSet2)
{
    Criteria criteria;
    ASSERT_TRUE(criteria.empty());
    criteria.AddCriterion("abc", Condition::equal, "1");
    ASSERT_EQ(criteria.size(), 1);
    criteria.AddCriterion("abc", Condition::equal, "1");
    ASSERT_EQ(criteria.size(), 1);
    criteria.AddCriterion("def", Condition::isNull, "2");
    ASSERT_EQ(criteria.size(), 2);
    ASSERT_EQ(
        criteria,
        CriteriaBase({{"abc", {Condition::equal, "1"}}, {"def", {Condition::isNull, "2"}}}));
}

TEST(CppOrm_Unit_Db_Criteria, TestSet3)
{
    Criteria criteria;
    ASSERT_TRUE(criteria.GetOrderBy().empty());
    criteria.AddOrderBy("abc", SortOrder::ascending);
    ASSERT_EQ(criteria.GetOrderBy().size(), 1);
    criteria.AddOrderBy("def", SortOrder::descending);
    ASSERT_EQ(
        criteria.GetOrderBy(),
        OrderBySpec({{"abc", SortOrder::ascending}, {"def", SortOrder::descending}}));
}
