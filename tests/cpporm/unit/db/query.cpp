#include <cpporm/db/query.h>

// C++ library includes
#include <string>

// External library includes
#include <gtest/gtest.h>

// Using namespace
using namespace cpporm::db;

TEST(CppOrm_Unit_Db_Query, TestSet1)
{
    Query query("test");
    ASSERT_EQ(query.GetAndReset(), "test;");
    ASSERT_EQ(query.AddCustomQuery("test2").Get(), " test2;");
}

TEST(CppOrm_Unit_Db_Query, TestSet2)
{
    Query query;
    query.SubQueryBegin().SubQueryEnd();
    ASSERT_EQ(query.GetAndReset(), " ();");
}

TEST(CppOrm_Unit_Db_Query, TestSet3)
{
    Query query;
    query.Select();
    ASSERT_EQ(query.GetAndReset(), "SELECT;");
    query.Select("a");
    ASSERT_EQ(query.GetAndReset(), "SELECT a;");
    query.Select("a", "b");
    ASSERT_EQ(query.GetAndReset(), "SELECT a,b;");
}

TEST(CppOrm_Unit_Db_Query, TestSet4)
{
    Query query;
    query.Distinct();
    ASSERT_EQ(query.GetAndReset(), " DISTINCT;");
    query.Distinct("a");
    ASSERT_EQ(query.GetAndReset(), " DISTINCT a;");
    query.Distinct("a", "b");
    ASSERT_EQ(query.GetAndReset(), " DISTINCT a,b;");
}

TEST(CppOrm_Unit_Db_Query, TestSet5)
{
    Query query;
    query.Columns();
    ASSERT_EQ(query.GetAndReset(), " ();");
    query.Columns("a");
    ASSERT_EQ(query.GetAndReset(), " (a);");
    query.Columns("a", "b");
    ASSERT_EQ(query.GetAndReset(), " (a,b);");
}

TEST(CppOrm_Unit_Db_Query, TestSet6)
{
    Query query;
    query.Values();
    ASSERT_EQ(query.GetAndReset(), " VALUES ();");
    query.Values("a");
    ASSERT_EQ(query.GetAndReset(), " VALUES (a);");
    query.Values("a", "b");
    ASSERT_EQ(query.GetAndReset(), " VALUES (a,b);");
}

TEST(CppOrm_Unit_Db_Query, TestSet7)
{
    Query query;
    query.In();
    ASSERT_EQ(query.GetAndReset(), " IN;");
    query.In("a");
    ASSERT_EQ(query.GetAndReset(), " IN (a);");
    query.In("a", "b");
    ASSERT_EQ(query.GetAndReset(), " IN (a,b);");
}

TEST(CppOrm_Unit_Db_Query, TestSet8)
{
    Query query;
    query.As("abc");
    ASSERT_EQ(query.GetAndReset(), " AS abc;");
    query.Update("table");
    ASSERT_EQ(query.GetAndReset(), "UPDATE table;");
    query.Delete();
    ASSERT_EQ(query.GetAndReset(), "DELETE;");
    query.Insert();
    ASSERT_EQ(query.GetAndReset(), "INSERT;");
    query.Into("table");
    ASSERT_EQ(query.GetAndReset(), " INTO table;");
    query.From("table");
    ASSERT_EQ(query.GetAndReset(), " FROM table;");
    query.Where("col");
    ASSERT_EQ(query.GetAndReset(), " WHERE col;");
    query.Where("col", "table");
    ASSERT_EQ(query.GetAndReset(), " WHERE table.col;");
}

TEST(CppOrm_Unit_Db_Query, TestSet9)
{
    Query query;
    query.Avg("a");
    ASSERT_EQ(query.GetAndReset(), " AVG(a);");
    query.Avg("a", "", true);
    ASSERT_EQ(query.GetAndReset(), " AVG(DISTINCT a);");
    query.Count("a");
    ASSERT_EQ(query.GetAndReset(), " COUNT(a);");
    query.Count("a", "", true);
    ASSERT_EQ(query.GetAndReset(), " COUNT(DISTINCT a);");
    query.CountAll();
    ASSERT_EQ(query.GetAndReset(), " COUNT(*);");
    query.First("a");
    ASSERT_EQ(query.GetAndReset(), " FIRST(a);");
    query.Last("a");
    ASSERT_EQ(query.GetAndReset(), " LAST(a);");
    query.Max("a");
    ASSERT_EQ(query.GetAndReset(), " MAX(a);");
    query.Min("a");
    ASSERT_EQ(query.GetAndReset(), " MIN(a);");
    query.Sum("a");
    ASSERT_EQ(query.GetAndReset(), " SUM(a);");
    query.Sum("a", "", true);
    ASSERT_EQ(query.GetAndReset(), " SUM(DISTINCT a);");
}

