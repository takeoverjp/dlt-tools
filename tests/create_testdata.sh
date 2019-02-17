#!/bin/bash -e

dlt-daemon &
dlt-receive -o testdata.dlt localhost &

make create_testdata
./create_testdata

kill %2
kill %1
