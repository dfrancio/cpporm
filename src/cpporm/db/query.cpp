/*!
 * \file
 * \brief     Query class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#include <cpporm/db/query.h>

CPPORM_BEGIN_SUB_NAMESPACE(db)

/*!
 * \details
 */
Query::Query()
{
}

/*!
 * \details
 */
Query::Query(const std::string &sql) : mState(sql)
{
}

/*!
 * \details
 */
Query &Query::AddCustomQuery(const std::string &query)
{
    mState += " " + query;
    return *this;
}

/*!
 * \details
 */
Query &Query::AddContition(Condition condition, const std::string &value)
{
    switch (condition)
    {
    case Condition::equal:
        return Equals(value);
    case Condition::notEqual:
        return Differs(value);
    case Condition::lessThan:
        return LessThan(value);
    case Condition::greaterThan:
        return GreaterThan(value);
    case Condition::lessOrEqual:
        return LessOrEqual(value);
    case Condition::greaterOrEqual:
        return GreaterOrEqual(value);
    case Condition::like:
        return Like(value);
    case Condition::isNull:
        return Is().Null();
    default:
        return *this;
    }
}

/*!
 * \details
 */
Query &Query::SubQueryBegin()
{
    mState += " (";
    return *this;
}

/*!
 * \details
 */
Query &Query::SubQueryEnd()
{
    mState += ')';
    return *this;
}

/*!
 * \details
 */
Query &Query::SelectAll()
{
    mState += "SELECT *";
    return *this;
}

/*!
 * \details
 */
Query &Query::IncrementalSelect(const std::string &column)
{
    mColumns.push_back(column);
    return *this;
}

/*!
 * \details
 */
Query &Query::EndIncrementalSelect()
{
    if (!mColumns.empty())
    {
        mState += " ";
        for (auto &column : mColumns)
            mState += column + ",";
        mState.pop_back();
    }
    mColumns.clear();
    return *this;
}

/*!
 * \details
 */
Query &Query::IncrementalInsert(const std::string &column, const std::string &value)
{
    mColumns.push_back(column);
    mValues.push_back(value);
    if (value == CPPORM_PLACEHOLDER_MARK)
        ++mBindingIndex;
    return *this;
}

/*!
 * \details
 */
Query &Query::EndIncrementalInsert()
{
    assert(mColumns.size() == mValues.size());
    if (!mColumns.empty())
    {
        mState += " (";
        for (auto &column : mColumns)
            mState += column + ",";
        mState.pop_back();
        mState += ") VALUES (";
        for (auto &value : mValues)
            mState += value + ",";
        mState.back() = ')';
    }
    else
    {
        mState += " DEFAULT VALUES";
    }
    mColumns.clear();
    mValues.clear();
    return *this;
}

/*!
 * \details
 */
Query &Query::IncrementalUpdate(const std::string &column, const std::string &value)
{
    mColumns.push_back(column);
    mValues.push_back(value);
    if (value == CPPORM_PLACEHOLDER_MARK)
        ++mBindingIndex;
    return *this;
}

/*!
 * \details
 */
Query &Query::EndIncrementalUpdate()
{
    assert(mColumns.size() == mValues.size());
    if (!mColumns.empty())
    {
        mState += " SET ";
        auto vit = mValues.begin();
        for (auto cit = mColumns.begin(); cit != mColumns.end(); ++cit, ++vit)
            mState += *cit + "=" + *vit + ",";
        mState.pop_back();
    }
    mColumns.clear();
    mValues.clear();
    return *this;
}

/*!
 * \details
 */
Query &Query::IncrementalWhere(
    const std::string &column, Condition condition, const std::string &value)
{
    mColumns.push_back(column);
    mConditions.push_back(condition);
    mValues.push_back(value);
    if (value == CPPORM_PLACEHOLDER_MARK && condition != Condition::isNull)
        ++mBindingIndex;
    return *this;
}

