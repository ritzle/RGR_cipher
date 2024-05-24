#include "Header.h"


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char s;

    while (true)
    {
        cout << "Выберите опцию:\n 1 - генерация рандомных ключей, 2 - шифрование с файла, 3 - дешифрование с файла,\n 4 - шифрование с консоли, 5 - дешифрование с консоли, E - выход\n\n<<<";
        cin >> s;
        switch (s)
        {
        case('1'):
            cout << endl;
            GenerationOpenANDSecretKeyRSA();
            cout << endl;
            break;
        case('2'):
            cout << endl;
            EncryptedTextFileRSA();
            cout << endl;
            break;
        case('3'):
            cout << endl;
            DecryptedTextFileRSA();
            cout << endl;
            break;
        case('4'):
            cout << endl;
            EncryptTextFromTheConsoleRSA();
            cout << endl;
            break;
        case('5'):
            cout << endl;
            decryptedTextFromTheConsoleRSA();
            cout << endl;
            break;
        case('E'):
            return 0;
        default:
            cout << "Неизвестная команда. Повторите ввод\n" << endl;
        }

    }

    return 0;
}