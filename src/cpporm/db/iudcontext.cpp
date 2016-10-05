/*!
 * \file
 * \brief     IudContext class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#include <cpporm/db/iudcontext.h>

// Internal library includes
#include <cpporm/entity.h>

CPPORM_BEGIN_SUB_NAMESPACE(db)

/*!
 * \details
 */
IudContext::IudContext(Cache &cache) : Context(), mCache(cache)
{
}

/*!
 * \details
 */
IudContext::IudContext(IudContext *parent) : Context(parent), mCache(parent->mCache)
{
}

/*!
 * \details
 */
Context *IudContext::CreateSubcontext()
{
    auto result = new IudContext(this);
    mUpdates.PushState();
    return result;
}

/*!
 * \details
 */
void IudContext::InnerCommit()
{
    mInsertions.Commit();
    mUpdates.Commit();
    Reset();
}

/*!
 * \details
 */
void IudContext::InnerRollback()
{
    mCache.RemoveIn(mInsertions);
    for (auto &pair : mDeletions)
    {
        pair.second->Rollback();
        mCache.Add(pair.second->GetId(), pair.second);
    }
    for (auto &pair : mUpdates)
    {
        auto oldKey = pair.second->GetId();
        pair.second->Rollback();
        mCache.Rename(oldKey, pair.second->GetId());
    }
    Reset();
}

/*!
 * \details
 */
void IudContext::InnerRelease(Context &context)
{
    static_cast<IudContext &>(context).mInsertions.CopyFrom(mInsertions);
    static_cast<IudContext &>(context).mUpdates.CopyFrom(mUpdates);
    static_cast<IudContext &>(context).mDeletions.CopyFrom(mDeletions);
    Reset();
}

/*!
 * \details
 */
void IudContext::InnerAddInsertion(const std::string &key)
{
    if (!mInsertions.Has(key) && !mUpdates.Has(key) && !mDeletions.Has(key))
        mInsertions.Add(key, mCache.Get(key));
}

/*!
 * \details
 */
void IudContext::InnerAddUpdate(const std::string &oldKey, const std::string &newKey)
{
    if (mInsertions.Has(oldKey))
        mInsertions.Rename(oldKey, newKey);
    else if (mDeletions.Has(oldKey))
        mDeletions.Rename(oldKey, newKey);
    else
        mUpdates.Add(newKey, mCache.Get(oldKey));
}

/*!
 * \details
 */
void IudContext::InnerAddDeletion(const std::string &key)
{
    mUpdates.Remove(key);
    if (mInsertions.Has(key))
        mInsertions.Remove(key);
    else
        mDeletions.Add(key, mCache.Get(key));
}

/*!
 * \details
 */
void IudContext::Reset()
{
    mInsertions.clear();
    mUpdates.clear();
    mDeletions.clear();
}

CPPORM_END_SUB_NAMESPACE