/*!
 * \details
 */
Query &Query::EndIncrementalWhere()
{
    assert(mColumns.size() == mValues.size());
    assert(mColumns.size() == mConditions.size());
    if (!mColumns.empty())
    {
        mState += " WHERE ";
        auto savedBindingIndex = mBindingIndex;
        auto vit = mValues.begin();
        auto coit = mConditions.begin();
        for (auto cit = mColumns.begin(); cit != mColumns.end(); ++cit, ++vit, ++coit)
        {
            mState += *cit;
            AddContition(*coit, *vit);
            mState += " AND ";
        }
        mState.resize(mState.size() - 5);
        mBindingIndex = savedBindingIndex;
    }
    mColumns.clear();
    mConditions.clear();
    mValues.clear();
    return *this;
}

/*!
 * \details
 */
Query &Query::CreateTable(const std::string &name, bool temp, bool ifNotExists)
{
    mState += "CREATE ";
    if (temp)
        mState += "TEMPORARY ";
    mState += "TABLE ";
    if (ifNotExists)
        mState += "IF NOT EXISTS ";
    mState += name;
    return *this;
}

/*!
 * \details
 */
Query &Query::DropTable(const std::string &name, bool temp, bool ifExists)
{
    mState += "DROP ";
    if (temp)
        mState += "TEMPORARY ";
    mState += "TABLE ";
    if (ifExists)
        mState += "IF EXISTS ";
    mState += name;
    return *this;
}

/*!
 * \details
 */
Query &Query::IncrementalIndex(const std::string &column)
{
    mColumns.push_back(column);
    return *this;
}

/*!
 * \details
 */
Query &Query::EndIncrementalIndex(const std::string &type)
{
    if (!mColumns.empty())
    {
        std::string indexDef = type + " (";
        for (auto &name : mColumns)
            indexDef += name + ',';
        indexDef.pop_back();
        indexDef += ')';
        mColumnDefs.push_back(indexDef);
    }
    mColumns.clear();
    return *this;
}

/*!
 * \details
 */
Query &Query::IncrementalColumn(
    const std::string &name, const std::string &type, unsigned long long length,
    unsigned int decimals, const std::string &defaultValue, bool primaryKey, bool unique,
    bool notNull, bool autoIncrement)
{
    mColumnDefs.push_back(
        FormatColumnDefinition(
            name, type, length, decimals, defaultValue, primaryKey, unique, notNull,
            autoIncrement));
    return *this;
}

/*!
 * \details
 */
Query &Query::EndIncrementalColumn()
{
    if (!mColumnDefs.empty())
    {
        mState += " (";
        for (auto &def : mColumnDefs)
            mState += def + ',';
        mState.pop_back();
        mState += ')';
    }
    mColumnDefs.clear();
    return *this;
}

/*!
 * \details
 */
Query &Query::As(const std::string &alias)
{
    mState += " AS " + alias;
    return *this;
}

/*!
 * \details
 */
Query &Query::Update(const std::string &table)
{
    mState += "UPDATE " + table;
    return *this;
}

/*!
 * \details
 */
Query &Query::Delete()
{
    mState += "DELETE";
    return *this;
}

/*!
 * \details
 */
Query &Query::Insert()
{
    mState += "INSERT";
    return *this;
}

/*!
 * \details
 */
Query &Query::Into(const std::string &table)
{
    mState += " INTO " + table;
    return *this;
}

/*!
 * \details
 */
Query &Query::From(const std::string &table)
{
    mState += " FROM " + table;
    return *this;
}

/*!
 * \details
 */
Query &Query::Where(const std::string &column, const std::string &table)
{
    mState += " WHERE " + CPPORM_ADD_TABLE_SCOPE(table) + column;
    return *this;
}

/*!
 * \details
 */
