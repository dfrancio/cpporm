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

CPPORM_BEGIN_NAMESPACE
/*! \brief Namespace db */
namespace db
{
}
CPPORM_END_NAMESPACE

CPPORM_BEGIN_SUB_NAMESPACE(db)

/*!
 * \brief Database cache
 */
class CPPORM_EXPORT Cache : public util::StringMap<std::shared_ptr<Entity>>
{
public:
    /*!
     * \brief The object type
     */
    typedef StringMap::mapped_type Object;

    /*!
     * \brief Commit entities
     */
    void Commit();

    /*!
     * \brief Rollback entities
     */
    void Rollback();

    /*!
     * \brief Push state
     */
    void PushState();

    /*!
     * \brief Add value
     * \param[in] name The entry name
     * \param[in] value The mapped value
     * \return True if the value was inserted; false otherwise
     */
    bool Add(const std::string &name, const Object &value);

    /*!
     * \brief Remove entity
     * \param[in] name The entry name
     */
    void Remove(const std::string &name);

    /*!
     * \brief Rename entry
     * \param[in] from The source name
     * \param[in] to The target name
     */
    void Rename(const std::string &from, const std::string &to);

    /*!
     * \brief Copy from another map
     * \param[in] map The map
     */
    void CopyFrom(const Cache &map);

    /*!
     * \brief Remove entries that exist in another map
     * \param[in] map The map
     */
    void RemoveIn(const Cache &map);
};

CPPORM_END_SUB_NAMESPACE
