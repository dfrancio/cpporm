/*!
 * \file
 * \brief     cpporm implementation writer implementation
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#include "implementationwriter.h"

// C++ library includes
#include <sstream>

// External library includes
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>
#include <boost/tokenizer.hpp>

// Internal library includes
#include <cpporm/version.h>

// Global variables
static const auto cOutputStreamFlags = std::ios_base::binary | std::fstream::out;
static const auto cAppendStreamFlags = std::ios_base::ate | std::fstream::in;

namespace cpporm
{
/*!
 * \details
 */
ImplementationPreambleWriter::ImplementationPreambleWriter(
    const ListGraph &listGraph, const std::string &dir, const std::string &name)
    : GraphVisitor(listGraph), mDirectory(dir)
{
}

/*!
 * \details
 */
bool ImplementationPreambleWriter::VisitNode(const NodeContext &context)
{
    auto entityFactoryFilename = boost::algorithm::to_lower_copy(FLAGS_factory_name) + ".h";
    auto filename = boost::algorithm::to_lower_copy(context.node.name) + ".cpp";
    auto header = boost::algorithm::to_lower_copy(context.node.name) + ".h";
    mStream.open(mDirectory + "/" + filename, cOutputStreamFlags);
    mStream << boost::format(cPreambleText) % filename % CPPORM_VERSION % header
            % entityFactoryFilename;

    mIncludes.clear();
    auto result = VisitChildren(context);

    for (auto &name : mIncludes)
    {
        auto filename = boost::algorithm::to_lower_copy(name) + ".h";
        mStream << boost::format(cIncludeEntityHeader) % filename;
    }

    if (!FLAGS_namespace.empty())
        mStream << boost::format(cBeginNamespace) % FLAGS_namespace;
    mStream.close();
    return result;
}

/*!
 * \details
 */
bool ImplementationPreambleWriter::VisitOutEdge(const EdgeContext &context)
{
    assert(context.edge.indexNumber > 0 && context.edge.indexNumber <= context.node.indices.size());
    mIncludes.insert(context.edge.refNodeName);
    return true;
}

/*!
 * \details
 */
bool ImplementationPreambleWriter::VisitInEdge(const EdgeContext &context)
{
    assert(
        context.edge.indexNumber > 0
        && context.edge.indexNumber <= context.sourceNode.indices.size());
    mIncludes.insert(context.sourceNode.name);
    return true;
}

/*!
 * \details
 */
ImplementationEntityWriter::ImplementationEntityWriter(
    const ListGraph &listGraph, const std::string &dir, const std::string &name)
    : GraphVisitor(listGraph), mDirectory(dir)
{
    {
        boost::tokenizer<boost::char_separator<char>> tokenizer(
            FLAGS_version_fields, boost::char_separator<char>(","));
        mVersionFields.insert(tokenizer.begin(), tokenizer.end());
    }
    {
        boost::tokenizer<boost::char_separator<char>> tokenizer(
            FLAGS_guid_tables, boost::char_separator<char>(","));
        mGuidTables.insert(tokenizer.begin(), tokenizer.end());
    }
    {
        boost::tokenizer<boost::char_separator<char>> tokenizer(
            FLAGS_guid_fields, boost::char_separator<char>(","));
        mGuidFields.insert(tokenizer.begin(), tokenizer.end());
    }
}

/*!
 * \details
 */
bool ImplementationEntityWriter::VisitNode(const NodeContext &context)
{
    auto filename = boost::algorithm::to_lower_copy(context.node.name) + ".cpp";
    mStream.open(mDirectory + "/" + filename, cOutputStreamFlags | cAppendStreamFlags);

    std::ostringstream propertiesStream;
    for (auto &pair : context.node.properties)
        propertiesStream << boost::format(cMapProperty) % pair.first % pair.second;

    if (UseGuid(context.node))
        propertiesStream << boost::format(cMapProperty) % CPPORM_PROP_USE_GUID % "";

    mAttributeStream.str(std::string());
    mIndexStream.str(std::string());
    mRelationshipStream.str(std::string());
    mVersionFieldsWritten = false;
    mStream << boost::format(cWriteEntityComment) % context.node.name;
    mStream << boost::format(cRegisterEntity) % FLAGS_factory_name % context.node.name;
    auto result = VisitChildren(context);
    CheckWriteVersionFields(context.node);
    auto properties = propertiesStream.str();
    auto attributes = mAttributeStream.str();
    auto indices = mIndexStream.str();
    auto relationships = mRelationshipStream.str();
    if (!properties.empty())
        properties.pop_back();
    if (!attributes.empty())
        attributes.pop_back();
    if (!indices.empty())
        indices.pop_back();
    if (!relationships.empty())
        relationships.pop_back();
    mStream << boost::format(cDefineEntityMethods) % context.node.name % properties;
    mStream << boost::format(cDefineEntityAttributes) % context.node.name % attributes;
    mStream << boost::format(cDefineEntityIndices) % context.node.name % indices;
    mStream << boost::format(cDefineEntityRelationships) % context.node.name % relationships;

    if (!FLAGS_namespace.empty())
        mStream << boost::format(cNamespaceEnd) % FLAGS_namespace;
    mStream.close();
    return result;
}

