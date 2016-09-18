#include <cpporm/util/factory.h>

// C++ library includes
#include <string>

// External library includes
#include <gtest/gtest.h>

// Internal program includes
#include "helpers.h"

TEST(CppOrm_Unit_Util_Factory, TestSet1)
{
    MyFactory::GetInstance().Register<MyClass1>("a");
    MyFactory::GetInstance().Register<MyClass2>("b");
    MyFactory::GetInstance().Register<MyClass3>("d", "e", "f");
    MyFactory2::GetInstance().Register<MyClass3>("Ab", "cd", "EF");
}

TEST(CppOrm_Unit_Util_Factory, TestSet2)
{
    auto object = MyFactory::GetInstance().CreateUnique("a");
    ASSERT_TRUE(dynamic_cast<MyClass1 *>(object.get()));
    ASSERT_FALSE(dynamic_cast<MyClass2 *>(object.get()));
    ASSERT_FALSE(dynamic_cast<MyClass3 *>(object.get()));
}

TEST(CppOrm_Unit_Util_Factory, TestSet3)
{
    auto object = MyFactory::GetInstance().CreateUnique("b");
    ASSERT_FALSE(dynamic_cast<MyClass1 *>(object.get()));
    ASSERT_TRUE(dynamic_cast<MyClass2 *>(object.get()));
    ASSERT_FALSE(dynamic_cast<MyClass3 *>(object.get()));
}

TEST(CppOrm_Unit_Util_Factory, TestSet4)
{
    auto object = MyFactory::GetInstance().CreateUnique("d");
    ASSERT_FALSE(dynamic_cast<MyClass1 *>(object.get()));
    ASSERT_FALSE(dynamic_cast<MyClass2 *>(object.get()));
    ASSERT_TRUE(dynamic_cast<MyClass3 *>(object.get()));
}

TEST(CppOrm_Unit_Util_Factory, TestSet5)
{
    ASSERT_THROW(MyFactory::GetInstance().CreateUnique("z"), cpporm::EntryNonExistentError);
    ASSERT_THROW(MyFactory::GetInstance().CreateUnique("x"), cpporm::EntryNonExistentError);
}

TEST(CppOrm_Unit_Util_Factory, TestSet6)
{
    ASSERT_TRUE(dynamic_cast<MyClass3 *>(MyFactory2::GetInstance().CreateUnique("aB").get()));
    ASSERT_TRUE(dynamic_cast<MyClass3 *>(MyFactory2::GetInstance().CreateUnique("CD").get()));
    ASSERT_TRUE(dynamic_cast<MyClass3 *>(MyFactory2::GetInstance().CreateUnique("ef").get()));
}
