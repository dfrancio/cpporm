#include <cpporm/backend/nanodbc/utils.h>

// C++ library includes
#include <string>

// External library includes
#include <gtest/gtest.h>

// Using namespace
using namespace cpporm::backend::nanodbc;

TEST(CppOrm_Unit_Backend_Nanodbc_Utils, TestSet1)
{
    ASSERT_TRUE(Widen16("") == u"");
    ASSERT_TRUE(Widen16("1") == u"1");
    ASSERT_TRUE(Widen16(std::string("1")) == u"1");
    ASSERT_TRUE(Widen16("Приве́т") == u"Приве́т");
    ASSERT_TRUE(Widen16(std::string("Приве́т")) == u"Приве́т");
}

TEST(CppOrm_Unit_Backend_Nanodbc_Utils, TestSet2)
{
    ASSERT_EQ(Narrow(u""), "");
    ASSERT_EQ(Narrow(u"1"), "1");
    ASSERT_EQ(Narrow(std::u16string(u"1")), "1");
    ASSERT_EQ(Narrow(u"Приве́т"), "Приве́т");
    ASSERT_EQ(Narrow(std::u16string(u"Приве́т")), "Приве́т");
}

TEST(CppOrm_Unit_Backend_Nanodbc_Utils, TestSet3)
{
    ASSERT_EQ(HandleDateTime("1990-12-14"), "1990-12-14");
    ASSERT_EQ(HandleDateTime("11:22:33.000"), "11:22:33.000");
    ASSERT_EQ(HandleDateTime("1990-12-14 11:22:33.000"), "1990-12-14 11:22:33.000");
    ASSERT_EQ(HandleDateTime("1990-12-14 11:22:33.000 +000"), "1990-12-14 11:22:33.000");
}
