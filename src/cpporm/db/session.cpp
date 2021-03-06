/*!
 * \file
 * \brief     Session class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#include <cpporm/db/session.h>

// Internal library includes
#include <cpporm/db/cache.h>
#include <cpporm/db/connection.h>
#include <cpporm/db/context.h>
#include <cpporm/db/criteria.h>
#include <cpporm/db/cursor.h>
#include <cpporm/db/statement.h>
#include <cpporm/entity.h>

CPPORM_BEGIN_SUB_NAMESPACE(db)

/*!
 * \details
 */
Session::~Session()
{
}

/*!
 * \details
 */
void Session::Add(const std::shared_ptr<Entity> &entity)
{
    InsertIntoDatabase(*entity);
    FetchFromDatabase(*entity);
    entity->Commit();
    entity->SetSession(this);
    auto result = GetCache().Add(entity->GetId(), entity);
    assert(result);
    GetContext().AddInsertion(entity->GetId());
}

/*!
 * \details
 */
std::shared_ptr<Entity> Session::Get(const std::string &uniqueId)
{
    return GetCache().Get(uniqueId);
}

/*
 * \details
 */
std::vector<std::string> Session::Find(Entity &prototype, const Criteria &criteria)
{
    auto query = GetConnection().CreateQuery();
    auto statement = GetConnection().CreateStatement();
    auto statement2 = GetConnection().CreateStatement();
    assert(query);
    assert(statement);
    assert(statement2);

    prototype.FetchPrimaryKey(*query);
    criteria.Compose(*query);
    statement->Prepare(query->GetAndReset());
    criteria.Bind(*statement);
    prototype.SetSession(this);

    auto tempTableCreated = false;
    auto cursor = GetConnection().Execute(*statement);
    assert(cursor);
    std::vector<std::string> ids;
    ids.reserve(cursor->GetAffectedRowCount());
    while (cursor->Next())
    {
        prototype.Extract(*cursor);
        auto id = prototype.GetId();
        if (GetCache().Has(id))
        {
            ids.push_back(id);
        }
        else if (!criteria.GetCachedOnly())
        {
            if (!tempTableCreated)
            {
                prototype.CreateTempSchema(*query);
                GetConnection().JustExecute(query->GetAndReset());
                prototype.EraseTempTable(*query);
                GetConnection().JustExecute(query->GetAndReset());
                prototype.InsertIntoTemp(*query);
                statement2->Prepare(query->GetAndReset());
                statement2->StartBatch();
                tempTableCreated = true;
            }
            prototype.BindPrimaryKey(*statement2);
        }
    }

    if (tempTableCreated)
    {
        statement2->EndBatch();
        GetConnection().Execute(*statement2);

        prototype.Fetch(*query);
        prototype.JoinTemp(*query);
        statement2->Prepare(query->Get());
        cursor = GetConnection().Execute(*statement2);
        assert(cursor);
        while (cursor->Next())
        {
            prototype.Extract(*cursor);
            prototype.Commit();
            GetCache().Add(prototype.GetId(), std::shared_ptr<Entity>(prototype.Clone()));
            ids.push_back(prototype.GetId());
        }
    }
    return ids;
}

/*!
 * \details
 */
std::shared_ptr<Entity> Session::FindOne(Entity &prototype, const db::Criteria &criteria)
{
    auto ids = Find(prototype, criteria);
    if (ids.empty())
        throw EntryNonExistentError();
    return GetCache().Get(ids.back());
}

/*!
 * \details
 */
void Session::Update(Entity &entity)
{
    assert(GetCache().Has(entity.GetId()));
    if (entity.WasModified())
    {
        auto oldId = entity.GetId();
        entity.ResetId();
        GetContext().AddUpdate(oldId, entity.GetId());
        GetCache().Rename(oldId, entity.GetId());
        UpdateInDatabase(entity);
        FetchFromDatabase(entity);
        entity.ReloadRelationships();
    }
}

/*!
 * \details
 */
void Session::Delete(Entity &entity)
{
    assert(GetCache().Has(entity.GetId()));
    RemoveFromCache(entity);
    DeleteFromDatabase(entity);
}

/*!
 * \details
 */
void Session::RemoveFromCache(Entity &entity)
{
    if (!entity.MarkForRemoval())
    {
        entity.DissolveRelationships();
        GetContext().AddDeletion(entity.GetId());
        GetCache().Remove(entity.GetId());
    }
}

/*!
 * \details
 */
void Session::FetchFromDatabase(Entity &entity)
{
    auto query = GetConnection().CreateQuery();
    auto statement = GetConnection().CreateStatement();
    assert(query);
    assert(statement);

    entity.Fetch(*query);
    entity.Where(*query);
    statement->Prepare(query->Get());
    entity.BindPrimaryKey(*statement);
    auto cursor = GetConnection().Execute(*statement);
    assert(cursor);
    if (!cursor->Next())
        throw EntityNonExistentError(entity.GetId());
    entity.Extract(*cursor);
}

/*!
 * \details
 */
void Session::InsertIntoDatabase(Entity &entity)
{
    auto query = GetConnection().CreateQuery();
    auto statement = GetConnection().CreateStatement();
    assert(query);
    assert(statement);

    entity.Insert(*query);
    statement->Prepare(query->GetAndReset());
    entity.Bind(*statement);
    GetConnection().Execute(*statement);
    if (entity.FetchLastId(*query))
    {
        statement->Prepare(query->Get());
        auto cursor = GetConnection().Execute(*statement);
        assert(cursor);
        auto result = cursor->Next();
        assert(result);
        entity.ExtractPrimaryKey(*cursor);
    }
}

/*!
 * \details
 */
void Session::UpdateInDatabase(Entity &entity)
{
    auto query = GetConnection().CreateQuery();
    auto statement = GetConnection().CreateStatement();
    assert(query);
    assert(statement);

    entity.Update(*query);
    entity.Where(*query);
    statement->Prepare(query->Get());
    entity.BindPrimaryKey(*statement);
    entity.Bind(*statement);
    auto cursor = GetConnection().Execute(*statement);
    assert(cursor);
    if (cursor->GetAffectedRowCount() == 0)
        throw EntityNotUpdatedError(entity.GetId());
    entity.SavePrimaryKey();
}

/*!
 * \details
 */
void Session::DeleteFromDatabase(Entity &entity)
{
    auto query = GetConnection().CreateQuery();
    auto statement = GetConnection().CreateStatement();
    assert(query);
    assert(statement);

    entity.Delete(*query);
    entity.Where(*query);
    statement->Prepare(query->Get());
    entity.BindPrimaryKey(*statement);
    auto cursor = GetConnection().Execute(*statement);
    assert(cursor);
    if (cursor->GetAffectedRowCount() == 0)
        throw EntityNotDeletedError(entity.GetId());
}

CPPORM_END_SUB_NAMESPACE
