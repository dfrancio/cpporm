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
 * \brief Class that represents a database savepoint
 *
 * Savepoints are similar to transactions, but are intended to be used inside a transaction as a
 * more fine-grained mechanism. It allows one to save the state of a transaction at a specific
 * point and then rollback to this point, reverting everything that happened since, without
 * losing what happened before. Altough savepoints can be released, the transaction can still be
 * rolled back independently of the internal savepoints.
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
     * \brief The transaction object
     */
    Transaction &mTransaction;

    /*!
     * \brief The name of the savepoint
     */
    std::string mName;

    /*!
     * \brief A flag to indicate whether the savepoint was released
     */
    bool mReleased;
};

CPPORM_END_SUB_NAMESPACE
