/*!
 * \file
 * \brief     cpporm serializer implementation
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#include "serializer.h"

// External library includes
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>
#include <boost/tokenizer.hpp>

// Internal library includes
#include "entrypointwriter.h"
#include "headerwriter.h"
#include "implementationwriter.h"
#include "standaloneheaderwriter.h"
#include "standaloneimplementationwriter.h"

// Global variables
CPPORM_REGISTER(SerializerFactory, cpporm::Serializer, cpporm, "cpporm");
DEFINE_string(version_fields, "", "comma-separated list of names of version fields");
DEFINE_string(guid_tables, "", "comma-separated list of names of GUID-enabled tables");
DEFINE_string(
    guid_fields, "",
    "comma-separated list of names of columns used for detection of GUID-enabled tables");
DEFINE_bool(amalgamate, true, "whether to amalgamate the output into one .cpp and one .h");

namespace cpporm
{
/*!
 * \details
 */
void Serializer::Parse(const std::string &, ListGraph &)
{
    throw NotImplementedError("cpporm::Serializer::Parse(const std::string &, ListGraph &)");
}

/*!
 * \details
 */
void Serializer::Write(const std::string &dir, const std::string &name, const ListGraph &graph)
{
    if (!FLAGS_amalgamate)
    {
        EntryPointHeaderWriter(graph, dir, name).Visit();
        EntryPointImplementationWriter(graph, dir, name).Visit();
        HeaderPreambleWriter(graph, dir, name).Visit();
        HeaderSchemaWriter(graph, dir, name).Visit();
        ImplementationPreambleWriter(graph, dir, name).Visit();
        ImplementationEntityWriter(graph, dir, name).Visit();
    }
    else
    {
        StandaloneHeaderPreambleWriter(graph, dir, name).Visit();
        StandaloneHeaderSchemaWriter(graph, dir, name).Visit();
        StandaloneImplementationPreambleWriter(graph, dir, name).Visit();
        StandaloneImplementationEntityWriter(graph, dir, name).Visit();
    }
}

} // namespace cpporm
