/*!
 * \file
 * \brief     nanodbc statement implementation
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#include <cpporm/backend/nanodbc/statement.h>

// Internal library includes
#include <cpporm/backend/nanodbc/utils.h>
#include <cpporm/error.h>

CPPORM_BEGIN_SUB_SUB_NAMESPACE(backend, nanodbc)

/*!
 * \details
 */
Statement::Statement(cpporm::nanodbc::connection &native) : mNativeStatement(native)
{
}

/*!
 * \details
 */
void Statement::Prepare(const std::string &sql)
{
    Clear();
    try
    {
        mNativeStatement.prepare(Widen16(sql));
    }
    catch (const std::exception &e)
    {
        throw DatabaseStatementPrepareError(e.what());
    }
}

/*!
 * \details
 */
void Statement::Bind(short param, const std::string &value)
{
    if (mIsBatchProcessing)
    {
        ++mBatchCount;
        mBatchCopies[param].push_back(Widen16(value));
        auto it = mBatchNulls.find(param);
        if (it != mBatchNulls.end())
            it->second.push_back(false);
        return;
    }
    try
    {
        mCopies.push_back(Widen16(value));
        mNativeStatement.bind(param, mCopies.back().c_str());
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
    if (mIsBatchProcessing)
    {
        ++mBatchCount;
        mBatchCopies[param].push_back(u"");
        auto it = mBatchNulls.find(param);
        if (it != mBatchNulls.end())
            it->second.push_back(true);
        else
            mBatchNulls.emplace(param, std::vector<unsigned char>(mBatchCount, false))
                .first->second.back()
                = true;
        return;
    }
    try
    {
        mNativeStatement.bind_null(param);
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
    mBatchCount = 0;
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
            std::size_t maxLength = 0;
            for (auto &value : pair.second)
                if (value.size() > maxLength)
                    maxLength = value.size();
            ++maxLength;

            auto &buffer = mBatchBuffers[pair.first];
            buffer.resize(maxLength * mBatchCount);
            std::size_t index = 0;
            for (auto it = pair.second.begin(); it != pair.second.end(); ++it, index += maxLength)
                std::copy(it->begin(), it->end(), &buffer[index]);

            auto it = mBatchNulls.find(pair.first);
            if (it != mBatchNulls.end())
                mNativeStatement.bind_strings(
                    pair.first, buffer.data(), maxLength, mBatchCount, it->second.data());
            else
                mNativeStatement.bind_strings(pair.first, buffer.data(), maxLength, mBatchCount);
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
void Statement::Clear()
{
    mCopies.clear();
    mBatchCopies.clear();
    mBatchNulls.clear();
    mBatchBuffers.clear();
    mBatchCount = 1;
    mIsBatchProcessing = false;
}

CPPORM_END_SUB_SUB_NAMESPACE