Query &Query::Avg(const std::string &column, const std::string &table, bool distinct)
{
    if (!distinct)
        mState += " AVG(" + CPPORM_ADD_TABLE_SCOPE(table) + column + ")";
    else
        mState += " AVG(DISTINCT " + CPPORM_ADD_TABLE_SCOPE(table) + column + ")";
    return *this;
}

/*!
 * \details
 */
Query &Query::CountAll()
{
    mState += " COUNT(*)";
    return *this;
}

/*!
 * \details
 */
Query &Query::Count(const std::string &column, const std::string &table, bool distinct)
{
    if (!distinct)
        mState += " COUNT(" + CPPORM_ADD_TABLE_SCOPE(table) + column + ")";
    else
        mState += " COUNT(DISTINCT " + CPPORM_ADD_TABLE_SCOPE(table) + column + ")";
    return *this;
}

/*!
 * \details
 */
Query &Query::First(const std::string &column, const std::string &table)
{
    mState += " FIRST(" + CPPORM_ADD_TABLE_SCOPE(table) + column + ")";
    return *this;
}

/*!
 * \details
 */
Query &Query::Last(const std::string &column, const std::string &table)
{
    mState += " LAST(" + CPPORM_ADD_TABLE_SCOPE(table) + column + ")";
    return *this;
}

/*!
 * \details
 */
Query &Query::Max(const std::string &column, const std::string &table)
{
    mState += " MAX(" + CPPORM_ADD_TABLE_SCOPE(table) + column + ")";
    return *this;
}

/*!
 * \details
 */
Query &Query::Min(const std::string &column, const std::string &table)
{
    mState += " MIN(" + CPPORM_ADD_TABLE_SCOPE(table) + column + ")";
    return *this;
}

/*!
 * \details
 */
Query &Query::Sum(const std::string &column, const std::string &table, bool distinct)
{
    if (!distinct)
        mState += " SUM(" + CPPORM_ADD_TABLE_SCOPE(table) + column + ")";
    else
        mState += " SUM(DISTINCT " + CPPORM_ADD_TABLE_SCOPE(table) + column + ")";
    return *this;
}

/*!
 * \details
 */
Query &Query::Like(const std::string &pattern)
{
    mState += " LIKE " + pattern;
    if (pattern == CPPORM_PLACEHOLDER_MARK)
        ++mBindingIndex;
    return *this;
}

/*!
 * \details
 */
Query &Query::Equals(const std::string &value)
{
    mState += "=" + value;
    if (value == CPPORM_PLACEHOLDER_MARK)
        ++mBindingIndex;
    return *this;
}

/*!
 * \details
 */
Query &Query::Differs(const std::string &value)
{
    mState += "<>" + value;
    if (value == CPPORM_PLACEHOLDER_MARK)
        ++mBindingIndex;
    return *this;
}

/*!
 * \details
 */
Query &Query::LessThan(const std::string &value)
{
    mState += "<" + value;
    if (value == CPPORM_PLACEHOLDER_MARK)
        ++mBindingIndex;
    return *this;
}

/*!
 * \details
 */
Query &Query::GreaterThan(const std::string &value)
{
    mState += ">" + value;
    if (value == CPPORM_PLACEHOLDER_MARK)
        ++mBindingIndex;
    return *this;
}

/*!
 * \details
 */
Query &Query::LessOrEqual(const std::string &value)
{
    mState += "<=" + value;
    if (value == CPPORM_PLACEHOLDER_MARK)
        ++mBindingIndex;
    return *this;
}

/*!
 * \details
 */
Query &Query::GreaterOrEqual(const std::string &value)
{
    mState += ">=" + value;
    if (value == CPPORM_PLACEHOLDER_MARK)
        ++mBindingIndex;
    return *this;
}

/*!
 * \details
 */
Query &Query::Between(const std::string &value)
{
    mState += " BETWEEN " + value;
    if (value == CPPORM_PLACEHOLDER_MARK)
        ++mBindingIndex;
    return *this;
}

