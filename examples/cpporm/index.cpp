MyAttribute attr;

class MyIndex : public cpporm::Index
{
    const std::string &MyIndex::GetName() const
    {
        static const std::string cName = "primary_key";
        return cName;
    }
    const cpporm::PropertyMap &MyIndex::GetProperties() const
    {
        static const cpporm::PropertyMap cMap;
        return cMap;
    }
    const cpporm::AttributeMap &MyIndex::GetAttributes() const
    {
        static const cpporm::AttributeMap cMap = {CPPORM_MAP_ATTRIBUTE(MyEntity, attr)};
        return cMap;
    }
};