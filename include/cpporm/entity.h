/*!
 * \file
 * \brief     Entity class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

#include <cpporm/util/preprocessor.h>

CPPORM_BEGIN_NAMESPACE

/*
 * Forward declarations
 */
namespace db
{
class Session;
class Cursor;
class Query;
class Statement;
}
class Attribute;
class Entity;
class Index;
class Relationship;
class PropertyMap;
class AttributeMap;
class RelationshipMap;
class IndexMap;

/*!
 * \brief %Entity
 */
class CPPORM_EXPORT Entity
{
public:
    /*!
     * \brief Destructor
     */
    virtual ~Entity();

    /*!
     * \brief Clone
     * \return The cloned entity
     */
    virtual Entity *Clone() const = 0;

    /*!
     * \brief Get name
     * \return The entity name
     */
    virtual const std::string &GetName() const = 0;

    /*!
     * \brief Get properties
     * \return The entity properties
     */
    virtual const PropertyMap &GetProperties() const = 0;

    /*!
     * \brief Get attributes
     * \return The entity attributes
     */
    virtual const AttributeMap &GetAttributes() const = 0;

    /*!
     * \brief Get relationships
     * \return The entity relationships
     */
    virtual const RelationshipMap &GetRelationships() const = 0;

    /*!
     * \brief Get indices
     * \return The entity indices
     */
    virtual const IndexMap &GetIndices() const = 0;

    /*!
     * \brief Get primary key
     * \return The primary key
     */
    const AttributeMap &GetPrimaryKey() const;

    /*!
     * \brief Get version fields
     * \return The version fields
     */
    const AttributeMap &GetVersionFields() const;

    /*!
     * \brief operator[]
     * \param[in] name The attribute name
     * \return The attribute
     */
    Attribute &operator[](const std::string &name);

    /*!
     * \brief Get relationship
     * \param[in] name The relationship name
     * \return The relationship
     */
    Relationship &GetRelationship(const std::string &name);

    /*!
     * \brief Set session
     * \param[in] session The database session
     */
    void SetSession(db::Session *session);

    /*!
     * \brief Get unique ID
     * \return The unique ID
     */
    const std::string &GetId();

    /*!
     * \brief Reset unique ID
     */
    void ResetId();

    /*!
     * \brief Was modified?
     * \return True, if the entity was modified; false otherwise
     */
    bool WasModified();

    /*!
     * \brief Mark for removal
     * \return True, if the entity was previously marked for removal; false otherwise
     */
    bool MarkForRemoval();

    /*!
     * \brief Rollback
     */
    void Rollback();

    /*!
     * \brief Commit
     */
    void Commit();

    /*!
     * \brief Push state
     */
    void PushState();

    /*!
     * \brief Extract
     * \param[in] cursor The database cursor
     */
    void Extract(db::Cursor &cursor);

    /*!
     * \brief Save primary key
     */
    void SavePrimaryKey();

    /*!
     * \brief Fetch from database
     * \param[in] query The database query
     */
    void Fetch(db::Query &query);

    /*!
     * \brief Fetch last inserted id
     * \param[in] query The database query
     */
    void FetchLastId(db::Query &query);

    /*!
     * \brief Fetch primary key
     * \param[in] query The database query
     */
    void FetchPrimaryKey(db::Query &query);

    /*!
     * \brief Insert into database
     * \param[in] query The database query
     */
    void Insert(db::Query &query);

    /*!
     * \brief Update in database
     * \param[in] query The database query
     */
    void Update(db::Query &query);

    /*!
     * \brief Delete from database
     * \param[in] query The database query
     */
    void Delete(db::Query &query);

    /*!
     * \brief Add where clause
     * \param[in] query The database query
     */
    void Where(db::Query &query);

    /*!
     * \brief Bind to statement
     * \param[in] statement The database statement
     */
    void Bind(db::Statement &statement);

    /*!
     * \brief Bind primarey key to statement
     * \param[in] statement The database statement
     */
    void BindPrimaryKey(db::Statement &statement);

    /*!
     * \brief Validate database schema
     */
    void ValidateSchema() const;

    /*!
     * \brief Create database schema
     * \param[in] query The database query
     */
    void CreateSchema(db::Query &query) const;

    /*!
     * \brief Reload relationships
     */
    void ReloadRelationships();

    /*!
     * \brief Dissolve relationships
     */
    void DissolveRelationships();

protected:
    /*!
     * \brief Befriend class Relationship
     */
    friend class Relationship;

    /*!
     * \brief The database session
     */
    db::Session *mSession;

private:
    /*!
     * \brief The unique ID
     */
    std::string mUniqueId;

    /*!
     * \brief A flag to indicate whether the entity is marked for update
     */
    bool mIsMarkedForUpdate = false;

    /*!
     * \brief A flag to indicate whether the entity is marked for removal
     */
    bool mIsMarkedForRemoval = false;
};

CPPORM_END_NAMESPACE
