#include "../headers/ciphers.h"
#include <iomanip>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "--------------------ENCRYPTOR--------------------" << endl;

    isValidSystemPassword();

    string cipherType;

    while (true)
    {
        cin.ignore();
        cout << "Enter the name of the cipher (Affine, Vernam, Bacon, RSA, Skitala) or 'exit' to output:\n<<<";
        getline(cin, cipherType);

        if (cipherType == "exit")
        {
            break;
        }
        else if (cipherType == "Affine")
        {
            Affin();
            cout << "\n the result was successfully recorded\n\n";
        }
        else if (cipherType == "Vernam")
        {
            Vernam();
            cout << "\n the result was successfully recorded\n\n";
        }
        else if (cipherType == "Bacon")
        {
            Bacon();
            cout << "\n the result was successfully recorded\n\n";
        }
        else if (cipherType == "RSA")
        {
            RSA();
            cout << "\n the result was successfully recorded\n\n";
        }
        else if (cipherType == "Skitala")
        {
            Skitala();
            cout << "\n the result was successfully recorded\n\n";
        }
        else
        {
            cout << "Unknown cipher. Re-enter" << endl;
        }
    }

    return 0;
}
