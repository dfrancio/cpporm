#include <cpporm/util/macros.h>

// C++ library includes
#include <string>

// External library includes
#include <gtest/gtest.h>

// Internal program includes
#include "helpers.h"

// Using namespace
using namespace cpporm::util;

// Global variables
CPPORM_REGISTER(MyFactory, MyClass3, MyClass3, "MyClass3");

TEST(CppOrm_Unit_Util_Preprocessor, TestSet1)
{
    ASSERT_EQ(VariadicUnpackTester().count, 0);
    ASSERT_EQ(VariadicUnpackTester(1).count, 1);
    ASSERT_EQ(VariadicUnpackTester(1, 'c').count, 2);
    ASSERT_EQ(VariadicUnpackTester(1, 'c', "a").count, 3);
}

TEST(CppOrm_Unit_Util_Preprocessor, TestSet3)
{
    ASSERT_TRUE(dynamic_cast<MyClass3 *>(MyFactory::GetInstance().CreateUnique("MyClass3").get()));
}

TEST(CppOrm_Unit_Util_Preprocessor, TestSet4)
{
    ASSERT_EQ(CPPORM_INDEX_PRIMARY_KEY, "primary_key");
    ASSERT_EQ(CPPORM_INDEX_FOREIGN_KEY, "foreign_key");
    ASSERT_EQ(CPPORM_INDEX_UNIQUE, "unique");
    ASSERT_EQ(CPPORM_INDEX_VERSION, "version_fields");
}

TEST(CppOrm_Unit_Util_Preprocessor, TestSet5)
{
    ASSERT_STREQ(CPPORM_PROP_NOT_NULL, "NOT_NULL");
    ASSERT_STREQ(CPPORM_PROP_IDENTITY, "IDENTITY");
    ASSERT_STREQ(CPPORM_PROP_DEFAULT, "DEFAULT");
    ASSERT_STREQ(CPPORM_PROP_ON_UPDATE, "ON_UPDATE");
    ASSERT_STREQ(CPPORM_PROP_ON_DELETE, "ON_DELETE");
    ASSERT_STREQ(CPPORM_PROP_DATA_TYPE, "DATA_TYPE");
    ASSERT_STREQ(CPPORM_PROP_LENGTH, "LENGTH");
    ASSERT_STREQ(CPPORM_PROP_DECIMALS, "DECIMALS");
}

TEST(CppOrm_Unit_Util_Preprocessor, TestSet6)
{
    ASSERT_STREQ(CPPORM_ON_DELETE_SET_NULL, "SET NULL");
    ASSERT_STREQ(CPPORM_ON_DELETE_CASCADE, "CASCADE");
    ASSERT_STREQ(CPPORM_ON_DELETE_NO_ACTION, "NO ACTION");
}

TEST(CppOrm_Unit_Util_Preprocessor, TestSet7)
{
    ASSERT_EQ(CPPORM_ADD_TABLE_SCOPE(""), "");
    ASSERT_EQ(CPPORM_ADD_TABLE_SCOPE("abc"), "abc.");
}
