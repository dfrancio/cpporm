#include <cpporm/util/factory.h>

// C++ library includes
#include <string>

// External library includes
#include <gtest/gtest.h>

// Internal program includes
#include "helpers.h"

TEST(CppOrm_Unit_Util_Factory, TestSet1)
{
    MyFactory::GetInstance().Register<MyClass3>("d", "e", "f");
    MyFactory2::GetInstance().Register<MyClass3>("Ab", "cd", "EF");
    MyFactory::GetInstance().Register([]() { return new MyClass1(); }, "a");
    MyFactory::GetInstance().Register([]() { return new MyClass2(); }, "b", "c");
}

TEST(CppOrm_Unit_Util_Factory, TestSet2)
{
    auto object = MyFactory::GetInstance().Create("a");
    ASSERT_TRUE(dynamic_cast<MyClass1 *>(object.get()));
    ASSERT_FALSE(dynamic_cast<MyClass2 *>(object.get()));
    ASSERT_FALSE(dynamic_cast<MyClass3 *>(object.get()));
}

TEST(CppOrm_Unit_Util_Factory, TestSet3)
{
    auto object = MyFactory::GetInstance().Create("b");
    ASSERT_FALSE(dynamic_cast<MyClass1 *>(object.get()));
    ASSERT_TRUE(dynamic_cast<MyClass2 *>(object.get()));
    ASSERT_FALSE(dynamic_cast<MyClass3 *>(object.get()));
}

TEST(CppOrm_Unit_Util_Factory, TestSet4)
{
    auto object = MyFactory::GetInstance().Create("d");
    ASSERT_FALSE(dynamic_cast<MyClass1 *>(object.get()));
    ASSERT_FALSE(dynamic_cast<MyClass2 *>(object.get()));
    ASSERT_TRUE(dynamic_cast<MyClass3 *>(object.get()));
}

TEST(CppOrm_Unit_Util_Factory, TestSet5)
{
    ASSERT_THROW(MyFactory::GetInstance().Create("z"), cpporm::EntryNonExistentError);
    ASSERT_THROW(MyFactory::GetInstance().Create("x"), cpporm::EntryNonExistentError);
}

TEST(CppOrm_Unit_Util_Factory, TestSet6)
{
    ASSERT_TRUE(dynamic_cast<MyClass3 *>(MyFactory2::GetInstance().Create("aB").get()));
    ASSERT_TRUE(dynamic_cast<MyClass3 *>(MyFactory2::GetInstance().Create("CD").get()));
    ASSERT_TRUE(dynamic_cast<MyClass3 *>(MyFactory2::GetInstance().Create("ef").get()));
}
