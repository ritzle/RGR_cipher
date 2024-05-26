#include "../headers/functionVernam.h"

int xorS(char a, char b)
{
    return static_cast<int>(a) ^ static_cast<int>(b);
}

void encryptMessageVernam(string &encryptText, const string &message, const string &key)
{

    for (size_t i = 0; i < message.size(); ++i)
    {
        encryptText += static_cast<unsigned char>(xorS(message[i], key[i % key.size()]));
    }
}

void decryptMessageVernam(string &encryptText, const string &encryptedMessage, const string &key)
{
    return encryptMessageVernam(encryptText, encryptedMessage, key); // Дешифрование - то же самое, что и шифрование в шифре Вернама
}

string generateKeyVernam(const string &message)
{
    string key = " ";
    int rd;

    for (size_t i = 0; i < message.size(); i++)
    {
        rd = 66 + (rand() % 55);
        key += static_cast<char>(rd);
    }

    return key;
}