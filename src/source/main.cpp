#include "../headers/ciphers.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

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
            cout << "the result was successfully recorded\n";
        }
        else if (cipherType == "Vernam")
        {
            Vernam();
            cout << "the result was successfully recorded\n";
        }
        else if (cipherType == "Bacon")
        {
            Bacon();
            cout << "the result was successfully recorded\n";
        }
        else if (cipherType == "RSA")
        {
            RSA();
            cout << "the result was successfully recorded\n";
        }
        else if (cipherType == "Skitala")
        {
            Skitala();
            cout << "the result was successfully recorded\n";
        }
        else
        {
            cout << "Unknown cipher. Re-enter" << endl;
        }
    }

    return 0;
}
