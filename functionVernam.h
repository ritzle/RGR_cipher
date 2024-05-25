#ifndef FUNCTIONVERNAM_H
#define FUNCTIONVERNAM_H

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

using namespace std;

int xorS(char a, char b);
void encryptMessageVernam(string &encryptText, const string &message, const string &key);
void decryptMessageVernam(string &encryptText, const string &encryptedMessage, const string &key);
string generateKeyVernam(const string &message);

#endif