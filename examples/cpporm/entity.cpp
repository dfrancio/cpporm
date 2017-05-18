class MyEntity : public cpporm::Entity
{
public:
    cpporm::Entity *Clone() const override
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
        static cpporm::PropertyMap properties = {{"USE_GUID", ""}};
        return map;
    }
    const AttributeMap &GetAttributes() const override
    {
        static cpporm::AttributeMap map = {CPPORM_MAP_ATTRIBUTE(MyEntity, attr)};
        return map;
    }
    const RelationshipMap &GetRelationships() const override
    {
        static cpporm::RelationshipMap map;
        return map;
    }
    const IndexMap &GetIndices() const override
    {
        static cpporm::IndexMap map;
        return map;
    }
    MyAttribute attr;
};

void test()
{
    MyEntity entity;
    assert(entity.GetId() == "ent");
    assert(entity.GetProperties.Has(("USE_GUID"));
    assert(!entity.WasModified());

    entity.attr.Set("1");
    assert(entity.WasModified());
    entity.ResetId();
    assert(entity.GetId() == "ent1");

    entity.Rollback();
    assert(entity.attr.Get() == "");
    assert(!entity.WasModified());

    entity["attr"] = "1";
    entity.Commit();
    assert(entity.attr.Get() == "1");
    assert(!entity.WasModified());
}