/*!
 * \details
 */
bool ImplementationEntityWriter::VisitField(const FieldContext &context)
{
    std::ostringstream propertiesStream;
    for (auto &pair : context.field.properties)
        propertiesStream << boost::format(cMapProperty) % pair.first % pair.second;
    propertiesStream << boost::format(cMapProperty) % CPPORM_PROP_DATA_TYPE
            % context.field.dataType;
    auto properties = propertiesStream.str();
    if (!properties.empty())
        properties.pop_back();

    mAttributeStream << boost::format(cMapAttribute) % context.node.name % context.field.name;
    mStream << boost::format(cDefineAttribute) % context.node.name % context.field.name
            % properties;
    return true;
}

/*!
 * \details
 */
bool ImplementationEntityWriter::VisitIndex(const IndexContext &context)
{
    std::ostringstream propertiesStream;
    for (auto &pair : context.index.properties)
        propertiesStream << boost::format(cMapProperty) % pair.first % pair.second;
    auto properties = propertiesStream.str();
    if (!properties.empty())
        properties.pop_back();

    std::ostringstream attributeStream;
    for (auto &name : context.index.fieldNames)
        attributeStream << boost::format(cMapAttribute) % context.node.name % name;
    auto attributes = attributeStream.str();
    if (!attributes.empty())
        attributes.pop_back();

    std::string indName = boost::algorithm::to_lower_copy(context.index.type);
    if (context.index.type != "PRIMARY_KEY")
    {
        for (auto &name : context.index.fieldNames)
            indName += indName.empty() ? name : "_" + name;
    }
    mIndexStream << boost::format(cMapIndex) % context.node.name % indName;
    mStream << boost::format(cDefineIndex) % context.node.name % indName % properties % attributes;
    return true;
}

/*!
 * \details
 */
bool ImplementationEntityWriter::VisitOutEdge(const EdgeContext &context)
{
    assert(context.edge.indexNumber > 0 && context.edge.indexNumber <= context.node.indices.size());

    CheckWriteVersionFields(context.node);

    auto &index = context.node.indices[context.edge.indexNumber - 1];
    std::string relName, fkNames, refNames;
    std::string indName = CPPORM_INDEX_FOREIGN_KEY;
    std::string reciprocalName = "all_" + context.edge.refNodeName;
    for (auto &name : index.fieldNames)
    {
        if (!fkNames.empty())
            fkNames += ", ";
        fkNames += "\"" + name + "\"";
        indName += "_" + name;
        relName += relName.empty() ? name : "_" + name;
        reciprocalName += "_" + name;
    }
    relName += "_" + context.edge.refNodeName;
    for (auto &name : context.edge.refFieldNames)
    {
        if (!refNames.empty())
            refNames += ", ";
        refNames += "\"" + name + "\"";
    }
    mRelationshipStream << boost::format(cMapRelationship) % context.node.name % relName;
    mStream << boost::format(cDefineRelationship) % context.node.name % relName % indName % fkNames
            % refNames % reciprocalName % context.node.name % context.edge.refNodeName;
    mStream << boost::format(cDefineToOneRelationship) % context.node.name % relName
            % context.edge.refNodeName;
    return true;
}

/*!
 * \details
 */
