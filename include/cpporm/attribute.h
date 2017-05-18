/*!
 * \file
 * \brief     Attribute class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

#include <cpporm/util/macros.h>

CPPORM_BEGIN_NAMESPACE

/*
 * Forward declarations
 */
namespace db
{
class Cursor;
class Query;
class Statement;
}
class PropertyMap;

/*!
 * \brief Abstract class to represent database columns
 *
 * An attribute maps a C++ object to a database column in a database table. All attributes should
 * derive from this class. It has a name and a set of properties, both being static members of the
 * derived class. It also contains a state: the current attribute value. This value is always cached
 * as a string and is guaranteed to be the actual value stored in the database, during the course of
 * a database session. Transactions and savepoints can be used with attributes.
 *
 * The attribute value can be read and assigned, or it can be set NULL. Assigning an empty string is
 * the same as setting it NULL. Equality comparisons are made upon the cached attribute value only.
 * A history of values that were assigned to the attribute is kept within, in order to accomplish
 * transaction and savepoint semantics. Thus, the internal state can be rolled back if necessary
 * without breaking consistency. The state can also be queried as to whether it was modified since
 * the last commit.
 *
 * Some of the methods help in the construction of prepared statements, while others have to do with
 * the database schema of the database column being represented.
 *
 * Finally, a couple of methods have to do with Globally Unique Identifiers (GUID). Use of these
 * only make sense for GUID-compliant database columns.
 *
 * \note Copy and move semantics are the compiler default.
 * \note Transaction atomicity is ensured by means of the RAII idiom and use of exceptions.
 *
 * Usage example:
 *
 * ~~~{.cpp}
 * class MyAttribute : public cpporm::Attribute
 * {
 *     using Attribute::Attribute;
 *
 * public:
 *     const std::string &GetName() const override
 *     {
 *         static std::string name = "name";
 *         return name;
 *     }
 *     const PropertyMap &GetProperties() const override
 *     {
 *         static cpporm::PropertyMap properties = {{"IDENTITY", ""}, {"DATA_TYPE", "INT"}};
 *         return properties;
 *     }
 * };
 *
 * void test()
 * {
 *     MyAttribute attribute;
 *     assert(attribute.GetName() == "name");
 *     assert(attribute.GetProperties().Get("DATA_TYPE") == "INT");
 *     assert(attribute.Get() == "");
 *     assert(attribute->empty());
 *     assert(attribute.IsNull());
 *     assert(!attribute.WasModified());
 *
 *     attribute.Set("abc");
 *     assert(attribute.Get() == "abc");
 *     assert(!attribute->empty());
 *     assert(!attribute.IsNull());
 *     assert(attribute.WasModified());
 *
 *     attribute.Commit();
 *     assert(!attribute.WasModified());
 *
 *     attribute.SetNull();
 *     assert(attribute.Get() == "");
 *     assert(attribute.IsNull());
 *     assert(attribute.WasModified());
 *
 *     attribute.Rollback();
 *     assert(attribute.Get() == "abc");
 *     assert(!attribute.WasModified());
 * }
 * ~~~
 */
class CPPORM_EXPORT Attribute
{
public:
    /*!
     * \brief Destructor
     */
    virtual ~Attribute();

    /*!
     * \brief Get attribute name
     * \return The attribute name
     */
    virtual const std::string &GetName() const = 0;

    /*!
     * \brief Get attribute properties
     * \return The attribute properties
     */
    virtual const PropertyMap &GetProperties() const = 0;

    /*!
     * \brief Get attribute value
     * \return The attribute value
     */
    const std::string &Get() const;

    /*!
     * \brief Get attribute value (dereference operator)
     * \return The attribute value
     */
    const std::string *operator->() const;

    /*!
     * \brief Set attribute value
     * \param[in] value The new attribute value
     */
    void Set(const std::string &value);

    /*!
     * \brief Set attribute NULL
     */
    void SetNull();

    /*!
     * \brief Check whether the attribute is NULL
     * \return True if the attribute is NULL; false otherwise
     */
    bool IsNull() const;

