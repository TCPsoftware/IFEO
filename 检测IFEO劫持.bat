@echo off
reg query "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Image File Execution Options" >tmp_reg.txt
find "Debug" < tmp_reg.txt
if %errorlevel% NEQ 0 (
echo.
echo û�з���IFEO�ٳ֡�
echo.
) else (
echo.
echo ��ӳ��ٳ֣�
echo.
)
del tmp_reg.txt
pause