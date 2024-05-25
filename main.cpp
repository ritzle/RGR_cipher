#include "functionAfin.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Afin cipher" << endl
         << endl;

    string inputSelection;
    string message;

    int decA, decB, decModule;

MetkaIntputText:

    while (true)
    {
        cout << "Writing a text via the 'console' or 'file'" << endl;
        cout << ": ";

        getline(cin, inputSelection);
        cout << endl;

        if (inputSelection == "console")
        {
            cout << "Input message\n:";
            getline(cin, message);
            writeToFile(message, "inputConsoleMessage.txt");
            break;
        }
        else if (inputSelection == "file")
        {
            readingFile(message, "openText.txt");
            break;
        }
        else
        {
            cout << "unknown command, please try again" << endl;
            goto MetkaIntputText;
        }
    }
    cout << endl;

    cin.clear();
    cin.sync();

MetkaIntputParametrsEncryption:
    int a, b, module;

    while (true)
    {
        cout << "recording parameters for encryption via the 'console' or 'random'" << endl;
        cout << ": ";
        getline(cin, inputSelection);

        string key; // для записи в фаил параметров

        if (inputSelection == "console")
        {
        MetkaIntputParametrsConsole:
            module = 256;
            cout << "enter only a b (for module = 256)\n: ";

            if (!(cin >> a >> b))
            {
                cout << "a and b must be numbers\n";
                cin.clear();
                cin.ignore(1000, '\n');
                goto MetkaIntputParametrsConsole;
            }

            if (checkAffineCipherParams(a, module))
            {
                key = to_string(a) + " " + to_string(b) + " " + to_string(module);
                writeToFile(key, "keyEncrypt.txt");
                writeToFile(key, "keyDecrypt.txt");
                break;
            }
            else
            {
                cout << "enter again\n";
                goto MetkaIntputParametrsConsole;
            }
        }
        else if (inputSelection == "random")
        {
            RandomParametersAfin(a, b, module);
            key = to_string(a) + " " + to_string(b) + " " + to_string(module);
            writeToFile(key, "keyEncrypt.txt");
            writeToFile(key, "keyDecrypt.txt");
            break;
        }
        else
        {
            cout << "unknown command, please try again" << endl;
            goto MetkaIntputParametrsEncryption;
        }
    }
    cout << endl;

    // шифруем текст
    string encryptedMessage = "";
    encryptMessageAfin(encryptedMessage, message, a, b, module);
    writeToFile(encryptedMessage, "encryptedMessage.txt");

    // расшифровываем текст

    cin.clear();
    cin.sync();

MetkaIntputParametrsDecryption:
    while (true)
    {
        cout << "recording parameters for decryption via the 'console' or 'file'(file is true)" << endl;
        cout << ": ";
        getline(cin, inputSelection);

        string decKey; // для записи в фаил параметров

        if (inputSelection == "console")
        {
            cout << "enter  a b module\n: ";

        MetkaIntputParametrsDecryptionConsole:

            if (!(cin >> decA >> decB >> decModule))
            {
                cout << "a and b and Module must be numbers\n";
                cin.clear();
                cin.ignore(1000, '\n');
                goto MetkaIntputParametrsDecryptionConsole;
            }

            if (checkAffineCipherParams(decA, decModule))
            {
                decKey = to_string(decA) + " " + to_string(decB) + " " + to_string(decModule);
                writeToFile(decKey, "keyDecrypt.txt");
                break;
            }
            else
            {
                cout << "enter again\n";
                goto MetkaIntputParametrsDecryptionConsole;
            }
        }
        else if (inputSelection == "file")
        {
            readKeyDecryptAfin(decA, decB, decModule, "keyDecrypt");
            break;
        }
        else
        {
            cout << "unknown command, please try again" << endl;
            goto MetkaIntputParametrsDecryption;
        }
    }

    string decryptedMessage = "";
    decryptMessageAfin(decryptedMessage, encryptedMessage, decA, decB, decModule);
    writeToFile(decryptedMessage, "decryptedMessage.txt");

    return 0;
}
