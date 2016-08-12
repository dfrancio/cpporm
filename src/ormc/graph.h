/*!
 * \file
 * \brief     Model class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

// C++ library includes
#include <map>
#include <string>
#include <vector>

// External library includes
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/adjacency_matrix.hpp>
#include <boost/graph/labeled_graph.hpp>

/*!
 * \brief Node field
 */
struct Field
{
    std::string name;
    std::string dataType;
    std::map<std::string, std::string> properties;
};

/*!
 * \brief Index constraint
 */
struct Index
{
    std::string name;
    std::string type;
    std::vector<std::string> fieldNames;
    std::map<std::string, std::string> properties;
};

/*!
 * \brief Check constraint
 */
struct Check
{
    std::string name;
    std::string expression;
};

/*!
 * \brief Graph node
 */
struct Node
{
    std::string name;
    std::vector<Field> fields;
    std::vector<Index> indices;
    std::vector<Check> checks;
    std::map<std::string, std::string> properties;
};

/*!
 * \brief Graph edge
 */
struct Edge
{
    std::size_t indexNumber;
    std::string refNodeName;
    std::vector<std::string> refFieldNames;
};

/*!
 * \brief Graph model
 */
struct Model
{
    std::string name;
    unsigned int version;
    std::map<std::string, std::string> properties;
};

/*!
 * \brief List graph
 */
typedef boost::adjacency_list<boost::multisetS, boost::vecS, boost::directedS, Node, Edge, Model>
    ListGraph;

/*!
 * \brief Labeled graph
 */
typedef boost::labeled_graph<ListGraph *, std::string> LabeledGraph;

/*!
 * \brief Matrix graph
 */
class MatrixGraph : public boost::adjacency_matrix<boost::directedS, Node, Edge, Model>
{
public:
    /*!
     * \brief Constructor
     * \param[in] graph The graph
     */
    MatrixGraph(const ListGraph &graph);
};

/*!
 * \brief %Graph builder
 */
class GraphBuilder
{
public:
    /*!
     * \brief Destructor
     */
    virtual ~GraphBuilder();

    /*!
     * \brief Constructor
     * \param[in] graph The graph
     */
    GraphBuilder(ListGraph &graph);

    /*!
     * \brief Add edge
     */
    void AddEdge();

    /*!
     * \brief Add index
     */
    void AddIndex();

    /*!
     * \brief Add check
     */
    void AddCheck();

    /*!
     * \brief Get current node
     * \return The node
     */
    Node &GetCurrentNode();

    /*!
     * \brief Get current edge
     * \return The edge
     */
    Edge &GetCurrentEdge();

    /*!
     * \brief Get current field
     * \return The field
     */
    Field &GetCurrentField();

    /*!
     * \brief Get current index
     * \return The index
     */
    Index &GetCurrentIndex();

    /*!
     * \brief Get current check
     * \return The check
     */
    Check &GetCurrentCheck();

protected:
    /*!
     * \brief The current node name
     */
    std::string mNodeName;

    /*!
     * \brief The current referenced node name
     */
    std::string mRefNodeName;

    /*!
     * \brief The current field name
     */
    std::string mFieldName;

    /*!
     * \brief The field map
     */
    std::map<std::string, std::size_t> mFieldMap;

private:
    /*!
     * \brief The labeled graph wrapper
     */
    LabeledGraph mLabeledGraph;
};

/*!
 * \brief Graph visitor
 */
class GraphVisitor
{
public:
    /*!
     * \brief Destructor
     */
    virtual ~GraphVisitor();

    /*!
     * \brief Constructor
     * \param[in] listGraph The list graph
     * \param[in] matrixGraph The matrix graph
     */
    GraphVisitor(const ListGraph &listGraph, const MatrixGraph &matrixGraph);

    /*!
     * \brief Visit
     */
    void Visit();

protected:
    struct Context
    {
        virtual bool Accept(GraphVisitor &visitor) const;
    };

    struct NodeContext : Context
    {
        typedef typename ListGraph::vertex_descriptor VertexId;
        VertexId vertexId;
        const Node &node;
        NodeContext(const VertexId &aId, const Node &aNode);
        bool Accept(GraphVisitor &visitor) const override;
    };

    struct EdgeContext : Context
    {
        typedef typename ListGraph::edge_descriptor EdgeId;
        EdgeId edgeId;
        const Node &node;
        const Node &sourceNode;
        const Edge &edge;
        EdgeContext(
            const EdgeId &id, const Node &aNode, const Node &aSourceNode, const Edge &aEdge);
    };

    struct FieldContext : Context
    {
        const Node &node;
        const Field &field;
        FieldContext(const Node &aNode, const Field &aField);
    };

    struct IndexContext : Context
    {
        const Node &node;
        const Index &index;
        IndexContext(const Node &aNode, const Index &aIndex);
    };

    struct CheckContext : Context
    {
        const Node &node;
        const Check &check;
        CheckContext(const Node &aNode, const Check &aCheck);
    };

    /*!
     * \brief Visit node
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    virtual bool VisitNode(const NodeContext &context);

    /*!
     * \brief Visit field
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    virtual bool VisitField(const FieldContext &context);

    /*!
     * \brief Visit index
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    virtual bool VisitIndex(const IndexContext &context);

    /*!
     * \brief Visit check constraint
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    virtual bool VisitCheck(const CheckContext &context);

    /*!
     * \brief Visit out edge
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    virtual bool VisitOutEdge(const EdgeContext &context);

    /*!
     * \brief Visit in edge
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    virtual bool VisitInEdge(const EdgeContext &context);

    /*!
     * \brief Visit children
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitChildren(const Context &context);

private:
    /*!
     * \brief The adjacency list graph
     */
    const ListGraph &mListGraph;

    /*!
     * \brief The adjacency matrix graph
     */
    const MatrixGraph &mMatrixGraph;
};
