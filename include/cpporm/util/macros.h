/*!
 * \file
 * \brief     Preprocessor macros
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#pragma once

// C library includes
#include <cassert>
#include <cstring>

// C++ library includes
#include <algorithm>
#include <chrono>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

// Internal library includes
#include <cpporm/config.h>
#include <cpporm/export.h>

/*!
 * \internal
 * \brief Unpack a variadic template
 */
#define CPPORM_UNPACK(X)                                                                           \
    {                                                                                              \
        int unpack[]{0, (X, 0)...};                                                                \
        static_cast<void>(unpack);                                                                 \
    }

/*!
 * \brief Attribute property NOT NULL
 */
#define CPPORM_PROP_NOT_NULL "NOT_NULL"

/*!
 * \brief Attribute property IDENTITY
 */
#define CPPORM_PROP_IDENTITY "IDENTITY"

/*!
 * \brief Attribute property DEFAULT
 */
#define CPPORM_PROP_DEFAULT "DEFAULT"

/*!
 * \brief Attribute property ON UPDATE
 */
#define CPPORM_PROP_ON_UPDATE "ON_UPDATE"

/*!
 * \brief Attribute property ON DELETE
 */
#define CPPORM_PROP_ON_DELETE "ON_DELETE"

/*!
 * \brief Attribute property DATA TYPE
 */
#define CPPORM_PROP_DATA_TYPE "DATA_TYPE"

/*!
 * \brief Attribute property LENGTH
 */
#define CPPORM_PROP_LENGTH "LENGTH"

/*!
 * \brief Attribute property DECIMALS
 */
#define CPPORM_PROP_DECIMALS "DECIMALS"

/*!
 * \brief Attribute property USE GUID
 */
#define CPPORM_PROP_USE_GUID "USE_GUID"

/*!
 * \brief Relationship on delete action SET NULL
 */
#define CPPORM_ON_DELETE_SET_NULL "SET NULL"

/*!
 * \brief Relationship on delete action CASCADE
 */
#define CPPORM_ON_DELETE_CASCADE "CASCADE"

/*!
 * \brief Relationship on delete action NO ACTION
 */
#define CPPORM_ON_DELETE_NO_ACTION "NO ACTION"

/*!
 * \brief Primary key index name
 */
#define CPPORM_INDEX_PRIMARY_KEY "primary_key"

/*!
 * \brief Foreign key index name
 */
#define CPPORM_INDEX_FOREIGN_KEY "foreign_key"

/*!
 * \brief Unique index name
 */
#define CPPORM_INDEX_UNIQUE "unique"

/*!
 * \brief Version fields index name
 */
#define CPPORM_INDEX_VERSION "version_fields"

/*!
 * \internal
 * \brief Query placeholder character
 */
#define CPPORM_PLACEHOLDER_MARK "?"

/*!
 * \internal
 * \brief Add table scope in queries
 */
#define CPPORM_ADD_TABLE_SCOPE(table) ((table) == "" ? "" : std::string(table) + ".")

/*!
 * \brief Register type with a key in factory
 *
 * Usage example:
 *
 * ~~~{.cpp}
 * CPPORM_REGISTER(SerializerFactory, cpporm::Serializer, cpporm, "cpporm");
 * ~~~
 */
#define CPPORM_REGISTER(factory, derived, varname, keys...)                                        \
    static const cpporm::util::FactoryRegister<factory, derived> c##varname##Reg(keys)

/*!
 * \brief Map an attribute name to an attribute object
 *
 * Usage example:
 *
 * ~~~{.cpp}
   static const cpporm::AttributeMap cMap = {CPPORM_MAP_ATTRIBUTE(MyEntity, attr)};
 * ~~~
 */
#define CPPORM_MAP_ATTRIBUTE(ent, att)                                                             \
    {                                                                                              \
        #att, [](cpporm::Entity &entity)                                                           \
                     -> cpporm::Attribute & { return static_cast<ent &>(entity).att; }             \
    }

/*!
 * \brief Map an index name to an index object
 *
 * Usage example:
 *
 * ~~~{.cpp}
   static IndexMap map = {CPPORM_MAP_INDEX(MyEntity, primary_key)};
 * ~~~
 */
#define CPPORM_MAP_INDEX(ent, ind)                                                                 \
    {                                                                                              \
        #ind, &ent::ind                                                                            \
    }

/*!
 * \brief Map a relationship name to a relationship object
 *
 * Usage example:
 *
 * ~~~{.cpp}
  static const cpporm::RelationshipMap cMap = {CPPORM_MAP_RELATIONSHIP(MyEntity, attr_MyEntity)};
 * ~~~
 */
#define CPPORM_MAP_RELATIONSHIP(ent, rel)                                                          \
    {                                                                                              \
        #rel, [](cpporm::Entity &entity)                                                           \
                     -> cpporm::Relationship & { return static_cast<ent &>(entity).rel; }          \
    }

/*!
 * \brief Mark a class with default visibility
 *
 * Usage example:
 *
 * ~~~{.cpp}
 * class CPPORM_VISBILITY_DEFAULT MyClass
 * {
 * };
 * ~~~
 */
#define CPPORM_VISBILITY_DEFAULT __attribute__((visibility("default")))

