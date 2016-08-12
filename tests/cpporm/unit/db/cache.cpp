#include <cpporm/db/cache.h>

// C++ library includes
#include <string>

// External library includes
#include <gtest/gtest.h>

// Internal program includes
#include "helpers.h"

// Using namespace
using namespace cpporm::util;

// Test fixture
class CppOrm_Unit_Db_Cache : public testing::Test
{
protected:
    CppOrm_Unit_Db_Cache() : entity(new MyEntity("abc", "123")), entity2(new MyEntity("def", "456"))
    {
    }
    Cache cache;
    Cache cache2;
    std::shared_ptr<MyEntity> entity;
    std::shared_ptr<MyEntity> entity2;
};

TEST_F(CppOrm_Unit_Db_Cache, TestSet1)
{
    ASSERT_FALSE(cache.Has(entity->GetId()));
    ASSERT_TRUE(cache.Add(entity->GetId(), entity));
    ASSERT_TRUE(cache.Has(entity->GetId()));
    ASSERT_EQ(cache.Get(entity->GetId()), entity);
    ASSERT_FALSE(cache.Add(entity->GetId(), entity));
    ASSERT_TRUE(cache.Add(entity2->GetId(), entity2));
    ASSERT_EQ(cache.Get(entity2->GetId()), entity2);
    ASSERT_NO_THROW(cache.Remove(entity->GetId()));
    ASSERT_FALSE(cache.Has(entity->GetId()));
    ASSERT_NO_THROW(cache.Remove(entity->GetId()));
    ASSERT_THROW(cache.Get(entity->GetId()), cpporm::EntryNonExistentError);
}

TEST_F(CppOrm_Unit_Db_Cache, TestSet2)
{
    ASSERT_TRUE(cache.empty());
    ASSERT_EQ(cache.size(), 0);
    ASSERT_TRUE(cache.Add(entity->GetId(), entity));
    ASSERT_FALSE(cache.empty());
    ASSERT_EQ(cache.size(), 1);
    ASSERT_TRUE(cache.Add(entity2->GetId(), entity2));
    ASSERT_EQ(cache.size(), 2);
    ASSERT_NO_THROW(cache.clear());
    ASSERT_TRUE(cache.empty());
    ASSERT_EQ(cache.size(), 0);
}

TEST_F(CppOrm_Unit_Db_Cache, TestSet3)
{
    ASSERT_TRUE(cache.Add(entity->GetId(), entity));
    ASSERT_TRUE(cache.Has(entity->GetId()));
    ASSERT_EQ(cache.size(), 1);
    ASSERT_NO_THROW(cache.Rename(entity->GetId(), entity2->GetId()));
    ASSERT_FALSE(cache.Has(entity->GetId()));
    ASSERT_TRUE(cache.Has(entity2->GetId()));
    ASSERT_EQ(cache.size(), 1);
}

TEST_F(CppOrm_Unit_Db_Cache, TestSet4)
{
    ASSERT_TRUE(cache.Add(entity->GetId(), entity));
    ASSERT_TRUE(cache2.Add(entity2->GetId(), entity2));
    ASSERT_FALSE(cache.Has(entity2->GetId()));
    ASSERT_EQ(cache.size(), 1);
    cache.CopyFrom(cache2);
    ASSERT_TRUE(cache.Has(entity2->GetId()));
    ASSERT_EQ(cache.size(), 2);
    cache.RemoveIn(cache2);
    ASSERT_FALSE(cache.Has(entity2->GetId()));
    ASSERT_EQ(cache.size(), 1);
}
