/*!
 * \file
 * \brief     Statement class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

#include <cpporm/util/macros.h>

CPPORM_BEGIN_SUB_NAMESPACE(db)

/*!
 * \brief Database statement
 */
class CPPORM_EXPORT Statement
{
public:
    /*!
     * \brief Destructor
     */
    virtual ~Statement()
    {
    }

    /*!
     * \brief Prepare
     * \param[in] sql The SQL text
     */
    virtual void Prepare(const std::string &sql) = 0;

    /*!
     * \brief Bind
     * \param[in] param The parameter index
     * \param[in] value The parameter value
     */
    virtual void Bind(short param, const std::string &value) = 0;

    /*!
     * \brief Bind null
     * \param[in] param The parameter index
     */
    virtual void BindNull(short param) = 0;

    /*!
     * \brief Start batch
     */
    virtual void StartBatch() = 0;

    /*!
     * \brief End batch
     */
    virtual void EndBatch() = 0;

    /*!
     * \brief Is batch active
     */
    virtual bool IsBatchActive() = 0;
};

CPPORM_END_SUB_NAMESPACE
