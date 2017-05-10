#pragma once

// C++ library includes
#include <map>
#include <string>
#include <vector>

// External library includes
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/adjacency_matrix.hpp>
#include <boost/graph/labeled_graph.hpp>

struct Field
{
    std::string name;
    std::string dataType;
    std::map<std::string, std::string> properties;
};

struct Index
{
    std::string name;
    std::string type;
    std::vector<std::string> fieldNames;
    std::map<std::string, std::string> properties;
};

struct Check
{
    std::string name;
    std::string expression;
};

struct Node
{
    std::string name;
    std::vector<Field> fields;
    std::vector<Index> indices;
    std::vector<Check> checks;
    std::map<std::string, std::string> properties;
};

struct Edge
{
    std::size_t indexNumber;
    std::string refNodeName;
    std::vector<std::string> refFieldNames;
};

struct Model
{
    std::string name;
    unsigned int version;
    std::map<std::string, std::string> properties;
};

typedef boost::
    adjacency_list<boost::multisetS, boost::listS, boost::bidirectionalS, Node, Edge, Model>
        ListGraph;

typedef boost::labeled_graph<ListGraph *, std::string> LabeledGraph;

class GraphBuilder
{
public:
    virtual ~GraphBuilder();

    GraphBuilder(ListGraph &graph);

    void AddEdge();

    void AddIndex();

    void AddCheck();

    Node &GetCurrentNode();

    Edge &GetCurrentEdge();

    Field &GetCurrentField();

    Index &GetCurrentIndex();

    Check &GetCurrentCheck();

protected:
    std::string mNodeName;

    std::string mRefNodeName;

    std::string mFieldName;

    std::map<std::string, std::size_t> mFieldMap;

private:
    LabeledGraph mLabeledGraph;
};

class GraphVisitor
{
public:
    virtual ~GraphVisitor();

    GraphVisitor(const ListGraph &listGraph);

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

    virtual bool VisitNode(const NodeContext &context);

    virtual bool VisitField(const FieldContext &context);

    virtual bool VisitIndex(const IndexContext &context);

    virtual bool VisitCheck(const CheckContext &context);

    virtual bool VisitOutEdge(const EdgeContext &context);

    virtual bool VisitInEdge(const EdgeContext &context);

    bool VisitChildren(const Context &context);

private:
    const ListGraph &mListGraph;
};
