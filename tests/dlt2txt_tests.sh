#!/bin/bash -e
function usage() {
    echo "[USAGE] $0 BIN_DIR TEST_DATA_DIR"
    exit 1
}

NG_CNT=0
OK_CNT=0
function test_lineno() {
    local FILE=$1
    local LINENO_EXP=$2

    ${DLT2TXT} ${TEST_DATA_DIR}/$1 > result
    local LINENO_ACT=`cat result | wc -l`

    if [ ${LINENO_EXP} != ${LINENO_ACT} ]; then
        printf "X"
        NG_CNT=`expr ${NG_CNT} + 1`
        return
    fi

    printf "."
    OK_CNT=`expr ${OK_CNT} + 1`
}

if [ $# != 2 ]; then
    usage
fi

BIN_DIR=$1
TEST_DATA_DIR=$2

DLT2TXT=${BIN_DIR}/dlt2txt
if [ ! -x ${DLT2TXT} ]; then
    usage
fi

test_lineno testdata.dlt 18


echo ""
echo "Passed: ${OK_CNT}, Failed: ${NG_CNT}"

if [ ${NG_CNT} -gt 0 ]; then
    exit 1
fi
