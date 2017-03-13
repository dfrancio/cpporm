/*!
 * \file
 * \brief     SOCI cursor implementation
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#include <cpporm/backend/soci/cursor.h>

// Internal library includes
#include <cpporm/backend/soci/utils.h>
#include <cpporm/error.h>

CPPORM_BEGIN_SUB_SUB_NAMESPACE(backend, soci)

/*!
 * \details
 */
Cursor::Cursor(Statement *statement)
    : mOwnedStatement(statement), mStatement(*statement), mFirstRowFetched(false)
{
    mStatement.Execute();
}

/*!
 * \details
 */
Cursor::Cursor(Statement &statement) : mStatement(statement), mFirstRowFetched(false)
{
    mStatement.Execute();
}

/*!
 * \details
 */
bool Cursor::Next()
{
    if (!mFirstRowFetched)
    {
        mFirstRowFetched = true;
        if (mStatement.mNativeStatement.got_data())
            return true;
        return false;
    }
    try
    {
        return mStatement.mNativeStatement.fetch();
    }
    catch (const std::exception &e)
    {
        throw DatabaseCursorNavigationError(e.what());
    }
}

/*!
 * \details
 */
std::size_t Cursor::GetAffectedRowCount() const
{
    try
    {
        auto &stmt = const_cast<::soci::statement &>(mStatement.mNativeStatement);
        auto result = stmt.get_affected_rows();
        assert(result >= 0);
        return result;
    }
    catch (const std::exception &e)
    {
        throw DatabaseCursorQueryError(e.what());
    }
}

/*!
 * \details
 */
bool Cursor::Has(const std::string &name) const
{
    try
    {
        mStatement.mNativeRow.get_indicator(name);
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

/*!
 * \details
 */
bool Cursor::IsNull(const std::string &name) const
{
    try
    {
        return mStatement.mNativeRow.get_indicator(name) == ::soci::i_null;
    }
    catch (const std::exception &e)
    {
        throw DatabaseCursorQueryError(e.what());
    }
}

/*!
 * \details
 */
std::string Cursor::Get(short column) const
{
    try
    {
        return GetString(column);
    }
    catch (const std::exception &e)
    {
        throw DatabaseCursorQueryError(e.what());
    }
}

/*!
 * \details
 */
std::string Cursor::Get(const std::string &name) const
{
    try
    {
        return GetString(name);
    }
    catch (const std::exception &e)
    {
        throw DatabaseCursorQueryError(e.what());
    }
}

/*!
 * \details
 */
std::string Cursor::GetString(short column) const
{
    switch (mStatement.mNativeRow.get_properties(column).get_data_type())
    {
    case ::soci::dt_double:
        return Convert(mStatement.mNativeRow.get<double>(column));
    case ::soci::dt_integer:
        return Convert(mStatement.mNativeRow.get<int>(column));
    case ::soci::dt_long_long:
        return Convert(mStatement.mNativeRow.get<long long>(column));
    case ::soci::dt_unsigned_long_long:
        return Convert(mStatement.mNativeRow.get<unsigned long long>(column));
    case ::soci::dt_date:
        return Convert(mStatement.mNativeRow.get<std::tm>(column));
    case ::soci::dt_string:
    case ::soci::dt_blob:
    case ::soci::dt_xml:
    default:
        return mStatement.mNativeRow.get<std::string>(column);
    }
}

/*!
 * \details
 */
std::string Cursor::GetString(const std::string &name) const
{
    switch (mStatement.mNativeRow.get_properties(name).get_data_type())
    {
    case ::soci::dt_double:
        return Convert(mStatement.mNativeRow.get<double>(name));
    case ::soci::dt_integer:
        return Convert(mStatement.mNativeRow.get<int>(name));
    case ::soci::dt_long_long:
        return Convert(mStatement.mNativeRow.get<long long>(name));
    case ::soci::dt_unsigned_long_long:
        return Convert(mStatement.mNativeRow.get<unsigned long long>(name));
    case ::soci::dt_date:
        return Convert(mStatement.mNativeRow.get<std::tm>(name));
    case ::soci::dt_string:
    case ::soci::dt_blob:
    case ::soci::dt_xml:
    default:
        return mStatement.mNativeRow.get<std::string>(name);
    }
}

CPPORM_END_SUB_SUB_NAMESPACE
