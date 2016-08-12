/*!
 * \file
 * \brief     nanodbc statement class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

// External library includes
#include <nanodbc.h>

// Internal library includes
#include <cpporm/backend/nanodbc/export.h>
#include <cpporm/db/statement.h>

CPPORM_BEGIN_SUB_SUB_NAMESPACE(backend, nanodbc)

/*!
 * \brief Database statement
 */
class CPPORM_NANODBC_EXPORT Statement : public db::Statement
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
     * \brief Constructor
     * \param[in] native The native connection object
     */
    Statement(::nanodbc::connection &native);

    /*!
     * \brief The native statement object
     */
    ::nanodbc::statement mNativeStatement;

    /*!
     * \brief The list of copies of bound values
     */
    std::list<std::u16string> mCopies;
};

CPPORM_END_SUB_SUB_NAMESPACE
