#cmake -H. -Bbuild
#cmake --build build -- -j3

#!/bin/bash
CUR_DIR=`pwd`
BLD_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

cd ${BLD_DIR}
cmake -DCMAKE_BUILD_TYPE=Debug ${BLD_DIR}
make
cd ${CUR_DIR}
