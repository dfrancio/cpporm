#include <cpporm/db/connectionstring.h>

// C++ library includes
#include <string>

// External library includes
#include <gtest/gtest.h>

// Using namespace
using namespace cpporm::db;

TEST(CppOrm_Unit_Db_ConnectionString, TestSet1)
{
    ConnectionString connectionString;
    ASSERT_EQ(connectionString.Get(), "");
    connectionString.SetParameter("Driver", "SQL Server");
    ASSERT_EQ(connectionString.Get(), "Driver=SQL Server");
    connectionString.SetParameter("", "'abc'");
    connectionString.SetParameter("name", "ab;c");
    ASSERT_EQ(connectionString.Get(), "Driver=SQL Server;\"'abc'\";name=\"ab;c\"");
}

/*
 * TestSet2
 * Implementation details go here...
 */
TEST(CppOrm_Unit_Db_ConnectionString, TestSet2)
{
    ConnectionString connectionString;
    connectionString.SetSeparator(' ').SetParameters({{"Database", "a.db"}, {"Pwd", "1 23"}});
    ASSERT_EQ(connectionString.Get(), "Database=a.db Pwd=\"1 23\"");
    connectionString.Reset().SetParameter("Driver", "ABC");
    connectionString.SetParameter("Database", "\"test.db\"");
    ASSERT_EQ(connectionString.Get(), "Driver=ABC Database='\"test.db\"'");
}
