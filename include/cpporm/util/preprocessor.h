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

// Unpack variadic template
#define CPPORM_UNPACK(X)                                                                           \
    {                                                                                              \
        int unpack[]{0, (X, 0)...};                                                                \
        static_cast<void>(unpack);                                                                 \
    }

// Predefined property names
#define CPPORM_PROP_NOT_NULL "NOT_NULL"
#define CPPORM_PROP_IDENTITY "IDENTITY"
#define CPPORM_PROP_DEFAULT "DEFAULT"
#define CPPORM_PROP_ON_UPDATE "ON_UPDATE"
#define CPPORM_PROP_ON_DELETE "ON_DELETE"
#define CPPORM_PROP_DATA_TYPE "DATA_TYPE"
#define CPPORM_PROP_LENGTH "LENGTH"
#define CPPORM_PROP_DECIMALS "DECIMALS"

// Predefined on-delete actions
#define CPPORM_ON_DELETE_SET_NULL "SET NULL"
#define CPPORM_ON_DELETE_CASCADE "CASCADE"
#define CPPORM_ON_DELETE_NO_ACTION "NO ACTION"

// Predefined index names
#define CPPORM_INDEX_PRIMARY_KEY "primary_key"
#define CPPORM_INDEX_FOREIGN_KEY "foreign_key"
#define CPPORM_INDEX_UNIQUE "unique"
#define CPPORM_INDEX_VERSION "version_fields"

// Query utilities
#define CPPORM_PLACEHOLDER_MARK "?"
#define CPPORM_ADD_TABLE_SCOPE(table) ((table) == "" ? "" : std::string(table) + ".")

// Factory utilities
#define CPPORM_REGISTER(factory, derived, varname, keys...)                                        \
    static const cpporm::util::FactoryRegister<factory, derived> c##varname##Reg(keys)

// Map utilities
#define CPPORM_MAP_ATTRIBUTE(ent, att)                                                             \
    {                                                                                              \
        #att, [](cpporm::Entity &entity)                                                           \
                     -> cpporm::Attribute & { return static_cast<ent &>(entity).att; }             \
    }
#define CPPORM_MAP_INDEX(ent, ind)                                                                 \
    {                                                                                              \
        #ind, &ent::ind                                                                            \
    }
#define CPPORM_MAP_RELATIONSHIP(ent, rel)                                                          \
    {                                                                                              \
        #rel, [](cpporm::Entity &entity)                                                           \
                     -> cpporm::Relationship & { return static_cast<ent &>(entity).rel; }          \
    }

// Exception utilities
#define CPPORM_VISBILITY_DEFAULT __attribute__((visibility("default")))
#define CPPORM_DECLARE_EXCEPTION(name, msg, base)                                                  \
    class CPPORM_VISBILITY_DEFAULT name : public base                                              \
    {                                                                                              \
    public:                                                                                        \
        template <typename... Args>                                                                \
        name(Args &&... args) : base(msg, std::forward<Args>(args)...)                             \
        {                                                                                          \
        }                                                                                          \
    }

// Client class declarations
#define CPPORM_DECLARE_ENTITY(name, specs...) class specs name : public cpporm::Entity
#define CPPORM_DECLARE_ENTITY_METHODS                                                              \
public:                                                                                            \
    cpporm::Entity *Clone() const override;                                                        \
    const std::string &GetName() const override;                                                   \
    const cpporm::PropertyMap &GetProperties() const override;                                     \
    const cpporm::AttributeMap &GetAttributes() const override;                                    \
    const cpporm::RelationshipMap &GetRelationships() const override;                              \
    const cpporm::IndexMap &GetIndices() const override
#define CPPORM_DECLARE_ATTRIBUTE(name)                                                             \
    class _attribute##_##name : public cpporm::Attribute                                           \
    {                                                                                              \
    public:                                                                                        \
        const std::string &GetName() const override;                                               \
        const cpporm::PropertyMap &GetProperties() const override;                                 \
        _attribute##_##name &operator=(const Attribute &other);                                    \
        _attribute##_##name &operator=(const std::string &value);                                  \
    } name
#define CPPORM_DECLARE_INDEX(name)                                                                 \
    static class _index##_##name : public cpporm::Index                                            \
    {                                                                                              \
    public:                                                                                        \
        const std::string &GetName() const override;                                               \
        const cpporm::PropertyMap &GetProperties() const override;                                 \
        const cpporm::AttributeMap &GetAttributes() const override;                                \
    } name
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
