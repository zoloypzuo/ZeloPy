@rem build_vs2017.bat
@rem created on 2021/4/4
@rem author @zoloypzuo
@echo off
set CurrentDir=%cd%
set ScriptDir=%~dp0
set RootDir=%ScriptDir%\..
set Args=%*

cd /d %RootDir%
@echo on
mkdir build_vs2017
cd build_vs2017

cmake -DCMAKE_GENERATOR_PLATFORM=win32 -G  "Visual Studio 15" ..
cmake --build . --config debug


cd %CurrentDir%
pause