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
    for (auto &spec : mJoins)
    {
        query.Join(std::get<1>(spec), std::get<0>(spec));
        if (!std::get<2>(spec).empty())
        {
            query.On(std::get<2>(spec), std::get<1>(spec))
                .Equals(std::get<4>(spec), std::get<3>(spec));
        }
    }
    if (!mConditions.empty())
    {
        auto it = mConditions.begin();
        query.Where(std::get<1>(*it), std::get<0>(*it)).AddContition(std::get<2>(*it));
        for (++it; it != mConditions.end(); ++it)
            query.And(std::get<1>(*it), std::get<0>(*it)).AddContition(std::get<2>(*it));
    }
    for (auto &spec : mOrderBys)
        query.OrderBy(std::get<1>(spec), std::get<0>(spec), std::get<2>(spec));
    if (mLimitCount > 0)
        query.Limit(mLimitCount, mLimitOffset);
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

CPPORM_END_SUB_NAMESPACE
