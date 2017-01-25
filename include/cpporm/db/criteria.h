/*!
 * \file
 * \brief     Criteria interface
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

#include <cpporm/db/query.h>

/*
 * Forward declarations
 */
CPPORM_BEGIN_NAMESPACE
class Relationship;
CPPORM_END_NAMESPACE

CPPORM_BEGIN_SUB_NAMESPACE(db)

/*
 * Forward declarations
 */
class Statement;

/*!
 * \brief Join specification
 */
typedef std::tuple<JoinType, std::string, std::string, std::string, std::string> JoinSpec;

/*!
 * \brief Condition specification
 */
typedef std::tuple<std::string, std::string, Condition, std::string> ConditionSpec;

/*!
 * \brief Order-by specification
 */
typedef std::tuple<std::string, std::string, SortOrder> OrderBySpec;

/*!
 * \brief %Criteria
 */
class CPPORM_EXPORT Criteria
{
public:
    /*
     * \brief Add join
     * \param[in] join The join type
     * \param[in] table The table name
     * \param[in] column The column name
     * \param[in] conditionTable The name of the condition table
     * \param[in] conditionColumn The name of the condition column (from the condition table)
     * \return A reference to *this
     */
    Criteria &AddJoin(
        JoinType join, const std::string &table, const std::string &column = "",
        const std::string &conditionTable = "", const std::string &conditionColumn = "");

    /*
     * \brief Add condition
     * \param[in] table The table name
     * \param[in] column The column name
     * \param[in] condition The condition
     * \param[in] value The column value
     * \return A reference to *this
     */
    Criteria &AddCondition(
        const std::string &table, const std::string &column, Condition condition,
        const std::string &value = "");

    /*
     * \brief Add order-by
     * \param[in] table The table name
     * \param[in] column The column name
     * \param[in] order The sort order
     * \return A reference to *this
     */
    Criteria &AddOrderBy(const std::string &table, const std::string &column, SortOrder order);

    /*
     * \brief Set limit count
     * \param[in] count The limit count
     * \return A reference to *this
     */
    Criteria &SetLimitCount(unsigned int count);

    /*
     * \brief Set limit count
     * \param[in] offset The limit offset
     * \return A reference to *this
     */
    Criteria &SetLimitOffset(unsigned int offset);

    /*
     * \brief Set cached only
     * \param[in] value The value of the flag
     * \return A reference to *this
     */
    Criteria &SetCachedOnly(bool value);

    /*
     * \brief Compose
     * \param[in] query The query
     */
    void Compose(Query &query) const;

    /*
     * \brief Bind
     * \param[in] statement The statement
     */
    void Bind(Statement &statement) const;

    /*
     * \brief Reset
     * \return A reference to *this
     */
    Criteria &Reset();

private:
    /*!
     * \brief Befriend class Session
     */
    friend class Session;

    /*!
     * \brief Befriend class Relationship
     */
    friend class cpporm::Relationship;

    /*
     * \brief Get cached only
     * \return The value of the flag
     */
    bool GetCachedOnly() const;

    /*!
     * \brief The set of condition specifications
     */
    std::set<ConditionSpec> mConditions;

    /*!
     * \brief The set of join specifications
     */
    std::set<JoinSpec> mJoins;

    /*!
     * \brief The set of order-by specifications
     */
    std::set<OrderBySpec> mOrderBys;

    /*!
     * \brief The limit count
     */
    unsigned int mLimitCount = 0;

    /*!
     * \brief The limit offset
     */
    unsigned int mLimitOffset = 0;

    /*!
     * \brief The cached only flag
     */
    bool mCachedOnly = false;
};

CPPORM_END_SUB_NAMESPACE
