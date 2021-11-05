#!/bin/bash

#export CC=/usr/bin/clang
#export CXX=/usr/bin/clang++

#--preset=dev

cmake -S . -B build -G Ninja $* --preset=dev-coverage

ninja -C build
