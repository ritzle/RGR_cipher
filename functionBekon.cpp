#include "functionBekon.h"

void readingFile(string &text, const string &filename)
{
    ifstream file(filename, ios::binary);
    if (!file.is_open())
    {
        cerr << "Unable to open file " << filename << endl;
        throw "Unable to open file ";
    }

    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    text = move(content);
    file.close();
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

map<char, int> generateRandomTableKey()
{
    srand(time(NULL));

    map<char, int> charMap;

    for (int c = 0; c <= 255; c++)
    {
        charMap[static_cast<char>(c)] = rand() % 2; // Генерация случайного значения 0 или 1
    }

    ofstream file("tableKey.txt", std::ios::out);
    if (!file.is_open())
    {
        throw std::runtime_error("Не удалось открыть файл 'tableKey.txt'");
    }

    for (const auto &pair : charMap)
    {
        std::string binaryString = charToBinary(pair.first);
        file << pair.first << "\t" << binaryString << "\t" << pair.second << "\n";
    }

    file.close();
    return charMap;
}

void distributionByValue(vector<char> &meaning0, vector<char> &meaning1, const map<char, int> &table)
{
    for (auto tableMeaning : table)
    {
        if (tableMeaning.second == 1)
        {
            meaning0.push_back(tableMeaning.first);
        }
        else
        {
            meaning1.push_back(tableMeaning.first);
        }
    }
}

string charToBinary(char c)
{
    int asciiValue = static_cast<int>(c);
    bitset<8> binary(asciiValue);
    return binary.to_string();
}

char binaryToChar(const string &binaryString)
{
    if (binaryString.length() != 8)
    {
        throw invalid_argument("Входная строка должна иметь длину 8 символов");
    }

    bitset<8> binaryValue(binaryString);
    return static_cast<char>(binaryValue.to_ulong());
}

string encryptSimbol(string charBinary, vector<char> &meaning0, vector<char> &meaning1)
{
    srand(time(0));
    string encryptChar = "";
    for (auto simbol : charBinary)
    {
        encryptChar += (simbol == '0' ? meaning0[rand() % (meaning0.size() - 1)] : meaning1[rand() % (meaning1.size() - 1)]);
    }
    return encryptChar;
}

void encryptMessage(string &encryptText, const string &message, vector<char> &meaning0, vector<char> &meaning1)
{
    string binText = "";

    for (auto simbol : message)
    {
        string binChar = charToBinary(simbol);

        binText += binChar + " ";

        string encryptChar = encryptSimbol(binChar, meaning0, meaning1);

        encryptText += encryptChar;
    }

    writeToFile(binText, "binEncrypted.txt");
}

string decryptSimbol(string enWord, vector<char> &meaning0, vector<char> &meaning1)
{
    string decryptChar = "";
    for (auto simbol : enWord)
    {
        if (find(meaning0.begin(), meaning0.end(), simbol) != meaning0.end())
        {
            decryptChar += '0';
        }
        else
        {
            decryptChar += '1';
        }
    }
    return decryptChar;
}

void decryptMessage(string &decryptText, const string &encryptText, vector<char> &meaning0, vector<char> &meaning1)
{
    // Итерируем по входной строке с шагом 8 (длина одного символа)
    for (size_t i = 0; i < encryptText.length(); i += 8)
    {
        string wordLen8 = encryptText.substr(i, 8);
        string binWord = decryptSimbol(wordLen8, meaning0, meaning1);

        decryptText += binaryToChar(binWord);
    }
}
