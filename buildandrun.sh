#!/bin/bash

if [ ! -d "build" ]; then
    echo "Directory 'build' does not exist. Creating now."
    mkdir build
    echo "Directory 'build' created."
fi

cd build
cmake ..
make
./logl