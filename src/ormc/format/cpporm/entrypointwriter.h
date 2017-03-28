/*!
 * \file
 * \brief     cpporm entry point writer interface
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
class EntryPointHeaderWriter : public GraphVisitor
{
public:
    /*!
     * \brief Destructor
     */
    ~EntryPointHeaderWriter();

    /*!
     * \brief Constructor
     * \param[in] listGraph The list graph
     * \param[in] dir The output directory
     * \param[in] name The output name
     */
    EntryPointHeaderWriter(
        const ListGraph &listGraph, const std::string &dir, const std::string &name);

    /*!
     * \brief Visit node
     * \param[in] context The context
     * \return True if the remaining siblings should be visited; false otherwise
     */
    bool VisitNode(const NodeContext &context) override;

private:
    /*!
     * \brief
     */
    static const std::string cPreambleText;

    /*!
     * \brief
     */
    static const std::string cIncludeEntityHeader;

    /*!
     * \brief
     */
    static const std::string cBeginNamespace;

    /*!
     * \brief
     */
    static const std::string cDeclareEntityCreator;

    /*!
     * \brief
     */
    static const std::string cNamespaceEnd;

    /*!
     * \brief The output stream
     */
    std::ofstream mStream;
};

/*!
 * \brief Entry point implementation writer
 */
class EntryPointImplementationWriter : public GraphVisitor
{
public:
    /*!
     * \brief Destructor
     */
    ~EntryPointImplementationWriter();

    /*!
     * \brief Constructor
     * \param[in] listGraph The list graph
     * \param[in] dir The output directory
     * \param[in] name The output name
     */
    EntryPointImplementationWriter(
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
    static const std::string cDefineEntityCreator;

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
