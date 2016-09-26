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

// Internal library includes
#include <cpporm/db/cursor.h>
#include <cpporm/db/query.h>
#include <cpporm/db/statement.h>
#include <cpporm/maps.h>

CPPORM_BEGIN_NAMESPACE

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
    return mValue.empty() && !GetProperties().Has(CPPORM_PROP_NOT_NULL);
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
    while (!mHistory.empty())
        mHistory.pop();
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
        if (cursor.IsNull(GetName()))
            SetNull();
        else
            Set(cursor.Get(GetName()));
    }
}

/*!
 * \details
 */
void Attribute::Insert(db::Query &query)
{
    if (!mValue.empty() || (!GetProperties().Has(CPPORM_PROP_IDENTITY)
                            && !GetProperties().Has(CPPORM_PROP_DEFAULT)))
    {
        query.IncrementalInsert(GetName());
        mBindingIndices.push(query.GetBindingIndex());
    }
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
        mBindingIndices.pop();
    }
}

/*!
 * \details
 */
void Attribute::ValidateSchema() const
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

CPPORM_END_NAMESPACE
