@echo off
set SCRIPT_DIRECTORY=%~dp0
set CURRENT_DIRECTORY=%cd%
set ARGUMENTS=%*

cd /d %SCRIPT_DIRECTORY%

rd /s/q build
md build
cd build
echo on
pyinstaller --onefile ..\chrysanthemum.py --distpath . --path ..
copy .\chrysanthemum.exe ..\chrysanthemum.exe

cd /d %CURRENT_DIRECTORY%
