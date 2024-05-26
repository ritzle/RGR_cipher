cmake_minimum_required(VERSION 3.29.3 FATAL_ERROR)

project(RGRCiphers)

set(SOURCE_LIST 
    src/source/main.cpp 
    src/source/ciphers.cpp 
    src/source/functionAfin.cpp 
    src/source/functionBekon.cpp 
    src/source/functionRSA.cpp 
    src/source/functionVernam.cpp 
    src/source/mathFunctions.cpp
    src/source/readANDwrite.cpp)

set(HEADERS_LIST
    src/headers/ciphers.h
    src/headers/functionAfin.h 
    src/headers/functionBekon.h
    src/headers/functionRSA.h
    src/headers/functionVernam.h
    src/headers/mathFunctions.h
    src/headers/readANDwrite.h)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/Release)

add_executable(RGRCiphersExe ${SOURCE_LIST} ${HEADERS_LIST})
