.RECIPEPREFIX = >
BUILD_DIR ?= build

.PHONY: all build test clean

all: build

build:
> cmake -S . -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=Debug
> cmake --build $(BUILD_DIR) -j

test: build
> ctest --test-dir $(BUILD_DIR) --output-on-failure

clean:
> rm -rf $(BUILD_DIR) build-*
