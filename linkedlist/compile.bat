@echo off
if not exist .\bin mkdir .\bin

pushd .\bin

gcc -Wall -c ..\ll.c -o ..\bin\ll.o
gcc -Wall -c ..\main.c -o ..\bin\main.o


gcc -o ..\bin\ll ..\bin\ll.o ..\bin\main.o

popd
