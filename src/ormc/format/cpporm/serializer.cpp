/*!
 * \file
 * \brief     cpporm serializer implementation
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#include "serializer.h"

// C++ library includes
#include <fstream>
#include <sstream>

// External library includes
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>
#include <boost/tokenizer.hpp>
#include <gflags/gflags.h>

// Global variables
static const auto cOutputStreamFlags = std::ios_base::binary | std::fstream::out;
static const auto cAppendStreamFlags = std::ios_base::ate | std::fstream::in;
CPPORM_REGISTER(SerializerFactory, cpporm::Serializer, cpporm, "cpporm");
DEFINE_string(version_fields, "", "comma-separated list of names of version fields");

namespace cpporm
{
/*!
 * \brief Header preamble writer
 */
class HeaderPreambleWriter : public GraphVisitor
{
public:
    /*!
     * \brief Destructor
     */
    ~HeaderPreambleWriter()
    {
        mStream << cDeclareEntityCreator;
        mStream.close();
    }

    /*!
     * \brief Constructor
     * \param[in] listGraph The list graph
     * \param[in] matrixGraph The matrix graph
     * \param[in] dir The output directory
     * \param[in] name The output name
     */
    HeaderPreambleWriter(
        const ListGraph &listGraph, const MatrixGraph &matrixGraph, const std::string &dir,
        const std::string &name)
        : GraphVisitor(listGraph, matrixGraph)
    {
        mStream.open(dir + "/" + name + ".h", cOutputStreamFlags);
        if (FLAGS_namespace.empty())
            mStream << boost::format(cPreambleTextNoNamespace) % (name + ".h") % CPPORM_VERSION;
        else
            mStream << boost::format(cPreambleText) % (name + ".h") % CPPORM_VERSION
                    % FLAGS_namespace;
    }

    /*!
     * \brief Visit node
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitNode(const NodeContext &context) override
    {
        mStream << boost::format(cForwardDeclareEntity) % context.node.name;
        return true;
    }

private:
    /*!
     * \brief
     */
    static const std::string cPreambleText;

    /*!
     * \brief
     */
    static const std::string cPreambleTextNoNamespace;

    /*!
     * \brief
     */
    static const std::string cForwardDeclareEntity;

    /*!
     * \brief
     */
    static const std::string cDeclareEntityCreator;

    /*!
     * \brief The output stream
     */
    std::ofstream mStream;
};

/*!
 * \brief Namespace end writer
 */
class NamespaceEndWriter
{
public:
    /*!
     * \brief Destructor
     */
    ~NamespaceEndWriter()
    {
        if (!FLAGS_namespace.empty())
            mStream << boost::format(cNamespaceEnd) % FLAGS_namespace;
    }

    /*!
     * \brief Constructor
     * \param[in] stream The output stream
     */
    NamespaceEndWriter(std::ostream &stream) : mStream(stream)
    {
    }

private:
    /*!
     * \brief
     */
    static const std::string cNamespaceEnd;

    /*!
     * \brief Stream
     */
    std::ostream &mStream;
};

/*!
 * \brief Header schema writer
 */
class HeaderSchemaWriter : public GraphVisitor
{
public:
    /*!
     * \brief Destructor
     */
    ~HeaderSchemaWriter()
    {
        NamespaceEndWriter{mStream};
        mStream.close();
    }

    /*!
     * \brief Constructor
     * \param[in] listGraph The list graph
     * \param[in] matrixGraph The matrix graph
     * \param[in] dir The output directory
     * \param[in] name The output name
     */
    HeaderSchemaWriter(
        const ListGraph &listGraph, const MatrixGraph &matrixGraph, const std::string &dir,
        const std::string &name)
        : GraphVisitor(listGraph, matrixGraph)
    {
        mStream.open(dir + "/" + name + ".h", cOutputStreamFlags | cAppendStreamFlags);
    }

