#include "functionAfin.h"

bool NOD(int a, int b) // находит наибольший общий делитель
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    if (a == 1)
    {
        return true;
    }

    else
    {
        return false;
    }
}

string InputText()
{
    string firstText = "";
    getline(cin, firstText);
    return firstText;
}

char Encrypt_simbol(char simbol, int a, int b, int module)
{
    char encryptSimbol;

    encryptSimbol = static_cast<char>((a * static_cast<int>(simbol) + b) % module);

    return encryptSimbol;
}

// Функция для нахождения обратного элемента
int extendedEuclideanAlgorithm(int number, int module, int &x, int &y)
{
    if (module == 0)
    {
        x = 1;
        y = 0;
        return number;
    }
    int x1 = 0, y1 = 0;
    int NOD = extendedEuclideanAlgorithm(module, number % module, x1, y1); // в реккуретной форме переставляем число и модуль местами
    x = y1;
    y = x1 - (number / module) * y1;
    return NOD;
}

int findInverseElement(int number, int module)
{
    int x = 0, y = 0;
    int NOD = extendedEuclideanAlgorithm(number, module, x, y);
    if (NOD != 1)
    {
        cout << "Обратного элемента не существует";
        return 0;
    }
    else
    {
        return (x % module + module) % module; // обработка отрицательных значений
    }
}

char Decryption_simbol(char simbol, int a, int b, int module)
{
    char openSimbol;

    int inversA = findInverseElement(a, module);

    openSimbol = static_cast<char>((inversA * (static_cast<int>(simbol) - b)) % module);

    return openSimbol;
}

void RandomParameters(int &a, int &b, int &module) // рандомные параметры для а и b
{
    module = 256; // ну тут нечего не поделать

    vector<int> coprimeNumbersWithM;

    for (int i = 2; i < module; i++)
    {
        if (NOD(i, module))
        {
            coprimeNumbersWithM.push_back(i);
        }
    }

    srand(time(0));

    a = coprimeNumbersWithM[rand() % coprimeNumbersWithM.size()];
    b = 2 + rand() % 255;
}

void decryptTheMessage(int a, int b, int module)
{

    ifstream fileEncrypted("encryptedMessage.txt");                  // Открываем файл для чтения
    ofstream fileDecrypted("decryptedMessage.txt", std::ios::trunc); // Открываем файл для записи

    // Проверяем, удалось ли открыть файл
    if (fileEncrypted.is_open())
    {

        // Считываем сообщения построчно из файла
        char c;
        while (fileEncrypted.get(c))
        {

            if (fileDecrypted.is_open())
            {                                                        // Проверяем, удалось ли открыть файл
                fileDecrypted << Decryption_simbol(c, a, b, module); // Записываем элементы массива в файл
            }
            else
            {
                std::cerr << "Не удалось открыть файл для записи." << std::endl; // Выводим сообщение об ошибке, если файл не удалось открыть
            }
        }
        fileEncrypted.close(); // Закрываем файл после чтения
        fileDecrypted.close(); // Закрываем файл после записи
    }
    else
    {
        std::cerr << "Unable to open file" << std::endl; // Выводим сообщение об ошибке, если файл не удалось открыть
    }
}

void encryptTheMessage(int a, int b, int module)
{
    std::ifstream fileMessage("messages.txt");                            // Открываем файл для чтения
    std::ofstream fileEncrypted("encryptedMessage.txt", std::ios::trunc); // Открываем файл для записи
    if (fileMessage.is_open())
    { // Проверяем, удалось ли открыть файл
        string message;

        // Считываем сообщения построчно из файла
        while (getline(fileMessage, message))
        {
            // Проверяем, удалось ли открыть файл
            if (fileEncrypted.is_open())
            {
                char c;
                while (fileMessage.get(c))
                {
                    fileEncrypted << Encrypt_simbol(c, a, b, module);
                }

                //  std::cout << "Массив успешно записан в файл." << std::endl;
            }
            else
            {
                std::cerr << "Не удалось открыть файл для записи." << std::endl; // Выводим сообщение об ошибке, если файл не удалось открыть
            }
        }

        fileMessage.clear(); // Сброс состояния потока

        fileMessage.close();   // Закрываем файл после чтения
        fileEncrypted.close(); // Закрываем файл после записи
    }
    else
    {
        std::cerr << "Unable to open file" << std::endl; // Выводим сообщение об ошибке, если файл не удалось открыть
        fileMessage.close();                             // Закрываем файл после чтения
        fileEncrypted.close();
    }
}
