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

map<char, int> generateRandomTableKeyBekon();
void distributionByValueBekon(vector<char> &meaning0, vector<char> &meaning1, const map<char, int> &table);
string charToBinaryBekon(char c);
char binaryToCharBekon(const string &binaryString);
string encryptSimbolBekon(string charBinary, vector<char> &meaning0, vector<char> &meaning1);
void encryptMessageBekon(string &encryptText, const string &message, vector<char> &meaning0, vector<char> &meaning1);
string decryptSimbolBekon(string enWord, vector<char> &meaning0, vector<char> &meaning1);
void decryptMessageBekon(string &decryptText, const string &encryptText, vector<char> &meaning0, vector<char> &meaning1);
void readTableKey(map<char, int> &tableKey, const string &filename);
void writeTableKeyToFile(const map<char, int> &tableKey, const string &filename);
#endif