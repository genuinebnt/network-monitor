set -x
set -eo pipefail

BUILD_DIR="$(pwd)/build/"
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
    conan install . --profile conanprofile.toml --output-folder=build/
fi

cd ${BUILD_DIR}
cmake .. -GNinja -DCMAKE_BUILD_TYPE=Release
ninja
cd ${cwd}

