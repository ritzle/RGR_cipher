#include "Skitala.h"


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	int diameter = 0;
    string message;

    cout << "Шифр Скитала" << endl;

    char s;

    while (true)
    {
        cout << "Выберите опцию:\n1 - шифрование с файла, 2 - дешифрование с файла,\n 3 - шифрование с консоли, 4 - дешифрование с консоли, E - выход\n\n<<<";
        cin >> s;
        switch (s)
        {
        case('1'):
            cout << endl;
            encodeScytaleFile();
            cout << endl;
            break;
        case('2'):
            cout << endl;
            decodeScytaleFile();
            cout << endl;
            break;
        case('3'):
            cout << endl;
            cout << "Введите сообщение для шифрования\n<<<";
            cin.ignore(); // Очистка буфера ввода
            getline(cin, message);
            message = encodeScytaleConsole(message);
            cout << message << endl;;
            cout << endl;
            break;
        case('4'):
            cout << endl;
            cout << decodeScytaleConsole(message) << endl;
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