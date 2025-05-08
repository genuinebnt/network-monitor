set -x
set -eo pipefail

BUILD_DIR="$(pwd)/build/"
BUILD_TYPE="Release"
cwd=$(pwd)

mkdir -p ${BUILD_DIR}

if ! [ -x "$(command -v conan)" ];
then
    echo 'Error: conan is not installed.'
fi

if ! [ -x "$(command -v cmake)" ];
then
    echo 'Error: cmake is not installed.'
fi

if ! [ -x "$(command -v ninja)" ];
then
    echo 'Error: ninja is not installed.'
fi

if  [[ -z $SKIP_CONAN ]];
then
    conan install .  --profile conanprofile.toml --output-folder=${BUILD_DIR} --build=missing -s build_type=${BUILD_TYPE}
fi

cmake -B build \
    -DCMAKE_BUILD_TYPE=${BUILD_TYPE} \
    -DCMAKE_TOOLCHAIN_FILE=${BUILD_DIR}/build/${BUILD_TYPE}/generators/conan_toolchain.cmake \
    -G Ninja
cmake --build build

