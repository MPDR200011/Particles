#!/bin/sh

BUILT_TARGET="Release"

#First parameter, if any, is used as build target.
#If no parameter is given, then default to Release
if [ "$#" == 0 ]; then
	BUILD_TARGET="Release"
else
	BUILD_TARGET="$1"
fi

mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE="$BUILD_TARGET" ../
make -j 4
cd ..