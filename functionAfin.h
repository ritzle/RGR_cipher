#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <sstream>
#include <numeric>

#include <stdio.h>

using namespace std;

bool NOD(int a, int b);

char encryptSimbolAfin(char simbol, int a, int b, int module);
char decryptionSimbolAfin(char simbol, int a, int b, int module);

// Функция для нахождения обратного элемента
int extendedEuclideanAlgorithm(int number, int module, int &x, int &y);
int findInverseElement(int number, int module);

void RandomParametersAfin(int &a, int &b, int &module);

void readingFile(string &text, const string &filename);
void writeToFile(const string &text, const string &filename);

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