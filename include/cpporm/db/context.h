/*!
 * \file
 * \brief     Context class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

#include <cpporm/util/preprocessor.h>

CPPORM_BEGIN_SUB_NAMESPACE(db)

/*!
 * \brief Database context
 */
class CPPORM_EXPORT Context
{
public:
    /*!
     * \brief Destructor
     */
    virtual ~Context();

    /*!
     * \brief Context function type
     */
    typedef void(ContextFunction)(Context *);

    /*!
     * \brief Activate
     */
    void Activate();

    /*!
     * \brief Rollback
     * \param[in] function The callback function
     */
    void Rollback(std::function<ContextFunction> function = {});

    /*!
     * \brief Commit
     */
    void Commit();

    /*!
     * \brief Add insertion
     * \param[in] key The key
     */
    void AddInsertion(const std::string &key);

    /*!
     * \brief Add update
     * \param[in] oldKey The old key
     * \param[in] newKey The new key
     */
    void AddUpdate(const std::string &oldKey, const std::string &newKey);

    /*!
     * \brief Add deletion
     * \param[in] key The key
     */
    void AddDeletion(const std::string &key);

    /*!
     * \brief Create subcontext
     * \return The newly created subcontext
     */
    virtual Context *CreateSubcontext() = 0;

protected:
    /*!
     * \brief Constructor
     * \param[in] parent The parent context
     */
    explicit Context(Context *parent = nullptr);

    /*!
     * \brief Inner commit
     */
    virtual void InnerCommit() = 0;

    /*!
     * \brief Inner rollback
     */
    virtual void InnerRollback() = 0;

    /*!
     * \brief Inner release
     * \param[in] context The context to release to
     */
    virtual void InnerRelease(Context &context) = 0;

    /*!
     * \brief Inner add insertion
     * \param[in] key The key
     */
    virtual void InnerAddInsertion(const std::string &key) = 0;

    /*!
     * \brief Inner add update
     * \param[in] oldKey The old key
     * \param[in] newKey The new key
     */
    virtual void InnerAddUpdate(const std::string &oldKey, const std::string &newKey) = 0;

    /*!
     * \brief Inner add deletion
     * \param[in] key The key
     */
    virtual void InnerAddDeletion(const std::string &key) = 0;

private:
    /*!
     * \brief Commit all contexts
     */
    void CommitAll();

    /*!
     * \brief Rollback all contexts
     */
    void RollbackAll();

    /*!
     * \brief Rollback to this context
     * \param[in] function The callback function
     */
    void RollbackToThis(std::function<ContextFunction> function);

    /*!
     * \brief Release this
     */
    void ReleaseThis();

    /*!
     * \brief The parent context
     */
    Context *mParentContext;

    /*!
     * \brief The subcontext
     */
    Context *mSubcontext;

    /*!
     * \brief The subcontext
     */
    bool mActive;
};

CPPORM_END_SUB_NAMESPACE
