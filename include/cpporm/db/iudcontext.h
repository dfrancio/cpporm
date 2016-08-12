/*!
 * \file
 * \brief     IudContext class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

#include <cpporm/db/cache.h>
#include <cpporm/db/context.h>

CPPORM_BEGIN_SUB_NAMESPACE(db)

/*!
 * \brief Insertion/Update/Deletion context
 */
class CPPORM_EXPORT IudContext : public Context
{
public:
    /*!
     * \brief Constructor
     * \param[in] cache The cache
     */
    IudContext(Cache &cache);

    /*!
     * \brief Constructor
     * \param[in] parent The parent context
     */
    IudContext(IudContext *parent);

    /*!
     * \brief Create subcontext
     * \return The newly created subcontext
     */
    Context *CreateSubcontext() override;

protected:
    /*!
     * \brief Inner commit
     */
    void InnerCommit() override;

    /*!
     * \brief Inner rollback
     */
    void InnerRollback() override;

    /*!
     * \brief Inner release
     * \param[in] context The context to release to
     */
    void InnerRelease(Context &context) override;

    /*!
     * \brief Inner add insertion
     * \param[in] key The key
     */
    void InnerAddInsertion(const std::string &key) override;

    /*!
     * \brief Inner add update
     * \param[in] oldKey The old key
     * \param[in] newKey The new key
     */
    void InnerAddUpdate(const std::string &oldKey, const std::string &newKey) override;

    /*!
     * \brief Inner add deletion
     * \param[in] key The key
     */
    void InnerAddDeletion(const std::string &key) override;

    /*!
     * \brief The insertion cache
     */
    Cache mInsertions;

    /*!
     * \brief The update cache
     */
    Cache mUpdates;

    /*!
     * \brief The deletion cache
     */
    Cache mDeletions;

private:
    /*!
     * \brief Reset context
     */
    void Reset();

    /*!
     * \brief The main cache
     */
    Cache &mCache;
};

CPPORM_END_SUB_NAMESPACE
