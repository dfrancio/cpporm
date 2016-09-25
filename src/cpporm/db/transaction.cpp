/*!
 * \file
 * \brief     Transaction class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#include <cpporm/db/transaction.h>

// Internal library includes
#include <cpporm/db/connection.h>
#include <cpporm/db/context.h>
#include <cpporm/db/cursor.h>
#include <cpporm/db/query.h>

CPPORM_BEGIN_SUB_NAMESPACE(db)

/*!
 * \details
 */
Transaction::~Transaction()
{
    Rollback();
}

/*!
 * \details
 */
Transaction::Transaction(Session &session) : mSession(session)
{
    mSession.GetContext().Activate();
}

/*!
 * \details
 */
void Transaction::Rollback()
{
    mSession.GetContext().Rollback();
    mSavePoints.clear();
}

/*!
 * \details
 */
void Transaction::Commit()
{
    mSession.GetContext().Commit();
    mSavePoints.clear();
}

/*!
 * \details
 */
void Transaction::AddSavePoint(const std::string &name)
{
    Release(name);
    auto &connection = mSession.GetConnection();
    connection.Execute(connection.CreateQuery()->SavePoint(name).Get());
    mSavePoints.emplace(name, mSession.GetContext().CreateSubcontext());
}

/*!
 * \details
 */
void Transaction::RollbackTo(const std::string &name)
{
    auto it = mSavePoints.find(name);
    if (it != mSavePoints.end())
    {
        using std::placeholders::_1;
        auto &connection = mSession.GetConnection();
        connection.Execute(connection.CreateQuery()->RollbackToSavePoint(name).Get());
        it->second->Rollback(std::bind(&Transaction::RemoveSavePoint, this, _1));
        it->second->Activate();
    }
}

/*!
 * \details
 */
void Transaction::Release(const std::string &name)
{
    auto it = mSavePoints.find(name);
    if (it != mSavePoints.end())
    {
        auto &connection = mSession.GetConnection();
        connection.Execute(connection.CreateQuery()->ReleaseSavePoint(name).Get());
        it->second->Commit();
        mSavePoints.erase(it);
    }
}

/*!
 * \details
 */
void Transaction::RemoveSavePoint(Context *context)
{
    auto it = mSavePoints.begin();
    while (it != mSavePoints.end())
    {
        if (it->second == context)
            it = mSavePoints.erase(it);
        else
            ++it;
    }
}

CPPORM_END_SUB_NAMESPACE
