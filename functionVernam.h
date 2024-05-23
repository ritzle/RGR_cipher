#ifndef FUNCTIONVERNAM_H
#define FUNCTIONVERNAM_H

#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

string readingFile(const string &filename);
void writeToFile(const string &text, const string &filename);
int xorS(char a, char b);
string encryptMessage(const string &message, const string &key);
string decryptMessage(const string &encryptedMessage, const string &key);
string generateKey(const string &message);

#endif