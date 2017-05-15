/*!
 * \file
 * \brief     Query class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

#include <cpporm/util/string.h>

CPPORM_BEGIN_SUB_NAMESPACE(db)

/*!
 * \brief Join type
 */
enum class JoinType
{
    cross, /*!< cross join */
    inner, /*!< inner join */
    natural, /*!< natural join */
    leftouter, /*!< left outer join */
    rightouter, /*!< right outer join */
    fullouter /*!< full outer join */
};

/*!
 * \brief Sort order
 */
enum class SortOrder
{
    ascending,
    descending
};

/*!
 * \brief Database condition
 */
enum class Condition
{
    equal,
    notEqual,
    lessThan,
    greaterThan,
    lessOrEqual,
    greaterOrEqual,
    like,
    isNull,
    notNull
};

/*!
 * \brief %Query
 */
class CPPORM_EXPORT Query
{
public:
    /*!
     * \brief Query
     */
    Query();

    /*!
     * \brief Query
     * \param[in] sql The initial SQL text
     */
    explicit Query(const std::string &sql);

    /*!
     * \brief Add custom query
     * \param[in] query The query
     * \return A reference to *this
     */
    Query &AddCustomQuery(const std::string &query);

    /*!
     * \brief AddContition
     * \param[in] condition The condition type
     * \param[in] value The condition value
     */
    Query &AddContition(Condition condition, const std::string &value = CPPORM_PLACEHOLDER_MARK);

    /*!
     * \brief Begin sub-query
     * \param[in] column The column name
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &SubQueryBegin(const std::string &column = "", const std::string &table = "");

    /*!
     * \brief End sub-query
     * \return A reference to *this
     */
    Query &SubQueryEnd();

    /*!
     * \brief Select all
     * \return A reference to *this
     */
    Query &SelectAll();

    /*!
     * \brief Add select clause
     * \param[in] columns The column names
     * \return A reference to *this
     */
    template <typename... Args>
    Query &Select(Args &&... columns)
    {
        mState += "SELECT " + util::Stringify<','>(std::forward<Args>(columns)...);
        if (mState.back() == ' ')
            mState.pop_back();
        return *this;
    }

    /*!
     * \brief Add distinct clause
     * \param[in] columns The column names
     * \return A reference to *this
     */
    template <typename... Args>
    Query &Distinct(Args &&... columns)
    {
        mState += " DISTINCT " + util::Stringify<','>(std::forward<Args>(columns)...);
        if (mState.back() == ' ')
            mState.pop_back();
        return *this;
    }

    /*!
     * \brief Add columns
     * \param[in] columns The column names
     * \return A reference to *this
     */
    template <typename... Args>
    Query &Columns(Args &&... columns)
    {
        mState += " (" + util::Stringify<','>(std::forward<Args>(columns)...) + ")";
        return *this;
    }

    /*!
     * \brief Add values clause
     * \param[in] values The values
     * \return A reference to *this
     */
    template <typename... Args>
    Query &Values(Args &&... values)
    {
        mState += " VALUES (" + util::Stringify<','>(std::forward<Args>(values)...) + ")";
        return *this;
    }

    /*!
     * \brief Add individual column to a select clause
     * \param[in] column The column name
     * \return A reference to *this
     */
    Query &IncrementalSelect(const std::string &column);

    /*!
     * \brief Finish the select clause in incremental mode
     * \param[in] table The table name (optional)
     * \return A reference to *this
     */
    Query &EndIncrementalSelect(const std::string &table = "");

    /*!
     * \brief Add individual name-value-pair to a insert clause
     * \param[in] column The column name
     * \param[in] value The value
     * \return A reference to *this
     */
    Query &IncrementalInsert(
        const std::string &column, const std::string &value = CPPORM_PLACEHOLDER_MARK);

    /*!
     * \brief Finish the insert clause in incremental mode
     * \return A reference to *this
     */
    Query &EndIncrementalInsert();

