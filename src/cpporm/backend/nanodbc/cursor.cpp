/*!
 * \file
 * \brief     nanodbc cursor implementation
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#include <cpporm/backend/nanodbc/cursor.h>

// Internal library includes
#include <cpporm/backend/nanodbc/utils.h>
#include <cpporm/error.h>

CPPORM_BEGIN_SUB_SUB_NAMESPACE(backend, nanodbc)

/*!
 * \details
 */
Cursor::Cursor(cpporm::nanodbc::result &&native) : mNativeCursor(native)
{
}

/*!
 * \details
 */
bool Cursor::Next()
{
    assert(mNativeCursor);
    try
    {
        return mNativeCursor.next();
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

/*!
 * \details
 */
std::size_t Cursor::GetAffectedRowCount() const
{
    try
    {
        return mNativeCursor ? mNativeCursor.affected_rows() : 0;
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
    assert(mNativeCursor);
    try
    {
        mNativeCursor.column(Widen16(name));
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
    assert(mNativeCursor);
    try
    {
        return mNativeCursor.is_null(Widen16(name));
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
    assert(mNativeCursor);
    try
    {
        return HandleDateTime(Narrow(mNativeCursor.get<std::u16string>(column)));
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
    assert(mNativeCursor);
    try
    {
        return HandleDateTime(Narrow(mNativeCursor.get<std::u16string>(Widen16(name))));
    }
    catch (const std::exception &e)
    {
        throw DatabaseCursorQueryError(e.what());
    }
}

CPPORM_END_SUB_SUB_NAMESPACE