    /*!
     * \brief Visit node
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitNode(const NodeContext &context) override
    {
        mStream << boost::format(cDeclareEntity) % context.node.name;
        mStream << boost::format(cDeclareEntityMethods);

        mVersionFieldsWritten = false;
        auto result = VisitChildren(context);
        CheckWriteVersionFields(context.node);
        mStream << "};\n";
        return result;
    }

    /*!
     * \brief Visit field
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitField(const FieldContext &context) override
    {
        mStream << boost::format(cDeclareAttribute) % context.field.name;
        return true;
    }

    /*!
     * \brief Visit index
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitIndex(const IndexContext &context) override
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
     * \brief Visit out edge
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitOutEdge(const EdgeContext &context) override
    {
        assert(
            context.edge.indexNumber > 0
            && context.edge.indexNumber <= context.node.indices.size());

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
     * \brief Visit in edge
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitInEdge(const EdgeContext &context) override
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

private:
    /*!
     * \brief Check write version fields
     * \param[in] node The current node
     */
    void CheckWriteVersionFields(const Node &node)
    {
        if (mVersionFieldsWritten)
            return;

        std::set<std::string> fieldNames;
        for (const auto &field : node.fields)
            fieldNames.insert(field.name);

        boost::tokenizer<boost::char_separator<char>> tokenizer(
            FLAGS_version_fields, boost::char_separator<char>(","));

        for (auto &token : tokenizer)
            if (fieldNames.find(token) != fieldNames.end())
            {
                mStream << boost::format(cDeclareIndex) % CPPORM_INDEX_VERSION;
                break;
            }

        mVersionFieldsWritten = true;
    }

    /*!
     * \brief
     */
    static const std::string cDeclareEntity;

    /*!
     * \brief
     */
    static const std::string cDeclareEntityMethods;

    /*!
     * \brief
     */
    static const std::string cDeclareAttribute;

    /*!
     * \brief
     */
    static const std::string cDeclareIndex;

    /*!
     * \brief
     */
    static const std::string cDeclareToOneRelationship;

    /*!
     * \brief
     */
    static const std::string cDeclareToManyRelationship;

    /*!
     * \brief The output stream
     */
    std::ofstream mStream;

    /*
     * Internal flags
     */
    bool mVersionFieldsWritten;
};
/*!
 * \brief Implementation preamble writer
 */
class ImplementationPreambleWriter : public GraphVisitor
{
public:
    /*!
     * \brief Destructor
     */
    ~ImplementationPreambleWriter()
    {
        mStream << boost::format(cDefineEntityCreator);
        mStream.close();
    }

    /*!
     * \brief Constructor
     * \param[in] listGraph The list graph
     * \param[in] matrixGraph The matrix graph
     * \param[in] dir The output directory
     * \param[in] name The output name
     */
    ImplementationPreambleWriter(
        const ListGraph &listGraph, const MatrixGraph &matrixGraph, const std::string &dir,
        const std::string &name)
        : GraphVisitor(listGraph, matrixGraph)
    {
        mStream.open(dir + "/" + name + ".cpp", cOutputStreamFlags);
        if (FLAGS_namespace.empty())
            mStream << boost::format(cPreambleTextNoNamespace) % (name + ".cpp") % CPPORM_VERSION
                    % (name + ".h");
        else
            mStream << boost::format(cPreambleText) % (name + ".cpp") % CPPORM_VERSION
                    % (name + ".h") % FLAGS_namespace;

        mStream << boost::format(cDefineEntityFactory);
    }

    /*!
     * \brief Visit node
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitNode(const NodeContext &context) override
    {
        mStream << boost::format(cRegisterEntity) % context.node.name;
        return true;
    }

private:
    /*!
     * \brief
     */
    static const std::string cPreambleText;

    /*!
     * \brief
     */
    static const std::string cPreambleTextNoNamespace;

    /*!
     * \brief
     */
    static const std::string cDefineEntityFactory;

    /*!
     * \brief
     */
    static const std::string cRegisterEntity;

    /*!
     * \brief
     */
    static const std::string cDefineEntityCreator;

