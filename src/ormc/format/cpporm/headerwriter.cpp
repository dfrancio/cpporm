/*!
 * \file
 * \brief     cpporm header writer implementation
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#include "headerwriter.h"

// C++ library includes
#include <fstream>
#include <sstream>

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
HeaderPreambleWriter::HeaderPreambleWriter(
    const ListGraph &listGraph, const std::string &dir, const std::string &name)
    : GraphVisitor(listGraph), mDirectory(dir)
{
}

/*!
 * \details
 */
bool HeaderPreambleWriter::VisitNode(const NodeContext &context)
{
    auto filename = boost::algorithm::to_lower_copy(context.node.name) + ".h";
    mStream.open(mDirectory + "/" + filename, cOutputStreamFlags);
    if (FLAGS_namespace.empty())
        mStream << boost::format(cPreambleTextNoNamespace) % filename % CPPORM_VERSION;
    else
        mStream << boost::format(cPreambleText) % filename % CPPORM_VERSION % FLAGS_namespace;

    mForwardDecls.clear();
    auto result = VisitChildren(context);
    for (auto &name : mForwardDecls)
        mStream << boost::format(cForwardDeclareEntity) % name;
    mStream.close();
    return result;
}

/*!
 * \details
 */
bool HeaderPreambleWriter::VisitOutEdge(const EdgeContext &context)
{
    assert(context.edge.indexNumber > 0 && context.edge.indexNumber <= context.node.indices.size());
    mForwardDecls.insert(context.edge.refNodeName);
    return true;
}

/*!
 * \details
 */
HeaderSchemaWriter::HeaderSchemaWriter(
    const ListGraph &listGraph, const std::string &dir, const std::string &name)
    : GraphVisitor(listGraph), mDirectory(dir)
{
    boost::tokenizer<boost::char_separator<char>> tokenizer(
        FLAGS_version_fields, boost::char_separator<char>(","));
    mVersionFields.insert(tokenizer.begin(), tokenizer.end());
}

/*!
 * \details
 */
bool HeaderSchemaWriter::VisitNode(const NodeContext &context)
{
    auto filename = boost::algorithm::to_lower_copy(context.node.name) + ".h";
    mStream.open(mDirectory + "/" + filename, cOutputStreamFlags | cAppendStreamFlags);

    mStream << boost::format(cDeclareEntity) % context.node.name;
    mStream << boost::format(cDeclareEntityMethods);

    mVersionFieldsWritten = false;
    auto result = VisitChildren(context);
    CheckWriteVersionFields(context.node);
    mStream << "};\n";

    if (!FLAGS_namespace.empty())
        mStream << boost::format(cNamespaceEnd) % FLAGS_namespace;
    mStream.close();
    return result;
}

/*!
 * \details
 */
bool HeaderSchemaWriter::VisitField(const FieldContext &context)
{
    mStream << boost::format(cDeclareAttribute) % context.field.name;
    return true;
}

/*!
 * \details
 */
bool HeaderSchemaWriter::VisitIndex(const IndexContext &context)
{
    std::string indexName = boost::algorithm::to_lower_copy(context.index.type);
    if (context.index.type != "PRIMARY_KEY")
    {
        for (auto &name : context.index.fieldNames)
            indexName += indexName.empty() ? name : "_" + name;
    }
    mStream << boost::format(cDeclareIndex) % indexName;
    return true;
}

/*!
 * \details
 */
bool HeaderSchemaWriter::VisitOutEdge(const EdgeContext &context)
{
    assert(context.edge.indexNumber > 0 && context.edge.indexNumber <= context.node.indices.size());

    CheckWriteVersionFields(context.node);

    auto &index = context.node.indices[context.edge.indexNumber - 1];
    std::string relName;
    for (auto &name : index.fieldNames)
        relName += relName.empty() ? name : "_" + name;
    relName += "_" + context.edge.refNodeName;
    mStream << boost::format(cDeclareToOneRelationship) % relName % context.edge.refNodeName;
    return true;
}

/*!
 * \details
 */
bool HeaderSchemaWriter::VisitInEdge(const EdgeContext &context)
{
    assert(
        context.edge.indexNumber > 0
        && context.edge.indexNumber <= context.sourceNode.indices.size());

    CheckWriteVersionFields(context.node);

    auto &index = context.sourceNode.indices[context.edge.indexNumber - 1];
    std::string relName = "all_" + context.sourceNode.name;
    for (auto &name : index.fieldNames)
        relName += relName.empty() ? name : "_" + name;
    mStream << boost::format(cDeclareToManyRelationship) % relName;
    return true;
}

/*!
 * \details
 */
void HeaderSchemaWriter::CheckWriteVersionFields(const Node &node)
{
    if (mVersionFieldsWritten)
        return;

    for (const auto &field : node.fields)
        if (mVersionFields.find(field.name) != mVersionFields.end())
        {
            mStream << boost::format(cDeclareIndex) % CPPORM_INDEX_VERSION;
            break;
        }

    mVersionFieldsWritten = true;
}

/*!
 * \details
 */
const std::string HeaderPreambleWriter::cPreambleText
    = "/*\n"
      " * %s\n"
      " *\n"
      " * generated by the ORM-compiler version %s\n"
      " */\n"
      "#pragma once\n"
      "\n"
      "/*\n"
      " * The entry-point header for cpporm\n"
      " */\n"
      "#include <cpporm/cpporm.h>\n"
      "\n"
      "/*\n"
      " * The client namespace\n"
      " */\n"
      "namespace %s {\n"
      "\n"
      "/*\n"
      " * Forward declarations\n"
      " */\n";

/*!
 * \details
 */
const std::string HeaderPreambleWriter::cPreambleTextNoNamespace
    = "/*\n"
      " * %s\n"
      " *\n"
      " * generated by the ORM-compiler version %s\n"
      " */\n"
      "#pragma once\n"
      "\n"
      "/*\n"
      " * The entry-point header for cpporm\n"
      " */\n"
      "#include <cpporm/cpporm.h>\n"
      "\n"
      "/*\n"
      " * Forward declarations\n"
      " */\n";

/*!
 * \details
 */
const std::string HeaderPreambleWriter::cForwardDeclareEntity = "struct %s;\n";

/*!
 * \details
 */
const std::string HeaderSchemaWriter::cDeclareEntity
    = "\n"
      "/*******************************************************************************\n"
      " * %1%\n"
      " ******************************************************************************/\n"
      "CPPORM_DECLARE_ENTITY(%1%)\n"
      "{\n";

/*!
 * \details
 */
const std::string HeaderSchemaWriter::cDeclareEntityMethods
    = "    CPPORM_DECLARE_ENTITY_METHODS;\n";

/*!
 * \details
 */
const std::string HeaderSchemaWriter::cDeclareAttribute = "    CPPORM_DECLARE_ATTRIBUTE(%s);\n";

/*!
 * \details
 */
const std::string HeaderSchemaWriter::cDeclareIndex = "    CPPORM_DECLARE_INDEX(%s);\n";

/*!
 * \details
 */
const std::string HeaderSchemaWriter::cDeclareToOneRelationship
    = "    CPPORM_DECLARE_TO_ONE_RELATIONSHIP(%s, %s);\n";

/*!
 * \details
 */
const std::string HeaderSchemaWriter::cDeclareToManyRelationship
    = "    CPPORM_DECLARE_TO_MANY_RELATIONSHIP(%s);\n";

/*!
 * \details
 */
const std::string HeaderSchemaWriter::cNamespaceEnd = "\n"
                                                      "} // namespace %s\n";

} // namespace cpporm
