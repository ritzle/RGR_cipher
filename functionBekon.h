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
#include <bitset>
#include <algorithm>
#include <map>
#include <cstdlib>

using namespace std;

void readingFile(string &text, const string &filename);
void writeToFile(const string &text, const string &filename);
map<char, int> generateRandomTableKey();
void distributionByValue(vector<char> &meaning0, vector<char> &meaning1, const map<char, int> &table);
string charToBinary(char c);
char binaryToChar(const string &binaryString);
string encryptSimbol(string charBinary, vector<char> &meaning0, vector<char> &meaning1);
void encryptMessage(string &encryptText, const string &message, vector<char> &meaning0, vector<char> &meaning1);
string decryptSimbol(string enWord, vector<char> &meaning0, vector<char> &meaning1);
void decryptMessage(string &decryptText, const string &encryptText, vector<char> &meaning0, vector<char> &meaning1);

#endif