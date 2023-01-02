@echo off
SETLOCAL ENABLEDELAYEDEXPANSION

SET BIN_DIR=.\bin
SET CC=gcc
SET FLAGS=-std=c99 -I..\utils
if not exist %BIN_DIR% mkdir %BIN_DIR%
for %%i in ( *.c ) do (
    %CC% -Wall -g -o %BIN_DIR%\%%~ni.exe %%i %FLAGS%
)