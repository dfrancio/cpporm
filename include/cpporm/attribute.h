/*!
 * \file
 * \brief     Attribute class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

#include <cpporm/util/preprocessor.h>

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
 * \brief %Attribute
 */
class CPPORM_EXPORT Attribute
{
public:
    /*!
     * \brief Destructor
     */
    virtual ~Attribute();

    /*!
     * \brief Get name
     * \return The attribute name
     */
    virtual const std::string &GetName() const = 0;

    /*!
     * \brief Get properties
     * \return The attribute properties
     */
    virtual const PropertyMap &GetProperties() const = 0;

    /*!
     * \brief Get
     * \return The attribute value
     */
    const std::string &Get() const;

    /*!
     * \brief operator ->
     * \return The attribute value
     */
    const std::string *operator->() const;

    /*!
     * \brief Set value
     * \param[in] value The new value
     */
    void Set(const std::string &value);

    /*!
     * \brief Set null
     */
    void SetNull();

    /*!
     * \brief Is null?
     * \return True if the attribute is null; false otherwise
     */
    bool IsNull() const;

    /*!
     * \brief Constructor
     */
    Attribute();

    /*!
     * \brief Constructor
     * \param[in] value The initial attribute value
     */
    Attribute(const std::string &value);

    /*!
     * \brief operator =
     * \param[in] value The new value
     * \return A reference to *this
     */
    Attribute &operator=(const std::string &value);

    /*!
     * \brief operator ==
     * \param[in] other The other attribute
     * \return True, if the attribute values are equal; false otherwise
     */
    bool operator==(const Attribute &other) const;

    /*!
     * \brief operator !=
     * \param[in] other The other attribute
     * \return True, if the attribute values are different; false otherwise
     */
    bool operator!=(const Attribute &other) const;

    /*!
     * \brief Was modified?
     * \return True, if the entity was modified; false otherwise
     */
    bool WasModified();

    /*!
     * \brief Rollback
     */
    void Rollback();

    /*!
     * \brief Commit
     */
    void Commit();

    /*!
     * \brief Push state
     */
    void PushState();

    /*!
     * \brief Save state
     */
    void SaveState();

    /*!
     * \brief Extract
     * \param[in] cursor The database cursor
     */
    void Extract(db::Cursor &cursor);

    /*!
     * \brief Insert into database
     */
    void Insert(db::Query &query);

    /*!
     * \brief Update in database
     */
    void Update(db::Query &query);

    /*!
     * \brief Add where clause
     * \param[in] query The database query
     */
    void Where(db::Query &query);

    /*!
     * \brief Bind to statement
     * \param[in] statement The database statement
     * \param[in] useSavedValue A flag to indicate whether to use the saved attribute value
     */
    void Bind(db::Statement &statement, bool useSavedValue = false);

    /*!
     * \brief Validate database schema
     */
    void ValidateSchema() const;

    /*!
     * \brief Create database schema
     * \param[in] query The database query
     */
    void CreateSchema(db::Query &query) const;

    /*!
     * \brief Get GUID
     * \return The GUID
     */
    std::string GetGuid();

    /*!
     * \brief Generate GUID
     */
    void GenerateGuid();

protected:
    /*!
     * \brief The attribute value
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
     * \brief The binding indices
     */
    std::stack<short> mBindingIndices;

    /*!
     * \brief Initialize flags
     */
    void InitializeFlags() const;

    /*
     * Internal flags
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

CPPORM_END_NAMESPACE
