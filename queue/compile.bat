@echo off
if not exist .\bin mkdir .\bin

pushd .\bin

gcc -Wall -c ..\queue.c -o ..\bin\queue.o
gcc -Wall -c ..\main.c -o ..\bin\main.o


gcc -o ..\bin\queue ..\bin\queue.o ..\bin\main.o

popd