/*!
 * \brief Declare a new type of exception
 *
 * Usage example:
 *
 * ~~~{.cpp}
 * CPPORM_DECLARE_EXCEPTION(MyError, "error message", Error);
 * ~~~
 */
#define CPPORM_DECLARE_EXCEPTION(name, msg, base)                                                  \
    class CPPORM_VISBILITY_DEFAULT name : public base                                              \
    {                                                                                              \
    public:                                                                                        \
        template <typename... Args>                                                                \
        name(Args &&... args) : base(msg, std::forward<Args>(args)...)                             \
        {                                                                                          \
        }                                                                                          \
    }

/*!
 * \brief Declare a new entity
 *
 * Usage example:
 *
 * ~~~{.cpp}
 * CPPORM_DECLARE_ENTITY(User)
 * {
 * };
 * ~~~
 */
#define CPPORM_DECLARE_ENTITY(name, specs...) class specs name : public cpporm::Entity

/*!
 * \brief Declare the entity methods
 *
 * Usage example:
 *
 * ~~~{.cpp}
 * CPPORM_DECLARE_ENTITY(User)
 * {
 *     CPPORM_DECLARE_ENTITY_METHODS;
 * };
 * ~~~
 */
#define CPPORM_DECLARE_ENTITY_METHODS                                                              \
public:                                                                                            \
    cpporm::Entity *Clone() const override;                                                        \
    const std::string &GetName() const override;                                                   \
    const cpporm::PropertyMap &GetProperties() const override;                                     \
    const cpporm::AttributeMap &GetAttributes() const override;                                    \
    const cpporm::RelationshipMap &GetRelationships() const override;                              \
    const cpporm::IndexMap &GetIndices() const override

/*!
 * \brief Declare the entity attributes
 *
 * Usage example:
 *
 * ~~~{.cpp}
 * CPPORM_DECLARE_ENTITY(User)
 * {
       CPPORM_DECLARE_ATTRIBUTE(id);
 * };
 * ~~~
 */
#define CPPORM_DECLARE_ATTRIBUTE(name)                                                             \
    class _attribute##_##name : public cpporm::Attribute                                           \
    {                                                                                              \
    public:                                                                                        \
        const std::string &GetName() const override;                                               \
        const cpporm::PropertyMap &GetProperties() const override;                                 \
        _attribute##_##name &operator=(const Attribute &other);                                    \
        _attribute##_##name &operator=(const std::string &value);                                  \
    } name

/*!
 * \brief Declare the entity indices
 *
 * Usage example:
 *
 * ~~~{.cpp}
 * CPPORM_DECLARE_ENTITY(User)
 * {
 *     CPPORM_DECLARE_INDEX(primary_key);
 * };
 * ~~~
 */
#define CPPORM_DECLARE_INDEX(name)                                                                 \
    static class _index##_##name : public cpporm::Index                                            \
    {                                                                                              \
    public:                                                                                        \
        const std::string &GetName() const override;                                               \
        const cpporm::PropertyMap &GetProperties() const override;                                 \
        const cpporm::AttributeMap &GetAttributes() const override;                                \
    } name

/*!
 * \brief Declare the entity to-one relationships
 *
 * Usage example:
 *
 * ~~~{.cpp}
 * CPPORM_DECLARE_ENTITY(User)
 * {
 *     CPPORM_DECLARE_TO_ONE_RELATIONSHIP(created_by_User, User);
 * };
 * ~~~
 */
#define CPPORM_DECLARE_TO_ONE_RELATIONSHIP(name, related)                                          \
    class _relationship##_##name : public cpporm::ToOneRelationship                                \
    {                                                                                              \
        using ToOneRelationship::ToOneRelationship;                                                \
                                                                                                   \
    public:                                                                                        \
        const std::string &GetName() const override;                                               \
        const cpporm::PropertyMap &GetProperties() const override;                                 \
        const std::vector<std::string> &GetForeignKeyNames() const override;                       \
        const std::vector<std::string> &GetReferencedNames() const override;                       \
        related *operator->();                                                                     \
        related &operator*();                                                                      \
                                                                                                   \
    protected:                                                                                     \
        const std::string &GetReciprocalName() const override;                                     \
        cpporm::Entity &GetPrototype() const override;                                             \
    } name = {*this}

/*!
 * \brief Declare the entity to-many relationships
 *
 * Usage example:
 *
 * ~~~{.cpp}
 * CPPORM_DECLARE_ENTITY(User)
 * {
 *     CPPORM_DECLARE_TO_MANY_RELATIONSHIP(all_User_created_by);
 * };
 * ~~~
 */
#define CPPORM_DECLARE_TO_MANY_RELATIONSHIP(name)                                                  \
    class _relationship##_##name : public cpporm::ToManyRelationship                               \
    {                                                                                              \
        using ToManyRelationship::ToManyRelationship;                                              \
                                                                                                   \
    public:                                                                                        \
        const std::string &GetName() const override;                                               \
        const cpporm::PropertyMap &GetProperties() const override;                                 \
        const std::vector<std::string> &GetForeignKeyNames() const override;                       \
        const std::vector<std::string> &GetReferencedNames() const override;                       \
                                                                                                   \
    protected:                                                                                     \
        const std::string &GetReciprocalName() const override;                                     \
        cpporm::Entity &GetPrototype() const override;                                             \
    } name = {*this}
