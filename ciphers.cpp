#include "ciphers.h"

void Affin()
{
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
            readKeyDecryptAfin(decA, decB, decModule, "keyDecrypt.txt");
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
}

void Vernam()
{
    cout << "Vernam cipher" << endl;

    string inputSelection;
    string message;
    string key;
    string decKey;

MetkaIntputText:
    while (true)
    {
        cout << "writing a text via the console or file" << endl;
        cout << ": ";

        getline(cin, inputSelection);
        cout << endl;

        if (inputSelection == "console")
        {
            cout << ": ";
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

MetkaIntputKeyEncrypted:
    while (true)
    {
        cout << "recording key for encryption via the console or random" << endl;
        cout << ": ";
        getline(cin, inputSelection);

        if (inputSelection == "console")
        {
            cin.clear();
            cin.sync();
            cout << ": ";
            getline(cin, key);
            writeToFile(key, "keyEncrypt.txt");
            writeToFile(key, "keyDecrypt.txt");
            break;
        }
        else if (inputSelection == "random")
        {
            cin.clear();
            cin.sync();
            key = generateKeyVernam(message);
            writeToFile(key, "keyEncrypt.txt");
            writeToFile(key, "keyDecrypt.txt");
            break;
        }
        else
        {
            cout << "unknown command, please try again" << endl;
            goto MetkaIntputKeyEncrypted;
        }
    }
    cout << endl;

    // шифруем текст

    string encryptedMessage = "";
    encryptMessageVernam(encryptedMessage, message, key);
    writeToFile(encryptedMessage, "encryptedMessage.txt");

    // расшифровка текста

    cin.clear();
    cin.sync();

MetkaIntputKeyDecrypted:
    while (true)
    {
        cout << "recording key for decryption via the console or file(file is true)" << endl;
        cout << ": ";
        getline(cin, inputSelection);

        if (inputSelection == "console")
        {
            cout << "enter key decrypt\n :";
            cin >> decKey;
            writeToFile(decKey, "keyDecrypt.txt");
            break;
        }
        else if (inputSelection == "file")
        {
            readingFile(decKey, "keyDecrypt.txt");
            break;
        }
        else
        {
            cout << "unknown command, please try again" << endl;
            goto MetkaIntputKeyDecrypted;
        }
    }
    cout << endl;

    string decryptedMessage = "";
    decryptMessageVernam(decryptedMessage, encryptedMessage, decKey);
    writeToFile(decryptedMessage, "decryptedMessage.txt");

    cout << endl;
    // cin.get(); //для ожидания
}

void Bacon()
{
    cout << "Bacon cipher" << endl
         << endl;

    string inputSelection;

    string message;

MetkaIntputText:
    cin.clear();
    cin.sync();
    while (true)
    {
        cout << "writing a text via the console or file" << endl;
        cout << ": ";

        getline(cin, inputSelection);
        cout << endl;

        if (inputSelection == "console")
        {
            cout << ": ";
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

    map<char, int> tableKey;

    vector<char> meaningEncrypt0;
    vector<char> meaningEncrypt1;

MetkaIntputKeyEncrypted:
    while (true)
    {
        cout << "recording key for encryption via the 'myFile' or random" << endl;
        cout << ": ";
        getline(cin, inputSelection);

        if (inputSelection == "myFile")
        {
            cin.clear();
            cin.sync();

            readTableKey(tableKey, "myKey.txt");
            writeTableKeyToFile(tableKey, "keyEncrypt.txt");
            writeTableKeyToFile(tableKey, "keyDecrypt.txt");
            distributionByValueBekon(meaningEncrypt0, meaningEncrypt1, tableKey);

            break;
        }
        else if (inputSelection == "random")
        {
            cin.clear();
            cin.sync();

            tableKey = generateRandomTableKeyBekon();
            writeTableKeyToFile(tableKey, "keyEncrypt.txt");
            writeTableKeyToFile(tableKey, "keyDecrypt.txt");
            distributionByValueBekon(meaningEncrypt0, meaningEncrypt1, tableKey);
            break;
        }
        else
        {
            cout << "unknown command, please try again" << endl;
            goto MetkaIntputKeyEncrypted;
        }
    }
    cout << endl;

    // шифруем текст

    string encryptedMessage = "";
    encryptMessageBekon(encryptedMessage, message, meaningEncrypt0, meaningEncrypt1);
    writeToFile(encryptedMessage, "encryptedMessage.txt");

    // расшифровка
    cin.clear();
    cin.sync();

    map<char, int> tableKeyDecrypt;

    vector<char> meaningDecrypt0;
    vector<char> meaningDecrypt1;

MetkaIntputKeyDecrypted:
    while (true)
    {
        cout << "recording key for decryption via the 'myFile' or keyDecrupt(is true)" << endl;
        cout << ": ";
        getline(cin, inputSelection);

        if (inputSelection == "myFile")
        {
            readTableKey(tableKeyDecrypt, "myKey.txt");
            distributionByValueBekon(meaningDecrypt0, meaningDecrypt1, tableKeyDecrypt);
            writeTableKeyToFile(tableKeyDecrypt, "keyDecrypt.txt");
            break;
        }
        else if (inputSelection == "keyDecrupt")
        {
            readTableKey(tableKeyDecrypt, "keyDecrypt.txt");
            distributionByValueBekon(meaningDecrypt0, meaningDecrypt1, tableKeyDecrypt);
            break;
        }
        else
        {
            cout << "unknown command, please try again" << endl;
            goto MetkaIntputKeyDecrypted;
        }
    }
    cout << endl;

    string decryptedMessage = "";
    decryptMessageBekon(decryptedMessage, encryptedMessage, meaningDecrypt0, meaningDecrypt1);
    writeToFile(decryptedMessage, "decryptedMessage.txt");
}
