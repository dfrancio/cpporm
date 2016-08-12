#include <cpporm/util/stringmap.h>

// C++ library includes
#include <string>

// External library includes
#include <gtest/gtest.h>

// Internal program includes
#include "helpers.h"

TEST(CppOrm_Unit_Util_StringMap, TestSet1)
{
    IntStringMap map{{"abc", 1}};
    ASSERT_TRUE(map.Has("abc"));
    ASSERT_EQ(map.Get("abc"), 1);
    ASSERT_THROW(map.Get("def"), cpporm::EntryNonExistentError);
}
