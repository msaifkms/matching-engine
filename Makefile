.RECIPEPREFIX = >
BUILD_DIR ?= build

.PHONY: all build test asan tsan sanitize clean

all: build

build:
> cmake -S . -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=Debug
> cmake --build $(BUILD_DIR) -j

test: build
> ctest --test-dir $(BUILD_DIR) --output-on-failure

asan:
> cmake -S . -B build-asan -DCMAKE_BUILD_TYPE=Debug -DSANITIZE=address
> cmake --build build-asan -j
> ctest --test-dir build-asan --output-on-failure

tsan:
> cmake -S . -B build-tsan -DCMAKE_BUILD_TYPE=Debug -DSANITIZE=thread
> cmake --build build-tsan -j
> ctest --test-dir build-tsan --output-on-failure

sanitize: asan tsan

clean:
> rm -rf $(BUILD_DIR) build-*
