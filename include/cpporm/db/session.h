/*!
 * \file
 * \brief     Session class
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
class Entity;
class Relationship;
CPPORM_END_NAMESPACE

CPPORM_BEGIN_SUB_NAMESPACE(db)

/*
 * Forward declarations
 */
class Cache;
class Criteria;
class Context;
class Connection;

/*!
 * \brief Database session
 */
class CPPORM_EXPORT Session
{
public:
    /*!
     * \brief Destructor
     */
    virtual ~Session();

    /*!
     * \brief Add entity
     * \param[in] entity The entity pointer
     */
    void Add(const std::shared_ptr<Entity> &entity);

    /*!
     * \brief Get entity
     * \param[in] uniqueId The entity unique ID
     * \return The entity pointer
     */
    std::shared_ptr<Entity> Get(const std::string &uniqueId);

    /*
     * \brief Find entities
     * \param[in] prototype The entity prototype
     * \param[in] criteria The search criteria
     * \return The list of entity unique IDs
     */
    std::vector<std::string> Find(Entity &prototype, const db::Criteria &criteria);

    /*!
     * \brief Update entity
     * \param[in] entity The entity
     */
    void Update(Entity &entity);

    /*!
     * \brief Delete entity
     * \param[in] entity The entity
     */
    void Delete(Entity &entity);

    /*!
     * \brief Get connection
     * \return The connection
     */
    virtual Connection &GetConnection() = 0;

protected:
    /*!
     * \brief Befriend class Transaction
     */
    friend class Transaction;

    /*!
     * \brief Befriend class Relationship
     */
    friend class cpporm::Relationship;

    /*!
     * \brief Get cache
     * \return The cache
     */
    virtual Cache &GetCache() = 0;

    /*!
     * \brief Get context
     * \return The context
     */
    virtual Context &GetContext() = 0;

    /*!
     * \brief Remove entity from cache
     * \param[in] entity The entity
     */
    void RemoveFromCache(Entity &entity);

    /*!
     * \brief Fetch entity from the database
     * \param[in] entity The entity
     */
    virtual void FetchFromDatabase(Entity &entity);

    /*!
     * \brief Insert entity into the database
     * \param[in] entity The entity
     */
    virtual void InsertIntoDatabase(Entity &entity);

    /*!
     * \brief Update entity in the database
     * \param[in] entity The entity
     */
    virtual void UpdateInDatabase(Entity &entity);

    /*!
     * \brief Delete entity from the database
     * \param[in] entity The entity
     */
    virtual void DeleteFromDatabase(Entity &entity);
};

CPPORM_END_SUB_NAMESPACE
