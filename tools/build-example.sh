#!/usr/bin/env bash

set -euo pipefail

# src file is passed as argument
# out binary file has the same name of src file (without the .cpp extension)

src="${1:?Usage: ./tools/build-example.sh path/example-file.cpp}"

root="$(cd "$(dirname "$0")/.." && pwd)"

# relative path of src file w.r.t. the root project/repo folder
# remove the leading ./ and the .cpp extension
out_rel_path="${src#./}"
out_rel_path="${out_rel_path%.cpp}"

# common build folder for all binaries (already ignored by .gitignore)
out="$root/build/bin/$out_rel_path"

mkdir -p "$(dirname "$out")"
clang++ -std=c++20 -Wall -Wextra -Werror -I . "$src" common/*.cpp -o "$out"
echo "Built: ${out#$root/}"
