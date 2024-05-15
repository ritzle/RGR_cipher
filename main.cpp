#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

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

string InputText()
{
    string firstText = "";
    getline(cin, firstText);
    return firstText;
}
char E(char simbol, int a, int b, int m)
{
    char encryptSimbol;

    encryptSimbol = static_cast<char>((a * static_cast<int>(simbol) + b) % m);

    return encryptSimbol;
}

string EncryptionText(string &openText, int a, int b, int m)
{
    string EncryptText = "";

    for (auto simbol : openText)
    {
        EncryptText += E(simbol, a, b, m);
    }
    return EncryptText;
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

char D(char simbol, int a, int b, int m)
{
    char openSimbol;

    int inversA = findInverseElement(a, m);

    openSimbol = static_cast<char>((inversA * (static_cast<int>(simbol) - b)) % m);

    return openSimbol;
}

string DecryptionText(string &EncryptText, int a, int b, int m)
{
    string OpenText = "";

    for (auto simbol : EncryptText)
    {
        OpenText += D(simbol, a, b, m);
    }
    return OpenText;
}

void RandomParameters(int &a, int &b, int &m)
{
    m = 256; // ну тут нечего не поделать

    vector<int> coprimeNumbersWithM;

    for (int i = 2; i < m; i++)
    {
        if (NOD(i, m))
        {
            coprimeNumbersWithM.push_back(i);
        }
    }

    srand(time(0));

    a = coprimeNumbersWithM[rand() % coprimeNumbersWithM.size()];
    b = 2 + rand() % 255;
}

void decryptTheMessage(int a, int b, int m)
{

    std::ifstream fileEncrypted("encryptedMessage.txt");                  // Открываем файл для чтения
    std::ofstream fileDecrypted("decryptedMessage.txt", std::ios::trunc); // Открываем файл для записи

    // Проверяем, удалось ли открыть файл
    if (fileEncrypted.is_open())
    {

        // Считываем сообщения построчно из файла
        char c;
        while (fileEncrypted.get(c))
        {

            if (fileDecrypted.is_open())
            {                                   // Проверяем, удалось ли открыть файл
                fileDecrypted << D(c, a, b, m); // Записываем элементы массива в файл
            }
            else
            {
                std::cerr << "Не удалось открыть файл для записи." << std::endl; // Выводим сообщение об ошибке, если файл не удалось открыть
            }
        }
        fileEncrypted.close(); // Закрываем файл после чтения
        fileDecrypted.close(); // Закрываем файл после записи
    }
    else
    {
        std::cerr << "Unable to open file" << std::endl; // Выводим сообщение об ошибке, если файл не удалось открыть
    }
}

void encryptTheMessage(int a, int b, int m)
{
    std::ifstream fileMessage("messages.txt");                            // Открываем файл для чтения
    std::ofstream fileEncrypted("encryptedMessage.txt", std::ios::trunc); // Открываем файл для записи
    if (fileMessage.is_open())
    { // Проверяем, удалось ли открыть файл
        string message;

        // Считываем сообщения построчно из файла
        while (getline(fileMessage, message))
        {
            // Проверяем, удалось ли открыть файл
            if (fileEncrypted.is_open())
            {
                char c;
                while (fileMessage.get(c))
                {
                    fileEncrypted << E(c, a, b, m);
                }

                //  std::cout << "Массив успешно записан в файл." << std::endl;
            }
            else
            {
                std::cerr << "Не удалось открыть файл для записи." << std::endl; // Выводим сообщение об ошибке, если файл не удалось открыть
            }
        }

        fileMessage.clear(); // Сброс состояния потока

        fileMessage.close();   // Закрываем файл после чтения
        fileEncrypted.close(); // Закрываем файл после записи
    }
    else
    {
        std::cerr << "Unable to open file" << std::endl; // Выводим сообщение об ошибке, если файл не удалось открыть
        fileMessage.close();                             // Закрываем файл после чтения
        fileEncrypted.close();
    }
}

/*
Стандартные ASCII-символы (от 0 до 127):

Латинские буквы (A-Z, a-z)
Цифры (0-9)
Знаки пунктуации и специальные символы

Расширенные символы (от 128 до 255):

Русские буквы (А-Я, а-я)
Некоторые другие символы, используемые в европейских языках
*/

// функция шифрования
/*
E(x) = (a * x + b) mod m

Где:
E(x) - это функция шифрования
a и b - некоторые константы
x - входное значение
m - модуль, обычно простое число
*/

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a, b, m;
    RandomParameters(a, b, m);

    encryptTheMessage(a, b, m);
    decryptTheMessage(a, b, m);

    // // cout << "Введите текст: ";
    // string inputText = InputText();

    // string encryptedText = EncryptionText(inputText, a, b, m);
    // // cout << "Зашифрованный текст: ";
    // cout << encryptedText << endl;

    // string decryptedText = DecryptionText(encryptedText, a, b, m);
    // // cout << "Расшифрованный текст: ";
    // cout << decryptedText << endl;

    return 0;
}