TEST(CppOrm_Unit_Db_Query, TestSet10)
{
    Query query;
    query.Like("abc");
    ASSERT_EQ(query.GetAndReset(), " LIKE abc;");
    query.Equals("a");
    ASSERT_EQ(query.GetAndReset(), "=a;");
    query.Differs("a");
    ASSERT_EQ(query.GetAndReset(), "<>a;");
    query.LessThan("a");
    ASSERT_EQ(query.GetAndReset(), "<a;");
    query.GreaterThan("a");
    ASSERT_EQ(query.GetAndReset(), ">a;");
    query.LessOrEqual("a");
    ASSERT_EQ(query.GetAndReset(), "<=a;");
    query.GreaterOrEqual("a");
    ASSERT_EQ(query.GetAndReset(), ">=a;");
}

TEST(CppOrm_Unit_Db_Query, TestSet11)
{
    Query query;
    query.Between("1").And("10");
    ASSERT_EQ(query.GetAndReset(), " BETWEEN 1 AND 10;");
    query.Null();
    ASSERT_EQ(query.GetAndReset(), " NULL;");
    query.And();
    ASSERT_EQ(query.GetAndReset(), " AND ;");
    query.And("col");
    ASSERT_EQ(query.GetAndReset(), " AND col;");
    query.Or();
    ASSERT_EQ(query.GetAndReset(), " OR ;");
    query.Or("col");
    ASSERT_EQ(query.GetAndReset(), " OR col;");
    query.Not();
    ASSERT_EQ(query.GetAndReset(), " NOT;");
}

TEST(CppOrm_Unit_Db_Query, TestSet12)
{
    Query query;
    query.Join("table");
    ASSERT_EQ(query.GetAndReset(), ", table;");
    query.Join("table", JoinType::inner);
    ASSERT_EQ(query.GetAndReset(), " INNER JOIN table;");
    query.Join("table", JoinType::natural);
    ASSERT_EQ(query.GetAndReset(), " NATURAL INNER JOIN table;");
    query.Join("table", JoinType::leftouter);
    ASSERT_EQ(query.GetAndReset(), " LEFT OUTER JOIN table;");
    query.Join("table", JoinType::rightouter);
    ASSERT_EQ(query.GetAndReset(), " RIGHT OUTER JOIN table;");
    query.Join("table", JoinType::fullouter);
    ASSERT_EQ(query.GetAndReset(), " FULL OUTER JOIN table;");
}

TEST(CppOrm_Unit_Db_Query, TestSet13)
{
    Query query;
    query.On("a");
    ASSERT_EQ(query.GetAndReset(), " ON a;");
    query.GroupBy("a");
    ASSERT_EQ(query.GetAndReset(), " GROUP BY a;");
    query.Having("a");
    ASSERT_EQ(query.GetAndReset(), " HAVING a;");
    query.OrderBy("a");
    ASSERT_EQ(query.GetAndReset(), " ORDER BY a ASC;");
    query.OrderBy("a", "", SortOrder::descending);
    ASSERT_EQ(query.GetAndReset(), " ORDER BY a DESC;");
}

TEST(CppOrm_Unit_Db_Query, TestSet14)
{
    Query query;
    query.Exists();
    ASSERT_EQ(query.GetAndReset(), " EXISTS;");
    query.Union();
    ASSERT_EQ(query.GetAndReset(), " UNION;");
    query.Except();
    ASSERT_EQ(query.GetAndReset(), " EXCEPT;");
    query.Intersect();
    ASSERT_EQ(query.GetAndReset(), " INTERSECT;");
}

