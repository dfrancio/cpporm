/*!
 * \file
 * \brief     Serializer class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

// C++ library includes
#include <iostream>

// External library includes
#include <gflags/gflags.h>

// Internal library includes
#include <cpporm/util/factory.h>

// Internal program includes
#include "graph.h"

// Command-line flags
DECLARE_string(namespace);

/*!
 * \brief %Serializer
 */
class Serializer
{
public:
    /*!
     * \brief Parse
     * \param[in] filename The input filename
     * \param[in] graph The output graph
     */
    virtual void Parse(const std::string &filename, ListGraph &graph) = 0;

    /*!
     * \brief Write
     * \param[in] dir The output directory
     * \param[in] name The output name
     * \param[in] graph The input graph
     */
    virtual void Write(const std::string &dir, const std::string &name, const ListGraph &graph) = 0;
};

/*!
 * \brief %Serializer
 */
class SerializerFactory : public cpporm::util::Factory<SerializerFactory, Serializer, std::string>
{
};

/*!
 * \brief Parse error
 */
class ParseError : public cpporm::Error
{
public:
    /*!
     * \brief Constructor
     * \param[in] args The error arguments
     */
    template <typename... Args>
    ParseError(Args &&... args)
        : Error("could not parse the input stream", std::forward<Args>(args)...)
    {
    }
};

/*!
 * \brief Write error
 */
class WriteError : public cpporm::Error
{
public:
    /*!
     * \brief Constructor
     * \param[in] args The error arguments
     */
    template <typename... Args>
    WriteError(Args &&... args)
        : Error("could write to the output stream", std::forward<Args>(args)...)
    {
    }
};

/*!
 * \brief Unknown format error
 */
class UnknownFormatError : public cpporm::Error
{
public:
    /*!
     * \brief Constructor
     * \param[in] args The error arguments
     */
    template <typename... Args>
    UnknownFormatError(Args &&... args)
        : Error("the format is unknown", std::forward<Args>(args)...)
    {
    }
};
