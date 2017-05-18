class MyAttribute : public cpporm::Attribute
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
        static cpporm::PropertyMap properties = {{"IDENTITY", ""}, {"DATA_TYPE", "INT"}};
        return properties;
    }
};

void test()
{
    MyAttribute attribute;
    assert(attribute.GetName() == "name");
    assert(attribute.GetProperties().Get("DATA_TYPE") == "INT");
    assert(attribute.Get() == "");
    assert(attribute->empty());
    assert(attribute.IsNull());
    assert(!attribute.WasModified());

    attribute.Set("abc");
    assert(attribute.Get() == "abc");
    assert(!attribute->empty());
    assert(!attribute.IsNull());
    assert(attribute.WasModified());

    attribute.Commit();
    assert(!attribute.WasModified());

    attribute.SetNull();
    assert(attribute.Get() == "");
    assert(attribute.IsNull());
    assert(attribute.WasModified());

    attribute.Rollback();
    assert(attribute.Get() == "abc");
    assert(!attribute.WasModified());
}
