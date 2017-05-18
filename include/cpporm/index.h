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
 * \brief Abstract class to represent database indices
 *
 * An index maps a C++ object to a database index. All indices should derive from this class. It has
 * a name, a set of properties and a set of attributes, all being static members of the derived
 * class. It does not contain any internal state.
 *
 * Usage example:
 *
 * ~~~{.cpp}
 * MyAttribute attr;
 *
 * class MyIndex : public cpporm::Index
 * {
 *     const std::string &MyIndex::GetName() const
 *     {
 *         static const std::string cName = "primary_key";
 *         return cName;
 *     }
 *     const cpporm::PropertyMap &MyIndex::GetProperties() const
 *     {
 *         static const cpporm::PropertyMap cMap;
 *         return cMap;
 *     }
 *     const cpporm::AttributeMap &MyIndex::GetAttributes() const
 *     {
 *         static const cpporm::AttributeMap cMap = {CPPORM_MAP_ATTRIBUTE(MyEntity, attr)};
 *         return cMap;
 *     }
 * };
 * ~~~
 */
class CPPORM_EXPORT Index
{
public:
    /*!
     * \brief Get index name
     * \return The index name
     */
    virtual const std::string &GetName() const = 0;

    /*!
     * \brief Get index properties
     * \return The index properties
     */
    virtual const PropertyMap &GetProperties() const = 0;

    /*!
     * \brief Get index attributes
     * \return The index attributes
     */
    virtual const AttributeMap &GetAttributes() const = 0;
};

/*!
 * \example index.cpp
 *
 * This is an example of how to use the Index class.
 */

CPPORM_END_NAMESPACE
