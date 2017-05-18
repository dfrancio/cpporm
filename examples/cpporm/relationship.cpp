class MyRelationship : public cpporm::ToOneRelationship
{
    using ToOneRelationship::ToOneRelationship;

public:
    const std::string &GetName() const override
    {
        static const std::string name = "MyRelationship";
        return name;
    }
    const cpporm::PropertyMap &GetProperties() const override
    {
        return MyEntity::foreign_key_attr.GetProperties();
    }
    const std::vector<std::string> &GetForeignKeyNames() const override
    {
        static const std::vector<std::string> names = {"attr"};
        return names;
    }
    const std::vector<std::string> &GetReferencedNames() const override
    {
        static const std::vector<std::string> names = {"attr2"};
        return names;
    }
    related *operator->()
    {
        return Get<MyEntity>();
    }
    related &operator*()
    {
        return *Get<MyEntity>();
    }

protected:
    const std::string &GetReciprocalName() const override
    {
        static const std::string name = "all_MyEntity_attr";
        return name;
    }
    cpporm::Entity &GetPrototype() const override
    {
        static MyEntity entity;
        return entity;
    }
};

void test()
{
    MyEntity entity;
    MyRelationship relationship(entity);
    if (relationship)
        relationship->attr.Set("abc");
}

class MyRelationship : public cpporm::ToManyRelationship
{
    using ToManyRelationship::ToManyRelationship;

public:
    const std::string &GetName() const override
    {
        static const std::string name = "all_MyEntity_attr";
        return name;
    }
    const cpporm::PropertyMap &GetProperties() const override
    {
        return MyEntity::foreign_key_attr.GetProperties();
    }
    const std::vector<std::string> &GetForeignKeyNames() const override
    {
        static const std::vector<std::string> names = {};
        return names;
    }
    const std::vector<std::string> &GetReferencedNames() const override
    {
        static const std::vector<std::string> names = {};
        return names;
    }

protected:
    const std::string &GetReciprocalName() const override
    {
        static const std::string name = "attr_MyEntity";
        return name;
    }
    cpporm::Entity &GetPrototype() const override
    {
        static MyEntity entity;
        return entity;
    }
};

void test()
{
    MyEntity entity;
    MyRelationship relationship(entity);
    int count = 0;
    entity.ForEach([](MyEntity &entity, int &count) {
        ++count;
        return true;
    }, count);
}