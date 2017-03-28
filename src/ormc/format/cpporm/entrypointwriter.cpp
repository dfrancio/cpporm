/*!
 * \file
 * \brief     cpporm entry point writer implementation
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#include "entrypointwriter.h"

// External library includes
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>
#include <boost/tokenizer.hpp>

// Global variables
static const auto cOutputStreamFlags = std::ios_base::binary | std::fstream::out;
static const auto cAppendStreamFlags = std::ios_base::ate | std::fstream::in;

namespace cpporm
{
/*!
 * \details
 */
EntryPointHeaderWriter::~EntryPointHeaderWriter()
{
    if (!FLAGS_namespace.empty())
        mStream << boost::format(cBeginNamespace) % FLAGS_namespace;
    mStream << cDeclareEntityCreator;
    if (!FLAGS_namespace.empty())
        mStream << boost::format(cNamespaceEnd) % FLAGS_namespace;
    mStream.close();
}

/*!
 * \details
 */
EntryPointHeaderWriter::EntryPointHeaderWriter(
    const ListGraph &listGraph, const std::string &dir, const std::string &name)
    : GraphVisitor(listGraph)
{
    mStream.open(dir + "/" + name + ".h", cOutputStreamFlags);
    mStream << boost::format(cPreambleText) % (name + ".h") % CPPORM_VERSION;
}

/*!
 * \details
 */
bool EntryPointHeaderWriter::VisitNode(const NodeContext &context)
{
    auto filename = boost::algorithm::to_lower_copy(context.node.name) + ".h";
    mStream << boost::format(cIncludeEntityHeader) % filename;
    return true;
}

/*!
 * \details
 */
EntryPointImplementationWriter::~EntryPointImplementationWriter()
{
}

/*!
 * \details
 */
EntryPointImplementationWriter::EntryPointImplementationWriter(
    const ListGraph &listGraph, const std::string &dir, const std::string &name)
    : GraphVisitor(listGraph)
{
    auto entityFactoryFilename = boost::algorithm::to_lower_copy(FLAGS_factory_name) + ".h";
    mStream.open(dir + "/" + name + ".cpp", cOutputStreamFlags);
    mStream << boost::format(cPreambleText) % (name + ".cpp") % CPPORM_VERSION % (name + ".h")
            % entityFactoryFilename;

    if (!FLAGS_namespace.empty())
        mStream << boost::format(cBeginNamespace) % FLAGS_namespace;
    mStream << boost::format(cDefineEntityCreator) % FLAGS_factory_name;
    if (!FLAGS_namespace.empty())
        mStream << boost::format(cNamespaceEnd) % FLAGS_namespace;

    mStream.close();
}

/*!
 * \details
 */
const std::string EntryPointHeaderWriter::cPreambleText
    = "/*\n"
      " * %s\n"
      " *\n"
      " * generated by the ORM-compiler version %s\n"
      " */\n"
      "#pragma once\n"
      "\n"
      "/*\n"
      " * The entity headers\n"
      " */\n";

/*!
 * \details
 */
const std::string EntryPointHeaderWriter::cIncludeEntityHeader = "#include \"%s\"\n";

/*!
 * \details
 */
const std::string EntryPointHeaderWriter::cBeginNamespace = "\n"
                                                            "/*\n"
                                                            " * The client namespace\n"
                                                            " */\n"
                                                            "namespace %s {\n";

/*!
 * \details
 */
const std::string EntryPointHeaderWriter::cDeclareEntityCreator
    = "\n"
      "/*\n"
      " * The entity creator function\n"
      " */\n"
      "std::shared_ptr<cpporm::Entity> Create(const std::string &key);\n";

/*!
 * \details
 */
const std::string EntryPointHeaderWriter::cNamespaceEnd = "\n"
                                                          "} // namespace %s\n";

/*!
 * \details
 */
const std::string EntryPointImplementationWriter::cPreambleText
    = "/*\n"
      " * %s\n"
      " *\n"
      " * generated by the ORM-compiler version %s\n"
      " */\n"
      "#include \"%s\"\n"
      "\n"
      "/*\n"
      " * The entity factory header\n"
      " */\n"
      "#include \"%s\"\n";

/*!
 * \details
 */
const std::string EntryPointImplementationWriter::cBeginNamespace = "\n"
                                                                    "/*\n"
                                                                    " * The client namespace\n"
                                                                    " */\n"
                                                                    "namespace %s {\n";

/*!
 * \brief
 */
const std::string EntryPointImplementationWriter::cDefineEntityCreator
    = "\n"
      "/*\n"
      "* The entity creator function\n"
      "*/\n"
      "std::shared_ptr<cpporm::Entity> Create(const std::string &key)\n"
      "{\n"
      "    return %s::GetInstance().CreateShared(key);\n"
      "}\n";

/*!
 * \details
 */
const std::string EntryPointImplementationWriter::cNamespaceEnd = "\n"
                                                                  "} // namespace %s\n";

} // namespace cpporm
