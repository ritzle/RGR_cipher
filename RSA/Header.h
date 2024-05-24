#ifdef HEADER_H
#define HEADER_H

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <numeric>
#include <Windows.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void DecryptedTextFileRSA();

void decryptedTextFromTheConsoleRSA();

void EncryptTextFromTheConsoleRSA();

void EncryptedTextFileRSA();

int modPower(int base, int exp, int mod);

void Eratosthenes(vector<int>& vector_Prime_Nums);  //решето Эратосфена 2- 200 диапазон

int GetRandomNumber(int min, int max);// генерация рандомных чисел в заданном диапазоне

int GenerationSimpleRandomNumber();

bool NOD(int a, int b); // находит наибольший общий делитель

int EilerFunction(int p, int q);

int GenerationOpenExponent(int p, int q);

int extendedEuclideanAlgorithm(int number, int module, int& x, int& y);

int findInverseElement(int number, int module);

void GenerationOpenANDSecretKeyRSA();// создаются два простых числа p, q. Находится их p*q = n - модуль. 


#endif

