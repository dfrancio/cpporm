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
 */
class PropertyMap : public util::StringMap<std::string>
{
    using StringMap::StringMap;
};

/*!
 * \brief Container that maps string keys to attribute functions
 */
class AttributeMap : public util::StringMap<std::function<AttributeFunction>>
{
    using StringMap::StringMap;
};

/*!
 * \brief Container that maps string keys to indices
 */
class IndexMap : public util::StringMap<const Index *>
{
    using StringMap::StringMap;
};

/*!
 * \brief Container that maps string keys to relationship functions
 */
class RelationshipMap : public util::StringMap<std::function<RelationshipFunction>>
{
    using StringMap::StringMap;
};

/*!
 * \example cpporm/maps.cpp
 *
 * This is an example of how to use the various map classes.
 */

CPPORM_END_NAMESPACE
