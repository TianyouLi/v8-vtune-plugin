#!/bin/bash
CUR_DIR=`pwd`
BLD_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

export INTEL_LIBITTNOTIFY32=/opt/intel/vtune_amplifier_2019.3.0.590814/lib32/runtime/libittnotify_collector.so
export INTEL_LIBITTNOTIFY64=/opt/intel/vtune_amplifier_2019.3.0.590814/lib64/runtime/libittnotify_collector.so
export INTEL_VTUNE=/opt/intel/vtune_amplifier_2019.3.0.590814

cd ${BLD_DIR}
cmake -DCMAKE_BUILD_TYPE=Debug ${BLD_DIR}
make
cd ${CUR_DIR}
