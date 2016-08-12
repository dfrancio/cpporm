/*!
 * \file
 * \brief     nanodbc transaction implementation
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#include <cpporm/backend/nanodbc/transaction.h>

// Internal library includes
#include <cpporm/backend/nanodbc/session.h>

CPPORM_BEGIN_SUB_SUB_NAMESPACE(backend, nanodbc)

/*!
 * \details
 */
Transaction::Transaction(Session &session)
    : db::Transaction(session),
      mNativeTransaction(
          new ::nanodbc::transaction(
              (session.mConnection.Connect(), session.mConnection.mNativeConnection)))
{
}

/*!
 * \details
 */
void Transaction::Rollback()
{
    if (!mNativeTransaction)
        throw DatabaseTransactionError("The transaction object cannot be handled twice.");
    try
    {
        mNativeTransaction->rollback();
    }
    catch (const std::exception &e)
    {
        throw DatabaseTransactionError(e.what());
    }
    mNativeTransaction.reset();
    db::Transaction::Rollback();
}

/*!
 * \details
 */
void Transaction::Commit()
{
    if (!mNativeTransaction)
        throw DatabaseTransactionError("The transaction object cannot be handled twice.");
    try
    {
        mNativeTransaction->commit();
    }
    catch (const std::exception &e)
    {
        throw DatabaseTransactionError(e.what());
    }
    mNativeTransaction.reset();
    db::Transaction::Commit();
}

CPPORM_END_SUB_SUB_NAMESPACE
