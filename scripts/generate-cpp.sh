#!/bin/bash

currentpath=$(dirname "${BASH_SOURCE[0]}")
antlr4tool="${currentpath}/antlr-4.6-complete.jar"
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
    find ${outputfolder} -iname "*${packagename}Lexer.cpp" -exec sed -e 's|const std::vector<std::string>& mysqlLexer::getModeNames() const {|const std::vector<std::string>\& mysqlLexer::getChannelNames() const {\n  return _channelNames;\n}\n\n&|g' -e 's|std::vector<std::string> mysqlLexer::_tokenNames;|&\nstd::vector<std::string> mysqlLexer::_channelNames;|g' -i {} \;
    find ${outputfolder} -iname "*${packagename}Lexer.h" -exec sed -e 's|  virtual const std::vector<std::string>& getModeNames() const override;|  virtual const std::vector<std::string>\& getChannelNames() const override;\n&|g' -e 's|  static std::vector<std::string> _modeNames;|&\n  static std::vector<std::string> _channelNames;|g' -i {} \;
    find ${outputfolder} \( -iname "*${packagename}Lexer.h" -or -iname "*${packagename}Parser.h" \) -exec sed -e 's|#include "antlr4-runtime.h"|&\n\n#define SAVED_NULL NULL\n#undef NULL\n#define SAVED_TRUE TRUE\n#undef TRUE\n#define SAVED_UNICODE UNICODE\n#undef UNICODE|g' -e '$a\\n#define NULL SAVED_NULL\n#define TRUE SAVED_TRUE\n#define UNICODE SAVED_UNICODE' -i {} \;
fi

find ${outputfolder} \( -iname '*.cpp' -or -iname '*.h' \) -exec clang-format -i -style=file {} \;

