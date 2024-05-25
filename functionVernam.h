#ifndef FUNCTIONVERNAM_H
#define FUNCTIONVERNAM_H

#include "ciphers.h"

int xorS(char a, char b);
void encryptMessageVernam(string &encryptText, const string &message, const string &key);
void decryptMessageVernam(string &encryptText, const string &encryptedMessage, const string &key);
string generateKeyVernam(const string &message);

#endif