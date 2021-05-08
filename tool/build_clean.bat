@rem build_clean.bat
@rem created on 2021/4/4
@rem author @zoloypzuo
@echo off
set CurrentDir=%cd%
set ScriptDir=%~dp0
set RootDir=%ScriptDir%\..
set Args=%*

cd /d %RootDir%
@echo on
rd /s/q build_vs2017
rd /s/q build_vs2019
rd /s/q cmake-build-debug

cd %CurrentDir%
pause