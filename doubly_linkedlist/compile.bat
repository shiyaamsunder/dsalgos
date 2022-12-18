@echo off
SETLOCAL ENABLEDELAYEDEXPANSION 
set BIN_DIRECTORY=bin
set CC=gcc
set FLAGS=-std=c99 -Iinclude -I..\bin
if not exist %BIN_DIRECTORY% (
   mkdir %BIN_DIRECTORY%
)
SET cFiles= 
FOR /R %%f in (*.c) do ( 
  SET cFiles=!cFiles! %%f 
) 
%CC% !cFiles! -o %BIN_DIRECTORY%\main %FLAGS%
