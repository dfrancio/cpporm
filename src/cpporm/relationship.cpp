/*!
 * \file
 * \brief     Relationship class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#include <cpporm/relationship.h>

// Internal library includes
#include <cpporm/attribute.h>
#include <cpporm/db/criteria.h>
#include <cpporm/db/session.h>
#include <cpporm/entity.h>
#include <cpporm/maps.h>

CPPORM_BEGIN_NAMESPACE

/*!
 * \details
 */
Relationship::~Relationship()
{
}

/*!
 * \details
 */
void Relationship::Invalidate()
{
}

/*!
 * \details
 */
void Relationship::Dissolve()
{
}

/*!
 * \details
 */
void Relationship::Unrelate()
{
}

/*!
 * \details
 */
Relationship::Relationship(Entity &parent) : mParent(parent)
{
}

/*!
 * \details
 */
db::Session *Relationship::GetSession() const
{
    return mParent.mSession;
}

/*!
 * \details
 */
void Relationship::RemoveParent() const
{
    mParent.mSession->RemoveFromCache(mParent);
}

/*!
 * \details
 */
void Relationship::SetCachedOnly(db::Criteria &criteria, bool value) const
{
    criteria.SetCachedOnly(value);
}

/*!
 * \details
 */
ToOneRelationship::operator bool()
{
    Load();
    return get();
}

/*!
 * \details
 */
bool ToOneRelationship::operator==(const ToOneRelationship &other)
{
    Load();
    return get() == other.get();
}

/*!
 * \details
 */
bool ToOneRelationship::operator!=(const ToOneRelationship &other)
{
    Load();
    return get() != other.get();
}

/*!
 * \details
 */
void ToOneRelationship::Invalidate()
{
    mInvalidated = true;
}

/*!
 * \details
 */
void ToOneRelationship::Unrelate()
{
    auto &action = GetProperties().Get(CPPORM_PROP_ON_DELETE, CPPORM_ON_DELETE_NO_ACTION);
    if (action == CPPORM_ON_DELETE_SET_NULL)
        SetForeignKeyNull();
    else if (action == CPPORM_ON_DELETE_CASCADE)
        RemoveParent();
    else if (action == CPPORM_ON_DELETE_NO_ACTION)
        throw CannotDeleteEntity(mParent.GetId(), "foreign key", GetName(), "requires no action");
}

/*!
 * \details
 */
void ToOneRelationship::Load()
{
    assert(GetSession());
    if (!mInvalidated)
        return;

    if (IsForeignKeyNull())
    {
        if (get())
            reset();
    }
    else if (!get() || WasForeignKeyUpdated())
    {
        db::Criteria criteria;
        auto it1 = GetForeignKeyNames().begin();
        for (auto it2 = GetReferencedNames().begin(); it2 != GetReferencedNames().end();
             ++it1, ++it2)
            criteria.AddCondition(*it2, db::Condition::equal, mParent[*it1].Get());

        auto ids = GetSession()->Find(GetPrototype(), criteria);
        if (ids.empty())
            throw EntityNonExistentError(
                "could not find the required entity for this relationship", GetName(),
                "perhaps its primary key was altered?");

        std::shared_ptr<Entity>::operator=(GetSession()->Get(ids[0]));
        assert(get());
    }
    mInvalidated = false;
}

/*!
 * \details
 */
void ToOneRelationship::SetForeignKeyNull()
{
    for (const auto &name : GetForeignKeyNames())
    {
        auto &attr = mParent[name];
        if (attr.GetProperties().Has(CPPORM_PROP_NOT_NULL))
            throw CannotDeleteEntity(
                mParent.GetId(), "foreign key", GetName(), "attribute", name, "referenced by",
                mParent.GetId(), "does not allow nulls");
        attr.SetNull();
    }
    reset();
}

/*!
 * \details
 */
bool ToOneRelationship::IsForeignKeyNull() const
{
    for (const auto &name : GetForeignKeyNames())
        if (!mParent[name].IsNull())
            return false;
    return true;
}

/*!
 * \details
 */
bool ToOneRelationship::WasForeignKeyUpdated() const
{
    auto it1 = GetForeignKeyNames().begin();
    auto it2 = GetReferencedNames().begin();
    while (it2 != GetReferencedNames().end() && mParent[*it1] == (*get())[*it2])
    {
        ++it1;
        ++it2;
    }
    return it2 != GetReferencedNames().end();
}

/*!
 * \details
 */
void ToManyRelationship::Dissolve()
{
    Load(true);
    for (auto &pointer : *this)
        if (pointer->GetRelationships().Has(GetReciprocalName()))
            pointer->GetRelationship(GetReciprocalName()).Unrelate();
    clear();
}

/*!
 * \details
 */
void ToManyRelationship::Load(bool cachedOnly)
{
    assert(GetSession());

    db::Criteria criteria;
    auto it1 = GetForeignKeyNames().begin();
    for (auto it2 = GetReferencedNames().begin(); it2 != GetReferencedNames().end(); ++it1, ++it2)
        criteria.AddCondition(*it1, db::Condition::equal, mParent[*it2].Get());
    SetCachedOnly(criteria, cachedOnly);

    auto ids = GetSession()->Find(GetPrototype(), criteria);
    reserve(ids.size());
    for (auto &id : ids)
        push_back(GetSession()->Get(id));
}

CPPORM_END_NAMESPACE
