/*!
 * \file
 * \brief     Entity class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#include <cpporm/entity.h>

// Internal library includes
#include <cpporm/attribute.h>
#include <cpporm/db/query.h>
#include <cpporm/index.h>
#include <cpporm/maps.h>
#include <cpporm/relationship.h>

CPPORM_BEGIN_NAMESPACE

/*!
 * \details
 */
Entity::~Entity()
{
}

/*!
 * \details
 */
const AttributeMap &Entity::GetPrimaryKey() const
{
    return GetIndices().Has(CPPORM_INDEX_PRIMARY_KEY)
        ? GetIndices().Get(CPPORM_INDEX_PRIMARY_KEY)->GetAttributes()
        : GetAttributes();
}

/*!
 * \details
 */
const AttributeMap &Entity::GetVersionFields() const
{
    static const AttributeMap cEmptyMap = {};
    return GetIndices().Has(CPPORM_INDEX_VERSION)
        ? GetIndices().Get(CPPORM_INDEX_VERSION)->GetAttributes()
        : cEmptyMap;
}

/*!
 * \details
 */
Attribute &Entity::operator[](const std::string &name)
{
    return GetAttributes().Get(name)(*this);
}

/*!
 * \details
 */
Relationship &Entity::GetRelationship(const std::string &name)
{
    return GetRelationships().Get(name)(*this);
}

/*!
 * \details
 */
void Entity::SetSession(db::Session *session)
{
    mSession = session;
}

/*!
 * \details
 */
const std::string &Entity::GetId()
{
    if (mUniqueId.empty())
        ResetId();
    return mUniqueId;
}

/*!
 * \details
 */
void Entity::ResetId()
{
    mUniqueId = GetName();
    for (const auto &pair : GetPrimaryKey())
        mUniqueId += pair.second(*this).Get();
}

/*!
 * \details
 */
bool Entity::WasModified()
{
    for (const auto &pair : GetAttributes())
        if (pair.second(*this).WasModified())
            return true;
    return false;
}

/*!
 * \details
 */
bool Entity::MarkForRemoval()
{
    if (!mIsMarkedForRemoval)
    {
        mIsMarkedForRemoval = true;
        return false;
    }
    return true;
}

/*!
 * \details
 */
void Entity::Rollback()
{
    for (const auto &pair : GetAttributes())
        pair.second(*this).Rollback();
    if (mIsMarkedForRemoval)
        mIsMarkedForRemoval = false;
    if (mIsMarkedForUpdate)
        mIsMarkedForUpdate = false;
    mUniqueId.clear();
}

/*!
 * \details
 */
void Entity::Commit()
{
    for (const auto &pair : GetAttributes())
        pair.second(*this).Commit();
}

/*!
 * \details
 */
void Entity::PushState()
{
    for (const auto &pair : GetAttributes())
        pair.second(*this).PushState();
}

/*!
 * \details
 */
void Entity::Extract(db::Cursor &cursor)
{
    for (const auto &pair : GetAttributes())
        pair.second(*this).Extract(cursor);
    ResetId();
}

/*!
 * \details
 */
void Entity::ExtractPrimaryKey(db::Cursor &cursor)
{
    for (const auto &pair : GetPrimaryKey())
        pair.second(*this).Extract(cursor);
    ResetId();
}

/*!
 * \details
 */
void Entity::SavePrimaryKey()
{
    for (const auto &pair : GetPrimaryKey())
        pair.second(*this).SaveState();
    mIsMarkedForUpdate = false;
}

/*!
 * \details
 */
void Entity::Fetch(db::Query &query)
{
    query.SelectAll().From(GetName());
}

/*!
 * \details
 */
bool Entity::FetchLastId(db::Query &query)
{
    for (const auto &pair : GetPrimaryKey())
    {
        const auto &attr = pair.second(*this);
        if (attr.GetProperties().Has(CPPORM_PROP_IDENTITY))
        {
            query.Select().LastInsertId().As(attr.GetName());
            return true;
        }
    }
    return false;
}

/*!
 * \details
 */
void Entity::FetchPrimaryKey(db::Query &query)
{
    query.Select();
    for (const auto &pair : GetPrimaryKey())
        query.IncrementalSelect(pair.first);
    query.EndIncrementalSelect().From(GetName());
}

/*!
 * \details
 */
void Entity::Insert(db::Query &query)
{
    query.Insert().Into(GetName());
    for (const auto &pair : GetAttributes())
        pair.second(*this).Insert(query);
    query.EndIncrementalInsert();
}

/*!
 * \details
 */
void Entity::Update(db::Query &query)
{
    query.Update(GetName());
    for (const auto &pair : GetAttributes())
        pair.second(*this).Update(query);
    query.EndIncrementalUpdate();
    mIsMarkedForUpdate = true;
}

/*!
 * \details
 */
void Entity::Delete(db::Query &query)
{
    query.Delete().From(GetName());
}

/*!
 * \details
 */
void Entity::Where(db::Query &query)
{
    for (const auto &pair : GetPrimaryKey())
        pair.second(*this).Where(query);
    if (mIsMarkedForUpdate)
        for (const auto &pair : GetVersionFields())
            pair.second(*this).Where(query);
    query.EndIncrementalWhere();
}

/*!
 * \details
 */
void Entity::Bind(db::Statement &statement)
{
    for (const auto &pair : GetAttributes())
        pair.second(*this).Bind(statement);
}

/*!
 * \details
 */
void Entity::BindPrimaryKey(db::Statement &statement)
{
    for (const auto &pair : GetPrimaryKey())
        pair.second(*this).Bind(statement, mIsMarkedForUpdate);
    if (mIsMarkedForUpdate)
        for (const auto &pair : GetVersionFields())
            pair.second(*this).Bind(statement);
}

/*!
 * \details
 */
void Entity::ValidateSchema() const
{
    throw NotImplementedError("void Entity::ValidateSchema() const");
}

/*!
 * \details
 */
void Entity::CreateSchema(db::Query &query) const
{
    throw NotImplementedError("void Entity::CreateSchema(db::Query &query) const");
}

/*!
 * \details
 */
void Entity::ReloadRelationships()
{
    for (const auto &pair : GetRelationships())
        pair.second(*this).Invalidate();
}

/*!
 * \details
 */
void Entity::DissolveRelationships()
{
    for (const auto &pair : GetRelationships())
        pair.second(*this).Dissolve();
}

CPPORM_END_NAMESPACE