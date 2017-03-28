/*!
 * \file
 * \brief     cpporm entity factory writer interface
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#include "serializer.h"

// C++ library includes
#include <fstream>

namespace cpporm
{
/*!
 * \brief Entry point header writer
 */
class EntityFactoryWriter : public GraphVisitor
{
public:
    /*!
     * \brief Constructor
     * \param[in] listGraph The list graph
     * \param[in] dir The output directory
     * \param[in] name The output name
     */
    EntityFactoryWriter(
        const ListGraph &listGraph, const std::string &dir, const std::string &name);

private:
    /*!
     * \brief
     */
    static const std::string cPreambleText;

    /*!
     * \brief
     */
    static const std::string cBeginNamespace;

    /*!
     * \brief
     */
    static const std::string cDeclareEntityFactory;

    /*!
     * \brief
     */
    static const std::string cNamespaceEnd;

    /*!
     * \brief The output stream
     */
    std::ofstream mStream;
};

} // namespace cpporm
