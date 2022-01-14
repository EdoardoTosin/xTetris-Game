#!/bin/sh

set -o errexit

#Clean terminal
clear

rm -rf build
mkdir build
cd build

#Generate build folder
cmake ../.
#make, execute compile command
make
