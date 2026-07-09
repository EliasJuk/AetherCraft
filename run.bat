@echo off
setlocal

title AetherCraft

REM ==========================================================
REM Configuracao do vcpkg
REM ==========================================================

set "TOOLCHAIN="

if exist "C:\vcpkg\scripts\buildsystems\vcpkg.cmake" (
    set "TOOLCHAIN=-DCMAKE_TOOLCHAIN_FILE=C:\vcpkg\scripts\buildsystems\vcpkg.cmake"
)

REM ==========================================================
REM MENU
REM ==========================================================

:menu
cls
echo ============================
echo        AETHER CRAFT
echo ============================
echo.
echo [1] Configurar CMake
echo [2] Compilar
echo [3] Executar
echo [4] Rebuild completo
echo [5] Limpar build
echo [6] Quick Run
echo [0] Sair
echo.

set /p option=Escolha uma opcao:

if "%option%"=="1" goto configure
if "%option%"=="2" goto build
if "%option%"=="3" goto run
if "%option%"=="4" goto rebuild
if "%option%"=="5" goto clean
if "%option%"=="6" goto quick
if "%option%"=="0" exit /b

goto menu


REM ==========================================================
REM CONFIGURAR CMAKE
REM ==========================================================

:configure
cls

echo ============================
echo    CONFIGURAR CMAKE
echo ============================
echo.

if not exist build mkdir build

cmake -S . -B build %TOOLCHAIN%

pause
goto menu


REM ==========================================================
REM COMPILAR
REM ==========================================================

:build
cls

echo ============================
echo       COMPILANDO
echo ============================
echo.

cmake --build build --config Debug

pause
goto menu


REM ==========================================================
REM EXECUTAR
REM ==========================================================

:run
cls

echo ============================
echo       EXECUTANDO
echo ============================
echo.

if exist build\Debug\Aether.exe (
    build\Debug\Aether.exe
) else if exist build\Aether.exe (
    build\Aether.exe
) else (
    echo Executavel nao encontrado.
    echo Compile o projeto primeiro.
)

pause
goto menu


REM ==========================================================
REM REBUILD COMPLETO
REM ==========================================================

:rebuild
cls

echo ============================
echo    REBUILD COMPLETO
echo ============================
echo.

if exist build (
    rmdir /s /q build
)

mkdir build

cmake -S . -B build %TOOLCHAIN%

if errorlevel 1 (
    echo.
    echo Erro ao configurar o projeto.
    pause
    goto menu
)

cmake --build build --config Debug

if errorlevel 1 (
    echo.
    echo Erro na compilacao.
    pause
    goto menu
)

echo.
echo Rebuild concluido com sucesso.

pause
goto menu


REM ==========================================================
REM LIMPAR BUILD
REM ==========================================================

:clean
cls

echo ============================
echo      LIMPAR BUILD
echo ============================
echo.

if exist build (
    rmdir /s /q build
    echo Build removido com sucesso.
) else (
    echo Pasta build nao existe.
)

pause
goto menu


REM ==========================================================
REM QUICK RUN
REM ==========================================================

:quick
cls

echo ============================
echo        QUICK RUN
echo ============================
echo.

if not exist build (
    mkdir build
)

echo Configurando projeto...
cmake -S . -B build %TOOLCHAIN%

if errorlevel 1 (
    echo.
    echo Erro ao configurar o projeto.
    pause
    goto menu
)

echo.
echo Compilando...
cmake --build build --config Debug

if errorlevel 1 (
    echo.
    echo Erro na compilacao.
    pause
    goto menu
)

echo.
echo Executando...
echo.

if exist build\Debug\Aether.exe (
    build\Debug\Aether.exe
) else if exist build\Aether.exe (
    build\Aether.exe
) else (
    echo Executavel nao encontrado.
)

pause
goto menu