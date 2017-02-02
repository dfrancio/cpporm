/*!
 * \file
 * \brief     SQLite serializer implementation
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#include "serializer.h"

// C++ library includes
#include <fstream>

// External library includes
#include <boost/format.hpp>
#include <gflags/gflags.h>

// Helper macros
#define CPPORM_BACKQUOTE(name) std::string('`' + (name) + '`')

// Global variables
static const auto cOutputStreamFlags = std::ios_base::binary | std::fstream::out;
static const auto cAppendStreamFlags = std::ios_base::ate | std::fstream::in;
CPPORM_REGISTER(SerializerFactory, sqlite::Serializer, sqlite, "sqlite");

namespace sqlite
{
/*!
 * \brief Drop table writer
 */
class DropTableWriter : public GraphVisitor
{
public:
    /*!
     * \brief Destructor
     */
    ~DropTableWriter()
    {
        mStream << boost::format(cForeignKeysOn);
        mStream.close();
    }

    /*!
     * \brief Constructor
     * \param[in] listGraph The list graph
     * \param[in] dir The output directory
     * \param[in] name The output name
     */
    DropTableWriter(const ListGraph &listGraph, const std::string &dir, const std::string &name)
        : GraphVisitor(listGraph)
    {
        mStream.open(dir + "/" + name + ".sqlite.sql", cOutputStreamFlags);
        mStream << boost::format(cForeignKeysOff);
    }

    /*!
     * \brief Visit node
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitNode(const NodeContext &context) override
    {
        mStream << boost::format(cDropTable) % context.node.name;
        return true;
    }

private:
    /*!
     * \brief
     */
    static const std::string cForeignKeysOff;

    /*!
     * \brief
     */
    static const std::string cDropTable;

    /*!
     * \brief
     */
    static const std::string cForeignKeysOn;

    /*!
     * \brief The output stream
     */
    std::ofstream mStream;
};

/*!
 * \brief Create table writer
 */
class CreateTableWriter : public GraphVisitor
{
public:
    /*!
     * \brief Destructor
     */
    ~CreateTableWriter()
    {
        mStream.close();
    }

    /*!
     * \brief Constructor
     * \param[in] listGraph The list graph
     * \param[in] dir The output directory
     * \param[in] name The output name
     */
    CreateTableWriter(const ListGraph &listGraph, const std::string &dir, const std::string &name)
        : GraphVisitor(listGraph)
    {
        mStream.open(dir + "/" + name + ".sqlite.sql", cOutputStreamFlags | cAppendStreamFlags);
    }

    /*!
     * \brief Visit node
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitNode(const NodeContext &context) override
    {
        mFieldsVisited = false;

        mStream << boost::format(cCreateTable) % CPPORM_BACKQUOTE(context.node.name);
        auto result = VisitChildren(context);
        if (mFieldsVisited)
            mStream.seekp(-2, std::ios_base::cur) << '\n';
        mStream << ");\n";
        return result;
    }

    /*!
     * \brief Visit field
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitField(const FieldContext &context) override
    {
        std::string props;
        for (auto &pair : context.field.properties)
        {
            if (pair.first == "LENGTH")
            {
                props += "(" + pair.second + ")" + props;
            }
            else if (pair.first != CPPORM_PROP_IDENTITY && pair.first != CPPORM_PROP_ON_UPDATE)
            {
                auto name = pair.first;
                std::replace(name.begin(), name.end(), '_', ' ');
                props += " " + name + (pair.second.empty() ? "" : ' ' + pair.second);
            }
        }

        mStream << boost::format(cColumn) % CPPORM_BACKQUOTE(context.field.name)
                % context.field.dataType % props;

        mFieldsVisited = true;
        return true;
    }

    /*!
     * \brief Visit index
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitIndex(const IndexContext &context) override
    {
        if (context.index.type != "FOREIGN_KEY" && context.index.type != "INDEX")
        {
            std::string refs;
            for (auto &name : context.index.fieldNames)
                refs += refs.empty() ? CPPORM_BACKQUOTE(name) : ", " + CPPORM_BACKQUOTE(name);
            auto type = context.index.type;
            std::replace(type.begin(), type.end(), '_', ' ');
            mStream << boost::format(cIndex) % type % context.index.name % refs;
        }
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

        auto &index = context.node.indices[context.edge.indexNumber - 1];
        std::string fromRefs;
        for (auto &name : index.fieldNames)
            fromRefs += fromRefs.empty() ? CPPORM_BACKQUOTE(name) : ", " + CPPORM_BACKQUOTE(name);
        std::string toRefs;
        for (auto &name : context.edge.refFieldNames)
            toRefs += toRefs.empty() ? CPPORM_BACKQUOTE(name) : ", " + CPPORM_BACKQUOTE(name);

        std::string props;
        for (auto &pair : index.properties)
        {
            if (pair.first != CPPORM_PROP_IDENTITY && pair.first != CPPORM_PROP_ON_UPDATE)
            {
                auto name = pair.first;
                std::replace(name.begin(), name.end(), '_', ' ');
                props += " " + name + (pair.second.empty() ? "" : ' ' + pair.second);
            }
        }

        mStream << boost::format(cForeignKey) % fromRefs
                % CPPORM_BACKQUOTE(context.edge.refNodeName) % toRefs % props;
        return true;
    }

private:
    /*!
     * \brief
     */
    static const std::string cCreateTable;

    /*!
     * \brief
     */
    static const std::string cColumn;

    /*!
     * \brief
     */
    static const std::string cIndex;

    /*!
     * \brief
     */
    static const std::string cForeignKey;

    /*!
     * \brief The output stream
     */
    std::ofstream mStream;

