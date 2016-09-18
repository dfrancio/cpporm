/*!
 * \file
 * \brief     flatbuffers serializer implementation
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#include "serializer.h"

// External library includes
#include <gflags/gflags.h>

// Global variables
CPPORM_REGISTER(SerializerFactory, flatbuffers::Serializer, flatbuffers, "flatbuffers");
DEFINE_string(root_type, "", "root table for the flatbuffers serialized data");

namespace flatbuffers
{
/*!
 * \brief Header preamble writer
 */
class IdlPreambleWriter : public GraphVisitor
{
public:
    /*!
     * \brief Constructor
     * \param[in] listGraph The list graph
     * \param[in] matrixGraph The matrix graph
     * \param[in] stream The stream
     * \param[in] filename The filename to put in boilerplate code
     */
    IdlPreambleWriter(
        const ListGraph &listGraph, const MatrixGraph &matrixGraph, std::ostream &stream,
        const std::string &filename)
        : GraphVisitor(listGraph, matrixGraph), mStream(stream)
    {
        if (FLAGS_namespace.empty())
            mStream << boost::format(cPreambleTextNoNamespace) % filename % CPPORM_VERSION;
        else
            mStream << boost::format(cPreambleText) % filename % CPPORM_VERSION % FLAGS_namespace;
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
     * \brief Stream
     */
    std::ostream &mStream;
};

/*!
 * \brief Header schema writer
 */
class IdlSchemaWriter : public GraphVisitor
{
public:
    /*!
     * \brief Constructor
     * \param[in] listGraph The list graph
     * \param[in] matrixGraph The matrix graph
     * \param[in] stream The stream
     */
    IdlSchemaWriter(
        const ListGraph &listGraph, const MatrixGraph &matrixGraph, std::ostream &stream)
        : GraphVisitor(listGraph, matrixGraph), mStream(stream)
    {
    }

    /*!
     * \brief Visit node
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitNode(const NodeContext &context) override
    {
        mAttributesPassed = false;
        mToOneRelationshipsPassed = false;
        mToManyRelationshipsPassed = false;

        mStream << boost::format(cDeclareEntity) % context.node.name % context.node.name;
        mStream << "{";
        auto result = VisitChildren(context);
        mStream << "}\n";
        return result;
    }

    /*!
     * \brief Visit field
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitField(const FieldContext &context) override
    {
        if (!mAttributesPassed)
        {
            mStream << boost::format(cDeclareAttributes) % context.node.name;
            mAttributesPassed = true;
        }
        //        auto it = context.field.properties.find("DEFAULT_VALUE");
        //        if (it == context.field.properties.end())
        mStream << boost::format(cDeclareAttribute) % context.field.name % "string";
        //        else
        //            mStream << boost::format(cDeclareAttributeWithDefault) % context.field.name %
        //            context.field.dataType % it->second;
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
            context.edge.indexNumber > 0 && context.edge.indexNumber <= context.node.indices.size()
            && !context.edge.refFieldNames.empty());

        if (!mToOneRelationshipsPassed)
        {
            mStream << boost::format(cDeclareToOneRelationships) % context.node.name;
            mToOneRelationshipsPassed = true;
        }

        auto &index = context.node.indices[context.edge.indexNumber - 1];
        mStream << boost::format(cDeclareToOneRelationship) % index.fieldNames[0]
                % context.edge.refNodeName % context.edge.refNodeName;
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
            context.edge.indexNumber > 0 && context.edge.indexNumber <= context.node.indices.size()
            && !context.edge.refFieldNames.empty());

        if (!mToManyRelationshipsPassed)
        {
            mStream << boost::format(cDeclareToManyRelationships) % context.edge.refNodeName;
            mToManyRelationshipsPassed = true;
        }

        auto &index = context.node.indices[context.edge.indexNumber - 1];
        mStream << boost::format(cDeclareToManyRelationship) % context.node.name
                % index.fieldNames[0] % context.node.name;
        return true;
    }

private:
    /*!
     * \brief
     */
    static const std::string cDeclareEntity;

    /*!
     * \brief
     */
    static const std::string cDeclareAttribute;

    /*!
     * \brief
     */
    static const std::string cDeclareAttributes;

