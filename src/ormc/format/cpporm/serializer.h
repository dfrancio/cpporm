#pragma once

// Internal program includes
#include "../../serializer.h"

// Global variables
DECLARE_string(version_fields);
DECLARE_string(guid_tables);
DECLARE_string(guid_fields);
DECLARE_bool(amalgamate);
DECLARE_string(factory_name);

namespace cpporm
{
class Serializer : public ::Serializer
{
public:
    void Parse(const std::string &filename, ListGraph &graph) override;

    void Write(const std::string &dir, const std::string &name, const ListGraph &graph) override;
};

} // namespace cpporm
