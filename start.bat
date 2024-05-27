@echo off

mkdir build 
cd build
cmake .. 
cmake --build . 
cmake --build . --config Release
cd .. > nul
cd src > nul
cd Release > nul

cls


.\RGRCiphersExe.exe