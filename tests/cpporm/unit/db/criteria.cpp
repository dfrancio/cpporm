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
    SqliteQuery query;
    criteria.Compose(query);
    ASSERT_EQ(query.GetAndReset(), ";");
    criteria.SetLimitCount(1);
    criteria.SetLimitOffset(2);
    criteria.Compose(query);
    ASSERT_EQ(query.GetAndReset(), " LIMIT 1 OFFSET 2;");
}

TEST(CppOrm_Unit_Db_Criteria, TestSet2)
{
    Criteria criteria;
    SqliteQuery query;
    criteria.AddCondition("abc", Condition::equal, "1");
    criteria.AddCondition("def", Condition::equal, "2");
    criteria.AddCondition("ghi", Condition::isNull);
    criteria.Compose(query);
    ASSERT_EQ(query.GetAndReset(), " WHERE abc=? AND def=? AND ghi IS NULL;");
}

TEST(CppOrm_Unit_Db_Criteria, TestSet3)
{
    Criteria criteria;
    SqliteQuery query;
    criteria.AddOrderBy("table1", "abc", SortOrder::ascending);
    criteria.AddOrderBy("table2", "def", SortOrder::descending);
    criteria.Compose(query);
    ASSERT_EQ(query.GetAndReset(), " ORDER BY table1.abc ASC, table2.def DESC;");
}

TEST(CppOrm_Unit_Db_Criteria, TestSet4)
{
    Criteria criteria;
    SqliteQuery query;
    criteria.AddJoin("table1", JoinType::cross, "id", "tbl_id");
    criteria.AddJoin("table2", JoinType::inner, "abc", "tbl_abc");
    criteria.Compose(query);
    ASSERT_EQ(query.GetAndReset(), ", table1 ON id=tbl_id INNER JOIN table2 ON abc=tbl_abc;");
}

TEST(CppOrm_Unit_Db_Criteria, TestSet5)
{
    Criteria criteria;
    SqliteQuery query;
    query.SelectAll().From("Test");
    criteria.AddJoin("table1", JoinType::cross, "id", "tbl_id");
    criteria.AddJoin("table2", JoinType::inner, "abc", "tbl_abc");
    criteria.AddCondition("abc", Condition::equal, "1");
    criteria.AddCondition("def", Condition::equal, "2");
    criteria.AddCondition("ghi", Condition::isNull);
    criteria.AddOrderBy("table1", "abc", SortOrder::ascending);
    criteria.AddOrderBy("table2", "def", SortOrder::descending);
    criteria.SetLimitCount(1);
    criteria.SetLimitOffset(2);
    criteria.Compose(query);
    ASSERT_EQ(
        query.GetAndReset(), "SELECT * FROM Test, table1 "
                             "ON id=tbl_id INNER JOIN table2 ON abc=tbl_abc "
                             "WHERE abc=? AND def=? AND ghi IS NULL "
                             "ORDER BY table1.abc ASC, table2.def DESC "
                             "LIMIT 1 OFFSET 2;");
}
