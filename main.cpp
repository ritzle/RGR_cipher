#include "functionBekon.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

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
    return 0;
}
