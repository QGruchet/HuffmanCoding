#!/bin/bash

#
# build.sh : this is a configuration file, don't need to be modified.
# Author : Mickael.
#

if [ ! -d "src/bin" ]; then
mkdir src/bin;
fi

if [ ! -d "src/target" ];then
mkdir src/target;
fi

if [ ! -d "src/txtQt" ]; then
mkdir src/txtQt;
fi