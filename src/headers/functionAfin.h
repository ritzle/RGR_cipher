#ifndef FUNCTIONAFIN_H
#define FUNCTIONAFIN_H

#include <numeric>
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <fstream>
#include <sstream>
#include <bitset>
#include <algorithm>
#include <map>
#include <cstdlib>

#include "readANDwrite.h"
#include "mathFunctions.h"

using namespace std;

char encryptSimbolAfin(char simbol, int a, int b, int module);
char decryptionSimbolAfin(char simbol, int a, int b, int module);

void RandomParametersAfin(int &a, int &b, int &module);

void encryptMessageAfin(string &encryptText, const string &message, int a, int b, int module);
void decryptMessageAfin(string &decryptText, const string &encryptText, int a, int b, int module);

bool checkAffineCipherParams(int a, int module);

void readKeyDecryptAfin(int &a, int &b, int &module, const std::string &filename);

/*
Стандартные ASCII-символы (от 0 до 127):

Латинские буквы (A-Z, a-z)
Цифры (0-9)
Знаки пунктуации и специальные символы

Расширенные символы (от 128 до 255):

Русские буквы (А-Я, а-я)
Некоторые другие символы, используемые в европейских языках
*/

// функция шифрования
/*
E(x) = (a * x + b) mod module

Где:
E(x) - это функция шифрования
a и b - некоторые константы
x - входное значение
module - модуль, обычно простое число
*/
#endif