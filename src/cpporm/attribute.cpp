/*!
 * \file
 * \brief     Attribute class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#include <cpporm/attribute.h>

// C library includes
#include <cstdlib>
#include <cstring>

// External library includes
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

// Internal library includes
#include <cpporm/db/cursor.h>
#include <cpporm/db/query.h>
#include <cpporm/db/statement.h>
#include <cpporm/maps.h>

CPPORM_BEGIN_NAMESPACE

// Helper functions
std::string CheckAddZeroTime(std::string &&value);

/*!
 * \details
 */
Attribute::~Attribute()
{
}

/*!
 * \details
 */
const std::string &Attribute::Get() const
{
    return mValue;
}

/*!
 * \details
 */
const std::string *Attribute::operator->() const
{
    return &mValue;
}

/*!
 * \details
 */
void Attribute::Set(const std::string &value)
{
    mValue = value;
}

/*!
 * \details
 */
void Attribute::SetNull()
{
    mValue.clear();
}

/*!
 * \details
 */
bool Attribute::IsNull() const
{
    InitializeFlags();
    return mValue.empty() && !mFlags.notNull;
}

/*!
 * \details
 */
Attribute::Attribute()
{
}

/*!
 * \details
 */
Attribute::Attribute(const std::string &value) : mValue(value), mOldValue(value)
{
}

/*!
 * \details
 */
Attribute &Attribute::operator=(const std::string &value)
{
    Set(value);
    return *this;
}

/*!
 * \details
 */
bool Attribute::operator==(const Attribute &other) const
{
    return mValue == other.mValue;
}

/*!
 * \details
 */
bool Attribute::operator!=(const Attribute &other) const
{
    return mValue != other.mValue;
}

/*!
 * \details
 */
bool Attribute::WasModified()
{
    return mValue != mOldValue;
}

/*!
 * \details
 */
void Attribute::Rollback()
{
    mValue = mOldValue;
    mSavedValue.clear();
    if (!mHistory.empty())
    {
        mOldValue = mHistory.top();
        mHistory.pop();
    }
}

/*!
 * \details
 */
void Attribute::Commit()
{
    mOldValue = mValue;
    mSavedValue.clear();
    if (!mHistory.empty())
        mHistory = decltype(mHistory)();
}

/*!
 * \details
 */
void Attribute::PushState()
{
    if (WasModified())
    {
        mHistory.push(mOldValue);
        mOldValue = mValue;
        mSavedValue.clear();
    }
}

/*!
 * \details
 */
void Attribute::SaveState()
{
    if (WasModified())
        mSavedValue = mValue;
}

/*!
 * \details
 */
void Attribute::Extract(db::Cursor &cursor)
{
    if (cursor.Has(GetName()))
    {
        InitializeFlags();
        if (cursor.IsNull(GetName()))
            SetNull();
        else if (mFlags.checkDatetime)
            Set(CheckAddZeroTime(cursor.Get(GetName())));
        else
            Set(cursor.Get(GetName()));
    }
}

/*!
 * \details
 */
void Attribute::Insert(db::Query &query)
{
    if (mValue.empty())
    {
        InitializeFlags();
        if (mFlags.skipInsertIfEmpty)
            return;
    }
    query.IncrementalInsert(GetName());
    mBindingIndices.push(query.GetBindingIndex());
}

/*!
 * \details
 */
void Attribute::Update(db::Query &query)
{
    if (WasModified())
    {
        query.IncrementalUpdate(GetName());
        mBindingIndices.push(query.GetBindingIndex());
    }
}

/*!
 * \details
 */
void Attribute::Where(db::Query &query)
{
    if (IsNull())
    {
        query.IncrementalWhere(GetName(), db::Condition::isNull);
    }
    else
    {
        query.IncrementalWhere(GetName(), db::Condition::equal);
        mBindingIndices.push(query.GetBindingIndex());
    }
}

/*!
 * \details
 */
