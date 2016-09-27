/*!
 * \file
 * \brief     SavePoint class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#include <cpporm/db/savepoint.h>

// Internal library includes
#include <cpporm/db/transaction.h>

CPPORM_BEGIN_SUB_NAMESPACE(db)

/*!
 * \details
 */
SavePoint::SavePoint(Transaction &transaction, const std::string &name)
    : mTransaction(transaction), mName(name), mReleased(false)
{
    mTransaction.AddSavePoint(mName);
}

/*!
 * \details
 */
SavePoint::~SavePoint()
{
    if (!mReleased)
        mTransaction.RollbackTo(mName, true);
}

/*!
 * \details
 */
void SavePoint::Release()
{
    if (!mReleased)
    {
        mTransaction.Release(mName);
        mReleased = true;
    }
}

CPPORM_END_SUB_NAMESPACE
