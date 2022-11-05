#!/usr/bin/env bash

BIN_DIRECTORY="bin"

if [ ! -d $BIN_DIRECTORY ]; then
  mkdir ./bin
fi

gcc -Wall -c ll.c -o ./bin/ll.o
gcc -Wall -c main.c -o ./bin/main.o
gcc -o ./bin/ll ./bin/ll.o ./bin/main.o
