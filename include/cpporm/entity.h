/*!
 * \file
 * \brief     Entity class
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
 * \brief Abstract class to represent database tables
 *
 * An entity maps a C++ object to an entry in a database table. All entities should derive from this
 * class. It has a name, a set of properties and a set of indices, all being static members of the
 * derived class. It contains an internal state comprised of:
 *  1. a set of attributes, which correspond to the table cloumns
 *  2. a set of relationships, which correspond to the table foreign keys
 *
 * Transactions and savepoints can be used with entities. The entity attributes can be accessed and
 * modified polymorhpically by means of a container which maps column names to attributes.
 * Relationships can be accessed in a similar manner. This effectively implements a (rather
 * primitive) kind of object introspection mechanism.
 *
 * An entity can have a primary key. If there is no primary key declared in the database table, then
 * all attributes combined are considered as the primary key. This is needed to guarantee uniqueness
 * within the session cache.
 *
 * An entity can also have a version field. A version field is a set of attributes which indicates
 * the version of an entity. This is required for the optimistic locking strategy used in
 * concurrency control.
 *
 * One can loop through the entity relationships recusrively using a depth-first search procedure.
 *
 * There is a database session with which an entity can be associated, and a unique identifier for
 * the entity in the session cache. The nature of this identifier is implementation detail, and
 * should not matter for most users. There are methods for obtaining and resetting the ID.
 *
 * One can check if any of the entity attributes was modified since the last commit or since it was
 * constructed. It is also possible to rollback or save the internal state when using transactions.
 *
 * Some of the methods help in the construction of prepared statements, while others have to do with
 * the database schema of the database table being represented. Still others have do to with the
 * entity relationships.
 *
 * Finally, some convenience methods are provided which help in copying attributes from other
 * entities.
 *
 * \see Attribute
 * \see db::Session
 */
class CPPORM_EXPORT Entity
{
public:
    /*!
     * \brief Destructor
     */
    virtual ~Entity();

    /*!
     * \brief Clone entity
     * \return The cloned entity
     */
    virtual Entity *Clone() const = 0;

    /*!
     * \brief Get entity name
     * \return The entity name
     */
    virtual const std::string &GetName() const = 0;

    /*!
     * \brief Get entity properties
     * \return The entity properties
     */
    virtual const PropertyMap &GetProperties() const = 0;

    /*!
     * \brief Get entityattributes
     * \return The entity attributes
     */
    virtual const AttributeMap &GetAttributes() const = 0;

    /*!
     * \brief Get entity relationships
     * \return The entity relationships
     */
    virtual const RelationshipMap &GetRelationships() const = 0;

    /*!
     * \brief Get entity indices
     * \return The entity indices
     */
    virtual const IndexMap &GetIndices() const = 0;

    /*!
     * \brief Get entity primary key
     * \return The entity primary key
     */
    const AttributeMap &GetPrimaryKey() const;

    /*!
     * \brief Get entity version fields
     * \return The entity version fields
     */
    const AttributeMap &GetVersionFields() const;

    /*!
     * \brief Get entity attribute by name
     * \param[in] name The attribute name
     * \return The attribute
     */
    Attribute &operator[](const std::string &name);

    /*!
     * \brief Get entity attribute by name (const version)
     * \param[in] name The attribute name
     * \return The attribute
     */
    const Attribute &operator[](const std::string &name) const;

    /*!
     * \brief Get entity relationship by name
     * \param[in] name The relationship name
     * \return The relationship
     */
    Relationship &GetRelationship(const std::string &name);

    /*!
     * \brief Traverse result
     */
    enum class TraverseResult
    {
        ok, /*!< continue iterating */
        skip, /*!< skip this entity */
        halt /*!< halt the iteration and return */
    };

    /*!
     * \brief Traverse entity relationships
     * \param[in] function The function
     * \return The traverse result
     */
    TraverseResult TraverseRelationships(std::function<TraverseResult(Entity &)> function);

    /*!
     * \brief Associate entity with a database session
     * \param[in] session The database session
     */
    void SetSession(db::Session *session);

    /*!
     * \brief Get entity unique ID
     * \return The entity unique ID
     */
    const std::string &GetId();

    /*!
     * \brief Reset entity unique ID
     */
    void ResetId();

    /*!
     * \brief Check whether the entity was modified since last commit
     * \return True if the entity was modified; false otherwise
     */
    bool WasModified();

