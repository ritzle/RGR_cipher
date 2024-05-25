#include <iostream>
#include <string>

using namespace std;

int main()
{
    string cipherType;

    while (true)
    {
        cout << "Введите название шифра (Афинные, Вернам, Бэкона, RSA, Скитала) или 'exit' для выхода: ";
        getline(cin, cipherType);

        if (cipherType == "exit")
        {
            break;
        }
        else if (cipherType == "Афинные")
        {
        }
        else if (cipherType == "Вернам")
        {
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