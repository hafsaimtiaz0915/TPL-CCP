@echo off
REM CD-CCP Compiler Build Script for Windows

echo ================================
echo   CD-CCP COMPILER BUILD SCRIPT
echo ================================
echo.

echo [1] Checking for build tools...
where flex >nul 2>&1
if %ERRORLEVEL% neq 0 (
    echo   Error: flex not found
    goto :eof
)
where bison >nul 2>&1
if %ERRORLEVEL% neq 0 (
    echo   Error: bison not found
    goto :eof
)
where gcc >nul 2>&1
if %ERRORLEVEL% neq 0 (
    echo   Error: gcc not found
    goto :eof
)
echo   Build tools found.

REM Set Bison environment to handle spaces in Program Files path
set BISON_PKGDATADIR=C:\PROGRA~2\GnuWin32\share\bison

echo.
echo [2] Generating parser from c_parser.y...
bison -d -o c_parser.tab.c c_parser.y
if %ERRORLEVEL% neq 0 goto :error

echo.
echo [3] Generating lexer from c_lexer.l...
flex c_lexer.l
if %ERRORLEVEL% neq 0 goto :error
if exist lex.yy.c (
    echo   Lexer generated successfully.
) else (
    echo   Error: lex.yy.c not generated
    goto :error
)

echo.
echo [4] Compiling C files...
gcc -std=c99 -Wall -Wextra -g -o compiler.exe ^
    lex.yy.c c_parser.tab.c ast.c symbol_table.c codegen.c tac_executor.c token_logger.c ^
    semantic_analysis.c ast_enhanced.c main.c -lm
if %ERRORLEVEL% neq 0 goto :error

echo.
echo ================================
echo   BUILD SUCCESSFUL!
echo ================================
echo.
echo Usage: compiler.exe ^<source_file^>
echo.
goto :eof

:error
echo.
echo ERROR: Build failed!
exit /b 1
