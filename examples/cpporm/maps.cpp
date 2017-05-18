void test()
{
    cpporm::PropertyMap map = {{"A", "1"}};
    assert(map.Get("A") == "1");
}

void test()
{
    MyEntity entity;
    cpporm::AttributeMap map = {CPPORM_MAP_ATTRIBUTE(MyEntity, attr)};
    assert(&map.Get("attr")(entity) == &entity.attr);
}

void test()
{
    MyEntity entity;
    cpporm::IndexMap map = {CPPORM_MAP_INDEX(MyEntity, primary_key)};
    assert(&map.Get("primary_key") == &entity.primary_key);
}

void test()
{
    MyEntity entity;
    cpporm::RelationshipMap map = {CPPORM_MAP_RELATIONSHIP(MyEntity, attr_MyEntity)};
    assert(&map.Get("attr_MyEntity") == &entity.attr_MyEntity);
}