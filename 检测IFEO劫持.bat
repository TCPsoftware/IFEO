@echo off
reg query "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Image File Execution Options" >tmp_reg.txt
find "Debug" < tmp_reg.txt
if %errorlevel% NEQ 0 (
echo.
echo 没有发现IFEO劫持。
echo.
) else (
echo.
echo 有映像劫持！
echo.
)
del tmp_reg.txt
pause