    /*!
     * \brief Add individual name-value-pair to an update clause
     * \param[in] column The column name
     * \param[in] value The value
     * \return A reference to *this
     */
    Query &IncrementalUpdate(
        const std::string &column, const std::string &value = CPPORM_PLACEHOLDER_MARK);

    /*!
     * \brief Finish the update clause in incremental mode
     * \return A reference to *this
     */
    Query &EndIncrementalUpdate();

    /*!
     * \brief Add individual condition to a where clause
     * \param[in] column The column name
     * \param[in] value The value
     * \param[in] condition The condition
     * \return A reference to *this
     */
    Query &IncrementalWhere(
        const std::string &column, Condition condition,
        const std::string &value = CPPORM_PLACEHOLDER_MARK);

    /*!
     * \brief Finish the where clause in incremental mode
     * \return A reference to *this
     */
    Query &EndIncrementalWhere();

    /*!
     * \brief Add create table clause
     * \param[in] name The table name
     * \param[in] temp A flag to indicate whether table should be created in the temporary schema
     * \param[in] ifNotExists A flag to indicate whether table should be created only if it does not
     * exist
     * \return A reference to *this
     */
    virtual Query &CreateTable(
        const std::string &name, bool temp = false, bool ifNotExists = false);

    /*!
     * \brief Add drop table clause
     * \param[in] name The table name
     * \param[in] temp A flag to indicate whether table should be dropped from the temporary schema
     * \param[in] ifExists A flag to indicate whether table should be dropped only if it exists
     * \return A reference to *this
     */
    virtual Query &DropTable(const std::string &name, bool temp = false, bool ifExists = false);

    /*!
     * \brief Add individual column to index
     * \param[in] column The column name
     * \return A reference to *this
     */
    Query &IncrementalIndex(const std::string &column);

    /*!
     * \brief Finish the index in incremental mode
     * \param[in] type The index type
     * \return A reference to *this
     */
    Query &EndIncrementalIndex(const std::string &type);

    /*!
     * \brief Add individual column definitions to a create table clause
     * \param[in] name The column name
     * \param[in] type The column datatype
     * \param[in] length The column length
     * \param[in] decimals The number of fractional digits
     * \param[in] defaultValue The column default value
     * \param[in] primaryKey The column primary key constraint
     * \param[in] unique The column unique constraint
     * \param[in] notNull The column not null constraint
     * \param[in] autoIncrement The column auto increment flag
     * \return A reference to *this
     */
    Query &IncrementalColumn(
        const std::string &name, const std::string &type, unsigned long long length = 0,
        unsigned int decimals = 0, const std::string &defaultValue = "", bool primaryKey = false,
        bool unique = false, bool notNull = false, bool autoIncrement = false);

    /*!
     * \brief Finish the create table clause in incremental mode
     * \return A reference to *this
     */
    Query &EndIncrementalColumn();

    /*!
     * \brief Add in clause
     * \param[in] values The values
     * \return A reference to *this
     */
    template <typename... Args>
    Query &In(Args &&... values)
    {
        mState += " IN (" + util::Stringify<','>(std::forward<Args>(values)...) + ")";
        return *this;
    }

    /*!
     * \brief Add column alias
     * \param[in] alias The column alias
     * \return A reference to *this
     */
    Query &As(const std::string &alias);

    /*!
     * \brief Add update clause
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &Update(const std::string &table);

    /*!
     * \brief Add delete query
     * \return A reference to *this
     */
    Query &Delete();

    /*!
     * \brief Add insert clause
     * \return A reference to *this
     */
    Query &Insert();