TEST(CppOrm_Unit_Db_Query, TestSet15)
{
    Query query;
    query.Now();
    ASSERT_EQ(query.GetAndReset(), ";");
    query.CurrentDate();
    ASSERT_EQ(query.GetAndReset(), ";");
    query.CurrentTime();
    ASSERT_EQ(query.GetAndReset(), ";");
    query.Limit(1);
    ASSERT_EQ(query.GetAndReset(), ";");
    query.Limit(1, 1);
    ASSERT_EQ(query.GetAndReset(), ";");
    query.LastInsertId();
    ASSERT_EQ(query.GetAndReset(), ";");
    query.ResetSequence("table");
    ASSERT_EQ(query.GetAndReset(), ";");
    query.SavePoint("name");
    ASSERT_EQ(query.GetAndReset(), "SAVEPOINT name;");
    query.ReleaseSavePoint("name");
    ASSERT_EQ(query.GetAndReset(), "RELEASE SAVEPOINT name;");
    query.RollbackToSavePoint("name");
    ASSERT_EQ(query.GetAndReset(), "ROLLBACK TO SAVEPOINT name;");
}

TEST(CppOrm_Unit_Db_Query, TestSet16)
{
    SqliteQuery query;
    query.Now();
    ASSERT_EQ(query.GetAndReset(), " DATETIME();");
    query.CurrentDate();
    ASSERT_EQ(query.GetAndReset(), " DATE();");
    query.CurrentTime();
    ASSERT_EQ(query.GetAndReset(), " TIME();");
    query.Limit(1, 0);
    ASSERT_EQ(query.GetAndReset(), " LIMIT 1;");
    query.Limit(1, 1);
    ASSERT_EQ(query.GetAndReset(), " LIMIT 1 OFFSET 1;");
    query.LastInsertId();
    ASSERT_EQ(query.GetAndReset(), " last_insert_rowid();");
    query.ResetSequence("table");
    ASSERT_EQ(query.GetAndReset(), "DELETE FROM sqlite_sequence WHERE name = table;");
    query.SavePoint("name");
    ASSERT_EQ(query.GetAndReset(), "SAVEPOINT name;");
    query.ReleaseSavePoint("name");
    ASSERT_EQ(query.GetAndReset(), "RELEASE SAVEPOINT name;");
    query.RollbackToSavePoint("name");
    ASSERT_EQ(query.GetAndReset(), "ROLLBACK TO SAVEPOINT name;");
}

TEST(CppOrm_Unit_Db_Query, TestSet17)
{
    SqlServerQuery query;
    query.Now();
    ASSERT_EQ(query.GetAndReset(), " GETDATE();");
    query.CurrentDate();
    ASSERT_EQ(query.GetAndReset(), " CONVERT(date, GETDATE());");
    query.CurrentTime();
    ASSERT_EQ(query.GetAndReset(), " CONVERT(time, GETDATE());");
    query.Limit(1, 0);
    ASSERT_EQ(query.GetAndReset(), " OFFSET 0 ROWS FETCH NEXT 1 ROWS ONLY;");
    query.Limit(0, 1);
    ASSERT_EQ(query.GetAndReset(), " OFFSET 1 ROWS;");
    query.LastInsertId();
    ASSERT_EQ(query.GetAndReset(), " SCOPE_IDENTITY();");
    query.ResetSequence("table");
    ASSERT_EQ(query.GetAndReset(), "DBCC CHECKIDENT(table, RESEED, 0);");
    query.SavePoint("name");
    ASSERT_EQ(query.GetAndReset(), "SAVE TRANSACTION name;");
    query.ReleaseSavePoint("name");
    ASSERT_EQ(query.GetAndReset(), ";");
    query.RollbackToSavePoint("name");
    ASSERT_EQ(query.GetAndReset(), "ROLLBACK TRANSACTION name;");
}

