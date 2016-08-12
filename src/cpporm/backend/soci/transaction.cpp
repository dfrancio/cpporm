/*!
 * \file
 * \brief     SOCI transaction implementation
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#include <cpporm/backend/soci/transaction.h>

// Internal library includes
#include <cpporm/backend/soci/session.h>

CPPORM_BEGIN_SUB_SUB_NAMESPACE(backend, soci)

/*!
 * \details
 */
Transaction::Transaction(Session &session)
    : db::Transaction(session),
      mNativeTransaction((session.mConnection.Connect(), session.mConnection.mNativeConnection))
{
}

/*!
 * \details
 */
void Transaction::Rollback()
{
    try
    {
        mNativeTransaction.rollback();
    }
    catch (const std::exception &e)
    {
        throw DatabaseTransactionError(e.what());
    }
    db::Transaction::Rollback();
}

/*!
 * \details
 */
void Transaction::Commit()
{
    try
    {
        mNativeTransaction.commit();
    }
    catch (const std::exception &e)
    {
        throw DatabaseTransactionError(e.what());
    }
    db::Transaction::Commit();
}

CPPORM_END_SUB_SUB_NAMESPACE
