/*!
 * \file
 * \brief     Error types
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#pragma once

#include <cpporm/util/string.h>

CPPORM_BEGIN_NAMESPACE

/*!
 * \brief %Error
 */
class CPPORM_VISBILITY_DEFAULT Error : public std::runtime_error
{
public:
    /*!
     * \brief Constructor
     * \param[in] args The error arguments
     */
    template <typename... Args>
    Error(Args &&... args)
        : std::runtime_error(util::Stringify<':', ' '>(std::forward<Args>(args)...))
    {
    }
};

/*!
 * \brief Convert error
 */
CPPORM_DECLARE_EXCEPTION(ConvertError, "could not convert", Error);

/*!
 * \brief Not implemented error
 */
CPPORM_DECLARE_EXCEPTION(NotImplementedError, "the functionality is not yet implemented", Error);

/*!
 * \brief Not supported error
 */
CPPORM_DECLARE_EXCEPTION(NotSupportedError, "the functionality is not supported", Error);

/*!
 * \brief Entry non existent error
 */
CPPORM_DECLARE_EXCEPTION(EntryNonExistentError, "the required entry does not exist", Error);

/*!
 * \brief Entity non existent error
 */
CPPORM_DECLARE_EXCEPTION(EntityNonExistentError, "the required entity does not exist", Error);

/*!
 * \brief Save point non existent error
 */
CPPORM_DECLARE_EXCEPTION(SavePointNonExistentError, "the savepoint does not exist", Error);

/*!
 * \brief Cannot delete entity
 */
CPPORM_DECLARE_EXCEPTION(CannotDeleteEntity, "cannot delete entity", Error);

/*!
 * \brief Database execute error
 */
CPPORM_DECLARE_EXCEPTION(DatabaseExecuteError, "could not execute query in the database", Error);

/*!
 * \brief Database connection error
 */
CPPORM_DECLARE_EXCEPTION(
    DatabaseConnectionError, "could not connect or disconnect from the database", Error);

/*!
 * \brief Database statement prepare error
 */
CPPORM_DECLARE_EXCEPTION(
    DatabaseStatementPrepareError, "could not prepare database statement", Error);

/*!
 * \brief Database statement bind error
 */
CPPORM_DECLARE_EXCEPTION(DatabaseStatementBindError, "could not bind statement parameter", Error);

/*!
 * \brief Database cursor navigation error
 */
CPPORM_DECLARE_EXCEPTION(
    DatabaseCursorNavigationError, "could not navigate through the result set", Error);

/*!
 * \brief Database cursor query error
 */
CPPORM_DECLARE_EXCEPTION(DatabaseCursorQueryError, "could not query the result set", Error);

/*!
 * \brief Entity not updated error
 */
CPPORM_DECLARE_EXCEPTION(
    EntityNotUpdatedError, "the entity was not updated in the database", Error);

/*!
 * \brief Entity not deleted error
 */
CPPORM_DECLARE_EXCEPTION(
    EntityNotDeletedError, "the entity was not deleted in the database", Error);

/*!
 * \brief Database transaction error
 */
CPPORM_DECLARE_EXCEPTION(
    DatabaseTransactionError, "could not execute transaction operation", Error);

CPPORM_END_NAMESPACE
