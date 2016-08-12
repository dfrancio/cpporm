/*!
 * \file
 * \brief     SOCI session implementation
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#include <cpporm/backend/soci/session.h>

CPPORM_BEGIN_SUB_SUB_NAMESPACE(backend, soci)

/*!
 * \details
 */
Session::Session() : mContext(mCache)
{
}

/*!
 * \details
 */
db::Connection &Session::GetConnection()
{
    return mConnection;
}

/*!
 * \details
 */
db::Cache &Session::GetCache()
{
    return mCache;
}

/*!
 * \details
 */
db::Context &Session::GetContext()
{
    return mContext;
}

CPPORM_END_SUB_SUB_NAMESPACE