    /*!
     * \brief The output stream
     */
    std::ofstream mStream;
};

/*!
 * \brief Implementation entity writer
 */
class ImplementationEntityWriter : public GraphVisitor
{
public:
    /*!
     * \brief Destructor
     */
    ~ImplementationEntityWriter()
    {
        NamespaceEndWriter{mStream};
        mStream.close();
    }

    /*!
     * \brief Constructor
     * \param[in] listGraph The list graph
     * \param[in] matrixGraph The matrix graph
     * \param[in] dir The output directory
     * \param[in] name The output name
     */
    ImplementationEntityWriter(
        const ListGraph &listGraph, const MatrixGraph &matrixGraph, const std::string &dir,
        const std::string &name)
        : GraphVisitor(listGraph, matrixGraph), mDirectory(dir), mName(name)
    {
        mStream.open(dir + "/" + name + ".cpp", cOutputStreamFlags | cAppendStreamFlags);
    }

    /*!
     * \brief Visit node
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitNode(const NodeContext &context) override
    {
        std::ostringstream propertiesStream;
        for (auto &pair : context.node.properties)
            propertiesStream << boost::format(cMapProperty) % pair.first % pair.second;

        mAttributeStream.str(std::string());
        mIndexStream.str(std::string());
        mRelationshipStream.str(std::string());
        mVersionFieldsWritten = false;
        mStream << boost::format(cWriteEntityComment) % context.node.name;
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
        return result;
    }

    /*!
     * \brief Visit field
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitField(const FieldContext &context) override
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
     * \brief Visit index
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitIndex(const IndexContext &context) override
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
        mStream << boost::format(cDefineIndex) % context.node.name % indName % properties
                % attributes;
        return true;
    }

    /*!
     * \brief Visit out edge
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitOutEdge(const EdgeContext &context) override
    {
        assert(
            context.edge.indexNumber > 0
            && context.edge.indexNumber <= context.node.indices.size());

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
        mStream << boost::format(cDefineRelationship) % context.node.name % relName % indName
                % fkNames % refNames % reciprocalName % context.node.name;
        mStream << boost::format(cDefineToOneRelationship) % context.node.name % relName
                % context.edge.refNodeName;
        return true;
    }

    /*!
     * \brief Visit in edge
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitInEdge(const EdgeContext &context) override
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
        mStream << boost::format(cDefineRelationship) % context.node.name % relName % indName
                % fkNames % refNames % reciprocalName % context.sourceNode.name;
        return true;
    }

private:
    /*!
     * \brief Check Write version fields
     * \param[in] node The current node
     */
    void CheckWriteVersionFields(const Node &node)
    {
        if (mVersionFieldsWritten)
            return;

        std::set<std::string> fieldNames;
        for (const auto &field : node.fields)
            fieldNames.insert(field.name);

        boost::tokenizer<boost::char_separator<char>> tokenizer(
            FLAGS_version_fields, boost::char_separator<char>(","));

        std::ostringstream attributeStream;
        for (auto &token : tokenizer)
            if (fieldNames.find(token) != fieldNames.end())
                attributeStream << boost::format(cMapAttribute) % node.name % token;

        auto attributes = attributeStream.str();
        if (!attributes.empty())
        {
            mIndexStream << boost::format(cMapIndex) % node.name % CPPORM_INDEX_VERSION;
            attributes.pop_back();
            mStream << boost::format(cDefineIndex) % node.name % CPPORM_INDEX_VERSION % ""
                    % attributes;
        }

        mVersionFieldsWritten = true;
    }

    /*!
     * \brief
     */
    static const std::string cWriteEntityComment;

    /*!
     * \brief
     */
    static const std::string cDefineEntityMethods;

    /*!
     * \brief
     */
    static const std::string cDefineEntityAttributes;

    /*!
     * \brief
     */
    static const std::string cDefineEntityIndices;

    /*!
     * \brief
     */
    static const std::string cDefineEntityRelationships;

    /*!
     * \brief
     */
    static const std::string cMapProperty;