    //    /*!
    //     * \brief
    //     */
    //    static const std::string cDeclareAttributeWithDefault;

    /*!
     * \brief
     */
    static const std::string cDeclareToOneRelationships;

    /*!
     * \brief
     */
    static const std::string cDeclareToOneRelationship;

    /*!
     * \brief
     */
    static const std::string cDeclareToManyRelationships;

    /*!
     * \brief
     */
    static const std::string cDeclareToManyRelationship;

    /*!
     * \brief Stream
     */
    std::ostream &mStream;

    /*
     * Internal flags
     */
    bool mAttributesPassed;
    bool mToOneRelationshipsPassed;
    bool mToManyRelationshipsPassed;
};

/*!
 * \brief Root type writer
 */
class RootTypeWriter
{
public:
    /*!
     * \brief Destructor
     */
    ~RootTypeWriter()
    {
        if (!FLAGS_root_type.empty())
            mStream << boost::format(cRootType) % FLAGS_root_type;
    }

    /*!
     * \brief Constructor
     * \param[in] stream The stream
     */
    RootTypeWriter(std::ostream &stream) : mStream(stream)
    {
    }

private:
    /*!
     * \brief
     */
    static const std::string cRootType;

    /*!
     * \brief Stream
     */
    std::ostream &mStream;
};

/*!
 * \details
 */
const std::string IdlPreambleWriter::cPreambleText = "//\n"
                                                     "// %s\n"
                                                     "//\n"
                                                     "// generated by the ORM-compiler version %s\n"
                                                     "//\n"
                                                     "\n"
                                                     "namespace %s;\n";

/*!
 * \details
 */
const std::string IdlPreambleWriter::cPreambleTextNoNamespace
    = "//\n"
      "// %s\n"
      "//\n"
      "// generated by the ORM-compiler version %s\n"
      "//\n"
      "\n";

/*!
 * \details
 */
const std::string IdlSchemaWriter::cDeclareEntity = "\n"
                                                    "//\n"
                                                    "// Entity %s\n"
                                                    "//\n"
                                                    "table %s\n";

/*!
 * \details
 */
const std::string IdlSchemaWriter::cDeclareAttributes = "\n"
                                                        "    //\n"
                                                        "    // %s fields\n"
                                                        "    //\n";

/*!
 * \details
 */
const std::string IdlSchemaWriter::cDeclareAttribute = "    %s:%s;\n";

///*!
// * \details
// */
// const std::string HeaderSchemaWriter::cDeclareAttributeWithDefault = "    %s:%s = %s;\n";

/*!
 * \details
 */
const std::string IdlSchemaWriter::cDeclareToOneRelationships = "\n"
                                                                "    //\n"
                                                                "    // %s to-one relationships\n"
                                                                "    //\n";

/*!
 * \details
 */
const std::string IdlSchemaWriter::cDeclareToOneRelationship = "    %s_%s:%s;\n";

/*!
 * \details
 */
const std::string IdlSchemaWriter::cDeclareToManyRelationships = "\n"
                                                                 "    //\n"
                                                                 "    // %s to-many relationships\n"
                                                                 "    //\n";

/*!
 * \details
 */
const std::string IdlSchemaWriter::cDeclareToManyRelationship = "    %s_%s:[%s];\n";

/*!
 * \details
 */
const std::string RootTypeWriter::cRootType = "\n"
                                              "root_type %s;\n";

/*!
 * \details
 */
void Serializer::Parse(const std::string &, ListGraph &)
{
    throw cpporm::NotImplementedError(
        "flatbuffers::Serializer::Parse(const std::string &, ListGraph &)");
}

/*!
 * \details
 */
void Serializer::Write(const std::string &dir, const std::string &name, const ListGraph &graph)
{
    MatrixGraph mMatrixGraph(graph);

    std::ofstream idlStream(dir + "/" + name + ".fbs");
    IdlPreambleWriter idlPreambleWriter(graph, mMatrixGraph, idlStream, name + ".fbs");
    idlPreambleWriter.Visit();
    IdlSchemaWriter idlSchemaWriter(graph, mMatrixGraph, idlStream);
    idlSchemaWriter.Visit();
    RootTypeWriter{idlStream};
}

} // namespace flatbuffers
