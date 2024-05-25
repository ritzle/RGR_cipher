#include "functionAfin.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Afin cipher" << endl
         << endl;

    cout << "writing a text via the console or file" << endl;
    cout << ": ";

    string inputSelection;
    getline(cin, inputSelection);
    cout << endl;

    string message;

    if (inputSelection == "console")
    {
        cout << ": ";
        getline(cin, message);
        writeToFile(message, "inputConsoleMessage.txt");
    }
    else if (inputSelection == "file")
    {
        readingFile(message, "openText.txt");
    }
    else
    {
        cout << "unknown command" << endl;
        return 1;
    }
    cout << endl;

    cin.clear();
    cin.sync();

    cout << "recording parameters for encryption via the console or random" << endl;
    cout << ": ";
    getline(cin, inputSelection);

enterAgain: // проверка на правильность ввода параметров

    int a, b, module;
    string key; // для записи в фаил параметров

    if (inputSelection == "console")
    {
        module = 256;
        cout << "enter only a b (for module = 256)\n :";
        cin >> a;
        cin >> b;

        if (checkAffineCipherParams(a, module))
        {

            key = to_string(a) + " " + to_string(b) + " " + to_string(module);
            writeToFile(key, "keyEncrypt.txt");
            writeToFile(key, "keyDecrypt.txt");
        }
        else
        {
            cout << "enter again";
            goto enterAgain;
        }
    }
    else if (inputSelection == "random")
    {
        RandomParametersAfin(a, b, module);

        key = to_string(a) + " " + to_string(b) + " " + to_string(module);
        writeToFile(key, "keyEncrypt.txt");
        writeToFile(key, "keyDecrypt.txt");
    }
    else
    {
        cout << "unknown command" << endl;
    }

    // шифруем текст
    string encryptedMessage = "";
    encryptMessageAfin(encryptedMessage, message, a, b, module);
    writeToFile(encryptedMessage, "encryptedMessage.txt");

    // расшифровываем текст

    cin.clear();
    cin.sync();

    cout << "recording parameters for decryption via the console or file(file is true)" << endl;
    cout << ": ";
    getline(cin, inputSelection);

enterAgain2: // проверка на правильность ввода параметров

    int decA, decB, decModule;
    string decKey; // для записи в фаил параметров

    if (inputSelection == "console")
    {
        module = 256;
        cout << "enter  a b module\n :";
        cin >> decA;
        cin >> decB;
        cin >> decModule;

        if (checkAffineCipherParams(decA, decModule))
        {

            decKey = to_string(decA) + " " + to_string(decB) + " " + to_string(decModule);
            writeToFile(decKey, "keyDecrypt.txt");
        }
        else
        {
            cout << "enter again";
            goto enterAgain2;
        }
    }
    else if (inputSelection == "file")
    {
        readKeyDecrypt(decA, decB, decModule, "keyDecrypt");
    }
    else
    {
        cout << "unknown command" << endl;
    }

    string decryptedMessage = "";
    decryptMessageAfin(decryptedMessage, encryptedMessage, decA, decB, decModule);
    writeToFile(decryptedMessage, "decryptedMessage.txt");

    return 0;
}