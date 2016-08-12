/*!
 * \file
 * \brief     Cache class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#include <cpporm/db/cache.h>

// Internal library includes
#include <cpporm/entity.h>

CPPORM_BEGIN_SUB_NAMESPACE(db)

/*!
 * \details
 */
void Cache::Commit()
{
    for (auto &pair : *this)
        pair.second->Commit();
}

/*!
 * \details
 */
void Cache::Rollback()
{
    for (auto &pair : *this)
        pair.second->Rollback();
}

/*!
 * \details
 */
void Cache::PushState()
{
    for (auto &pair : *this)
        pair.second->PushState();
}

/*!
 * \details
 */
bool Cache::Add(const std::string &name, const Object &value)
{
    return this->emplace(name, value).second;
}

/*!
 * \details
 */
void Cache::Remove(const std::string &name)
{
    auto it = this->find(name);
    if (it != this->end())
        this->erase(it);
}

/*!
 * \details
 */
void Cache::Rename(const std::string &from, const std::string &to)
{
    if (from != to)
    {
        auto it = this->find(from);
        if (it != this->end())
        {
            (*this)[to] = it->second;
            this->erase(it);
        }
    }
}

/*!
 * \details
 */
void Cache::CopyFrom(const Cache &map)
{
    this->insert(map.begin(), map.end());
}

/*!
 * \details
 */
void Cache::RemoveIn(const Cache &map)
{
    for (auto &pair : map)
    {
        auto it = this->find(pair.first);
        if (it != this->end())
            this->erase(it);
    }
}

CPPORM_END_SUB_NAMESPACE
