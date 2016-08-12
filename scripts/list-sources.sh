#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")/.."
find include src tests \
     \( -iname '*.C' \
    -or -iname '*.c' \
    -or -iname '*.c++' \
    -or -iname '*.cc' \
    -or -iname '*.cpp' \
    -or -iname '*.cxx' \
    -or -iname '*.H' \
    -or -iname '*.h' \
    -or -iname '*.h++' \
    -or -iname '*.hh' \
    -or -iname '*.hpp' \
    -or -iname '*.hxx' \
    -or -iname '*.ii' \
    -or -iname '*.inl' \
    -or -iname '*.ipp' \
    -or -iname '*.ixx' \
    -or -iname '*.tpl' \
    -or -iname '*.tcc' \
    -or -iname '*.tpp' \
    -or -iname '*.txx' \
    \) | sort
