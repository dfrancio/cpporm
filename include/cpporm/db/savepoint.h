/*!
 * \file
 * \brief     SavePoint class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

#include <cpporm/util/macros.h>

CPPORM_BEGIN_SUB_NAMESPACE(db)

/*
 * Forward declarations
 */
class Transaction;

/*!
 * \brief Savepoint
 */
class CPPORM_EXPORT SavePoint
{
public:
    /*!
     * \brief Constructor
     * \param[in] transaction The transaction
     * \param[in] name The name of the savepoint
     */
    SavePoint(Transaction &transaction, const std::string &name);

    /*!
     * \brief Destructor
     */
    ~SavePoint();

    /*!
     * \brief Release
     */
    void Release();

private:
    /*!
     * \brief The transaction
     */
    Transaction &mTransaction;

    /*!
     * \brief The name of the savepoint
     */
    std::string mName;

    /*!
     * \brief Was released?
     */
    bool mReleased;
};

CPPORM_END_SUB_NAMESPACE
