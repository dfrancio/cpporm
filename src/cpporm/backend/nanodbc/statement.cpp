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
Statement::Statement(::nanodbc::connection &native) : mNativeStatement(native)
{
}

/*!
 * \details
 */
void Statement::Prepare(const std::string &sql)
{
    try
    {
        mCopies.clear();
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
    try
    {
        mNativeStatement.bind_null(param);
    }
    catch (const std::exception &e)
    {
        throw DatabaseStatementBindError(e.what());
    }
}

CPPORM_END_SUB_SUB_NAMESPACE
