#ifndef READWRITE_H
#define READWRITE_H

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

using namespace std;

void readingFile(string &text, const string &filename);
void writeToFile(const string &text, const string &filename);

#endif