/*!
 * \details
 */
Query &Query::Is()
{
    mState += " IS";
    return *this;
}

/*!
 * \details
 */
Query &Query::Null()
{
    mState += " NULL";
    return *this;
}

/*!
 * \details
 */
Query &Query::And(const std::string &column, const std::string &table)
{
    mState += " AND " + CPPORM_ADD_TABLE_SCOPE(table) + column;
    return *this;
}

/*!
 * \details
 */
Query &Query::Or(const std::string &column, const std::string &table)
{
    mState += " OR " + CPPORM_ADD_TABLE_SCOPE(table) + column;
    return *this;
}

/*!
 * \details
 */
Query &Query::Not()
{
    mState += " NOT";
    return *this;
}

/*!
 * \details
 */
Query &Query::Join(const std::string &table, JoinType type)
{
    switch (type)
    {
    case JoinType::cross:
        mState += ", " + table;
        break;
    case JoinType::inner:
        mState += " INNER JOIN " + table;
        break;
    case JoinType::natural:
        mState += " NATURAL JOIN " + table;
        break;
    case JoinType::leftouter:
        mState += " LEFT OUTER JOIN " + table;
        break;
    case JoinType::rightouter:
        mState += " RIGHT OUTER JOIN " + table;
        break;
    case JoinType::fullouter:
        mState += " FULL OUTER JOIN " + table;
        break;
    }
    return *this;
}

/*!
 * \details
 */
Query &Query::On(const std::string &column, const std::string &table)
{
    mState += " ON " + CPPORM_ADD_TABLE_SCOPE(table) + column;
    return *this;
}

/*!
 * \details
 */
Query &Query::GroupBy(const std::string &column, const std::string &table)
{
    mState += " GROUP BY " + CPPORM_ADD_TABLE_SCOPE(table) + column;
    return *this;
}

/*!
 * \details
 */
Query &Query::Having(const std::string &column, const std::string &table)
{
    mState += " HAVING " + CPPORM_ADD_TABLE_SCOPE(table) + column;
    return *this;
}

/*!
 * \details
 */
Query &Query::OrderBy(const std::string &column, const std::string &table, SortOrder order)
{
    if (mState.find("ASC") == mState.size() - std::strlen("ASC")
        || mState.find("DESC") == mState.size() - std::strlen("DESC"))
        mState += ", " + CPPORM_ADD_TABLE_SCOPE(table) + column;
    else
        mState += " ORDER BY " + CPPORM_ADD_TABLE_SCOPE(table) + column;

    switch (order)
    {
    case SortOrder::ascending:
        mState += " ASC";
        break;
    case SortOrder::descending:
        mState += " DESC";
        break;
    }
    return *this;
}

/*!
 * \details
 */
Query &Query::In()
{
    mState += " IN";
    return *this;
}

/*!
 * \details
 */
Query &Query::Exists()
{
    mState += " EXISTS";
    return *this;
}

/*!
 * \details
 */
Query &Query::Union()
{
    mState += " UNION";
    return *this;
}

/*!
 * \details
 */
Query &Query::Except()
{
    mState += " EXCEPT";
    return *this;
}

/*!
 * \details
 */
Query &Query::Intersect()
{
    mState += " INTERSECT";
    return *this;
}

/*!
 * \details
 */
Query &Query::Now()
{
    return *this;
}

/*!
 * \details
 */
Query &Query::CurrentDate()
{
    return *this;
}

/*!
 * \details
 */
Query &Query::CurrentTime()
{
    return *this;
}

/*!
 * \details
 */
Query &Query::Limit(unsigned int count, unsigned int offset)
{
    return *this;
}

/*!
 * \details
 */
Query &Query::LastInsertId()
{
    return *this;
}

/*!
 * \details
 */
Query &Query::ResetSequence(const std::string &table)
{
    return *this;
}

/*!
 * \details
 */
