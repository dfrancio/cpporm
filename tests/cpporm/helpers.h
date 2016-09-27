#pragma once

// C++ library includes
#include <set>
#include <string>

// Internal library includes
#include <cpporm/attribute.h>
#include <cpporm/db/connection.h>
#include <cpporm/db/connectionstring.h>
#include <cpporm/db/cursor.h>
#include <cpporm/db/iudcontext.h>
#include <cpporm/db/query.h>
#include <cpporm/db/savepoint.h>
#include <cpporm/db/session.h>
#include <cpporm/db/statement.h>
#include <cpporm/db/transaction.h>
#include <cpporm/entity.h>
#include <cpporm/index.h>
#include <cpporm/maps.h>
#include <cpporm/relationship.h>

using cpporm::Index;
using cpporm::Attribute;
using cpporm::Relationship;
using cpporm::Entity;
using cpporm::PropertyMap;
using cpporm::AttributeMap;
using cpporm::IndexMap;
using cpporm::RelationshipMap;
using cpporm::ToOneRelationship;
using cpporm::ToManyRelationship;
using cpporm::db::Session;
using cpporm::db::Cache;
using cpporm::db::Query;
using cpporm::db::Context;
using cpporm::db::Cursor;
using cpporm::db::Statement;
using cpporm::db::IudContext;
using cpporm::db::SavePoint;
using cpporm::db::Connection;
using cpporm::db::ConnectionString;
using cpporm::db::Transaction;
using cpporm::db::QueryFactory;
using cpporm::util::Factory;
using cpporm::util::StringMap;

class MyStatement : public Statement
{
public:
    void Prepare(const std::string &sql) override
    {
    }
    void Bind(short param, const std::string &value) override
    {
        boundParams.push_back(param);
        boundValues.push_back(value);
    }
    void BindNull(short param) override
    {
        boundParams.push_back(param);
        nullCount++;
    }
    void StartBatch() override
    {
    }
    void EndBatch() override
    {
    }

    std::vector<int> boundParams;
    std::vector<std::string> boundValues;
    int nullCount = 0;
};

class MyCursor : public Cursor
{
public:
    bool Next() override
    {
        return count--;
    }
    std::size_t GetAffectedRowCount() const override
    {
        return 0;
    }
    bool Has(const std::string &name) const override
    {
        return false;
    }
    bool IsNull(const std::string &name) const override
    {
        return true;
    }
    std::string Get(short column) const override
    {
        return "";
    }
    std::string Get(const std::string &name) const override
    {
        return "";
    }
    int count = 1;
};

class MyCursor2 : public Cursor
{
public:
    bool Next() override
    {
        return count--;
    }
    std::size_t GetAffectedRowCount() const override
    {
        return 0;
    }
    bool Has(const std::string &name) const override
    {
        return true;
    }
    bool IsNull(const std::string &name) const override
    {
        return false;
    }
    std::string Get(short column) const override
    {
        return "";
    }
    std::string Get(const std::string &name) const override
    {
        return "abc";
    }
    int count = 1;
};

class MyCursor3 : public Cursor
{
public:
    bool Next() override
    {
        return count--;
    }
    std::size_t GetAffectedRowCount() const override
    {
        return 0;
    }
    bool Has(const std::string &name) const override
    {
        return true;
    }
    bool IsNull(const std::string &name) const override
    {
        return true;
    }
    std::string Get(short column) const override
    {
        return "";
    }
    std::string Get(const std::string &name) const override
    {
        return "";
    }
    int count = 1;
};

class MyIudContext : public IudContext
{
    using IudContext::IudContext;

public:
    Context *CreateSubcontext() override
    {
        return new MyIudContext(this);
    }
    static Cache insertions;
    static Cache updates;
    static Cache deletions;

protected:
    void InnerCommit() override
    {
        insertions.CopyFrom(mInsertions);
        updates.CopyFrom(mUpdates);
        deletions.CopyFrom(mDeletions);
        IudContext::InnerCommit();
    }
};

class MyContext : public Context
{
    using Context::Context;

public:
    Context *CreateSubcontext() override
    {
        return new MyContext(this);
    }
    static std::set<std::string> committedWords;

protected:
    void InnerCommit() override
    {
        committedWords.insert(words.begin(), words.end());
    }
    void InnerRollback() override
    {
        words.clear();
    }
    void InnerRelease(Context &context) override
    {
        static_cast<MyContext &>(context).words.insert(words.begin(), words.end());
    }
    void InnerAddInsertion(const std::string &key) override
    {
        words.insert(key);
    }
    void InnerAddUpdate(const std::string &oldKey, const std::string &newKey) override
    {
    }
    void InnerAddDeletion(const std::string &key) override
    {
    }
    std::set<std::string> words;
};

class MyAttribute : public Attribute
{
    using Attribute::Attribute;

public:
    const std::string &GetName() const override
    {
        static std::string name = "name";
        return name;
    }
    const PropertyMap &GetProperties() const override
    {
        static PropertyMap map = {{"IDENTITY", ""}, {"DATA_TYPE", "INT"}};
        return map;
    }
};

class MyAttribute2 : public Attribute
{
    using Attribute::Attribute;

public:
    const std::string &GetName() const override
    {
        static std::string name = "name2";
        return name;
    }
    const PropertyMap &GetProperties() const override
    {
        static PropertyMap map = {{"DEFAULT", "1"}, {"DATA_TYPE", "TEXT"}};
        return map;
    }
};

