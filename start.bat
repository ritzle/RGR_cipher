@echo off

mkdir build > nul
cd build > nul
cmake .. > nul
cmake --build . > nul
cmake --build . --config Release > nul
cd .. > nul
cd src > nul
cd Release > nul


.\RGRCiphersExe.exe