#!/bin/bash
CUR_DIR=`pwd`
BLD_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

export INTEL_VTUNE=/opt/intel/vtune_amplifier_2019.3.0.590814

cd ${BLD_DIR}
cmake ${BLD_DIR}
make
cd ${CUR_DIR}
