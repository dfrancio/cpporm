#include <cpporm/error.h>

// C++ library includes
#include <string>

// External library includes
#include <gtest/gtest.h>

// Using namespace
using namespace cpporm;

TEST(CppOrm_Unit_Error, TestSet1)
{
    ASSERT_STREQ(Error("a", 1, 2.3).what(), "a: 1: 2.300000");
    ASSERT_STREQ(NotImplementedError().what(), "the functionality is not yet implemented");
    ASSERT_STREQ(NotSupportedError().what(), "the functionality is not supported");
    ASSERT_STREQ(EntryNonExistentError().what(), "the required entry does not exist");
    ASSERT_STREQ(EntityNonExistentError().what(), "the required entity does not exist");
    ASSERT_STREQ(SavePointNonExistentError().what(), "the savepoint does not exist");
    ASSERT_STREQ(CannotDeleteEntity().what(), "cannot delete entity");
    ASSERT_STREQ(DatabaseExecuteError().what(), "could not execute query in the database");
    ASSERT_STREQ(
        DatabaseConnectionError().what(), "could not connect or disconnect from the database");
    ASSERT_STREQ(DatabaseStatementPrepareError().what(), "could not prepare database statement");
    ASSERT_STREQ(DatabaseStatementBindError().what(), "could not bind statement parameter");
    ASSERT_STREQ(
        DatabaseCursorNavigationError().what(), "could not navigate through the result set");
    ASSERT_STREQ(DatabaseCursorQueryError().what(), "could not query the result set");
    ASSERT_STREQ(EntityNotUpdatedError().what(), "the entity was not updated in the database");
    ASSERT_STREQ(EntityNotDeletedError().what(), "the entity was not deleted in the database");
    ASSERT_STREQ(DatabaseTransactionError().what(), "could not execute transaction operation");
}
