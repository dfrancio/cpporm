/*!
 * \file
 * \brief     Context class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#include <cpporm/db/context.h>

CPPORM_BEGIN_SUB_NAMESPACE(db)

/*!
 * \details
 */
Context::~Context()
{
    if (mParentContext)
        mParentContext->mSubcontext = mSubcontext;
}

/*!
 * \details
 */
void Context::Rollback(std::function<ContextFunction> function)
{
    if (!mParentContext)
        RollbackAll();
    else
        RollbackToThis(function);
}

/*!
 * \details
 */
void Context::Commit()
{
    if (!mParentContext)
        CommitAll();
    else
        ReleaseThis();
}

/*!
 * \details
 */
void Context::AddInsertion(const std::string &key)
{
    if (mParentContext || !mSubcontext)
        InnerAddInsertion(key);
    else
        mSubcontext->InnerAddInsertion(key);
}

/*!
 * \details
 */
void Context::AddUpdate(const std::string &oldKey, const std::string &newKey)
{
    if (mParentContext || !mSubcontext)
        InnerAddUpdate(oldKey, newKey);
    else
        mSubcontext->InnerAddUpdate(oldKey, newKey);
}

/*!
 * \details
 */
void Context::AddDeletion(const std::string &key)
{
    if (mParentContext || !mSubcontext)
        InnerAddDeletion(key);
    else
        mSubcontext->InnerAddDeletion(key);
}

/*!
 * \details
 */
Context::Context(Context *parent)
    : mParentContext(parent && parent->mParentContext ? parent->mParentContext : parent),
      mSubcontext(mParentContext ? mParentContext->mSubcontext : nullptr)
{
    if (mParentContext)
        mParentContext->mSubcontext = this;
}

/*!
 * \details
 */
void Context::CommitAll()
{
    while (mSubcontext)
    {
        mSubcontext->InnerCommit();
        delete mSubcontext;
    }
    InnerCommit();
}

/*!
 * \details
 */
void Context::RollbackAll()
{
    while (mSubcontext)
    {
        mSubcontext->InnerRollback();
        delete mSubcontext;
    }
    InnerRollback();
}

/*!
 * \details
 */
void Context::RollbackToThis(std::function<ContextFunction> function)
{
    while (mParentContext->mSubcontext != this)
    {
        mParentContext->mSubcontext->InnerRollback();
        if (function)
            function(mParentContext->mSubcontext);
        delete mParentContext->mSubcontext;
    }
    InnerRollback();
}

/*!
 * \details
 */
void Context::ReleaseThis()
{
    auto context = mParentContext;
    while (context && context->mSubcontext != this)
        context = context->mSubcontext;
    assert(context);
    InnerRelease(mSubcontext ? *mSubcontext : *mParentContext);
    mParentContext = context;
    delete this;
}

CPPORM_END_SUB_NAMESPACE
