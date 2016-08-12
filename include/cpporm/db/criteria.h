/*!
 * \file
 * \brief     Search criteria class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

#include <cpporm/db/query.h>

CPPORM_BEGIN_NAMESPACE

/*
 * Forward declarations
 */
class Relationship;

CPPORM_END_NAMESPACE

CPPORM_BEGIN_SUB_NAMESPACE(db)

/*!
 * \brief %Criteria base class
 */
typedef std::map<std::string, std::pair<Condition, std::string>> CriteriaBase;

/*!
 * \brief Order-by specification class
 */
typedef std::vector<std::pair<std::string, SortOrder>> OrderBySpec;

/*!
 * \brief %Criteria
 */
class CPPORM_EXPORT Criteria : public CriteriaBase
{
public:
    /*
     * \brief Add criterion
     * \param[in] name The column name
     * \param[in] condition The condition
     * \param[in] value The column value
     * \return A reference to *this
     */
    Criteria &AddCriterion(const std::string &name, Condition condition, const std::string &value);

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
     * \brief Set limit count
     * \param[in] name The column name
     * \param[in] order The sort order
     * \return A reference to *this
     */
    Criteria &AddOrderBy(const std::string &name, SortOrder order);

    /*
     * \brief Get limit count
     * \return The limit count
     */
    unsigned int GetLimitCount() const;

    /*
     * \brief Get limit offset
     * \return The limit offset
     */
    unsigned int GetLimitOffset() const;

    /*
     * \brief Get order-by
     * \return The order-by specs
     */
    const OrderBySpec &GetOrderBy() const;

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
     * \brief Set cached only
     * \param[in] value The value of the flag
     * \return A reference to *this
     */
    Criteria &SetCachedOnly(bool value);

    /*
     * \brief Get cached only
     * \return The value of the flag
     */
    bool GetCachedOnly() const;

    /*!
     * \brief The limit count
     */
    unsigned int mLimitCount = 0;

    /*!
     * \brief The limit offset
     */
    unsigned int mLimitOffset = 0;

    /*!
     * \brief The order by specifications
     */
    OrderBySpec mOrderBy;

    /*!
     * \brief The cached only flag
     */
    bool mCachedOnly = false;
};

CPPORM_END_SUB_NAMESPACE
