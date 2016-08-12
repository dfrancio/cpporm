/*!
 * \file
 * \brief     Search criteria class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#include <cpporm/db/criteria.h>

CPPORM_BEGIN_SUB_NAMESPACE(db)

/*
 * \details
 */
Criteria &Criteria::AddCriterion(
    const std::string &name, Condition condition, const std::string &value)
{
    this->emplace(name, std::make_pair(condition, value));
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
Criteria &Criteria::AddOrderBy(const std::string &name, SortOrder order)
{
    mOrderBy.emplace_back(name, order);
    return *this;
}

/*
 * \details
 */
unsigned int Criteria::GetLimitCount() const
{
    return mLimitCount;
}

/*
 * \details
 */
unsigned int Criteria::GetLimitOffset() const
{
    return mLimitOffset;
}

/*
 * \details
 */
const OrderBySpec &Criteria::GetOrderBy() const
{
    return mOrderBy;
}

/*
 * \details
 */
Criteria &Criteria::SetCachedOnly(bool value)
{
    mCachedOnly = value;
}

/*
 * \details
 */
bool Criteria::GetCachedOnly() const
{
    return mCachedOnly;
}

CPPORM_END_SUB_NAMESPACE
