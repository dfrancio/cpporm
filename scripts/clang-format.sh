#!/bin/bash

currentpath=$(dirname "${BASH_SOURCE[0]}")
files=$(source "${currentpath}/list-sources.sh" | tr '\n' '\0' | xargs -0)
echo "Formatting code under $(cd ${currentpath}/.. && pwd)"
clang-format -i -style=file ${files}