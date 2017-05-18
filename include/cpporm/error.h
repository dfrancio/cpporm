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
 * \brief Generic error class
 *
 * An error object is descendant from `std::runtime_error`. It can be constructed/thrown anywhere
 * deemed necessary. It takes an arbitrary number of parameters of arbitrary types as construction
 * arguments. It then transforms these values to string using the generic util::to_string function,
 * which can be overloaded for any type.
 *
 * All error classes should inherit from this base class, so that their instances can be catched by
 * reference using the base class type or even `std::exception`.
 *
 * One can use the \ref CPPORM_DECLARE_EXCEPTION macro to conveniently declare new exceptions. Some
 * common exception classes are declared as well for convenience.
 *
 * Usage example:
 *
 * ~~~{.cpp}
 * void test()
 * {
 *     try
 *     {
 *         throw new Error("error message");
 *     }
 *     catch (const std::exception &e)
 *     {
 *         std::cout << e.what() << std::endl;
 *     }
 * }
 * ~~~
 */
class CPPORM_VISBILITY_DEFAULT Error : public std::runtime_error
{
public:
    /*!
     * \brief Constructor
     * \param[in] args The construction arguments
     */
    template <typename... Args>
    Error(Args &&... args)
        : std::runtime_error(util::Stringify<':', ' '>(std::forward<Args>(args)...))
    {
    }
};

/*!
 * \brief Error thrown when a procedure is not yet implemented
 */
CPPORM_DECLARE_EXCEPTION(NotImplementedError, "the functionality is not yet implemented", Error);

/*!
 * \brief Error thrown when a procedure is not supported
 */
CPPORM_DECLARE_EXCEPTION(NotSupportedError, "the functionality is not supported", Error);

/*!
 * \brief Error thrown when an element is not found in a container
 */
CPPORM_DECLARE_EXCEPTION(EntryNonExistentError, "the required entry does not exist", Error);

/*!
 * \brief Error thrown when an entity does not exist in the database
 */
CPPORM_DECLARE_EXCEPTION(EntityNonExistentError, "the required entity does not exist", Error);

/*!
 * \brief Error thrown when a specified savepoint does not exist
 */
CPPORM_DECLARE_EXCEPTION(SavePointNonExistentError, "the savepoint does not exist", Error);

/*!
 * \brief Error thrown when a database entity cannot be deleted
 */
CPPORM_DECLARE_EXCEPTION(CannotDeleteEntity, "cannot delete entity", Error);

/*!
 * \brief Error thrown when a database query could not be executed
 */
CPPORM_DECLARE_EXCEPTION(DatabaseExecuteError, "could not execute query in the database", Error);

/*!
 * \brief Error thrown when a database connection cannot be established or terminated
 */
CPPORM_DECLARE_EXCEPTION(
    DatabaseConnectionError, "could not connect or disconnect from the database", Error);

/*!
 * \brief Error thrown when a database statement could not be prepared
 */
CPPORM_DECLARE_EXCEPTION(
    DatabaseStatementPrepareError, "could not prepare database statement", Error);

/*!
 * \brief Error thrown when a parameter could not be bound to a prepared statement
 */
CPPORM_DECLARE_EXCEPTION(DatabaseStatementBindError, "could not bind statement parameter", Error);

/*!
 * \brief Error thrown when a database cursor could not be navigated through
 */
CPPORM_DECLARE_EXCEPTION(
    DatabaseCursorNavigationError, "could not navigate through the result set", Error);

/*!
 * \brief Error thrown when a database cursor could not be queried
 */
CPPORM_DECLARE_EXCEPTION(DatabaseCursorQueryError, "could not query the result set", Error);

/*!
 * \brief Error thrown when an entity could not be updated in the database
 */
CPPORM_DECLARE_EXCEPTION(
    EntityNotUpdatedError, "the entity was not updated in the database", Error);

/*!
 * \brief Error thrown when an entity could not be deleted in the database
 */
CPPORM_DECLARE_EXCEPTION(
    EntityNotDeletedError, "the entity was not deleted in the database", Error);

/*!
 * \brief Error thrown when a database transaction could not be executed properly
 */
CPPORM_DECLARE_EXCEPTION(
    DatabaseTransactionError, "could not execute transaction operation", Error);

/*!
 * \example error.cpp
 *
 * This is an example of how to use the Error class.
 */

CPPORM_END_NAMESPACE
