#!/usr/bin/env bash

BIN_DIRECTORY="bin"

if [ ! -d $BIN_DIRECTORY ]; then
  mkdir ./bin
fi

gcc -Wall -c stack.c -o ./bin/stack.o
gcc -Wall -c main.c -o ./bin/main.o
gcc -Wall -c infixToPostfix.c -o ./bin/infixToPostfix.o
gcc -o ./bin/stack ./bin/stack.o ./bin/main.o
gcc -o ./bin/infixToPostfix ./bin/stack.o ./bin/infixToPostfix.o
gcc -Wall -c simplestack.c -o ./bin/simplestack.o
