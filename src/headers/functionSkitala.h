#ifndef FUNCTIONSkitala_H
#define FUNCTIONSkitala_H

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <numeric>
#include <Windows.h>
#include <fstream>
#include <string>
#include <sstream>

#include "readANDwrite.h"

using namespace std;

string encodeScytaleConsole(string message);

string decodeScytaleConsole(string encodedMessage);

void encodeScytaleFile();

void decodeScytaleFile();

#endif