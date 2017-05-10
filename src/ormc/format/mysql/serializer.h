#pragma once

// Internal program includes
#include "../../serializer.h"

namespace mysql
{
class Serializer : public ::Serializer
{
public:
    void Parse(const std::string &filename, ListGraph &graph) override;

    void Write(const std::string &dir, const std::string &name, const ListGraph &graph) override;
};

} // namespace mysql
