cmake_minimum_required(VERSION 3.29.3 FATAL_ERROR)

project(RGRCiphers)

set(SOURCE_LIST 
    ${CMAKE_SOURCE_DIR}/src/source/main.cpp 
    ${CMAKE_SOURCE_DIR}/src/source/ciphers.cpp 
    ${CMAKE_SOURCE_DIR}/src/source/functionAfin.cpp 
    ${CMAKE_SOURCE_DIR}/src/source/functionBekon.cpp 
    ${CMAKE_SOURCE_DIR}/src/source/functionRSA.cpp
    ${CMAKE_SOURCE_DIR}/src/source/functionSkitala.cpp
    ${CMAKE_SOURCE_DIR}/src/source/functionVernam.cpp 
    ${CMAKE_SOURCE_DIR}/src/source/mathFunctions.cpp
    ${CMAKE_SOURCE_DIR}/src/source/readANDwrite.cpp)

set(HEADERS_LIST
    ${CMAKE_SOURCE_DIR}/src/headers/ciphers.h
    ${CMAKE_SOURCE_DIR}/src/headers/functionAfin.h 
    ${CMAKE_SOURCE_DIR}/src/headers/functionBekon.h
    ${CMAKE_SOURCE_DIR}/src/headers/functionRSA.h
    ${CMAKE_SOURCE_DIR}/src/headers/functionSkitala.h
    ${CMAKE_SOURCE_DIR}/src/headers/functionVernam.h
    ${CMAKE_SOURCE_DIR}/src/headers/mathFunctions.h
    ${CMAKE_SOURCE_DIR}/src/headers/readANDwrite.h)

set(TEXT_FILE_LIST
    ${CMAKE_SOURCE_DIR}/src/txtFile/binEncryptedBekon.txt
    ${CMAKE_SOURCE_DIR}/src/txtFile/decryptedMessage.txt
    ${CMAKE_SOURCE_DIR}/src/txtFile/encryptedMessage.txt
    ${CMAKE_SOURCE_DIR}/src/txtFile/inputConsoleMessage.txt
    ${CMAKE_SOURCE_DIR}/src/txtFile/keyDecrypt.txt
    ${CMAKE_SOURCE_DIR}/src/txtFile/keyEncrypt.txt
    ${CMAKE_SOURCE_DIR}/src/txtFile/myKey.txt
    ${CMAKE_SOURCE_DIR}/src/txtFile/openText.txt
    ${CMAKE_SOURCE_DIR}/src/txtFile/tableKeyBekon.txt
    ${CMAKE_SOURCE_DIR}/src/txtFile/systemPassword.txt)



# Проверяем наличие всех исходных файлов
set(ALL_SOURCE_FILES_EXIST TRUE)
foreach(source_file ${SOURCE_LIST})
    if(NOT EXISTS ${source_file})
        set(ALL_SOURCE_FILES_EXIST FALSE)
        message(FATAL_ERROR "Исходный файл не найден: ${source_file}")
        break()
    endif()
endforeach()

# Проверяем наличие всех заголовочных файлов
set(ALL_HEADER_FILES_EXIST TRUE)
foreach(header_file ${HEADERS_LIST})
    if(NOT EXISTS ${header_file})
        set(ALL_HEADER_FILES_EXIST FALSE)
        message(FATAL_ERROR "Заголовочный файл не найден: ${header_file}")
        break()
    endif()
endforeach()

# Проверяем наличие всех текстовых файлов
set(ALL_FILES_EXIST TRUE)
foreach(text_file ${TEXT_FILE_LIST})
    if(NOT EXISTS ${text_file})
        set(ALL_FILES_EXIST FALSE)
        message(FATAL_ERROR "Текстовый файл не найден: ${text_file}")
        break()
    endif()
endforeach()

# Если все файлы найдены, добавляем исполняемый файл
if(ALL_FILES_EXIST)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/src/Release)
    add_executable(RGRCiphersExe ${SOURCE_LIST} ${HEADERS_LIST} ${TEXT_FILE_LIST})
else()
    message(FATAL_ERROR "Сборка остановлена.")
endif()
