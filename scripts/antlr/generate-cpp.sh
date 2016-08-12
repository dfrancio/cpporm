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
