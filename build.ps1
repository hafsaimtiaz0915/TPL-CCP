#!/usr/bin/env pwsh

# CD-CCP Compiler Build Script for Windows PowerShell

Write-Host "================================" -ForegroundColor Cyan
Write-Host "  CD-CCP COMPILER BUILD SCRIPT  " -ForegroundColor Cyan
Write-Host "================================" -ForegroundColor Cyan
Write-Host ""

# Check for required tools
Write-Host "[1] Checking for build tools..." -ForegroundColor Yellow

if (Get-Command flex -ErrorAction SilentlyContinue) {
    Write-Host "  ✓ flex found" -ForegroundColor Green
} else {
    Write-Host "  ✗ flex NOT found" -ForegroundColor Red
}

if (Get-Command bison -ErrorAction SilentlyContinue) {
    Write-Host "  ✓ bison found" -ForegroundColor Green
} else {
    Write-Host "  ✗ bison NOT found" -ForegroundColor Red
}

if (Get-Command gcc -ErrorAction SilentlyContinue) {
    Write-Host "  ✓ gcc found" -ForegroundColor Green
} else {
    Write-Host "  ✗ gcc NOT found" -ForegroundColor Red
}

Write-Host ""
Write-Host "[2] Generating lexer from c_lexer.l..." -ForegroundColor Yellow
flex -o lex.yy.c c_lexer.l
Write-Host "  ✓ Lexer generated: lex.yy.c" -ForegroundColor Green

Write-Host ""
Write-Host "[3] Generating parser from c_parser.y..." -ForegroundColor Yellow
bison -d -o c_parser.tab.c c_parser.y
Write-Host "  ✓ Parser generated: c_parser.tab.c, c_parser.tab.h" -ForegroundColor Green

Write-Host ""
Write-Host "[4] Compiling C files..." -ForegroundColor Yellow
gcc -std=c99 -Wall -Wextra -g -o compiler.exe `
    lex.yy.c c_parser.tab.c symbol_table.c codegen.c main.c -lm
Write-Host "  ✓ Compiler built: compiler.exe" -ForegroundColor Green

Write-Host ""
Write-Host "================================" -ForegroundColor Green
Write-Host "  BUILD SUCCESSFUL!           " -ForegroundColor Green
Write-Host "================================" -ForegroundColor Green
Write-Host ""
Write-Host "Usage: .\compiler.exe <source_file>" -ForegroundColor Cyan
Write-Host ""

