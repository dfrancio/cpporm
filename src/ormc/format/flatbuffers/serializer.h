/*!
 * \file
 * \brief     flatbuffers serializer interface
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#pragma once

// Internal program includes
#include "../../serializer.h"

namespace flatbuffers
{
/*!
 * \brief flatbuffers serializer
 */
class Serializer : public ::Serializer
{
public:
    /*!
     * \brief Parse
     * \param[in] filename The input filename
     * \param[in] graph The output graph
     */
    void Parse(const std::string &filename, ListGraph &graph) override;

    /*!
     * \brief Write
     * \param[in] dir The output directory
     * \param[in] name The output name
     * \param[in] graph The input graph
     */
    void Write(const std::string &dir, const std::string &name, const ListGraph &graph) override;
};

} // namespace flatbuffers