TEST(CppOrm_Unit_Db_Query, TestSet18)
{
    MySqlQuery query;
    query.Now();
    ASSERT_EQ(query.GetAndReset(), " NOW();");
    query.CurrentDate();
    ASSERT_EQ(query.GetAndReset(), " CURDATE();");
    query.CurrentTime();
    ASSERT_EQ(query.GetAndReset(), " CURTIME();");
    query.Limit(1, 0);
    ASSERT_EQ(query.GetAndReset(), " LIMIT 1;");
    query.Limit(1, 1);
    ASSERT_EQ(query.GetAndReset(), " LIMIT 1 OFFSET 1;");
    query.LastInsertId();
    ASSERT_EQ(query.GetAndReset(), " LAST_INSERT_ID();");
    query.ResetSequence("table");
    ASSERT_EQ(query.GetAndReset(), "ALTER TABLE table AUTO_INCREMENT = 1;");
    query.SavePoint("name");
    ASSERT_EQ(query.GetAndReset(), "SAVEPOINT name;");
    query.ReleaseSavePoint("name");
    ASSERT_EQ(query.GetAndReset(), "RELEASE SAVEPOINT name;");
    query.RollbackToSavePoint("name");
    ASSERT_EQ(query.GetAndReset(), "ROLLBACK TO SAVEPOINT name;");
}

TEST(CppOrm_Unit_Db_Query, TestSet19)
{
    PostgreSqlQuery query;
    query.Now();
    ASSERT_EQ(query.GetAndReset(), " CURRENT_TIMESTAMP();");
    query.CurrentDate();
    ASSERT_EQ(query.GetAndReset(), " CURRENT_DATE();");
    query.CurrentTime();
    ASSERT_EQ(query.GetAndReset(), " CURRENT_TIME();");
    query.Limit(1, 0);
    ASSERT_EQ(query.GetAndReset(), " LIMIT 1;");
    query.Limit(1, 1);
    ASSERT_EQ(query.GetAndReset(), " LIMIT 1 OFFSET 1;");
    query.LastInsertId();
    ASSERT_EQ(query.GetAndReset(), " LASTVAL();");
    query.ResetSequence("table");
    ASSERT_EQ(query.GetAndReset(), "ALTER SEQUENCE table_id_seq RESTART WITH 1;");
    query.SavePoint("name");
    ASSERT_EQ(query.GetAndReset(), "SAVEPOINT name;");
    query.ReleaseSavePoint("name");
    ASSERT_EQ(query.GetAndReset(), "RELEASE SAVEPOINT name;");
    query.RollbackToSavePoint("name");
    ASSERT_EQ(query.GetAndReset(), "ROLLBACK TO SAVEPOINT name;");
}

TEST(CppOrm_Unit_Db_Query, TestSet20)
{
    const std::string cSqlQuery = "SELECT a,b FROM table WHERE a=\"text\" AND b<>2;";
    Query query;
    query.Select("a", "b").From("table").Where("a").Equals("\"text\"").And("b").Differs("2");
    ASSERT_EQ(query.GetAndReset(), cSqlQuery);
}

TEST(CppOrm_Unit_Db_Query, TestSet21)
{
    const std::string cSqlQuery = "SELECT c1,c2 FROM table WHERE col LIKE \"*a\";";
    Query query;
    query.Select()
        .IncrementalSelect("c1")
        .IncrementalSelect("c2")
        .EndIncrementalSelect()
        .From("table")
        .Where("col")
        .Like("\"*a\"");
    ASSERT_EQ(query.GetAndReset(), cSqlQuery);
}

TEST(CppOrm_Unit_Db_Query, TestSet22)
{
    const std::string cSqlQuery = "UPDATE table SET c1=v1,c2=? WHERE col LIKE \"*a\";";
    Query query;
    query.Update("table")
        .IncrementalUpdate("c1", "v1")
        .IncrementalUpdate("c2")
        .EndIncrementalUpdate()
        .Where("col")
        .Like("\"*a\"");
    ASSERT_EQ(query.GetBindingIndex(), 0);
    ASSERT_EQ(query.GetAndReset(), cSqlQuery);
}

TEST(CppOrm_Unit_Db_Query, TestSet23)
{
    const std::string cSqlQuery = "INSERT INTO table (c1,c2) VALUES (v1,?) WHERE col LIKE \"*a\";";
    Query query;
    query.Insert()
        .Into("table")
        .IncrementalInsert("c1", "v1")
        .IncrementalInsert("c2")
        .EndIncrementalInsert()
        .Where("col")
        .Like("\"*a\"");
    ASSERT_EQ(query.GetBindingIndex(), 0);
    ASSERT_EQ(query.GetAndReset(), cSqlQuery);

    query.Insert().Into("table").EndIncrementalInsert();
    ASSERT_EQ(query.GetAndReset(), "INSERT INTO table DEFAULT VALUES;");
}

