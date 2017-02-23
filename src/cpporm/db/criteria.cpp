/*!
 * \file
 * \brief     Criteria implementation
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#include <cpporm/db/criteria.h>

// Internal library includes
#include <cpporm/db/statement.h>

CPPORM_BEGIN_SUB_NAMESPACE(db)

/*
 * \details
 */
Criteria &Criteria::AddJoin(
    JoinType join, const std::string &table, const std::string &column,
    const std::string &conditionTable, const std::string &conditionColumn)
{
    mJoins.emplace_back(join, table, column, conditionTable, conditionColumn);
    return *this;
}

/*
 * \details
 */
Criteria &Criteria::AddCondition(
    const std::string &table, const std::string &column, Condition condition,
    const std::string &value)
{
    mConditions.emplace_back(table, column, condition, value);
    return *this;
}

/*
 * \details
 */
Criteria &Criteria::AddCondition(
    const std::string &column, Condition condition, const std::string &value)
{
    mConditions.emplace_back("", column, condition, value);
    return *this;
}

/*
 * \details
 */
Criteria &Criteria::OpenScope(LogicalConnective value)
{
    mScopeOpenings.emplace(mConditions.size(), value);
    return *this;
}

/*
 * \details
 */
Criteria &Criteria::CloseScope()
{
    mScopeEndings.emplace(mConditions.size());
    return *this;
}

/*
 * \details
 */
Criteria &Criteria::AddOrderBy(const std::string &table, const std::string &name, SortOrder order)
{
    mOrderBys.emplace_back(table, name, order);
    return *this;
}

/*
 * \details
 */
Criteria &Criteria::AddOrderBy(const std::string &name, SortOrder order)
{
    mOrderBys.emplace_back("", name, order);
    return *this;
}

/*
 * \details
 */
Criteria &Criteria::SetLimitCount(unsigned int count)
{
    mLimitCount = count;
    return *this;
}

/*
 * \details
 */
Criteria &Criteria::SetLimitOffset(unsigned int offset)
{
    mLimitOffset = offset;
    return *this;
}

/*
 * \details
 */
Criteria &Criteria::SetCachedOnly(bool value)
{
    mCachedOnly = value;
    return *this;
}

/*
 * \details
 */
void Criteria::Compose(Query &query) const
{
    ProcessJoins(query);
    ProcessConditions(query);
    ProcessOrderByAndLimit(query);
}

/*
 * \details
 */
void Criteria::Bind(Statement &statement) const
{
    std::size_t index = 0;
    for (auto &spec : mConditions)
        if (std::get<2>(spec) != Condition::isNull && std::get<2>(spec) != Condition::notNull)
            statement.Bind(index++, std::get<3>(spec));
}

/*
 * \details
 */
Criteria &Criteria::Reset()
{
    mConditions.clear();
    mScopeOpenings.clear();
    mScopeEndings.clear();
    mJoins.clear();
    mOrderBys.clear();
    return *this;
}

/*
 * \details
 */
bool Criteria::GetCachedOnly() const
{
    return mCachedOnly;
}

/*
 * \details
 */
void Criteria::ProcessJoins(Query &query) const
{
    for (auto &spec : mJoins)
    {
        query.Join(std::get<1>(spec), std::get<0>(spec));
        if (!std::get<2>(spec).empty())
        {
            query.On(std::get<2>(spec), std::get<1>(spec))
                .Equals(std::get<4>(spec), std::get<3>(spec));
        }
    }
}

/*
 * \details
 */
void Criteria::ProcessConditions(Query &query) const
{
    assert(mScopeOpenings.size() == mScopeEndings.size());
    if (mConditions.empty())
        return;

    std::size_t i = 0;
    std::stack<LogicalConnective> connectives;
    query.Where();
    ProcessScopeOpenings(query, connectives, i);

    auto &spec = mConditions[i];
    query.Column(std::get<1>(spec), std::get<0>(spec)).AddContition(std::get<2>(spec));

    for (++i; i < mConditions.size(); ++i)
    {
        ProcessScopeEndings(query, connectives, i);
        switch (connectives.empty() ? LogicalConnective::conjunction : connectives.top())
        {
        case LogicalConnective::conjunction:
            query.And();
            break;
        case LogicalConnective::disjunction:
            query.Or();
            break;
        }
        auto &spec = mConditions[i];
        ProcessScopeOpenings(query, connectives, i);
        query.Column(std::get<1>(spec), std::get<0>(spec)).AddContition(std::get<2>(spec));
    }
    ProcessScopeEndings(query, connectives, i);
}

/*
 * \details
 */
void Criteria::ProcessOrderByAndLimit(Query &query) const
{
    for (auto &spec : mOrderBys)
        query.OrderBy(std::get<1>(spec), std::get<0>(spec), std::get<2>(spec));
    if (mLimitCount > 0)
        query.Limit(mLimitCount, mLimitOffset);
}

/*
 * \details
 */
void Criteria::ProcessScopeOpenings(
    Query &query, std::stack<LogicalConnective> &connectives, std::size_t i) const
{
    auto end = mScopeOpenings.upper_bound(i);
    for (auto it = mScopeOpenings.lower_bound(i); it != end; ++it)
    {
        query.SubQueryBegin();
        connectives.push(it->second);
    }
}

/*
 * \details
 */
void Criteria::ProcessScopeEndings(
    Query &query, std::stack<LogicalConnective> &connectives, std::size_t i) const
{
    auto end = mScopeEndings.upper_bound(i);
    for (auto it = mScopeEndings.lower_bound(i); it != end; ++it)
    {
        query.SubQueryEnd();
        assert(!connectives.empty());
        connectives.pop();
    }
}

CPPORM_END_SUB_NAMESPACE
