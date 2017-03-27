/*!
 * \file
 * \brief     cpporm header writer interface
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
 * \brief Header preamble writer
 */
class HeaderPreambleWriter : public GraphVisitor
{
public:
    /*!
     * \brief Constructor
     * \param[in] listGraph The list graph
     * \param[in] dir The output directory
     * \param[in] name The output name
     */
    HeaderPreambleWriter(
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
    std::set<std::string> mForwardDecls;
};

/*!
 * \brief Header schema writer
 */
class HeaderSchemaWriter : public GraphVisitor
{
public:
    /*!
     * \brief Constructor
     * \param[in] listGraph The list graph
     * \param[in] dir The output directory
     * \param[in] name The output name
     */
    HeaderSchemaWriter(const ListGraph &listGraph, const std::string &dir, const std::string &name);

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
     * \brief Check write version fields
     * \param[in] node The current node
     */
    void CheckWriteVersionFields(const Node &node);

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
    std::set<std::string> mVersionFields;
    bool mVersionFieldsWritten;
};

} // namespace cpporm
