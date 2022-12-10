@echo off
setlocal enabledelayedexpansion

set FILENAME=%1

if "%~1"=="" (
    echo No parameters have been provided.
    exit /b
)

if exist %FILENAME% (
  echo Folder already exists!
  exit
)

mkdir %FILENAME%
cd %FILENAME%
mkdir include
cd include && echo.>%FILENAME%.h
cd ..
echo.>%FILENAME%.c
echo.>main.c

echo @echo off>compile.bat
echo SETLOCAL ENABLEDELAYEDEXPANSION >> compile.bat
echo set BIN_DIRECTORY=bin>>compile.bat
echo set CC=gcc>>compile.bat
echo set FLAGS=-std=c99 -Iinclude -I..\bin>>compile.bat

echo if not exist %%BIN_DIRECTORY%% (>>compile.bat
echo    mkdir %%BIN_DIRECTORY%%>>compile.bat
echo ^)>>compile.bat
echo SET cFiles= >> compile.bat
echo FOR /R %%%%f in (*.c^) do ( >> compile.bat
echo   SET cFiles=^^!cFiles^^! %%%%f >> compile.bat
echo ^) >> compile.bat
echo %%CC%% ^^!cFiles^^! -o %%BIN_DIRECTORY%%\main %%FLAGS%%>>compile.bat

echo @echo off > run.bat
echo call compile.bat>>run.bat
echo .\bin\main.exe>>run.bat

echo -Wall>>compile_flags.txt
echo -std=c99>>compile_flags.txt
echo -Iinclude>>compile_flags.txt
echo -I../include>>compile_flags.txt