    /*!
     * \brief
     */
    static const std::string cMapAttribute;

    /*!
     * \brief
     */
    static const std::string cMapIndex;

    /*!
     * \brief
     */
    static const std::string cMapRelationship;

    /*!
     * \brief
     */
    static const std::string cDefineAttribute;

    /*!
     * \brief
     */
    static const std::string cDefineIndex;

    /*!
     * \brief
     */
    static const std::string cDefineRelationship;

    /*!
     * \brief
     */
    static const std::string cDefineToOneRelationship;

    /*!
     * \brief The output stream
     */
    std::ofstream mStream;

    /*!
     * \brief The output directory
     */
    std::string mDirectory;

    /*!
     * \brief The output name
     */
    std::string mName;

    /*
     * Internal variables
     */
    std::ostringstream mAttributeStream;
    std::ostringstream mIndexStream;
    std::ostringstream mRelationshipStream;
    bool mVersionFieldsWritten;
};

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
      "namespace %s\n"
      "{\n"
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
const std::string HeaderPreambleWriter::cDeclareEntityCreator
    = "\n"
      "/*\n"
      " * The entity creator function\n"
      " */\n"
      "std::shared_ptr<cpporm::Entity> Create(const std::string &key);\n";

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
const std::string NamespaceEndWriter::cNamespaceEnd = "\n"
                                                      "} // namespace %s\n";

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
      " * The client namespace\n"
      " */\n"
      "namespace %s\n"
      "{\n";

/*!
 * \details
 */
const std::string ImplementationPreambleWriter::cPreambleTextNoNamespace
    = "/*\n"
      " * %s\n"
      " *\n"
      " * generated by the ORM-compiler version %s\n"
      " */\n"
      "#include \"%s\"\n";

/*!
 * \brief
 */
const std::string ImplementationPreambleWriter::cDefineEntityFactory
    = "\n"
      "/*\n"
      " * The entity factory\n"
      " */\n"
      "class EntityFactory : public cpporm::util::Factory<EntityFactory,\n"
      "                                                   cpporm::Entity, std::string>\n"
      "{\n"
      "private:\n"
      "    EntityFactory()\n"
      "    {\n";
/*!
 * \brief
 */
const std::string ImplementationPreambleWriter::cRegisterEntity
    = "        Register<%1%>(\"%1%\");\n";

/*!
 * \brief
 */
const std::string ImplementationPreambleWriter::cDefineEntityCreator
    = "    }\n"
      "    friend class Factory;\n"
      "};\n"
      "\n"
      "/*\n"
      "* The entity creator function\n"
      "*/\n"
      "std::shared_ptr<cpporm::Entity> Create(const std::string &key)\n"
      "{\n"
      "    return EntityFactory::GetInstance().CreateShared(key);\n"
      "}\n";

/*!
 * \details
 */
const std::string ImplementationEntityWriter::cWriteEntityComment
    = "\n"
      "/*******************************************************************************\n"
      " * %1%\n"
      " ******************************************************************************/\n";

/*!
 * \details
 */
const std::string ImplementationEntityWriter::cDefineEntityMethods
    = "cpporm::Entity *%1%::Clone() const {\n"
      "    return new %1%(*this);\n"
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
      "    static %1% cEntity;\n"
      "    return cEntity;\n"
      "}\n";

/*!
 * \details
 */
const std::string ImplementationEntityWriter::cDefineToOneRelationship
    = "%3% *%1%::_relationship_%2%::operator->() {\n"
      "    return Get<%3%>();\n"
      "}\n";

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
    MatrixGraph mMatrixGraph(graph);
    HeaderPreambleWriter(graph, mMatrixGraph, dir, name).Visit();
    HeaderSchemaWriter(graph, mMatrixGraph, dir, name).Visit();
    ImplementationPreambleWriter(graph, mMatrixGraph, dir, name).Visit();
    ImplementationEntityWriter(graph, mMatrixGraph, dir, name).Visit();
}

} // namespace cpporm
