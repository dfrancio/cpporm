/*!
 * \file
 * \brief     SOCI session class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

// Internal library includes
#include <cpporm/backend/soci/connection.h>
#include <cpporm/db/iudcontext.h>
#include <cpporm/db/session.h>

CPPORM_BEGIN_SUB_SUB_NAMESPACE(backend, soci)

/*!
 * \brief Class that implements a database session for the SOCI backend
 */
class CPPORM_SOCI_EXPORT Session : public db::Session
{
public:
    /*!
     * \brief Construct a new session object
     */
    Session();

    /*!
     * \brief Get database connection
     * \return The database connection
     */
    db::Connection &GetConnection() override;

protected:
    /*!
     * \brief Get database cache
     * \return The database cache
     */
    db::Cache &GetCache() override;

    /*!
     * \brief Get database context
     * \return The database context
     */
    db::Context &GetContext() override;

private:
    /*!
     * \brief Befriend Transaction class
     */
    friend class Transaction;

    /*!
     * \brief The database cache
     */
    db::Cache mCache;

    /*!
     * \brief The database context
     */
    db::IudContext mContext;

    /*!
     * \brief The database connection
     */
    Connection mConnection;
};

CPPORM_END_SUB_SUB_NAMESPACE