Query &Query::SavePoint(const std::string &name)
{
    mState += "SAVEPOINT " + name;
    return *this;
}

/*!
 * \details
 */
Query &Query::ReleaseSavePoint(const std::string &name)
{
    mState += "RELEASE SAVEPOINT " + name;
    return *this;
}

/*!
 * \details
 */
Query &Query::RollbackToSavePoint(const std::string &name)
{
    mState += "ROLLBACK TO SAVEPOINT " + name;
    return *this;
}

/*!
 * \details
 */
short Query::GetBindingIndex() const
{
    return mBindingIndex;
}

/*!
 * \details
 */
const std::string &Query::Get()
{
    if (mProduct.size() <= mState.size() + 1)
        mProduct = mState + ";";
    return mProduct;
}

/*!
 * \details
 */
std::string Query::GetAndReset()
{
    auto result = Get();
    Reset();
    return std::move(result);
}

/*!
 * \details
 */
Query &Query::Reset()
{
    mBindingIndex = -1;
    mState.clear();
    mProduct.clear();
    return *this;
}

/*!
 * \details
 */
std::string Query::FormatColumnDefinition(
    const std::string &name, const std::string &type, unsigned long long length,
    unsigned int decimals, const std::string &defaultValue, bool primaryKey, bool unique,
    bool notNull, bool autoIncrement)
{
    auto lengthSpec = length == 0 ? "" : '(' + std::to_string(length)
            + (decimals == 0 ? "" : ',' + std::to_string(decimals)) + ')';
    return name + ' ' + type + lengthSpec + (defaultValue.empty() ? "" : " DEFAULT " + defaultValue)
        + (primaryKey ? " PRIMARY KEY" : "") + (unique ? " UNIQUE" : "")
        + (notNull ? " NOT NULL" : "") + (autoIncrement ? " AUTO_INCREMENT" : "");
}

/*!
 * \details
 */
Query &SqliteQuery::DropTable(const std::string &name, bool temp, bool ifExists)
{
    mState += "DROP TABLE ";
    if (ifExists)
        mState += "IF EXISTS ";
    if (temp)
        mState += "temp.";
    mState += name;
    return *this;
}

/*!
 * \details
 */
Query &SqliteQuery::Now()
{
    mState += " DATETIME()";
    return *this;
}

/*!
 * \details
 */
Query &SqliteQuery::CurrentDate()
{
    mState += " DATE()";
    return *this;
}

/*!
 * \details
 */
Query &SqliteQuery::CurrentTime()
{
    mState += " TIME()";
    return *this;
}

/*!
 * \details
 */
Query &SqliteQuery::Limit(unsigned int count, unsigned int offset)
{
    mState += " LIMIT " + util::Stringify("", count);
    if (offset > 0)
        mState += " OFFSET " + util::Stringify("", offset);
    return *this;
}

/*!
 * \details
 */
Query &SqliteQuery::LastInsertId()
{
    mState += " last_insert_rowid()";
    return *this;
}

/*!
 * \details
 */
Query &SqliteQuery::ResetSequence(const std::string &table)
{
    mState += "DELETE FROM sqlite_sequence WHERE name = " + table;
    return *this;
}

/*!
 * \details
 */
std::string SqliteQuery::FormatColumnDefinition(
    const std::string &name, const std::string &type, unsigned long long length,
    unsigned int decimals, const std::string &defaultValue, bool primaryKey, bool unique,
    bool notNull, bool autoIncrement)
{
    auto lengthSpec = length == 0 ? "" : '(' + std::to_string(length)
            + (decimals == 0 ? "" : ',' + std::to_string(decimals)) + ')';
    return name + ' ' + type + lengthSpec + (defaultValue.empty() ? "" : " DEFAULT " + defaultValue)
        + (primaryKey ? " PRIMARY KEY" : "") + (unique ? " UNIQUE" : "")
        + (notNull ? " NOT NULL" : "");
}

