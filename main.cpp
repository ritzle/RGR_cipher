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
        readingFile(message, "messages.txt");
    }
    else
    {
        cout << "unknown command" << endl;
        return 1;
    }
    cout << endl;

    cin.clear();
    cin.sync();

    int a, b, module;
    RandomParametersAfin(a, b, module);

    string encryptedMessage = "";
    encryptMessageAfin(encryptedMessage, message, a, b, module);
    writeToFile(encryptedMessage, "encryptedMessage.txt");

    string decryptedMessage = "";
    decryptMessageAfin(decryptedMessage, encryptedMessage, a, b, module);
    writeToFile(decryptedMessage, "decryptedMessage.txt");

    return 0;
}