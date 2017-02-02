/*!
 * \file
 * \brief     Graph implementation
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#include "graph.h"

// External library includes
#include <boost/graph/copy.hpp>

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
    if (mLabeledGraph.vertex(mRefNodeName) == mLabeledGraph.null_vertex())
        throw std::runtime_error(
            mRefNodeName + " does not yet exist in the graph. Perhaps the input is ill-formed?");
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
    if (vertex == mLabeledGraph.null_vertex())
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
GraphVisitor::GraphVisitor(const ListGraph &listGraph) : mListGraph(listGraph)
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
    auto outEdges = boost::out_edges(vertexId, visitor.mListGraph);
    for (auto it = outEdges.first; it != outEdges.second; ++it)
    {
        EdgeContext context(*it, node, node, visitor.mListGraph[*it]);
        if (!visitor.VisitOutEdge(context))
            break;
    }
    auto inEedges = boost::in_edges(vertexId, visitor.mListGraph);
    for (auto it = inEedges.first; it != inEedges.second; ++it)
    {
        auto source = boost::source(*it, visitor.mListGraph);
        EdgeContext context(*it, node, visitor.mListGraph[source], visitor.mListGraph[*it]);
        if (!visitor.VisitInEdge(context))
            break;
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
