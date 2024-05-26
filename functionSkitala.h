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

using namespace std;


string encodeScytaleConsole(string message);

string decodeScytaleConsole(string encodedMessage); 

void encodeScytaleFile();

void decodeScytaleFile();

void writeToFile(const string& text, const string& filename);

void readingFile(string& text, const string& filename);
#endif