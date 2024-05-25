#include "functionBekon.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Bacon cipher" << endl
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

    map<char, int> tableKey = generateRandomTableKeyBekon();

    vector<char> meaning0;
    vector<char> meaning1;

    distributionByValueBekon(meaning0, meaning1, tableKey);

    string encryptedMessage = "";
    encryptMessageBekon(encryptedMessage, message, meaning0, meaning1);
    writeToFile(encryptedMessage, "encryptedMessage.txt");

    string decryptedMessage = "";
    decryptMessageBekon(decryptedMessage, encryptedMessage, meaning0, meaning1);
    writeToFile(decryptedMessage, "decryptedMessage.txt");
    return 0;
}
