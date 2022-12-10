@echo off
SETLOCAL ENABLEDELAYEDEXPANSION
if not exist .\bin mkdir .\bin

SET CC=gcc
SET FLAGS=-std=c99 -Iinclude -I..\include

SET cFiles=
FOR /R %%f in (*.c) do (
  SET cFiles=!cFiles! %%f
)

%CC% %cFiles% -o .\bin\main.exe %FLAGS%
