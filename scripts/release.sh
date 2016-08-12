#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")/.."
read -r ver < VERSION
echo "Creating template-${ver}.tar.gz"
git archive --prefix=template-${ver}/ -o template-${ver}.tar.gz v${ver}