#!/usr/bin/env bash

BIN_DIRECTORY="bin"
CC="gcc"
FLAGS="-std=c99 -Iinclude -I../include"

declare -a cFiles
for file in *.c
do
  cFiles=(${cFiles[@]} "$file")
done

if [ ! -d $BIN_DIRECTORY ]; then
  mkdir ./bin
fi

$CC "${cFiles[@]}" -o ./bin/main $FLAGS

