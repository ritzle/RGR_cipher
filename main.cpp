#include "ciphers.h"

#include "functionAfin.h"
#include "functionVernam.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string cipherType;

    while (true)
    {
        cout << "Введите название шифра (Affine, Vernam, Бэкона, RSA, Скитала) или 'exit' для выхода: ";
        getline(cin, cipherType);

        if (cipherType == "exit")
        {
            break;
        }
        else if (cipherType == "Affine")
        {
            Affin();
            cout << "the result was successfully recorded\n";
        }
        else if (cipherType == "Vernam")
        {
            Vernam();
            cout << "the result was successfully recorded\n";
        }
        else if (cipherType == "Бэкона")
        {
        }
        else if (cipherType == "RSA")
        {
        }
        else if (cipherType == "Скитала")
        {
        }
        else
        {
            cout << "Неизвестный шифр. Попробуйте еще раз." << endl;
        }
    }

    return 0;
}