void Attribute::Bind(db::Statement &statement, bool useSavedValue)
{
    if (!mBindingIndices.empty())
    {
        if (useSavedValue)
        {
            if (mSavedValue.empty())
            {
                if (mOldValue.empty())
                    statement.BindNull(mBindingIndices.top());
                else
                    statement.Bind(mBindingIndices.top(), mOldValue);
            }
            else
                statement.Bind(mBindingIndices.top(), mSavedValue);
        }
        else if (IsNull())
            statement.BindNull(mBindingIndices.top());
        else
            statement.Bind(mBindingIndices.top(), mValue);

        if (!statement.IsBatchActive())
            mBindingIndices.pop();
    }
}

/*!
 * \details
 */
void Attribute::ValidateSchema(db::Cursor &) const
{
    throw NotImplementedError("void Attribute::ValidateSchema() const");
}

/*!
 * \details
 */
void Attribute::CreateSchema(db::Query &query) const
{
    auto datatype = GetProperties().Get(CPPORM_PROP_DATA_TYPE);
    auto length = std::strtoull(GetProperties().Get(CPPORM_PROP_LENGTH, "0").c_str(), nullptr, 10);
    auto decimals
        = std::strtoull(GetProperties().Get(CPPORM_PROP_DECIMALS, "0").c_str(), nullptr, 10);
    auto defaultValue = GetProperties().Get(CPPORM_PROP_DEFAULT, "");
    auto isNotNull = GetProperties().Has(CPPORM_PROP_NOT_NULL);
    auto isAutoIncrement = GetProperties().Has(CPPORM_PROP_IDENTITY);
    query.IncrementalColumn(
        GetName(), datatype, length, decimals, defaultValue, false, false, isNotNull,
        isAutoIncrement);
}

/*!
 * \details
 */
void Attribute::GenerateGuid()
{
    InitializeFlags();
    assert(mFlags.isGuidCompliant);
    auto uuid = boost::uuids::random_generator()();

    if (GetProperties().Get(CPPORM_PROP_DATA_TYPE, "") == "CHAR")
    {
        mValue = boost::uuids::to_string(uuid);
    }
    else
    {
        mValue.resize(uuid.static_size());
        std::memcpy(&mValue[0], uuid.data, uuid.static_size());
    }
}

/*!
 * \details
 */
std::string Attribute::GetGuid() const
{
    InitializeFlags();
    assert(mFlags.isGuidCompliant);
    if (mValue.empty() || GetProperties().Get(CPPORM_PROP_DATA_TYPE, "") == "CHAR")
        return mValue;

    boost::uuids::uuid uuid;
    std::memcpy(uuid.data, &mValue[0], uuid.static_size());
    return boost::uuids::to_string(uuid);
}

/*!
 * \details
 */
void Attribute::InitializeFlags() const
{
    if (!mFlags.initialized)
    {
        auto &datatype = GetProperties().Get(CPPORM_PROP_DATA_TYPE, "");
        auto isAutoIncrement = GetProperties().Has(CPPORM_PROP_IDENTITY);
        auto length
            = std::strtoull(GetProperties().Get(CPPORM_PROP_LENGTH, "0").c_str(), nullptr, 10);
        mFlags.notNull = GetProperties().Has(CPPORM_PROP_NOT_NULL);
        mFlags.checkDatetime = datatype == "DATETIME";
        mFlags.isGuidCompliant = datatype == "GUID" || datatype == "UUID"
            || (datatype == "BINARY" && length == 16) || (datatype == "CHAR" && length == 36);
        mFlags.skipInsertIfEmpty = isAutoIncrement || GetProperties().Has(CPPORM_PROP_DEFAULT);
        mFlags.initialized = true;
    }
}

/*!
 * \details
 */
inline std::string CheckAddZeroTime(std::string &&value)
{
    if (value.size() <= 10)
        value += " 00:00:00";
    return value;
}

CPPORM_END_NAMESPACE
