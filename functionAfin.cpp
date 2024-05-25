#include "functionAfin.h"

void encryptMessageAfin(string &encryptText, const string &message, int a, int b, int module)
{
    for (auto sim : message)
    {
        encryptText += encryptSimbolAfin(sim, a, b, module);
    }
}

void decryptMessageAfin(string &decryptText, const string &encryptText, int a, int b, int module)
{
    for (auto sim : encryptText)
    {
        decryptText += decryptionSimbolAfin(sim, a, b, module);
    }
}

bool NOD(int a, int b) // находит наибольший общий делитель
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    if (a == 1)
    {
        return true;
    }

    else
    {
        return false;
    }
}

char encryptSimbolAfin(char simbol, int a, int b, int module)
{
    char encryptSimbol;

    encryptSimbol = static_cast<char>((a * static_cast<int>(simbol) + b) % module);

    return encryptSimbol;
}

// Функция для нахождения обратного элемента
int extendedEuclideanAlgorithm(int number, int module, int &x, int &y)
{
    if (module == 0)
    {
        x = 1;
        y = 0;
        return number;
    }
    int x1 = 0, y1 = 0;
    int NOD = extendedEuclideanAlgorithm(module, number % module, x1, y1); // в реккуретной форме переставляем число и модуль местами
    x = y1;
    y = x1 - (number / module) * y1;
    return NOD;
}

int findInverseElement(int number, int module)
{
    int x = 0, y = 0;
    int NOD = extendedEuclideanAlgorithm(number, module, x, y);
    if (NOD != 1)
    {
        cout << "Обратного элемента не существует";
        return 0;
    }
    else
    {
        return (x % module + module) % module; // обработка отрицательных значений
    }
}

char decryptionSimbolAfin(char simbol, int a, int b, int module)
{
    char openSimbol;

    int inversA = findInverseElement(a, module);

    openSimbol = static_cast<char>((inversA * (static_cast<int>(simbol) - b)) % module);

    return openSimbol;
}

void RandomParametersAfin(int &a, int &b, int &module) // рандомные параметры для а и b
{
    module = 256; // ну тут нечего не поделать

    vector<int> coprimeNumbersWithM;

    for (int i = 2; i < module; i++)
    {
        if (NOD(i, module))
        {
            coprimeNumbersWithM.push_back(i);
        }
    }

    srand(time(0));

    a = coprimeNumbersWithM[rand() % coprimeNumbersWithM.size()];
    b = 2 + rand() % 255;
}

bool checkAffineCipherParams(int a, int module)
{
    // Проверяем, что a и module являются взаимно простыми числами
    if (!NOD(a, module))
    {
        cout << "a must be coprime to module";
        return false;
    }
    return true;
}

void readKeyDecryptAfin(int &a, int &b, int &module, const std::string &filename)
{
    string text = "";
    readingFile(text, filename);

    std::istringstream iss(text);
    iss >> a >> b >> module;

    if (iss.fail())
    {
        throw std::runtime_error("Ошибка при чтении параметров из файла: " + filename);
    }
}