/*!
 * \file
 * \brief     SOCI statement implementation
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#include <cpporm/backend/soci/statement.h>

// Internal library includes
#include <cpporm/backend/soci/utils.h>
#include <cpporm/error.h>

CPPORM_BEGIN_SUB_SUB_NAMESPACE(backend, soci)

/*!
 * \details
 */
Statement::Statement(::soci::session &native) : mNativeStatement(native), mNativeConnection(native)
{
}

/*!
 * \details
 */
void Statement::Prepare(const std::string &sql)
{
    Clear();
    mQueryToPrepare = ProcessParameterNames(sql);
    mNativeStatement.~statement();
    new (&mNativeStatement)::soci::statement(mNativeConnection);
    mNativeStatement.exchange(::soci::into(mNativeRow));
}

/*!
 * \details
 */
void Statement::Bind(short param, const std::string &value)
{
    if (mIsBatchProcessing)
    {
        mBatchCopies[param].push_back(value);
        auto it = mBatchNulls.find(param);
        if (it != mBatchNulls.end())
            it->second.push_back(::soci::i_ok);
        return;
    }
    try
    {
        mCopies.push_back(value);
        mNativeStatement.exchange(::soci::use(mCopies.back(), MakeParameterName(param)));
    }
    catch (const std::exception &e)
    {
        throw DatabaseStatementBindError(e.what());
    }
}

/*!
 * \details
 */
void Statement::BindNull(short param)
{
    static const std::string cNullValue = "";
    static auto cNullFlag = ::soci::i_null;
    if (mIsBatchProcessing)
    {
        mBatchCopies[param].push_back(cNullValue);
        auto it = mBatchNulls.find(param);
        if (it != mBatchNulls.end())
            it->second.push_back(cNullFlag);
        else
            mBatchNulls
                .emplace(
                    param, std::vector<::soci::indicator>(mBatchCopies[param].size(), ::soci::i_ok))
                .first->second.back()
                = cNullFlag;
        return;
    }
    try
    {
        mNativeStatement.exchange(::soci::use(cNullValue, cNullFlag, MakeParameterName(param)));
    }
    catch (const std::exception &e)
    {
        throw DatabaseStatementBindError(e.what());
    }
}

/*!
 * \details
 */
void Statement::StartBatch()
{
    mIsBatchProcessing = true;
}

/*!
 * \details
 */
void Statement::EndBatch()
{
    try
    {
        for (auto &pair : mBatchCopies)
        {
            auto it = mBatchNulls.find(pair.first);
            if (it != mBatchNulls.end())
                mNativeStatement.exchange(
                    ::soci::use(pair.second, it->second, MakeParameterName(pair.first)));
            else
                mNativeStatement.exchange(::soci::use(pair.second, MakeParameterName(pair.first)));
        }
    }
    catch (const std::exception &e)
    {
        mIsBatchProcessing = false;
        throw DatabaseStatementBindError(e.what());
    }
    mIsBatchProcessing = false;
}

/*!
 * \details
 */
bool Statement::IsBatchActive()
{
    return mIsBatchProcessing;
}

/*!
 * \details
 */
void Statement::Execute()
{
    try
    {
        mNativeStatement.alloc();
        mNativeStatement.prepare(mQueryToPrepare);
        mNativeStatement.define_and_bind();
        mNativeStatement.execute(true);
    }
    catch (const std::exception &e)
    {
        throw DatabaseExecuteError(e.what());
    }
}

/*!
 * \details
 */
void Statement::Clear()
{
    mCopies.clear();
    mBatchCopies.clear();
    mBatchNulls.clear();
    mIsBatchProcessing = false;
}

CPPORM_END_SUB_SUB_NAMESPACE