TEST(CppOrm_Unit_Db_Query, TestSet24)
{
    const std::string cSqlQuery = " WHERE c1<>v1 AND c2 IS NULL AND c3=?;";
    Query query;
    query.IncrementalWhere("c1", Condition::notEqual, "v1")
        .IncrementalWhere("c2", Condition::isNull)
        .IncrementalWhere("c3", Condition::equal)
        .EndIncrementalWhere();
    ASSERT_EQ(query.GetBindingIndex(), 0);
    ASSERT_EQ(query.GetAndReset(), cSqlQuery);
}

TEST(CppOrm_Unit_Db_Query, TestSet25)
{
    const std::string cSqlQuery = "DELETE FROM table WHERE col=val;";
    Query query;
    query.Delete().From("table").Where("col").Equals("val");
    ASSERT_EQ(query.GetAndReset(), cSqlQuery);
}

TEST(CppOrm_Unit_Db_Query, TestSet26)
{
    const std::string cSqlQuery = "INSERT INTO table VALUES (val1,val2,val3);";
    Query query;
    query.Insert().Into("table").Values("val1", "val2", "val3");
    ASSERT_EQ(query.GetAndReset(), cSqlQuery);
}

TEST(CppOrm_Unit_Db_Query, TestSet27)
{
    const std::string cSqlQuery = "INSERT INTO table (col1,col2,col3) VALUES (val1,val2,val3);";
    Query query;
    query.Insert().Into("table").Columns("col1", "col2", "col3").Values("val1", "val2", "val3");
    ASSERT_EQ(query.GetAndReset(), cSqlQuery);
}

TEST(CppOrm_Unit_Db_Query, TestSet28)
{
    const std::string cSqlQuery
        = "SELECT DISTINCT col1,col2 FROM table ORDER BY col1 ASC, col2 DESC;";
    Query query;
    query.Select()
        .Distinct("col1", "col2")
        .From("table")
        .OrderBy("col1")
        .OrderBy("col2", "", SortOrder::descending);
    ASSERT_EQ(query.GetAndReset(), cSqlQuery);
}

TEST(CppOrm_Unit_Db_Query, TestSet29)
{
    const std::string cSqlQuery = "SELECT * FROM table WHERE table.id=?;";
    Query query;
    ASSERT_EQ(query.GetBindingIndex(), -1);
    query.SelectAll().From("table").Where("id", "table").Equals();
    ASSERT_EQ(query.GetBindingIndex(), 0);
    ASSERT_EQ(query.GetAndReset(), cSqlQuery);
    ASSERT_EQ(query.GetBindingIndex(), -1);
}

TEST(CppOrm_Unit_Db_Query, TestSet30)
{
    Query query;
    query.AddContition(Condition::equal);
    ASSERT_EQ(query.GetBindingIndex(), 0);
    query.AddContition(Condition::greaterOrEqual);
    ASSERT_EQ(query.GetBindingIndex(), 1);
    query.AddContition(Condition::greaterThan);
    ASSERT_EQ(query.GetBindingIndex(), 2);
    query.AddContition(Condition::lessOrEqual);
    ASSERT_EQ(query.GetBindingIndex(), 3);
    query.AddContition(Condition::lessThan);
    ASSERT_EQ(query.GetBindingIndex(), 4);
    query.AddContition(Condition::notEqual);
    ASSERT_EQ(query.GetBindingIndex(), 5);
    query.AddContition(Condition::like);
    ASSERT_EQ(query.GetBindingIndex(), 6);
}

TEST(CppOrm_Unit_Db_Query, TestSet31)
{
    Query query;
    query.IncrementalUpdate("abc");
    ASSERT_EQ(query.GetBindingIndex(), 0);
    query.IncrementalUpdate("def");
    ASSERT_EQ(query.GetBindingIndex(), 1);
    query.IncrementalInsert("ghi");
    ASSERT_EQ(query.GetBindingIndex(), 2);
    query.IncrementalInsert("jkl");
    ASSERT_EQ(query.GetBindingIndex(), 3);
}
