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
    mCopies.clear();
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
    static auto cNullIndicator = ::soci::i_null;
    try
    {
        mNativeStatement.exchange(
            ::soci::use(cNullValue, cNullIndicator, MakeParameterName(param)));
    }
    catch (const std::exception &e)
    {
        throw DatabaseStatementBindError(e.what());
    }
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

CPPORM_END_SUB_SUB_NAMESPACE
