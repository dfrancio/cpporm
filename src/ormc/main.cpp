/*!
 * \file
 * \brief     main routine of the ORM-compiler
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */

// C++ library includes
#include <fstream>

// External library includes
#include <gflags/gflags.h>

// Internal library includes
#include <cpporm/version.h>

// Internal program includes
#include "serializer.h"

// Command-line flags
DEFINE_string(input_format, "auto", "name of the input format");
DEFINE_string(output_format, "cpporm", "name of the output format");
DEFINE_string(namespace, "", "name of the output namespace");

/*!
 * \brief Get next argument
 * \details
 */
std::string GetNextArgument(int &argc, char **&argv, const std::string &def = "")
{
    return (argc-- > 0) ? *argv++ : def;
}

/*!
 * \brief Guess input format
 * \details
 */
std::string GuessInputFormat(const std::string &filename)
{
    auto pos = filename.find_last_of('.');
    if (pos != std::string::npos)
    {
        auto extension = filename.substr(pos);
        if (extension == ".proto")
            return "protobuf";
        else if (extension == ".fbs")
            return "flatbuffers";
        else if (extension == ".json")
            return "json";
        else if (extension == ".sql")
            return "mysql";
        else
            return "format guessing failed";
    }
    return "no extension provided";
}

/*!
 * \brief main routine
 * \details
 */
int main(int argc, char **argv)
{
    // Initialize command-line flags
    gflags::SetVersionString(CPPORM_VERSION);
    gflags::SetUsageMessage("Example usage: " + std::string(argv[0]) + " input.sql");
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    // Initialize input arguments
    auto programName = GetNextArgument(argc, argv);
    auto inputFilename = GetNextArgument(argc, argv);
    auto outputDir = GetNextArgument(argc, argv, ".");

    // Initialize output name
    auto lastSepPos = inputFilename.find_last_of("/\\");
    auto lastExtPos = inputFilename.find_last_of('.');
    auto outputName = inputFilename.substr(
        lastSepPos == std::string::npos ? 0 : lastSepPos + 1,
        lastExtPos == std::string::npos ? lastExtPos : lastExtPos - lastSepPos - 1);

    // Handle automatic format detection
    if (FLAGS_input_format == "auto")
        FLAGS_input_format = GuessInputFormat(inputFilename);

    ListGraph graph;
    try
    {
        // Parse input
        std::cout << "reading input: '" << inputFilename << "'" << std::endl;
        auto inputSerializer = SerializerFactory::GetInstance().CreateUnique(FLAGS_input_format);
        inputSerializer->Parse(inputFilename, graph);

        // Write output
        std::cout << "writing to: '" << outputDir << "'" << std::endl;
        auto outputSerializer = SerializerFactory::GetInstance().CreateUnique(FLAGS_output_format);
        outputSerializer->Write(outputDir, outputName, graph);
    }
    catch (const std::exception &e)
    {
        std::cerr << "***" << programName << ": " << e.what() << std::endl;
        return -1;
    }

    return 0;
}
