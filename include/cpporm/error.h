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
class CPPORM_VISIBILITY_DEFAULT Error : public std::runtime_error
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

CPPORM_DECLARE_EXCEPTION(ConvertError, "could not convert", Error);
CPPORM_DECLARE_EXCEPTION(NotImplementedError, "the functionality is not yet implemented", Error);
CPPORM_DECLARE_EXCEPTION(NotSupportedError, "the functionality is not supported", Error);
CPPORM_DECLARE_EXCEPTION(EntryNonExistentError, "the required entry does not exist", Error);
CPPORM_DECLARE_EXCEPTION(EntityNonExistentError, "the required entity does not exist", Error);
CPPORM_DECLARE_EXCEPTION(SavePointNonExistentError, "the savepoint does not exist", Error);
CPPORM_DECLARE_EXCEPTION(CannotDeleteEntity, "cannot delete entity", Error);
CPPORM_DECLARE_EXCEPTION(DatabaseExecuteError, "could not execute query in the database", Error);
CPPORM_DECLARE_EXCEPTION(
    DatabaseConnectionError, "could not connect or disconnect from the database", Error);
CPPORM_DECLARE_EXCEPTION(
    DatabaseStatementPrepareError, "could not prepare database statement", Error);
CPPORM_DECLARE_EXCEPTION(DatabaseStatementBindError, "could not bind statement parameter", Error);
CPPORM_DECLARE_EXCEPTION(
    DatabaseCursorNavigationError, "could not navigate through the result set", Error);
CPPORM_DECLARE_EXCEPTION(DatabaseCursorQueryError, "could not query the result set", Error);
CPPORM_DECLARE_EXCEPTION(EntityNotUpdated, "the entity was not updated in the database", Error);
CPPORM_DECLARE_EXCEPTION(EntityNotDeleted, "the entity was not deleted in the database", Error);
CPPORM_DECLARE_EXCEPTION(
    DatabaseTransactionError, "could not execute transaction operation", Error);

CPPORM_END_NAMESPACE