    /*!
     * \brief Add into clause
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &Into(const std::string &table);

    /*!
     * \brief Add from clause
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &From(const std::string &table);

    /*!
     * \brief Add where clause
     * \param[in] column The column name
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &Where(const std::string &column = "", const std::string &table = "");

    /*!
     * \brief Add column
     * \param[in] column The column name
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &Column(const std::string &column, const std::string &table = "");

    /*!
     * \brief Add average function
     * \param[in] column The column name
     * \param[in] table The table name
     * \param[in] distinct A flag to indicate whether the result set should or should not contain
     * duplicate values (default is false, meaning to permit duplicates)
     * \return A reference to *this
     */
    Query &Avg(const std::string &column, const std::string &table = "", bool distinct = false);

    /*!
     * \brief Count all
     * \return A reference to *this
     */
    Query &CountAll();

    /*!
     * \brief Add count function
     * \param[in] column The column name
     * \param[in] table The table name
     * \param[in] distinct A flag to indicate whether the result set should or should not contain
     * duplicate values (default is false, meaning to permit duplicates)
     * \return A reference to *this
     */
    Query &Count(const std::string &column, const std::string &table = "", bool distinct = false);

    /*!
     * \brief Add first function
     * \param[in] column The column name
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &First(const std::string &column, const std::string &table = "");

    /*!
     * \brief Add last function
     * \param[in] column The column name
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &Last(const std::string &column, const std::string &table = "");

    /*!
     * \brief Add maximum function
     * \param[in] column The column name
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &Max(const std::string &column, const std::string &table = "");

    /*!
     * \brief Add minimum function
     * \param[in] column The column name
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &Min(const std::string &column, const std::string &table = "");

    /*!
     * \brief Add sum function
     * \param[in] column The column name
     * \param[in] table The table name
     * \param[in] distinct A flag to indicate whether the result set should or should not contain
     * duplicate values (default is false, meaning to permit duplicates)
     * \return A reference to *this
     */
    Query &Sum(const std::string &column, const std::string &table = "", bool distinct = false);

    /*!
     * \brief Add like clause
     * \param[in] pattern The pattern
     * \return A reference to *this
     */
    Query &Like(const std::string &pattern);

    /*!
     * \brief Add equality operator
     * \param[in] columnOrValue The column name or value
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &Equals(
        const std::string &columnOrValue = CPPORM_PLACEHOLDER_MARK, const std::string &table = "");

    /*!
     * \brief Add inequality operator
     * \param[in] columnOrValue The column name or value
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &Differs(
        const std::string &columnOrValue = CPPORM_PLACEHOLDER_MARK, const std::string &table = "");

    /*!
     * \brief Add less than operator
     * \param[in] columnOrValue The column name or value
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &LessThan(
        const std::string &columnOrValue = CPPORM_PLACEHOLDER_MARK, const std::string &table = "");

    /*!
     * \brief Add greater than operator
     * \param[in] columnOrValue The column name or value
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &GreaterThan(
        const std::string &columnOrValue = CPPORM_PLACEHOLDER_MARK, const std::string &table = "");

    /*!
     * \brief Add less or equal operator
     * \param[in] columnOrValue The column name or value
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &LessOrEqual(
        const std::string &columnOrValue = CPPORM_PLACEHOLDER_MARK, const std::string &table = "");

    /*!
     * \brief Add greater or equal operator
     * \param[in] columnOrValue The column name or value
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &GreaterOrEqual(
        const std::string &columnOrValue = CPPORM_PLACEHOLDER_MARK, const std::string &table = "");

    /*!
     * \brief Add between operator
     * \param[in] columnOrValue The column name or value
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &Between(
        const std::string &columnOrValue = CPPORM_PLACEHOLDER_MARK, const std::string &table = "");

    /*!
     * \brief Add is clause
     * \return A reference to *this
     */
    Query &Is();

    /*!
     * \brief Add null value
     * \return A reference to *this
     */
    Query &Null();

    /*!
     * \brief Add and conective
     * \param[in] column The column name
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &And(const std::string &column = "", const std::string &table = "");

    /*!
     * \brief Add or conective
     * \param[in] column The column name
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &Or(const std::string &column = "", const std::string &table = "");

    /*!
     * \brief Add not operator
     * \return A reference to *this
     */
    Query &Not();

