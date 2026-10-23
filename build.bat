@echo off
cd /d "%~dp0"

g++ -std=c++20 -O2 -Wall -Wextra main.cpp runner.cpp parseCnt.cpp readAns.cpp -o dper.exe
if errorlevel 1 goto failed
g++ -std=c++20 -O2 -Wall -Wextra gen.cpp -o gen.exe
if errorlevel 1 goto failed
g++ -std=c++20 -O2 -Wall -Wextra std.cpp -o std.exe
if errorlevel 1 goto failed
g++ -std=c++20 -O2 -Wall -Wextra brute.cpp -o brute.exe

echo.
echo Build OK
pause
exit /b 0

:failed
echo.
echo BUILD FAILED
pause
exit /b 1