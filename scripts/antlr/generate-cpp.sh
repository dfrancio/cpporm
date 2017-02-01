#!/bin/bash

currentpath=$(dirname "${BASH_SOURCE[0]}")
antlr4tool="${currentpath}/antlr4-4.5.4-SNAPSHOT.jar"
javabinary=`which java`
if [ -z "$javabinary" ]; then
    javabinary="${JAVA_HOME}/bin/java"
fi
genoptions="-Dlanguage=Cpp -visitor"
outputfolder=$1
packagename=$2
shift
shift
"${javabinary}" -jar "${antlr4tool}" ${genoptions} -o "${outputfolder}" -package ${packagename} "$@"

if [ "$packagename" == "mysql" ]; then
    find ${outputfolder} -iname "*${packagename}Lexer.cpp" -exec sed -e 's|// Static vars and initialization.|#ifdef __linux__\nstd::string mysqlLexer::getSourceName()\n{\n    return Lexer::getSourceName();\n}\n#endif\n\n&|g' -i {} \;
    find ${outputfolder} -iname "*${packagename}Lexer.h" -exec sed -e 's|private:|#ifdef __linux__\n    virtual std::string getSourceName() override;\n#endif\n\n&|g' -i {} \;
    find ${outputfolder} \( -iname "*${packagename}Lexer.h" -or -iname "*${packagename}Parser.h" \) -exec sed -e 's|#include "antlr4-runtime.h"|&\n\n#define SAVED_NULL NULL\n#undef NULL\n#define SAVED_UNICODE UNICODE\n#undef UNICODE|g' -e '$a\\n#define NULL SAVED_NULL\n#define UNICODE SAVED_UNICODE' -i {} \;
fi

find ${outputfolder} \( -iname '*.cpp' -or -iname '*.h' \) -exec clang-format -i -style=file {} \;

