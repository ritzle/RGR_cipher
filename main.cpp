#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

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
        return true;
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

string EncryptionText(string openText, int a, int b, int m)
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

string DecryptionText(string EncryptText, int a, int b, int m)
{
    string OpenText = "";

    for (auto simbol : EncryptText)
    {
        EncryptText += D(simbol, a, b, m);
    }
    return EncryptText;
}

int main(void)
{

    /*
    Стандартные ASCII-символы (от 0 до 127):

    Латинские буквы (A-Z, a-z)
    Цифры (0-9)
    Знаки пунктуации и специальные символы

    Расширенные символы (от 128 до 255):

    Русские буквы (А-Я, а-я)
    Некоторые другие символы, используемые в европейских языках
    */
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // функция шифрования
    /*
    E(x) = (a * x + b) mod m

    Где:
    E(x) - это функция шифрования
    a и b - некоторые константы
    x - входное значение
    m - модуль, обычно простое число
    */
    int a = 13, b = 25, m = 256; // b - сдвиг по алфавиту
    // do
    // {
    //     cout << "Введите a и b";
    //     cin >> a >> b;

    // } while (NOD(a,b) != true);
    cout << DecryptionText(EncryptionText(InputText(), a, b, m), a, b, m);
    return 0;
}