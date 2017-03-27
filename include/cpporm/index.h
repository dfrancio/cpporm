/*!
 * \file
 * \brief     Index class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

#include <cpporm/util/macros.h>

CPPORM_BEGIN_NAMESPACE

/*
 * Forward declarations
 */
class Entity;
class Attribute;
class PropertyMap;
class AttributeMap;

/*!
 * \brief %Index
 */
class CPPORM_EXPORT Index
{
public:
    /*!
     * \brief Get name
     * \return The index name
     */
    virtual const std::string &GetName() const = 0;

    /*!
     * \brief Get properties
     * \return The index properties
     */
    virtual const PropertyMap &GetProperties() const = 0;

    /*!
     * \brief Get attributes
     * \return The index attributes
     */
    virtual const AttributeMap &GetAttributes() const = 0;
};

CPPORM_END_NAMESPACE
