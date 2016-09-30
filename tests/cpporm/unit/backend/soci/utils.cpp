#include <cpporm/backend/soci/utils.h>

// C++ library includes
#include <string>

// External library includes
#include <gtest/gtest.h>

// Using namespace
using namespace cpporm::backend::soci;

TEST(CppOrm_Unit_Backend_Soci_Utils, TestSet1)
{
    ASSERT_EQ(Convert((int)-294967296), "-294967296");
    ASSERT_EQ(Convert((int)294967297), "294967297");
    ASSERT_EQ(Convert((long long)-9223372036854775807), "-9223372036854775807");
    ASSERT_EQ(Convert((unsigned long long)9223372036854775807), "9223372036854775807");
}

TEST(CppOrm_Unit_Backend_Soci_Utils, TestSet2)
{
    ASSERT_EQ(Convert(double(0)), "0");
    ASSERT_EQ(Convert(double(0.1)), "0.100000000000000006");
    ASSERT_EQ(Convert(double(1.0)), "1");
    ASSERT_EQ(Convert(double(0.123456789)), "0.123456788999999997");
    ASSERT_EQ(Convert(double(-1e10)), "-10000000000");
#ifdef _WIN32
    ASSERT_EQ(Convert(double(1e-10)), "1e-010");
#else
    ASSERT_EQ(Convert(double(1e-10)), "1.00000000000000004e-10");
#endif
}

TEST(CppOrm_Unit_Backend_Soci_Utils, TestSet3)
{
    ASSERT_EQ(Convert(std::tm({0, 0, 0, 1, 0, -1890})), "10:01:01");
    ASSERT_EQ(Convert(std::tm({0, 0, 0, 14, 11, 90})), "1990-12-14");
    ASSERT_EQ(Convert(std::tm({1, 1, 10, 14, 11, 90})), "1990-12-14 10:01:01");
}

TEST(CppOrm_Unit_Backend_Soci_Utils, TestSet4)
{
    ASSERT_EQ(ProcessParameterNames(""), "");
    ASSERT_EQ(ProcessParameterNames("?"), ":0");
    ASSERT_EQ(ProcessParameterNames("? ??,?"), ":0 :1:2,:3");
}

TEST(CppOrm_Unit_Backend_Soci_Utils, TestSet5)
{
    ASSERT_EQ(MakeParameterName(0), "0");
    ASSERT_EQ(MakeParameterName(1), "1");
    ASSERT_EQ(MakeParameterName(2), "2");
}