    /*!
     * \brief Add join clause
     * \param[in] table The table name
     * \param[in] type The type of join (defaults to cross join)
     * \return A reference to *this
     */
    Query &Join(const std::string &table, JoinType type = JoinType::cross);

    /*!
     * \brief Add on clause
     * \param[in] column The column name
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &On(const std::string &column, const std::string &table = "");

    /*!
     * \brief Add group by clause
     * \param[in] column The column name
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &GroupBy(const std::string &column, const std::string &table = "");

    /*!
     * \brief Add having clause
     * \param[in] column The column name
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &Having(const std::string &column, const std::string &table = "");

    /*!
     * \brief Add order by clause
     * \param[in] column The column name
     * \param[in] table The table name
     * \param[in] order The sort order
     * \return A reference to *this
     */
    Query &OrderBy(
        const std::string &column, const std::string &table = "",
        SortOrder order = SortOrder::ascending);

    /*!
     * \brief Add in clause
     * \return A reference to *this
     */
    Query &In();

    /*!
     * \brief Add exists clause
     * \return A reference to *this
     */
    Query &Exists();

    /*!
     * \brief Add union clause
     * \return A reference to *this
     */
    Query &Union();

    /*!
     * \brief Add except clause
     * \return A reference to *this
     */
    Query &Except();

    /*!
     * \brief Add intersect clause
     * \return A reference to *this
     */
    Query &Intersect();

    /*!
     * \brief Add individual column to a match clause
     * \param[in] column The column name
     * \return A reference to *this
     */
    Query &IncrementalMatch(const std::string &column);

    /*!
     * \brief Add date and time of now
     * \return A reference to *this
     */
    virtual Query &Now();

    /*!
     * \brief Add date of now
     * \return A reference to *this
     */
    virtual Query &CurrentDate();

    /*!
     * \brief Add time of now
     * \return A reference to *this
     */
    virtual Query &CurrentTime();

    /*!
     * \brief Add limit clause
     * \param[in] count The count
     * \param[in] offset The offset
     * \return A reference to *this
     */
    virtual Query &Limit(unsigned int count, unsigned int offset = 0);

    /*!
     * \brief Add last insert id clause
     * \return A reference to *this
     */
    virtual Query &LastInsertId();

    /*!
     * \brief Reset sequence
     * \param[in] table The table name
     * \return A reference to *this
     */
    virtual Query &ResetSequence(const std::string &table);

    /*!
     * \brief Create save point
     * \param[in] name The savepoint name
     * \return A reference to *this
     */
    virtual Query &SavePoint(const std::string &name);

    /*!
     * \brief Release save point
     * \param[in] name The savepoint name
     * \return A reference to *this
     */
    virtual Query &ReleaseSavePoint(const std::string &name);

    /*!
     * \brief Rollback to save point
     * \param[in] name The savepoint name
     * \return A reference to *this
     */
    virtual Query &RollbackToSavePoint(const std::string &name);

    /*!
     * \brief Finish the match clause in incremental mode
     * \param[in] pattern The search pattern
     * \param[in] table The table name (optional)
     * \param[in] option The match option (optional)
     * \return A reference to *this
     */
    virtual Query &EndIncrementalMatch(
        const std::string &pattern = CPPORM_PLACEHOLDER_MARK, const std::string &table = "",
        const std::string &option = "");

    /*!
     * \brief Get binding index
     * \return A reference to *this
     */
    short GetBindingIndex() const;

    /*!
     * \brief Get
     * \return The product
     */
    const std::string &Get();

    /*!
     * \brief Get and reset
     * \return The product
     */
    std::string GetAndReset();

