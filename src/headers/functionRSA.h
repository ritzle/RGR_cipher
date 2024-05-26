#ifndef FUNCTIONRSA_H
#define FUNCTIONRSA_H

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <numeric>
#include <Windows.h>
#include <fstream>
#include <string>
#include <sstream>

#include "mathFunctions.h"

using namespace std;

void DecryptedTextFileRSA();

void decryptedTextFromTheConsoleRSA();

void EncryptTextFromTheConsoleRSA();

void EncryptedTextFileRSA();

int modPower(int base, int exp, int mod);

void Eratosthenes(vector<int> &vector_Prime_Nums); // решето Эратосфена 2- 200 диапазон

int GetRandomNumber(int min, int max); // генерация рандомных чисел в заданном диапазоне

int GenerationSimpleRandomNumber();

int EilerFunction(int p, int q);

int GenerationOpenExponent(int p, int q);

void GenerationOpenANDSecretKeyRSA(); // создаются два простых числа p, q. Находится их p*q = n - модуль.

#endif