bool ImplementationEntityWriter::VisitInEdge(const EdgeContext &context)
{
    assert(
        context.edge.indexNumber > 0
        && context.edge.indexNumber <= context.sourceNode.indices.size());

    CheckWriteVersionFields(context.node);

    auto &index = context.sourceNode.indices[context.edge.indexNumber - 1];
    std::string reciprocalName, fkNames, refNames;
    std::string indName = CPPORM_INDEX_FOREIGN_KEY;
    std::string relName = "all_" + context.sourceNode.name;
    for (auto &name : index.fieldNames)
    {
        if (!fkNames.empty())
            fkNames += ", ";
        fkNames += "\"" + name + "\"";
        indName += "_" + name;
        reciprocalName += reciprocalName.empty() ? name : "_" + name;
        relName += "_" + name;
    }
    reciprocalName += "_" + context.sourceNode.name;
    for (auto &name : context.edge.refFieldNames)
    {
        if (!refNames.empty())
            refNames += ", ";
        refNames += "\"" + name + "\"";
    }
    mRelationshipStream << boost::format(cMapRelationship) % context.node.name % relName;
    mStream << boost::format(cDefineRelationship) % context.node.name % relName % indName % fkNames
            % refNames % reciprocalName % context.sourceNode.name % context.sourceNode.name;
    return true;
}

/*!
 * \details
 */
void ImplementationEntityWriter::CheckWriteVersionFields(const Node &node)
{
    if (mVersionFieldsWritten)
        return;

    std::ostringstream attributeStream;
    for (const auto &field : node.fields)
        if (mVersionFields.find(field.name) != mVersionFields.end())
        {
            attributeStream << boost::format(cMapAttribute) % node.name % field.name;
            break;
        }

    auto attributes = attributeStream.str();
    if (!attributes.empty())
    {
        mIndexStream << boost::format(cMapIndex) % node.name % CPPORM_INDEX_VERSION;
        attributes.pop_back();
        mStream << boost::format(cDefineIndex) % node.name % CPPORM_INDEX_VERSION % "" % attributes;
    }

    mVersionFieldsWritten = true;
}

/*!
 * \details
 */
bool ImplementationEntityWriter::UseGuid(const Node &node)
{
    if (mGuidTables.find(node.name) != mGuidTables.end())
        return true;

    for (auto &field : node.fields)
        if (mGuidFields.find(field.name) != mGuidFields.end())
            return true;

    return false;
}

/*!
 * \details
 */
const std::string ImplementationPreambleWriter::cPreambleText
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
      "#include \"%s\"\n"
      "\n"
      "/*\n"
      " * The required entity headers\n"
      " */\n";

/*!
 * \brief
 */
const std::string ImplementationPreambleWriter::cIncludeEntityHeader = "#include \"%s\"\n";

/*!
 * \details
 */
const std::string ImplementationPreambleWriter::cBeginNamespace = "\n"
                                                                  "/*\n"
                                                                  " * The client namespace\n"
                                                                  " */\n"
                                                                  "namespace %s {\n";

/*!
 * \details
 */
const std::string ImplementationEntityWriter::cWriteEntityComment
    = "\n"
      "/*******************************************************************************\n"
      " * %1%\n"
      " ******************************************************************************/\n";
/*!
 * \brief
 */
const std::string ImplementationEntityWriter::cRegisterEntity
    = "CPPORM_REGISTER(%1%, %2%, %2%, \"%2%\");\n";

/*!
 * \details
 */
const std::string ImplementationEntityWriter::cDefineEntityMethods
    = "cpporm::Entity *%1%::Clone() const {\n"
      "    auto *result = new %1%();\n"
      "    *result = *this;\n"
      "    return result;\n"
      "}\n"
      "const std::string &%1%::GetName() const {\n"
      "    static const std::string cName = \"%1%\";\n"
      "    return cName;\n"
      "}\n"
      "const cpporm::PropertyMap &%1%::GetProperties() const {\n"
      "    static const cpporm::PropertyMap cMap = {%2%};\n"
      "    return cMap;\n"
      "}\n";

/*!
 * \details
 */
const std::string ImplementationEntityWriter::cDefineEntityAttributes
    = "const cpporm::AttributeMap &%1%::GetAttributes() const {\n"
      "    static const cpporm::AttributeMap cMap = {%2%};\n"
      "    return cMap;\n"
      "}\n";

/*!
 * \details
 */
const std::string ImplementationEntityWriter::cDefineEntityIndices
    = "const cpporm::IndexMap &%1%::GetIndices() const {\n"
      "    static const cpporm::IndexMap cMap = {%2%};\n"
      "    return cMap;\n"
      "}\n";

/*!
 * \details
 */
