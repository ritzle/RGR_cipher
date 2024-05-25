#ifndef CIPHERS_H
#define CIPHERS_H

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

void readingFile(string &text, const string &filename);
void writeToFile(const string &text, const string &filename);

void Affin();
void Vernam();

#endif