/*!
 * \details
 */
Query &SqlServerQuery::Now()
{
    mState += " GETDATE()";
    return *this;
}

/*!
 * \details
 */
Query &SqlServerQuery::CurrentDate()
{
    mState += " CONVERT(date, GETDATE())";
    return *this;
}

/*!
 * \details
 */
Query &SqlServerQuery::CurrentTime()
{
    mState += " CONVERT(time, GETDATE())";
    return *this;
}

/*!
 * \details
 */
Query &SqlServerQuery::Limit(unsigned int count, unsigned int offset)
{
    mState += " OFFSET " + util::Stringify("", offset) + " ROWS";
    if (count > 0)
        mState += " FETCH NEXT " + util::Stringify("", count) + " ROWS ONLY";
    return *this;
}

/*!
 * \details
 */
Query &SqlServerQuery::LastInsertId()
{
    mState += " SCOPE_IDENTITY()";
    return *this;
}

/*!
 * \details
 */
Query &SqlServerQuery::ResetSequence(const std::string &table)
{
    mState += "DBCC CHECKIDENT(" + table + ", RESEED, 0)";
    return *this;
}

/*!
 * \details
 */
Query &SqlServerQuery::SavePoint(const std::string &name)
{
    mState += "SAVE TRANSACTION " + name;
    return *this;
}

/*!
 * \details
 */
Query &SqlServerQuery::ReleaseSavePoint(const std::string &name)
{
    return *this;
}

/*!
 * \details
 */
Query &SqlServerQuery::RollbackToSavePoint(const std::string &name)
{
    mState += "ROLLBACK TRANSACTION " + name;
    return *this;
}

/*!
 * \details
 */
Query &MySqlQuery::Now()
{
    mState += " NOW()";
    return *this;
}

/*!
 * \details
 */
Query &MySqlQuery::CurrentDate()
{
    mState += " CURDATE()";
    return *this;
}

/*!
 * \details
 */
Query &MySqlQuery::CurrentTime()
{
    mState += " CURTIME()";
    return *this;
}

/*!
 * \details
 */
Query &MySqlQuery::Limit(unsigned int count, unsigned int offset)
{
    mState += " LIMIT " + util::Stringify("", count);
    if (offset > 0)
        mState += " OFFSET " + util::Stringify("", offset);
    return *this;
}

/*!
 * \details
 */
Query &MySqlQuery::LastInsertId()
{
    mState += " LAST_INSERT_ID()";
    return *this;
}

/*!
 * \details
 */
Query &MySqlQuery::ResetSequence(const std::string &table)
{
    mState += "ALTER TABLE " + table + " AUTO_INCREMENT = 1";
    return *this;
}

/*!
 * \details
 */
Query &PostgreSqlQuery::Now()
{
    mState += " CURRENT_TIMESTAMP()";
    return *this;
}

/*!
 * \details
 */
Query &PostgreSqlQuery::CurrentDate()
{
    mState += " CURRENT_DATE()";
    return *this;
}

/*!
 * \details
 */
Query &PostgreSqlQuery::CurrentTime()
{
    mState += " CURRENT_TIME()";
    return *this;
}

/*!
 * \details
 */
Query &PostgreSqlQuery::Limit(unsigned int count, unsigned int offset)
{
    mState += " LIMIT " + util::Stringify("", count);
    if (offset > 0)
        mState += " OFFSET " + util::Stringify("", offset);
    return *this;
}

/*!
 * \details
 */
Query &PostgreSqlQuery::LastInsertId()
{
    mState += " LASTVAL()";
    return *this;
}

/*!
 * \details
 */
Query &PostgreSqlQuery::ResetSequence(const std::string &table)
{
    mState += "ALTER SEQUENCE " + table + "_id_seq RESTART WITH 1";
    return *this;
}

CPPORM_END_SUB_NAMESPACE