    /*!
     * \brief Reset
     * \return A reference to *this
     */
    Query &Reset();

protected:
    /*!
     * \brief Format column definition
     * \param[in] name The column name
     * \param[in] type The column datatype
     * \param[in] length The column length
     * \param[in] decimals The number of fractional digits
     * \param[in] defaultValue The column default value
     * \param[in] primaryKey The column primary key constraint
     * \param[in] unique The column unique constraint
     * \param[in] notNull The column not null constraint
     * \param[in] autoIncrement The column auto increment flag
     * \return The column definition text
     */
    virtual std::string FormatColumnDefinition(
        const std::string &name, const std::string &type, unsigned long long length,
        unsigned int decimals, const std::string &defaultValue, bool primaryKey, bool unique,
        bool notNull, bool autoIncrement);

    /*!
     * \brief The state
     */
    std::string mState;

    /*!
     * \brief The columns
     */
    std::vector<std::string> mColumns;

    /*!
     * \brief The current binding index
     */
    short mBindingIndex;

private:
    /*!
     * \brief The product
     */
    std::string mProduct;

    /*!
     * \brief The values
     */
    std::vector<std::string> mValues;

    /*!
     * \brief The conditions
     */
    std::vector<Condition> mConditions;

    /*!
     * \brief The column definitions
     */
    std::vector<std::string> mColumnDefs;
};

/*!
 * \brief SQLite query
 */
class CPPORM_EXPORT SqliteQuery : public Query
{
    using Query::Query;

public:
    /*!
     * \brief Add drop table clause
     * \param[in] name The table name
     * \param[in] temp A flag to indicate whether table should be dropped from the temporary schema
     * \param[in] ifExists A flag to indicate whether table should be dropped only if it exists
     * \return A reference to *this
     */
    Query &DropTable(const std::string &name, bool temp, bool ifExists) override;

    /*!
     * \brief Add date and time of now
     * \return A reference to *this
     */
    Query &Now() override;

    /*!
     * \brief Add date of now
     * \return A reference to *this
     */
    Query &CurrentDate() override;

    /*!
     * \brief Add time of now
     * \return A reference to *this
     */
    Query &CurrentTime() override;

    /*!
     * \brief Add limit clause
     * \param[in] count The count
     * \param[in] offset The offset
     * \return A reference to *this
     */
    Query &Limit(unsigned int count, unsigned int offset) override;

    /*!
     * \brief Add last insert id clause
     * \return A reference to *this
     */
    Query &LastInsertId() override;

    /*!
     * \brief Reset sequence
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &ResetSequence(const std::string &table) override;

    /*!
     * \brief Finish the match clause in incremental mode
     * \param[in] pattern The search pattern
     * \param[in] table The table name (optional)
     * \param[in] option The match option (optional)
     * \return A reference to *this
     */
    Query &EndIncrementalMatch(
        const std::string &pattern, const std::string &table, const std::string &option) override;

protected:
    /*!
     * \brief Format column definition
     * \param[in] name The column name
     * \param[in] type The column datatype
     * \param[in] length The column length
     * \param[in] decimals The number of fractional digits
     * \param[in] defaultValue The column default value
     * \param[in] primaryKey The column primary key constraint
     * \param[in] unique The column unique constraint
     * \param[in] notNull The column not null constraint
     * \param[in] autoIncrement The column auto increment flag
     * \return The column definition text
     */
    std::string FormatColumnDefinition(
        const std::string &name, const std::string &type, unsigned long long length,
        unsigned int decimals, const std::string &defaultValue, bool primaryKey, bool unique,
        bool notNull, bool autoIncrement) override;
};

/*!
 * \brief SQL Server query
 */
class CPPORM_EXPORT SqlServerQuery : public Query
{
    using Query::Query;

public:
    /*!
     * \brief Add date and time of now
     * \return A reference to *this
     */
    Query &Now() override;

    /*!
     * \brief Add date of now
     * \return A reference to *this
     */
    Query &CurrentDate() override;

