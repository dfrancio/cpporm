/*!
 * \file
 * \brief     Graph implementation
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#include "graph.h"

/*!
 * \details
 */
GraphBuilder::~GraphBuilder()
{
}

/*!
 * \details
 */
GraphBuilder::GraphBuilder(ListGraph &graph) : mLabeledGraph(&graph)
{
}

/*!
 * \details
 */
void GraphBuilder::AddEdge()
{
    boost::add_edge_by_label(mNodeName, mRefNodeName, mLabeledGraph);
}

/*!
 * \details
 */
void GraphBuilder::AddIndex()
{
    GetCurrentNode().indices.emplace_back();
}

/*!
 * \details
 */
void GraphBuilder::AddCheck()
{
    GetCurrentNode().checks.emplace_back();
}

/*!
 * \details
 */
Node &GraphBuilder::GetCurrentNode()
{
    auto vertex = mLabeledGraph.vertex(mNodeName);
    if (vertex > boost::num_vertices(mLabeledGraph))
        vertex = mLabeledGraph.add_vertex(mNodeName);
    return mLabeledGraph.graph()[vertex];
}

/*!
 * \details
 */
Edge &GraphBuilder::GetCurrentEdge()
{
    auto source = mLabeledGraph.vertex(mNodeName);
    auto target = mLabeledGraph.vertex(mRefNodeName);
    auto edges = boost::edge_range(source, target, mLabeledGraph.graph());
    assert(edges.first != edges.second);
    return mLabeledGraph[*--edges.second];
}

/*!
 * \details
 */
Field &GraphBuilder::GetCurrentField()
{
    auto &vertex = GetCurrentNode();
    auto key = mNodeName + '_' + mFieldName;
    if (mFieldMap.find(key) == mFieldMap.end())
    {
        mFieldMap[key] = vertex.fields.size();
        vertex.fields.emplace_back();
        return vertex.fields.back();
    }
    return vertex.fields[mFieldMap[key]];
}

/*!
 * \details
 */
Index &GraphBuilder::GetCurrentIndex()
{
    auto &vertex = GetCurrentNode();
    assert(!vertex.indices.empty());
    return vertex.indices.back();
}

/*!
 * \details
 */
Check &GraphBuilder::GetCurrentCheck()
{
    auto &vertex = GetCurrentNode();
    assert(!vertex.checks.empty());
    return vertex.checks.back();
}

/*!
 * \details
 */
GraphVisitor::~GraphVisitor()
{
}

/*!
 * \details
 */
MatrixGraph::MatrixGraph(const ListGraph &graph)
    : boost::adjacency_matrix<boost::directedS, Node, Edge, Model>(boost::num_vertices(graph))
{
    auto edges = boost::edges(graph);
    for (auto edge = edges.first; edge != edges.second; ++edge)
        boost::add_edge(boost::source(*edge, graph), boost::target(*edge, graph), *this);
}

/*!
 * \details
 */
GraphVisitor::GraphVisitor(const ListGraph &listGraph, const MatrixGraph &matrixGraph)
    : mListGraph(listGraph), mMatrixGraph(matrixGraph)
{
}

/*!
 * \details
 */
void GraphVisitor::Visit()
{
    auto vertices = boost::vertices(mListGraph);
    for (auto vit = vertices.first; vit != vertices.second; ++vit)
    {
        NodeContext context(*vit, mListGraph[*vit]);
        if (!VisitNode(context))
            break;
    }
}

/*!
 * \details
 */
GraphVisitor::NodeContext::NodeContext(const VertexId &aId, const Node &aNode)
    : vertexId(aId), node(aNode)
{
}

/*!
 * \details
 */
GraphVisitor::EdgeContext::EdgeContext(
    const EdgeId &aId, const Node &aNode, const Node &aSourceNode, const Edge &aEdge)
    : edgeId(aId), node(aNode), sourceNode(aSourceNode), edge(aEdge)
{
}

/*!
 * \details
 */
GraphVisitor::FieldContext::FieldContext(const Node &aNode, const Field &aField)
    : node(aNode), field(aField)
{
}

/*!
 * \details
 */
GraphVisitor::IndexContext::IndexContext(const Node &aNode, const Index &aIndex)
    : node(aNode), index(aIndex)
{
}

/*!
 * \details
 */
GraphVisitor::CheckContext::CheckContext(const Node &aNode, const Check &aCheck)
    : node(aNode), check(aCheck)
{
}

/*!
 * \details
 */
bool GraphVisitor::Context::Accept(GraphVisitor &visitor) const
{
    return true;
}

/*!
 * \details
 */
bool GraphVisitor::NodeContext::Accept(GraphVisitor &visitor) const
{
    for (auto &field : node.fields)
    {
        FieldContext context(node, field);
        if (!visitor.VisitField(context))
            break;
    }
    for (auto &index : node.indices)
    {
        IndexContext context(node, index);
        if (!visitor.VisitIndex(context))
            break;
    }
    for (auto &check : node.checks)
    {
        CheckContext context(node, check);
        if (!visitor.VisitCheck(context))
            break;
    }
    auto outEdges = boost::out_edges(vertexId, visitor.mMatrixGraph);
    for (auto eit = outEdges.first; eit != outEdges.second; ++eit)
    {
        auto source = boost::source(*eit, visitor.mMatrixGraph);
        auto target = boost::target(*eit, visitor.mMatrixGraph);
        auto edges = boost::edge_range(source, target, visitor.mListGraph);
        for (auto eit2 = edges.first; eit2 != edges.second; ++eit2)
        {
            EdgeContext context(*eit2, node, node, visitor.mListGraph[*eit2]);
            if (!visitor.VisitOutEdge(context))
                break;
        }
    }
    auto inEedges = boost::in_edges(vertexId, visitor.mMatrixGraph);
    for (auto eit = inEedges.first; eit != inEedges.second; ++eit)
    {
        auto source = boost::source(*eit, visitor.mMatrixGraph);
        auto target = boost::target(*eit, visitor.mMatrixGraph);
        auto edges = boost::edge_range(source, target, visitor.mListGraph);
        for (auto eit2 = edges.first; eit2 != edges.second; ++eit2)
        {
            EdgeContext context(*eit2, node, visitor.mListGraph[source], visitor.mListGraph[*eit2]);
            if (!visitor.VisitInEdge(context))
                break;
        }
    }
    return true;
}

/*!
 * \details
 */
bool GraphVisitor::VisitNode(const NodeContext &context)
{
    return false;
}

/*!
 * \details
 */
bool GraphVisitor::VisitField(const FieldContext &context)
{
    return false;
}

/*!
 * \details
 */
bool GraphVisitor::VisitIndex(const IndexContext &context)
{
    return false;
}

/*!
 * \details
 */
bool GraphVisitor::VisitCheck(const CheckContext &context)
{
    return false;
}

/*!
 * \details
 */
bool GraphVisitor::VisitOutEdge(const EdgeContext &context)
{
    return false;
}

/*!
 * \details
 */
bool GraphVisitor::VisitInEdge(const EdgeContext &context)
{
    return false;
}

/*!
 * \details
 */
bool GraphVisitor::VisitChildren(const Context &context)
{
    return context.Accept(*this);
}
