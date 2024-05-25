#include "functionVernam.h"

string readingFile(const string &filename)
{
    ifstream file(filename, ios::binary);
    if (!file.is_open())
    {
        cerr << "Unable to open file " << filename << endl;
        throw "Unable to open file ";
    }

    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    return content;
}

void writeToFile(const string &text, const string &filename)
{
    ofstream file(filename, ios::binary | ios::trunc);
    if (!file.is_open())
    {
        throw "Unable to open file: " + filename;
        return;
    }

    file << text;
    file.close();
}

int xorSVernam(char a, char b)
{
    return static_cast<int>(a) ^ static_cast<int>(b);
}

string encryptMessageVernam(const string &message, const string &key)
{
    string encryptedMessage;
    for (size_t i = 0; i < message.size(); ++i)
    {
        encryptedMessage += static_cast<unsigned char>(xorSVernam(message[i], key[i % key.size()]));
    }
    return encryptedMessage;
}

string decryptMessageVernam(const string &encryptedMessage, const string &key)
{
    return encryptMessageVernam(encryptedMessage, key); // Дешифрование - то же самое, что и шифрование в шифре Вернама
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