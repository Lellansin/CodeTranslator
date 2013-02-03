@echo off
if not exist "%~dp0bin\cl.exe" goto epicfail1
if not exist "%~dp0config.bat" goto epicfail2
cmd /k ""%~dp0config.bat" && title CodeTranslator v0.1"
goto :eof

:epicfail1
set X_ERR1=错误: 请在根目录下运行 %~nx0 文件, 请不要移动或更改此文件。
set X_ERR2=       如果您更改了编译器的名称或路径，请进行还原或相应的修改当前配置文件。
set X_ERR3=       PS：生成快捷方式是可以允许的
cmd /t:4f /k "echo %X_ERR1% && echo %X_ERR2% && echo %X_ERR3% && title 错误"
goto :eof

:epicfail2
set X_ERR1=错误: 配置文件config.bat丢失,该文件原本处于根目录下
set X_ERR2=       请不要移动或更改该文件并重新尝试
cmd /t:4f /k "echo %X_ERR1% && echo %X_ERR2% && title 错误"
goto :eof


