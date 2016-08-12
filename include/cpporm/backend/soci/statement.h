/*!
 * \file
 * \brief     SOCI statement class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

// External library includes
#include <soci.h>

// Internal library includes
#include <cpporm/backend/soci/export.h>
#include <cpporm/db/statement.h>

CPPORM_BEGIN_SUB_SUB_NAMESPACE(backend, soci)

/*!
 * \brief Database statement
 */
class CPPORM_SOCI_EXPORT Statement : public db::Statement
{
public:
    /*!
     * \brief Prepare
     * \param[in] sql The SQL text
     */
    void Prepare(const std::string &sql) override;

    /*!
     * \brief Bind
     * \param[in] param The parameter index
     * \param[in] value The parameter value
     */
    void Bind(short param, const std::string &value) override;

    /*!
     * \brief Bind null
     * \param[in] param The parameter index
     */
    void BindNull(short param) override;

private:
    /*!
     * \brief Befriend Connection class
     */
    friend class Connection;

    /*!
     * \brief Befriend Cursor class
     */
    friend class Cursor;

    /*!
     * \brief Constructor
     * \param[in] native The native connection object
     */
    Statement(::soci::session &native);

    /*!
     * \brief Execute
     */
    void Execute();

    /*!
     * \brief The native connection object
     */
    ::soci::session &mNativeConnection;

    /*!
     * \brief The native statement object
     */
    ::soci::statement mNativeStatement;

    /*!
     * \brief The native row object
     */
    ::soci::row mNativeRow;

    /*!
     * \brief The list of copies of bound values
     */
    std::list<std::string> mCopies;

    /*!
     * \brief The query to prepare
     */
    std::string mQueryToPrepare;
};

CPPORM_END_SUB_SUB_NAMESPACE
