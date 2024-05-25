#ifndef FUNCTIONMATH_H
#define FUNCTIONMATH_H

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

// Функция для нахождения обратного элемента
int extendedEuclideanAlgorithm(int number, int module, int &x, int &y);
int findInverseElement(int number, int module);
bool NOD(int a, int b);

#endif
