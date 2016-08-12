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
 * \brief Database transaction
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
     */
    void RollbackTo(const std::string &name);

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
