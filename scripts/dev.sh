#!/usr/bin/env bash
set -euo pipefail

docker build -q -f Dockerfile.dev -t matching-engine-dev . > /dev/null
docker run --rm -it \
    --cap-add=SYS_PTRACE --security-opt seccomp=unconfined \
    -v "$(pwd)":/work -w /work \
    matching-engine-dev bash
