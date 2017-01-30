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
Entity::TraverseResult Entity::TraverseRelationships(
    std::function<TraverseResult(Entity &)> function)
{
    assert(function);
    auto result = function(*this);
    if (result != TraverseResult::ok)
        return result;

    for (auto &pair : GetRelationships())
    {
        if (auto *relationship = dynamic_cast<ToOneRelationship *>(&pair.second(*this)))
        {
            result = relationship->Get<Entity>()->TraverseRelationships(function);
            if (result == TraverseResult::halt)
                return result;
        }
    }
    return TraverseResult::ok;
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
    if (GetProperties().Has(CPPORM_PROP_USE_GUID))
    {
        assert(GetPrimaryKey().size() == 1);
        const auto &attr = GetPrimaryKey().begin()->second(*this);
        mUniqueId = attr.GetGuid();
    }
    else
    {
        mUniqueId = GetName();
        for (const auto &pair : GetPrimaryKey())
            mUniqueId += pair.second(*this).Get();
    }
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
    ResetId();
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
        if (attr.Get().empty() && attr.GetProperties().Has(CPPORM_PROP_IDENTITY))
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
    query.Select().Distinct();
    for (const auto &pair : GetPrimaryKey())
        query.IncrementalSelect(pair.first);
    query.EndIncrementalSelect(GetName()).From(GetName());
}

/*!
 * \details
 */
void Entity::Insert(db::Query &query)
{
    if (GetProperties().Has(CPPORM_PROP_USE_GUID))
    {
        assert(GetPrimaryKey().size() == 1);
        auto &attr = GetPrimaryKey().begin()->second(*this);
        if (attr.Get().empty())
            attr.GenerateGuid();
    }
    query.Insert().Into(GetName());
    for (const auto &pair : GetAttributes())
        pair.second(*this).Insert(query);
    query.EndIncrementalInsert();
}

/*!
 * \details
 */
void Entity::InsertIntoTemp(db::Query &query)
{
    if (GetProperties().Has(CPPORM_PROP_USE_GUID))
    {
        assert(GetPrimaryKey().size() == 1);
        auto &attr = GetPrimaryKey().begin()->second(*this);
        if (attr.Get().empty())
            attr.GenerateGuid();
    }
    query.Insert().Into(GetName() + "Temp");
    for (const auto &pair : GetPrimaryKey())
        pair.second(*this).Insert(query);
    query.EndIncrementalInsert();
}

/*!
 * \details
 */
void Entity::JoinTemp(db::Query &query)
{
    query.Join(GetName() + "Temp", db::JoinType::natural);
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
    query.CreateTable(GetName());
    for (const auto &pair : GetAttributes())
        pair.second(const_cast<Entity &>(*this)).CreateSchema(query);
    for (auto &indexPair : GetIndices())
    {
        if (indexPair.first == CPPORM_INDEX_PRIMARY_KEY)
        {
            for (auto &pair : indexPair.second->GetAttributes())
                query.IncrementalIndex(pair.first);
            query.EndIncrementalIndex("PRIMARY KEY");
        }
        else if (indexPair.first.find(CPPORM_INDEX_UNIQUE) == 0)
        {
            for (auto &pair : indexPair.second->GetAttributes())
                query.IncrementalIndex(pair.first);
            query.EndIncrementalIndex("UNIQUE");
        }
    }
    query.EndIncrementalColumn();
}

/*!
 * \details
 */
void Entity::CreateTempSchema(db::Query &query) const
{
    query.CreateTable(GetName() + "Temp", true, true);
    for (const auto &pair : GetPrimaryKey())
        pair.second(const_cast<Entity &>(*this)).CreateSchema(query);
    if (GetIndices().Has(CPPORM_INDEX_PRIMARY_KEY))
    {
        for (auto &pair : GetIndices().Get(CPPORM_INDEX_PRIMARY_KEY)->GetAttributes())
            query.IncrementalIndex(pair.first);
        query.EndIncrementalIndex("PRIMARY KEY");
    }
    query.EndIncrementalColumn();
}

/*!
 * \details
 */
void Entity::EraseTable(db::Query &query) const
{
    query.Delete().From(GetName());
}

/*!
 * \details
 */
void Entity::EraseTempTable(db::Query &query) const
{
    query.Delete().From(GetName() + "Temp");
}

/*!
 * \details
 */
void Entity::DropSchema(db::Query &query) const
{
    query.DropTable(GetName());
}

/*!
 * \details
 */
void Entity::DropTempSchema(db::Query &query) const
{
    query.DropTable(GetName() + "Temp", true);
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

/*!
 * \details
 */
void Entity::CopyFrom(Entity &entity)
{
    auto &primaryKey = GetPrimaryKey();
    auto &versionFields = GetVersionFields();
    for (const auto &pair : entity.GetAttributes())
        if (primaryKey.find(pair.first) == primaryKey.end()
            && versionFields.find(pair.first) == versionFields.end())
            (*this)[pair.first] = entity[pair.first];
}

/*!
 * \details
 */
void Entity::CopyAllFrom(Entity &entity)
{
    for (const auto &pair : entity.GetAttributes())
        (*this)[pair.first] = entity[pair.first];
}

CPPORM_END_NAMESPACE
