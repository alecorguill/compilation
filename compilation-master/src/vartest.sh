#!/bin/bash
rm variable.o variable_test.o
gcc -c variable.c
gcc -c variable_test.c
gcc variable.o variable_test.o -o vartest
./vartest