    /*!
     * \brief Mark entity for removal
     * \return True if the entity was previously marked for removal; false otherwise
     */
    bool MarkForRemoval();

    /*!
     * \brief Rollback entity internal state
     */
    void Rollback();

    /*!
     * \brief Commit entity internal state
     */
    void Commit();

    /*!
     * \brief Push entity internal state
     */
    void PushState();

    /*!
     * \brief Extract entity attributes
     * \param[in] cursor The database cursor
     */
    void Extract(db::Cursor &cursor);

    /*!
     * \brief Extract entity primary key
     * \param[in] cursor The database cursor
     */
    void ExtractPrimaryKey(db::Cursor &cursor);

    /*!
     * \brief Save entity primary key
     */
    void SavePrimaryKey();

    /*!
     * \brief Compose part of query needed to fetch the entity from the database
     * \param[in] query The database query
     */
    void Fetch(db::Query &query);

    /*!
     * \brief Compose part of query needed to fetch the last inserted ID from the database
     * \param[in] query The database query
     * \return True if there is a last insert id to be fetched; false otherwise
     */
    bool FetchLastId(db::Query &query);

    /*!
     * \brief Compose part of query needed to fetch the entity primary key from the database
     * \param[in] query The database query
     */
    void FetchPrimaryKey(db::Query &query);

    /*!
     * \brief Compose part of query needed to insert the entity into the database
     * \param[in] query The database query
     */
    void Insert(db::Query &query);

    /*!
     * \brief Compose part of query needed to insert the entity into a temporary database table
     * \param[in] query The database query
     */
    void InsertIntoTemp(db::Query &query);

    /*!
     * \brief Compose part of query needed to join the temporary database table
     * \param[in] query The database query
     */
    void JoinTemp(db::Query &query);

    /*!
     * \brief Compose part of query needed to update the entity in the database
     * \param[in] query The database query
     */
    void Update(db::Query &query);

    /*!
     * \brief Compose part of query needed to delete the entity from the database
     * \param[in] query The database query
     */
    void Delete(db::Query &query);

    /*!
     * \brief Compose part of query needed to lookup the entity in the database
     * \param[in] query The database query
     */
    void Where(db::Query &query);

    /*!
     * \brief Bind the entity attributes to a prepared statement
     * \param[in] statement The database statement
     */
    void Bind(db::Statement &statement);

    /*!
     * \brief Bind the primary key attributes of this entity to a prepared statement
     * \param[in] statement The database statement
     */
    void BindPrimaryKey(db::Statement &statement);

    /*!
     * \brief Validate the database schema of this entity
     */
    void ValidateSchema() const;

    /*!
     * \brief Compose part of query needed to create the database schema of this entity
     * \param[in] query The database query
     */
    void CreateSchema(db::Query &query) const;

    /*!
     * \brief Compose part of query needed to create the temporary database schema
     * \param[in] query The database query
     * \note Only the primary key attributes make up the temporary table
     */
    void CreateTempSchema(db::Query &query) const;

    /*!
     * \brief Compose part of query needed to erase the table associated with this entity
     * \param[in] query The database query
     */
    void EraseTable(db::Query &query) const;

    /*!
     * \brief Compose part of query needed to erase the temporary table associated with this entity
     * \param[in] query The database query
     */
    void EraseTempTable(db::Query &query) const;

    /*!
     * \brief Compose part of query needed to drop the database schema associated with this entity
     * \param[in] query The database query
     */
    void DropSchema(db::Query &query) const;

    /*!
     * \brief Compose part of query needed to drop the temporary database schema associated with
     * this entity
     * \param[in] query The database query
     */
    void DropTempSchema(db::Query &query) const;

    /*!
     * \brief Reload the entity relationships
     */
    void ReloadRelationships();

    /*!
     * \brief Dissolve the entity relationships
     */
    void DissolveRelationships();

    /*!
     * \brief Copy all attributes except primary key and version fields from another entity
     * \param[in] entity The other entity
     */
    void CopyFrom(Entity &entity);

    /*!
     * \brief Copy all attributes (including primary key and version fields) from another entity
     * \param[in] entity The other entity
     */
    void CopyAllFrom(Entity &entity);

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
     * \brief The entity unique ID
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

/*!
 * \example cpporm/entity.cpp
 *
 * This is an example of how to use the Entity class.
 */

CPPORM_END_NAMESPACE
