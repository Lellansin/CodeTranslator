@echo off
if not exist "%~dp0bin\cl.exe" goto epicfail1
if not exist "%~dp0config.bat" goto epicfail2
cmd /k ""%~dp0config.bat" && title CodeTranslator v0.1"
goto :eof

:epicfail1
set X_ERR1=����: ���ڸ�Ŀ¼������ %~nx0 �ļ�, �벻Ҫ�ƶ�����Ĵ��ļ���
set X_ERR2=       ����������˱����������ƻ�·��������л�ԭ����Ӧ���޸ĵ�ǰ�����ļ���
set X_ERR3=       PS�����ɿ�ݷ�ʽ�ǿ��������
cmd /t:4f /k "echo %X_ERR1% && echo %X_ERR2% && echo %X_ERR3% && title ����"
goto :eof

:epicfail2
set X_ERR1=����: �����ļ�config.bat��ʧ,���ļ�ԭ�����ڸ�Ŀ¼��
set X_ERR2=       �벻Ҫ�ƶ�����ĸ��ļ������³���
cmd /t:4f /k "echo %X_ERR1% && echo %X_ERR2% && title ����"
goto :eof


