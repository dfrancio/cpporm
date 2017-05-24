/*!
 * \file
 * \brief     Transaction class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

#include <cpporm/db/session.h>

CPPORM_BEGIN_SUB_NAMESPACE(db)

/*!
 * \brief Class that represents a database transaction
 *
 * Transactions can be commited or rolled back. Savepoints can be created inside a transaction.
 */
class CPPORM_EXPORT Transaction
{
public:
    /*!
     * \brief Destructor
     */
    virtual ~Transaction();

    /*!
     * \brief Constructor
     * \param[in] session The database session
     */
    Transaction(Session &session);

    /*!
     * \brief Rollback
     */
    virtual void Rollback();

    /*!
     * \brief Commit
     */
    virtual void Commit();

    /*!
     * \brief Add savepoint
     * \param[in] name The savepoint name
     */
    void AddSavePoint(const std::string &name);

    /*!
     * \brief Rollback to
     * \param[in] name The savepoint name
     * \param[in] remove A flag to indicate whether the savepoint should be removed
     */
    void RollbackTo(const std::string &name, bool remove = false);

    /*!
     * \brief Release
     * \param[in] name The savepoint name
     */
    void Release(const std::string &name);

private:
    /*!
     * \brief Remove save point
     * \param[in] context The context of the savepoint
     */
    void RemoveSavePoint(Context *context);

    /*!
     * \brief The database session
     */
    Session &mSession;

    /*!
     * \brief The list of savepoints
     */
    std::map<std::string, Context *> mSavePoints;
};

CPPORM_END_SUB_NAMESPACE
