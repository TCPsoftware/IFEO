@echo off
reg query "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Image File Execution Options" >tmp_reg.txt
find "996E" < tmp_reg.txt
if %errorlevel% NEQ 0 (
echo.
echo 没有发现IFEO 996E。
echo.
) else (
echo.
echo 有IFEO 996E！
echo.
)
del tmp_reg.txt
pause