    /*!
     * \brief Add time of now
     * \return A reference to *this
     */
    Query &CurrentTime() override;

    /*!
     * \brief Add limit clause
     * \param[in] count The count
     * \param[in] offset The offset
     * \return A reference to *this
     */
    Query &Limit(unsigned int count, unsigned int offset) override;

    /*!
     * \brief Add last insert id clause
     * \return A reference to *this
     */
    Query &LastInsertId() override;

    /*!
     * \brief Reset sequence
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &ResetSequence(const std::string &table) override;

    /*!
     * \brief Create save point
     * \param[in] name The savepoint name
     * \return A reference to *this
     */
    Query &SavePoint(const std::string &name) override;

    /*!
     * \brief Release save point
     * \param[in] name The savepoint name
     * \return A reference to *this
     */
    Query &ReleaseSavePoint(const std::string &name) override;

    /*!
     * \brief Rollback to save point
     * \param[in] name The savepoint name
     * \return A reference to *this
     */
    Query &RollbackToSavePoint(const std::string &name) override;

    /*!
     * \brief Finish the match clause in incremental mode
     * \param[in] pattern The search pattern
     * \param[in] table The table name (optional)
     * \param[in] option The match option (optional)
     * \return A reference to *this
     */
    Query &EndIncrementalMatch(
        const std::string &pattern, const std::string &table, const std::string &option) override;
};

/*!
 * \brief MySQL query
 */
class CPPORM_EXPORT MySqlQuery : public Query
{
    using Query::Query;

public:
    /*!
     * \brief Add date and time of now
     * \return A reference to *this
     */
    Query &Now() override;

    /*!
     * \brief Add date of now
     * \return A reference to *this
     */
    Query &CurrentDate() override;

    /*!
     * \brief Add time of now
     * \return A reference to *this
     */
    Query &CurrentTime() override;

    /*!
     * \brief Add limit clause
     * \param[in] count The count
     * \param[in] offset The offset
     * \return A reference to *this
     */
    Query &Limit(unsigned int count, unsigned int offset) override;

    /*!
     * \brief Add last insert id clause
     * \return A reference to *this
     */
    Query &LastInsertId() override;

    /*!
     * \brief Reset sequence
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &ResetSequence(const std::string &table) override;

    /*!
     * \brief Finish the match clause in incremental mode
     * \param[in] pattern The search pattern
     * \param[in] table The table name (optional)
     * \param[in] option The match option (optional)
     * \return A reference to *this
     */
    Query &EndIncrementalMatch(
        const std::string &pattern, const std::string &table, const std::string &option) override;
};

/*!
 * \brief PostgreSQL query
 */
class CPPORM_EXPORT PostgreSqlQuery : public Query
{
    using Query::Query;

public:
    /*!
     * \brief Add date and time of now
     * \return A reference to *this
     */
    Query &Now() override;

    /*!
     * \brief Add date of now
     * \return A reference to *this
     */
    Query &CurrentDate() override;

    /*!
     * \brief Add time of now
     * \return A reference to *this
     */
    Query &CurrentTime() override;

    /*!
     * \brief Add limit clause
     * \param[in] count The count
     * \param[in] offset The offset
     * \return A reference to *this
     */
    Query &Limit(unsigned int count, unsigned int offset) override;

    /*!
     * \brief Add last insert id clause
     * \return A reference to *this
     */
    Query &LastInsertId() override;

    /*!
     * \brief Reset sequence
     * \param[in] table The table name
     * \return A reference to *this
     */
    Query &ResetSequence(const std::string &table) override;

    /*!
     * \brief Finish the match clause in incremental mode
     * \param[in] pattern The search pattern
     * \param[in] table The table name (optional)
     * \param[in] option The match option (optional)
     * \return A reference to *this
     */
    Query &EndIncrementalMatch(
        const std::string &pattern, const std::string &table, const std::string &option) override;
};

CPPORM_END_SUB_NAMESPACE
