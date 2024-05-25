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
int xorSVernam(char a, char b);
string encryptMessageVernam(const string &message, const string &key);
string decryptMessageVernam(const string &encryptedMessage, const string &key);
string generateKeyVernam(const string &message);

#endif