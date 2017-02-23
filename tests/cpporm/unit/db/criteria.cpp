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
    const std::string cSqlQuery
        = " WHERE table1.abc=? AND def=? AND table2.ghi IS NULL AND jkl IS NOT NULL;";
    Criteria criteria;
    SqliteQuery query;
    criteria.AddCondition("table1", "abc", Condition::equal, "1");
    criteria.AddCondition("def", Condition::equal, "2");
    criteria.AddCondition("table2", "ghi", Condition::isNull);
    criteria.AddCondition("jkl", Condition::notNull);
    criteria.Compose(query);
    ASSERT_EQ(query.GetAndReset(), cSqlQuery);
}

TEST(CppOrm_Unit_Db_Criteria, TestSet3)
{
    const std::string cSqlQuery = " ORDER BY table1.abc ASC, def DESC;";
    Criteria criteria;
    SqliteQuery query;
    criteria.AddOrderBy("table1", "abc", SortOrder::ascending);
    criteria.AddOrderBy("def", SortOrder::descending);
    criteria.Compose(query);
    ASSERT_EQ(query.GetAndReset(), cSqlQuery);
}

TEST(CppOrm_Unit_Db_Criteria, TestSet4)
{
    const std::string cSqlQuery
        = " CROSS JOIN table1 INNER JOIN table2 ON table2.abc=table3.tbl_abc;";
    Criteria criteria;
    SqliteQuery query;
    criteria.AddJoin(JoinType::cross, "table1");
    criteria.AddJoin(JoinType::inner, "table2", "abc", "table3", "tbl_abc");
    criteria.Compose(query);
    ASSERT_EQ(query.GetAndReset(), cSqlQuery);
}

TEST(CppOrm_Unit_Db_Criteria, TestSet5)
{
    const std::string cSqlQuery
        = "SELECT * FROM Test CROSS JOIN table1 "
          "INNER JOIN table2 ON table2.abc=table3.tbl_abc "
          "WHERE table1.abc=? AND def=? AND table2.ghi IS NULL AND jkl IS NOT NULL "
          "ORDER BY table1.abc ASC, def DESC "
          "LIMIT 1 OFFSET 2;";
    Criteria criteria;
    SqliteQuery query;
    query.SelectAll().From("Test");
    criteria.AddJoin(JoinType::cross, "table1");
    criteria.AddJoin(JoinType::inner, "table2", "abc", "table3", "tbl_abc");
    criteria.AddCondition("table1", "abc", Condition::equal, "1");
    criteria.AddCondition("def", Condition::equal, "2");
    criteria.AddCondition("table2", "ghi", Condition::isNull);
    criteria.AddCondition("jkl", Condition::notNull);
    criteria.AddOrderBy("table1", "abc", SortOrder::ascending);
    criteria.AddOrderBy("def", SortOrder::descending);
    criteria.SetLimitCount(1);
    criteria.SetLimitOffset(2);
    criteria.Compose(query);
    ASSERT_EQ(query.GetAndReset(), cSqlQuery);
}

TEST(CppOrm_Unit_Db_Criteria, TestSet6)
{
    const std::string cSqlQuery
        = " WHERE (table1.abc=? OR (def=? AND table2.ghi IS NULL) OR jkl IS NOT NULL);";
    Criteria criteria;
    SqliteQuery query;
    criteria.OpenScope(LogicalConnective::disjunction);
    criteria.AddCondition("table1", "abc", Condition::equal, "1");
    criteria.OpenScope(LogicalConnective::conjunction);
    criteria.AddCondition("def", Condition::equal, "2");
    criteria.AddCondition("table2", "ghi", Condition::isNull);
    criteria.CloseScope();
    criteria.AddCondition("jkl", Condition::notNull);
    criteria.CloseScope();
    criteria.Compose(query);
    ASSERT_EQ(query.GetAndReset(), cSqlQuery);
}

TEST(CppOrm_Unit_Db_Criteria, TestSet7)
{
    const std::string cSqlQuery
        = " WHERE (table1.abc=? OR def=?) AND (table2.ghi IS NULL) AND jkl IS NOT NULL;";
    Criteria criteria;
    SqliteQuery query;
    criteria.OpenScope(LogicalConnective::disjunction);
    criteria.AddCondition("table1", "abc", Condition::equal, "1");
    criteria.AddCondition("def", Condition::equal, "2");
    criteria.OpenScope(LogicalConnective::conjunction);
    criteria.CloseScope();
    criteria.AddCondition("table2", "ghi", Condition::isNull);
    criteria.CloseScope();
    criteria.AddCondition("jkl", Condition::notNull);
    criteria.Compose(query);
    ASSERT_EQ(query.GetAndReset(), cSqlQuery);
}
