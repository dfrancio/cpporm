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
 */
typedef Attribute &(AttributeFunction)(Entity &entity);

/*!
 * \brief Relationship function
 */
typedef Relationship &(RelationshipFunction)(Entity &entity);

/*!
 * \brief Property map
 */
class PropertyMap : public util::StringMap<std::string>
{
    using StringMap::StringMap;
};

/*!
 * \brief Attribute map
 */
class AttributeMap : public util::StringMap<std::function<AttributeFunction>>
{
    using StringMap::StringMap;
};

/*!
 * \brief Index map
 */
class IndexMap : public util::StringMap<const Index *>
{
    using StringMap::StringMap;
};

/*!
 * \brief Relationship map
 */
class RelationshipMap : public util::StringMap<std::function<RelationshipFunction>>
{
    using StringMap::StringMap;
};

CPPORM_END_NAMESPACE
