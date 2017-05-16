#error Documentation only

#include <cpporm/config.h>

/*!
 * \brief The cpporm namespace
 *
 * This is the highest-level namespace. It contains the other namespaces and also some of the most
 * important classes in this library.
 */
CPPORM_BEGIN_NAMESPACE

/*!
 * \brief The backend namespace
 *
 * This is where (third-party) library-specific backends are found. A backend is a complement to the
 * core components. It implements the functionality modeled by abstract classes and acts as a bridge
 * between the exposed interface and an actual database driver.
 *
 * \see soci as an example backend
 */
namespace backend
{
/*!
 * \brief The soci namespace
 *
 * SOCI is a database access library for C++. It is one of the few open source libraries which can
 * connect with drivers from several database vendors without resorting to ODBC (altough it supports
 * ODBC also). It is the easiest to use and has good support for binary columns. The only downside
 * is that it does not treat dates and times separately, only date-and-time as one generic data
 * type. SOCI is licensed under the Boost Software License.
 *
 * \see http://soci.sourceforge.net/
 */
namespace soci
{
}
}

/*!
 * \brief The db namespace
 *
 * This is where all database related classes are located. These classes provide an interface to
 * connect/query/modify databases from any vendor supported by a backend. Furthermore, transaction
 * functionalty is implemented in a generic fashion using context objects. There is also a
 * convenience class to construct queries using different sets of criteria. The db::Session is the
 * main class in this namespace.
 */
namespace db
{
}

/*!
 * \brief The util namespace
 *
 * This is where all utility funcions and classes are located.
 */
namespace util
{
}

CPPORM_END_NAMESPACE
