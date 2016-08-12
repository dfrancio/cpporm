#include <cpporm/util/string.h>

// C++ library includes
#include <string>

// External library includes
#include <gtest/gtest.h>

// Internal program includes
#include "helpers.h"

// Using namespace
using namespace cpporm::util;

TEST(CppOrm_Unit_Util_String, TestSet1)
{
    ASSERT_TRUE((std::is_same<SafeUnderlyingType<int>, int>::value));
    ASSERT_TRUE((std::is_same<SafeUnderlyingType<std::string>, std::string>::value));
    ASSERT_TRUE((std::is_same<SafeUnderlyingType<A>, unsigned int>::value));
    ASSERT_TRUE((std::is_same<SafeUnderlyingType<B>, int>::value));
    ASSERT_TRUE((std::is_same<SafeUnderlyingType<C>, unsigned short>::value));
}

TEST(CppOrm_Unit_Util_String, TestSet2)
{
    ASSERT_EQ(to_string('a'), "97");
    ASSERT_EQ(to_string("a"), "a");
    ASSERT_EQ(to_string(1), "1");
    ASSERT_EQ(to_string(2.3), "2.300000");
}

TEST(CppOrm_Unit_Util_String, TestSet3)
{
    ASSERT_EQ(Stringify(), "");
    ASSERT_EQ(Stringify<','>(), "");
    ASSERT_EQ((Stringify<',', ' '>()), "");
    ASSERT_EQ(Stringify(true, AA, 2.3, "abc"), "102.300000abc");
    ASSERT_EQ(Stringify<','>(true, AA, 2.3, "abc"), "1,0,2.300000,abc");
    ASSERT_EQ((Stringify<',', ' '>(true, AA, 2.3, "abc")), "1, 0, 2.300000, abc");
}

TEST(CppOrm_Unit_Util_String, TestSet4)
{
    ASSERT_EQ(CaseInsensitiveCompare("aBc", "AcB"), -1);
    ASSERT_EQ(CaseInsensitiveCompare("AbC", "aBc"), 0);
    ASSERT_EQ(CaseInsensitiveCompare("bac", "ABC"), 1);
}
