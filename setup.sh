#!/bin/bash

if [ ! -d "bin" ]; then
    mkdir bin 
fi

export PATH=$PWD/bin/:$PATH