class MyEntity : public Entity
{
public:
    MyEntity()
    {
    }
    MyEntity(const std::string &key, const std::string &value) : attr(key), version(value)
    {
    }
    Entity *Clone() const override
    {
        return new MyEntity(*this);
    }
    const std::string &GetName() const override
    {
        static std::string name = "ent";
        return name;
    }
    const PropertyMap &GetProperties() const override
    {
        static PropertyMap map;
        return map;
    }
    const AttributeMap &GetAttributes() const override
    {
        static AttributeMap map
            = {CPPORM_MAP_ATTRIBUTE(MyEntity, attr), CPPORM_MAP_ATTRIBUTE(MyEntity, version)};
        return map;
    }
    const RelationshipMap &GetRelationships() const override
    {
        static RelationshipMap map;
        return map;
    }
    const IndexMap &GetIndices() const override
    {
        static IndexMap map
            = {CPPORM_MAP_INDEX(MyEntity, primary_key), CPPORM_MAP_INDEX(MyEntity, version_fields)};
        return map;
    }
    MyAttribute attr;
    MyAttribute2 version;
    CPPORM_DECLARE_INDEX(primary_key);
    CPPORM_DECLARE_INDEX(version_fields);
};

struct VariadicUnpackTester
{
    template <typename T>
    void increment(T &&arg)
    {
        count++;
    }
    template <typename... Args>
    VariadicUnpackTester(Args &&... args)
    {
        CPPORM_UNPACK(increment(args));
    }
    int count = 0;
};

enum A
{
    AA
};

enum class B
{
    BB
};

enum class C : unsigned short
{
    CC
};

class Base
{
public:
    virtual ~Base()
    {
    }
};

class MyFactory : public Factory<MyFactory, Base, std::string>
{
};

class MyFactory2 : public Factory<MyFactory2, Base, std::string, cpporm::util::CaseInsensitiveLess>
{
};

class MyClass1 : public Base
{
};

class MyClass2 : public Base
{
};

class MyClass3 : public Base
{
};

typedef StringMap<int> IntStringMap;

class MyConnection : public Connection
{
public:
    void Reconnect() override
    {
        mReconnectCalled = true;
    }
    void Disconnect() override
    {
        mConnected = false;
    }
    bool IsConnected() const override
    {
        return mConnected;
    }
    std::unique_ptr<Query> CreateQuery() override
    {
        return QueryFactory::GetInstance().CreateUnique(mVendor);
    }
    std::unique_ptr<Statement> CreateStatement() override
    {
        return std::unique_ptr<Statement>(new MyStatement());
    }
    void JustExecute(const std::string &sql) override
    {
    }
    std::unique_ptr<Cursor> Execute(const std::string &sql) override
    {
        return std::unique_ptr<Cursor>(new MyCursor());
    }
    std::unique_ptr<Cursor> Execute(Statement &statement) override
    {
        return std::unique_ptr<Cursor>(new MyCursor());
    }
    std::string mConnectionString;
    bool mReconnectCalled;

protected:
    void InnerConnect() override
    {
        if (!mParameters.empty())
            mConnected = true;
        ConnectionString connString;
        mConnectionString = connString.SetParameters(mParameters).Get();
    }
    bool mConnected = false;
};

class MySession : public Session
{
public:
    MySession() : mContext(mCache)
    {
    }

protected:
    Cache &GetCache() override
    {
        return mCache;
    }
    Context &GetContext() override
    {
        return mContext;
    }
    Connection &GetConnection() override
    {
        return mConnection;
    }
    Cache mCache;
    MyIudContext mContext;
    MyConnection mConnection;
};

CPPORM_DECLARE_ENTITY(MyEntity2)
{
    CPPORM_DECLARE_ENTITY_METHODS;
    CPPORM_DECLARE_ATTRIBUTE(attr);
    CPPORM_DECLARE_ATTRIBUTE(attr2);
    CPPORM_DECLARE_INDEX(foreign_key_attr);
    CPPORM_DECLARE_TO_ONE_RELATIONSHIP(attr_MyEntity2, MyEntity2);
    CPPORM_DECLARE_TO_MANY_RELATIONSHIP(all_MyEntity2_attr);
};

CPPORM_DECLARE_ENTITY(Test2)
{
    CPPORM_DECLARE_ENTITY_METHODS;
    CPPORM_DECLARE_ATTRIBUTE(id);
    CPPORM_DECLARE_ATTRIBUTE(name);
    CPPORM_DECLARE_ATTRIBUTE(datetime);
    CPPORM_DECLARE_ATTRIBUTE(created_by);
    CPPORM_DECLARE_INDEX(primary_key);
    CPPORM_DECLARE_INDEX(unique_name);
    CPPORM_DECLARE_INDEX(foreign_key_created_by);
    CPPORM_DECLARE_INDEX(version_fields);
    CPPORM_DECLARE_TO_ONE_RELATIONSHIP(created_by_Test2, Test2);
    CPPORM_DECLARE_TO_MANY_RELATIONSHIP(all_Test2_created_by);
};

CPPORM_DECLARE_ENTITY(Test3)
{
    CPPORM_DECLARE_ENTITY_METHODS;
    CPPORM_DECLARE_ATTRIBUTE(id);
    CPPORM_DECLARE_ATTRIBUTE(name);
    CPPORM_DECLARE_ATTRIBUTE(datetime);
    CPPORM_DECLARE_ATTRIBUTE(created_by);
    CPPORM_DECLARE_INDEX(primary_key);
    CPPORM_DECLARE_INDEX(unique_name);
    CPPORM_DECLARE_INDEX(foreign_key_created_by);
    CPPORM_DECLARE_INDEX(version_fields);
    CPPORM_DECLARE_TO_ONE_RELATIONSHIP(created_by_Test3, Test3);
    CPPORM_DECLARE_TO_MANY_RELATIONSHIP(all_Test3_created_by);
};
