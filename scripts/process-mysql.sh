#!/bin/bash

sed -e "s|(| LPAREN |g" \
    -e "s|)| RPAREN |g" \
    -e "s|,| COMMA |g" \
    -e "s|.| PERIOD |g" \
    -e "s|:| COLON |g" \
    -e "s|;| SEMI |g" \
    -e "s|=| EQUAL |g" -i $1
perl -pe 's|\[(.*?)\]|(\1)?|g' -i $1
perl -pe 's|\[(.*?)\]|(\1)?|g' -i $1
perl -pe 's|\{(.*?)\}|(\1)|g' -i $1