    /*!
     * \brief Construct a new attribute
     */
    Attribute();

    /*!
     * \brief Construct a new attribute
     * \param[in] value The initial attribute value
     */
    Attribute(const std::string &value);

    /*!
     * \brief Set attribute value
     * \param[in] value The new attribute value
     * \return The attribute object (*this)
     */
    Attribute &operator=(const std::string &value);

    /*!
     * \brief Check whether two attributes are equal
     * \param[in] other The other attribute
     * \return True if the attribute values are equal; false otherwise
     */
    bool operator==(const Attribute &other) const;

    /*!
     * \brief Check whether two attributes are different
     * \param[in] other The other attribute
     * \return True if the attribute values are different; false otherwise
     */
    bool operator!=(const Attribute &other) const;

    /*!
     * \brief Check whether the attribute was modified since last commit or since it was constructed
     * \return True if the attribute was modified; false otherwise
     */
    bool WasModified();

    /*!
     * \brief Rollback attribute internal state
     */
    void Rollback();

    /*!
     * \brief Commit attribute internal state
     */
    void Commit();

    /*!
     * \brief Push attribute internal state
     */
    void PushState();

    /*!
     * \brief Save attribute internal state
     */
    void SaveState();

    /*!
     * \brief Extract attribute value from database cursor
     * \param[in] cursor The database cursor
     */
    void Extract(db::Cursor &cursor);

    /*!
     * \brief Compose part of query needed to insert the attribute value into the database
     * \param[in] query The database query
     */
    void Insert(db::Query &query);

    /*!
     * \brief Compose part of query needed to update the attribute value in the database
     * \param[in] query The database query
     */
    void Update(db::Query &query);

    /*!
     * \brief Compose part of query needed to lookup the attribute value in the database
     * \param[in] query The database query
     */
    void Where(db::Query &query);

    /*!
     * \brief Bind the attribute value to a prepared statement
     * \param[in] statement The database statement
     * \param[in] useSavedValue A flag to indicate whether a previously saved attribute value should
     *     be used instead of the current (if applicable)
     */
    void Bind(db::Statement &statement, bool useSavedValue = false);

    /*!
     * \brief Validate the database schema of this attribute
     * \param[in] cursor The database cursor
     */
    void ValidateSchema(db::Cursor &cursor) const;

    /*!
     * \brief Compose part of query needed to create the database schema of this attribute
     * \param[in] query The database query
     */
    void CreateSchema(db::Query &query) const;

    /*!
     * \brief Get GUID string
     *
     * The GUID is always returned as a 36-character string in the following format: 8-4-4-4-12
     * (xxxxxxxx-xxxx-Mxxx-Nxxx-xxxxxxxxxxxx). This is independent of the column data type. In other
     * words, even if the column is declared as binary(16), the GUID will be returned as a string.
     *
     * \return The GUID string
     */
    std::string GetGuid() const;

    /*!
     * \brief Generate a standard version 4 UUID and set it as the new attribute value
     */
    void GenerateGuid();

protected:
    /*!
     * \brief The current attribute value
     */
    std::string mValue;

private:
    /*!
     * \brief The old attribute value
     */
    std::string mOldValue;

    /*!
     * \brief The saved attribute value
     */
    std::string mSavedValue;

    /*!
     * \brief The history of attribute values
     */
    std::stack<std::string> mHistory;

    /*!
     * \brief The binding indices (for prepared statements)
     */
    std::stack<short> mBindingIndices;

    /*!
     * \brief Initialize attribute flags
     */
    void InitializeFlags() const;

    /*!
     * \brief Internal flags
     */
    mutable struct
    {
        bool initialized = false;
        bool notNull = false;
        bool isGuidCompliant = false;
        bool checkDatetime = false;
        bool skipInsertIfEmpty = false;
    } mFlags;
};

/*!
 * \example cpporm/attribute.cpp
 *
 * This is an example of how to use the Attribute class.
 */

CPPORM_END_NAMESPACE
