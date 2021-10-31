#!/bin/bash

set -o errexit

rm -rf build
mkdir build
cd build

#Generate build folder
cmake ../.
#make, execute compile command
make

set -o errexit

#Clean terminal
clear

#run
./xTetris
