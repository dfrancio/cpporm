/*!
 * \file
 * \brief     Cache class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

#include <cpporm/util/stringmap.h>

/*
 * Forward declarations
 */
CPPORM_BEGIN_NAMESPACE
class Entity;
CPPORM_END_NAMESPACE

CPPORM_BEGIN_SUB_NAMESPACE(db)

/*!
 * \brief Class that implements database caching
 *
 * The cache maintains a copy of the information stored in a database. It does not have all the
 * data, but only that which was fetched from the database. Once this data is loaded to the cache,
 * it will remain in memory for the lifetime of the cache instance. It is possible to update or
 * remove the data associated with a database entity. Each entity has a unique ID which identifies
 * the entity in the cache. Itis  also possible to change the ID of an entity.
 *
 * Transaction and savepoint semantics are valid for cache objects.
 */
class CPPORM_EXPORT Cache : public util::StringMap<std::shared_ptr<Entity>>
{
public:
    /*!
     * \brief The object type
     */
    typedef StringMap::mapped_type Object;

    /*!
     * \brief Commit entities in the cache
     */
    void Commit();

    /*!
     * \brief Rollback entities in the cache
     */
    void Rollback();

    /*!
     * \brief Push state of the cache
     */
    void PushState();

    /*!
     * \brief Add entity to the cache
     * \param[in] id The entity id
     * \param[in] entity The mapped value
     * \return True if the entity was inserted; false otherwise
     */
    bool Add(const std::string &id, const Object &entity);

    /*!
     * \brief Remove entity from the cache
     * \param[in] id The entity id
     */
    void Remove(const std::string &id);

    /*!
     * \brief Rename entity in the cache
     * \param[in] from The old entity id
     * \param[in] to The new entity id
     */
    void Rename(const std::string &from, const std::string &to);

    /*!
     * \brief Copy entities from another cache
     * \param[in] map The map
     */
    void CopyFrom(const Cache &map);

    /*!
     * \brief Remove entities that exist in another cache
     * \param[in] map The map
     */
    void RemoveIn(const Cache &map);
};

CPPORM_END_SUB_NAMESPACE
