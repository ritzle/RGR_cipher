#include "../headers/functionRSA.h"

vector<int> vector_Prime_Nums;
vector<int> encryptTextVector;
vector<int> encryptedTextFromTheConsoleVector;

void EncryptedTextFileRSA()
{

    int openExponent = 0, n = 0;

    cout << "Введите открытый ключ для шифрования" << endl;
    cin >> openExponent >> n;

    ifstream openText("../txtFile/openText.txt");
    ofstream encryptText("../txtFile/encryptedMessage.txt");

    if (openText.is_open())
    {

        // Считываем сообщения построчно из файла
        char c;

        while (openText.get(c))
        {

            if (encryptText.is_open())
            {
                int openSymbol = static_cast<int>(c);
                int encryptSymbol = modPower(openSymbol, openExponent, n);
                encryptText << encryptSymbol;
                encryptTextVector.push_back(encryptSymbol);
            }
            else
            {
                std::cerr << "Не удалось открыть файл для записи." << std::endl; // Выводим сообщение об ошибке, если файл не удалось открыть
            }
        }
        openText.close();    // Закрываем файл после чтения
        encryptText.close(); // Закрываем файл после записи
    }
    else
    {
        std::cerr << "Unable to open file" << std::endl; // Выводим сообщение об ошибке, если файл не удалось открыть
    }
    cout << "Зашифрованный текст записан в файл (encryptedMessage.txt) " << endl;
}

void EncryptTextFromTheConsoleRSA()
{
    int openExponent = 0, n = 0;

    string openText = "";

    cout << "Введите текст для шифрования" << endl;
    cin.ignore(); // Очистка буфера ввода
    getline(cin, openText);

    cout << "Введите открытый ключ для шифровки" << endl;
    cin >> openExponent >> n;

    for (auto &i : openText)
    {
        int openSymbol = static_cast<int>(i);
        int encryptSymbol = modPower(openSymbol, openExponent, n);
        encryptedTextFromTheConsoleVector.push_back(encryptSymbol);
    }

    cout << "Зашифрованный текст" << endl;

    for (auto i : encryptedTextFromTheConsoleVector)
    {
        cout << i << " ";
    }
}

void decryptedTextFromTheConsoleRSA()
{
    int inverseForOpenExponent = 0, n = 0;

    vector<char> decryptTextFromTheConsoleRSA;

    cout << "Введите закрытый ключ" << endl;
    cin >> inverseForOpenExponent >> n;

    for (auto &i : encryptedTextFromTheConsoleVector)
    {
        int encryptSymbol = i;
        char decryptSymbol = static_cast<char>(modPower(encryptSymbol, inverseForOpenExponent, n));

        decryptTextFromTheConsoleRSA.push_back(decryptSymbol);
    }
    cout << "Расшифрованный текст" << endl;

    for (auto &i : decryptTextFromTheConsoleRSA)
    {
        cout << i;
    }

    cout << endl;
}

void DecryptedTextFileRSA()
{

    int inverseForOpenExponent = 0, n = 0;

    cout << "Введите закрытый ключ" << endl;
    cin >> inverseForOpenExponent >> n;

    ofstream decryptText("../txtFile/decryptedMessage.txt");

    if (decryptText.is_open())
    {

        // Считываем сообщения построчно из файла
        char c = 'f';

        for (auto &i : encryptTextVector)
        {
            int encryptSymbol = i;
            char decryptSymbol = static_cast<char>(modPower(encryptSymbol, inverseForOpenExponent, n));
            decryptText << decryptSymbol;
        }
        decryptText.close();
    }
    else
    {
        std::cerr << "Unable to open file" << std::endl; // Выводим сообщение об ошибке, если файл не удалось открыть
    }
    cout << "Расшифрованный текст записан в файл (decryptedMessage.txt) " << endl;
}
void Eratosthenes(vector<int> &vector_Prime_Nums)
{ // решето Эратосфена 2- 1000 диапазон
    for (int i = 2; i < 200; i++)
    {
        vector_Prime_Nums.push_back(i);
    }

    for (int i = 0; i <= sqrt(vector_Prime_Nums.size()); i++)
    {
        int j = i + 1;
        while (j < vector_Prime_Nums.size())
        {
            if (vector_Prime_Nums[j] % vector_Prime_Nums[i] == 0)
            {
                for (int k = j; k < vector_Prime_Nums.size() - 1; k++)
                { // не простое
                    vector_Prime_Nums[k] = vector_Prime_Nums[k + 1];
                }
                vector_Prime_Nums.pop_back(); // удаляем его
            }
            else
            {
                j++; // если простое, идем дальше
            }
        }
    }
}

int GetRandomNumber(int min, int max) // генерация рандомных чисел в заданном диапазоне
{
    random_device rd; // random_device, который является источником недетерминированных случайных чисел.
    // Затем мы используем это устройство для заполнения генератора std::minstd_rand. Затем функция генератора() используется для генерации случайного числа
    minstd_rand generator(rd());

    uniform_int_distribution<int> distribution(min, max); // функция destribition для задания диапозона значений
    int random_number = distribution(generator);
    return random_number;
}

int GenerationSimpleRandomNumber()
{
    Eratosthenes(vector_Prime_Nums);
    int simpleNumber = vector_Prime_Nums[GetRandomNumber(0, vector_Prime_Nums.size())]; // ввод случайного числа из массива простых чисел
    return simpleNumber;
}

int EilerFunction(int p, int q)
{
    int fi = (p - 1) * (q - 1);
    return fi;
}

int GenerationOpenExponent(int p, int q)
{
    int e = 0;
    do
    {
        e = GetRandomNumber(1, EilerFunction(p, q));

    } while (NOD(e, EilerFunction(p, q)) != true);

    return e;
}

void GenerationOpenANDSecretKeyRSA() // создаются два простых числа p, q. Находится их p*q = n - модуль.
{
    int simpleNumberP = 0, simpleNumberQ = 0, n = 0, openExponent = 0, inverseElementForOpenExponent = 0;
    ;

    simpleNumberP = GenerationSimpleRandomNumber();
    simpleNumberQ = GenerationSimpleRandomNumber();
    n = simpleNumberQ * simpleNumberP; // n - модуль

    // находим открытую экспоненту целое число  1 < e < fi(n)
    openExponent = GenerationOpenExponent(simpleNumberP, simpleNumberQ);

    inverseElementForOpenExponent = findInverseElement(openExponent, EilerFunction(simpleNumberP, simpleNumberQ));
    // inverseElementForOpenExponent = modInverse(openExponent, EilerFunction(simpleNumberP, simpleNumberQ));

    cout << "Open key" << "(" << openExponent << "," << n << ")" << endl;
    cout << "Secret key" << "(" << inverseElementForOpenExponent << "," << n << ")" << endl;
}

int modPower(int base, int exp, int mod)
{ // возведение в степень по модулю
    int result = 1;

    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}