const std::string ImplementationEntityWriter::cDefineEntityRelationships
    = "const cpporm::RelationshipMap &%1%::GetRelationships() const {\n"
      "    static const cpporm::RelationshipMap cMap = {%2%};\n"
      "    return cMap;\n"
      "}\n";

/*!
 * \details
 */
const std::string ImplementationEntityWriter::cMapProperty = "\n        {\"%1%\", \"%2%\"},";

/*!
 * \details
 */
const std::string ImplementationEntityWriter::cMapAttribute
    = "\n        CPPORM_MAP_ATTRIBUTE(%1%, %2%),";

/*!
 * \details
 */
const std::string ImplementationEntityWriter::cMapIndex = "\n        CPPORM_MAP_INDEX(%1%, %2%),";

/*!
 * \details
 */
const std::string ImplementationEntityWriter::cMapRelationship
    = "\n        CPPORM_MAP_RELATIONSHIP(%1%, %2%),";

/*!
 * \details
 */
const std::string ImplementationEntityWriter::cDefineAttribute
    = "const std::string &%1%::_attribute_%2%::GetName() const {\n"
      "    static const std::string cName = \"%2%\";\n"
      "    return cName;\n"
      "}\n"
      "const cpporm::PropertyMap &%1%::_attribute_%2%::GetProperties() const {\n"
      "    static const cpporm::PropertyMap cMap = {%3%};\n"
      "    return cMap;\n"
      "}\n"
      "%1%::_attribute_%2% &%1%::_attribute_%2%::operator=(const Attribute &other) {\n"
      "    mValue = other.Get();\n"
      "    return *this;\n"
      "}\n"
      "%1%::_attribute_%2% &%1%::_attribute_%2%::operator=(const std::string &value) {\n"
      "    mValue = value;\n"
      "    return *this;\n"
      "}\n";

/*!
 * \details
 */
const std::string ImplementationEntityWriter::cDefineIndex
    = "const std::string &%1%::_index_%2%::GetName() const {\n"
      "    static const std::string cName = \"%2%\";\n"
      "    return cName;\n"
      "}\n"
      "const cpporm::PropertyMap &%1%::_index_%2%::GetProperties() const {\n"
      "    static const cpporm::PropertyMap cMap = {%3%};\n"
      "    return cMap;\n"
      "}\n"
      "const cpporm::AttributeMap &%1%::_index_%2%::GetAttributes() const {\n"
      "    static const cpporm::AttributeMap cMap = {%4%};\n"
      "    return cMap;\n"
      "}\n"
      "%1%::_index_%2% %1%::%2%;\n";

/*!
 * \details
 */
const std::string ImplementationEntityWriter::cDefineRelationship
    = "const std::string &%1%::_relationship_%2%::GetName() const {\n"
      "    static const std::string cName = \"%2%\";\n"
      "    return cName;\n"
      "}\n"
      "const cpporm::PropertyMap &%1%::_relationship_%2%::GetProperties() const {\n"
      "    return %7%::%3%.GetProperties();\n"
      "}\n"
      "const std::vector<std::string> &%1%::_relationship_%2%::GetForeignKeyNames() const {\n"
      "    static const std::vector<std::string> cNames = {%4%};\n"
      "    return cNames;\n"
      "}\n"
      "const std::vector<std::string> &%1%::_relationship_%2%::GetReferencedNames() const {\n"
      "    static const std::vector<std::string> cNames = {%5%};\n"
      "    return cNames;\n"
      "}\n"
      "const std::string &%1%::_relationship_%2%::GetReciprocalName() const {\n"
      "    static const std::string cName = \"%6%\";\n"
      "    return cName;\n"
      "}\n"
      "cpporm::Entity &%1%::_relationship_%2%::GetPrototype() const {\n"
      "    static %8% cEntity;\n"
      "    return cEntity;\n"
      "}\n";

/*!
 * \details
 */
const std::string ImplementationEntityWriter::cDefineToOneRelationship
    = "%3% *%1%::_relationship_%2%::operator->() {\n"
      "    return Get<%3%>();\n"
      "}\n"
      "%3% &%1%::_relationship_%2%::operator*() {\n"
      "    return *Get<%3%>();\n"
      "}\n";

/*!
 * \details
 */
const std::string ImplementationEntityWriter::cNamespaceEnd = "\n"
                                                              "} // namespace %s\n";

} // namespace cpporm
