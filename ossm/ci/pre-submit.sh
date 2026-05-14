#!/bin/bash

set -exo pipefail

DIR=$(cd "$(dirname "$0")" ; pwd -P)

# shellcheck disable=SC1091
source "${DIR}/common.sh"

# Build Envoy
time bazel_build //:envoy

echo "Build succeeded. Binary generated:"
bazel-bin/envoy --version

# Run tests
time bazel_test //...

export ENVOY_PATH=bazel-bin/envoy
export GO111MODULE=on

# Use vendored Go modules if available for offline builds
if [ -d "vendor" ]; then
    echo "Using vendored Go modules for offline build"
    GO_MOD_FLAG="-mod=vendor"
else
    echo "Warning: No vendor directory found, will attempt to download Go modules"
    GO_MOD_FLAG=""
fi

# shellcheck disable=SC2046
time go test ${GO_MOD_FLAG} -timeout=30m -p=1 -parallel=1 $(go list ./...)
