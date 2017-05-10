
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

class Serializer
{
public:
    virtual void Parse(const std::string &filename, ListGraph &graph) = 0;

    virtual void Write(const std::string &dir, const std::string &name, const ListGraph &graph) = 0;
};

class SerializerFactory : public cpporm::util::Factory<SerializerFactory, Serializer, std::string>
{
};

class ParseError : public cpporm::Error
{
public:
    template <typename... Args>
    ParseError(Args &&... args)
        : Error("could not parse the input stream", std::forward<Args>(args)...)
    {
    }
};

class WriteError : public cpporm::Error
{
public:
    template <typename... Args>
    WriteError(Args &&... args)
        : Error("could write to the output stream", std::forward<Args>(args)...)
    {
    }
};

class UnknownFormatError : public cpporm::Error
{
public:
    template <typename... Args>
    UnknownFormatError(Args &&... args)
        : Error("the format is unknown", std::forward<Args>(args)...)
    {
    }
};
