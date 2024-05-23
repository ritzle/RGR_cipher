#include "functionVernam.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Vernam cipher" << endl
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
        message = readingFile("messages.txt");
    }
    else
    {
        cout << "unknown command" << endl;
        return 1;
    }
    cout << endl;

    cin.clear();
    cin.sync();

    cout << "writing a key via the console or random" << endl;
    cout << ": ";
    getline(cin, inputSelection);

    string key;

    if (inputSelection == "console")
    {
        cin.clear();
        cin.sync();
        cout << ": ";
        getline(cin, key);
        writeToFile(key, "keyEncrypt.txt");
    }
    else if (inputSelection == "random")
    {
        cin.clear();
        cin.sync();
        key = generateKey(message);
        writeToFile(key, "keyEncrypt.txt");
    }
    else
    {
        cout << "unknown command2" << endl;
        return 1;
    }

    string encryptedMessage = encryptMessage(message, key);
    writeToFile(encryptedMessage, "encryptedMessage.txt");

    string decryptedMessage = decryptMessage(encryptedMessage, key);
    writeToFile(decryptedMessage, "decryptedMessage.txt");

    return 0;
}
