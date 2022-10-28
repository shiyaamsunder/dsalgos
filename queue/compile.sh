#!/usr/bin/env bash

BIN_DIRECTORY="bin"

if [ ! -d $BIN_DIRECTORY ]; then
  mkdir ./bin
fi

gcc -Wall -c queue.c -o ./bin/queue.o
gcc -Wall -c main.c -o ./bin/main.o
#gcc -Wall -c infixToPostfix.c -o ./bin/infixToPostfix.o
gcc -o ./bin/queue ./bin/queue.o ./bin/main.o
#gcc -o ./bin/infixToPostfix ./bin/queue.o ./bin/infixToPostfix.o
#gcc -Wall -c simplequeue.c -o ./bin/simplequeue.o
