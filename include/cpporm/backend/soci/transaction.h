/*!
 * \file
 * \brief     SOCI connection class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

// External library includes
#include <soci/soci.h>

// Internal library includes
#include <cpporm/backend/soci/export.h>
#include <cpporm/db/transaction.h>

CPPORM_BEGIN_SUB_SUB_NAMESPACE(backend, soci)

/*
 * Forward declarations
 */
class Session;

/*!
 * \brief Database transaction
 */
class CPPORM_SOCI_EXPORT Transaction : public db::Transaction
{
public:
    /*!
     * \brief Constructor
     * \param[in] session The database session
     */
    Transaction(Session &session);

    /*!
     * \brief Rollback
     */
    void Rollback() override;

    /*!
     * \brief Commit
     */
    void Commit() override;

private:
    /*!
     * \brief The native transaction object
     */
    ::soci::transaction mNativeTransaction;
};

CPPORM_END_SUB_SUB_NAMESPACE
