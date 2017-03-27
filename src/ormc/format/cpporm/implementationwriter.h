/*!
 * \file
 * \brief     cpporm implementation writer implementation
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#include "serializer.h"

// C++ library includes
#include <fstream>

namespace cpporm
{
/*!
 * \brief Implementation preamble writer
 */
class ImplementationPreambleWriter : public GraphVisitor
{
public:
    /*!
     * \brief Constructor
     * \param[in] listGraph The list graph
     * \param[in] dir The output directory
     * \param[in] name The output name
     */
    ImplementationPreambleWriter(
        const ListGraph &listGraph, const std::string &dir, const std::string &name);

    /*!
     * \brief Visit node
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitNode(const NodeContext &context) override;

    /*!
     * \brief Visit out edge
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitOutEdge(const EdgeContext &context) override;

    /*!
     * \brief Visit in edge
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitInEdge(const EdgeContext &context) override;

private:
    /*!
     * \brief
     */
    static const std::string cPreambleText;

    /*!
     * \brief
     */
    static const std::string cIncludeEntityHeader;

    /*!
     * \brief
     */
    static const std::string cBeginNamespace;

    /*!
     * \brief The output stream
     */
    std::ofstream mStream;

    /*!
     * \brief The output directory
     */
    std::string mDirectory;

    /*
     * Internal variables
     */
    std::set<std::string> mIncludes;
};

/*!
 * \brief Implementation entity writer
 */
class ImplementationEntityWriter : public GraphVisitor
{
public:
    /*!
     * \brief Constructor
     * \param[in] listGraph The list graph
     * \param[in] dir The output directory
     * \param[in] name The output name
     */
    ImplementationEntityWriter(
        const ListGraph &listGraph, const std::string &dir, const std::string &name);

    /*!
     * \brief Visit node
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitNode(const NodeContext &context) override;

    /*!
     * \brief Visit field
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitField(const FieldContext &context) override;

    /*!
     * \brief Visit index
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitIndex(const IndexContext &context) override;

    /*!
     * \brief Visit out edge
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitOutEdge(const EdgeContext &context) override;

    /*!
     * \brief Visit in edge
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitInEdge(const EdgeContext &context) override;

private:
    /*!
     * \brief Check Write version fields
     * \param[in] node The current node
     */
    void CheckWriteVersionFields(const Node &node);

    /*!
     * \brief Check use GUID
     * \param[in] node The current node
     * \return True if GUID support for this table should be enabled; false otherwise
     */
    bool UseGuid(const Node &node);

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
     * \brief
     */
    static const std::string cNamespaceEnd;

    /*!
     * \brief The output stream
     */
    std::ofstream mStream;

    /*!
     * \brief The output directory
     */
    std::string mDirectory;

    /*
     * Internal variables
     */
    std::ostringstream mAttributeStream;
    std::ostringstream mIndexStream;
    std::ostringstream mRelationshipStream;
    std::set<std::string> mVersionFields;
    std::set<std::string> mGuidTables;
    std::set<std::string> mGuidFields;
    bool mVersionFieldsWritten;
};

} // namespace cpporm
