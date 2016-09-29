#include <cpporm/backend/nanodbc/utils.h>

// C++ library includes
#include <string>

// External library includes
#include <gtest/gtest.h>

// Using namespace
using namespace cpporm::backend::nanodbc;

TEST(CppOrm_Unit_Backend_Nanodbc_Utils, TestSet1)
{
    ASSERT_EQ(ProcessValue("1990-12-14"), "1990-12-14");
    ASSERT_EQ(ProcessValue("11:22:33.000"), "11:22:33.000");
    ASSERT_EQ(ProcessValue("1990-12-14 11:22:33.000"), "1990-12-14 11:22:33.000");
    ASSERT_EQ(ProcessValue("1990-12-14 11:22:33.000 +000"), "1990-12-14 11:22:33.000");
}

TEST(CppOrm_Unit_Backend_Nanodbc_Utils, TestSet2)
{
    ASSERT_EQ(ProcessValue("x'A0B1C2D3'"), "\xa0\xb1\xc2\xd3");
    ASSERT_THROW(ProcessValue("x'a0b1c2d3'"), std::invalid_argument);
}
