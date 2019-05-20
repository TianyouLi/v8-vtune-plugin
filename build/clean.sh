#!/bin/bash
CUR_DIR=`pwd`
BLD_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )


cd ${BLD_DIR}
rm -rf CMakeCache.txt CMakeFiles Makefile cmake_install.cmake
cd ${CUR_DIR}