    /*
     * Internal flags
     */
    bool mFieldsVisited;
};

/*!
 * \brief Create trigger writer
 */
class CreateTriggerWriter : public GraphVisitor
{
public:
    /*!
     * \brief Destructor
     */
    ~CreateTriggerWriter()
    {
        mStream.close();
    }

    /*!
     * \brief Constructor
     * \param[in] listGraph The list graph
     * \param[in] dir The output directory
     * \param[in] name The output name
     */
    CreateTriggerWriter(const ListGraph &listGraph, const std::string &dir, const std::string &name)
        : GraphVisitor(listGraph), mDirectory(dir), mName(name), mNodesVisited(false)
    {
        mStream.open(dir + "/" + name + ".sqlite.sql", cOutputStreamFlags | cAppendStreamFlags);
    }

    /*!
     * \brief Visit node
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitNode(const NodeContext &context) override
    {
        std::string whenClause;
        std::string setClause;
        std::string whereClause;

        for (const auto &field : context.node.fields)
        {
            auto it = field.properties.find(CPPORM_PROP_ON_UPDATE);
            if (it != field.properties.end())
            {
                if (!whenClause.empty())
                    whenClause += " AND ";
                whenClause += "[NEW].[" + field.name + "]=[OLD].[" + field.name + "]";

                if (!setClause.empty())
                    setClause += ",";
                setClause += "[" + field.name + "]=" + it->second;
            }
        }

        if (!whenClause.empty())
        {
            if (!mNodesVisited)
            {
                mStream << "\n";
                mNodesVisited = true;
            }

            for (const auto &index : context.node.indices)
            {
                if (index.type == "PRIMARY_KEY")
                {
                    for (const auto &name : index.fieldNames)
                    {
                        if (!whereClause.empty())
                            whereClause += " AND ";
                        whereClause += "[" + name + "]=[OLD].[" + name + "]";
                    }
                }
            }
            if (whereClause.empty())
                throw cpporm::Error(
                    "entity has version field but does not have primary key", context.node.name);

            mStream << boost::format(cTrigger) % context.node.name % context.node.name % whenClause
                    % context.node.name % setClause % whereClause;
        }

        return true;
    }

private:
    /*!
     * \brief
     */
    static const std::string cTrigger;

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
     * Internal flags
     */
    bool mNodesVisited;
};

/*!
 * \brief Create index writer
 */
class CreateIndexWriter : public GraphVisitor
{
public:
    /*!
     * \brief Destructor
     */
    ~CreateIndexWriter()
    {
        mStream.close();
    }

    /*!
     * \brief Constructor
     * \param[in] listGraph The list graph
     * \param[in] dir The output directory
     * \param[in] name The output name
     */
    CreateIndexWriter(const ListGraph &listGraph, const std::string &dir, const std::string &name)
        : GraphVisitor(listGraph), mDirectory(dir), mName(name)
    {
        mStream.open(dir + "/" + name + ".sqlite.sql", cOutputStreamFlags | cAppendStreamFlags);
    }

    /*!
     * \brief Visit node
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitNode(const NodeContext &context) override
    {
        return VisitChildren(context);
    }

    /*!
     * \brief Visit index
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitIndex(const IndexContext &context) override
    {
        if (context.index.type == "INDEX")
        {
            std::string refs;
            for (auto &name : context.index.fieldNames)
                refs += refs.empty() ? CPPORM_BACKQUOTE(name) : ", " + CPPORM_BACKQUOTE(name);
            auto name = context.index.name;
            if (name.empty())
                name = context.node.name + "_index";
            mStream << boost::format(cIndex) % name % context.node.name % refs;
        }
        return true;
    }

private:
    /*!
     * \brief
     */
    static const std::string cIndex;

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
};

/*!
 * \details
 */
const std::string DropTableWriter::cForeignKeysOff = "PRAGMA foreign_keys = OFF;\n";

/*!
 * \details
 */
const std::string DropTableWriter::cDropTable = "DROP TABLE IF EXISTS `%s`;\n";

/*!
 * \details
 */
const std::string DropTableWriter::cForeignKeysOn = "PRAGMA foreign_keys = ON;\n";

/*!
 * \details
 */
const std::string CreateTableWriter::cCreateTable = "CREATE TABLE %s (\n";

/*!
 * \details
 */
const std::string CreateTableWriter::cColumn = "    %s %s%s,\n";

/*!
 * \details
 */
const std::string CreateTableWriter::cIndex = "    %s %s (%s),\n";

/*!
 * \details
 */
const std::string CreateTableWriter::cForeignKey = "    FOREIGN KEY (%s) REFERENCES %s(%s)%s,\n";

/*!
 * \details
 */
const std::string CreateTriggerWriter::cTrigger
    = "CREATE TRIGGER IF NOT EXISTS [%s.UpdateVersionFields] AFTER UPDATE ON [%s] FOR EACH ROW "
      "WHEN %s BEGIN UPDATE [%s] SET %s WHERE %s; END;\n";

/*!
 * \details
 */
const std::string CreateIndexWriter::cIndex = "CREATE INDEX %s ON %s (%s);\n";

/*!
 * \details
 */
void Serializer::Parse(const std::string &, ListGraph &)
{
    throw cpporm::NotImplementedError(
        "sqlite::Serializer::Parse(const std::string &, ListGraph &)");
}

/*!
 * \details
 */
void Serializer::Write(const std::string &dir, const std::string &name, const ListGraph &graph)
{
    DropTableWriter(graph, dir, name).Visit();
    CreateTableWriter(graph, dir, name).Visit();
    CreateTriggerWriter(graph, dir, name).Visit();
    CreateIndexWriter(graph, dir, name).Visit();
}

} // namespace sqlite
