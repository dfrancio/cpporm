/*!
 * \file
 * \brief     Map classes
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

#include <cpporm/util/stringmap.h>

CPPORM_BEGIN_NAMESPACE

/*
 * Forward declarations
 */
class Attribute;
class Entity;
class Index;
class Relationship;

/*!
 * \brief Attribute function
 * \param[in] entity The entity
 * \return The attribute
 */
typedef Attribute &(AttributeFunction)(Entity &entity);

/*!
 * \brief Relationship function
 * \param[in] entity The entity
 * \return The relationship
 */
typedef Relationship &(RelationshipFunction)(Entity &entity);

/*!
 * \brief Container that maps string keys to string values
 *
 * Usage example:
 *
 * ~~~{.cpp}
 * void test()
 * {
 *     cpporm::PropertyMap map = {{"A", "1"}};
 *     assert(map.Get("A") == "1");
 * }
 * ~~~
 */
class PropertyMap : public util::StringMap<std::string>
{
    using StringMap::StringMap;
};

/*!
 * \brief Container that maps string keys to attribute functions
 *
 * Usage example:
 *
 * ~~~{.cpp}
 * void test()
 * {
 *     MyEntity entity;
 *     cpporm::AttributeMap map = {CPPORM_MAP_ATTRIBUTE(MyEntity, attr)};
 *     assert(&map.Get("attr")(entity) == &entity.attr);
 * }
 * ~~~
 */
class AttributeMap : public util::StringMap<std::function<AttributeFunction>>
{
    using StringMap::StringMap;
};

/*!
 * \brief Container that maps string keys to indices
 *
 * Usage example:
 *
 * ~~~{.cpp}
 * void test()
 * {
 *     MyEntity entity;
 *     cpporm::IndexMap map = {CPPORM_MAP_INDEX(MyEntity, primary_key)};
 *     assert(&map.Get("primary_key") == &entity.primary_key);
 * }
 * ~~~
 */
class IndexMap : public util::StringMap<const Index *>
{
    using StringMap::StringMap;
};

/*!
 * \brief Container that maps string keys to relationship functions
 *
 * Usage example:
 *
 * ~~~{.cpp}
 * void test()
 * {
 *     MyEntity entity;
 *     cpporm::RelationshipMap map = {CPPORM_MAP_RELATIONSHIP(MyEntity, attr_MyEntity)};
 *     assert(&map.Get("attr_MyEntity") == &entity.attr_MyEntity);
 * }
 * ~~~
 */
class RelationshipMap : public util::StringMap<std::function<RelationshipFunction>>
{
    using StringMap::StringMap;
};

CPPORM_END_NAMESPACE
