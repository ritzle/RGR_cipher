#include "function.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a, b, module;

    RandomParameters(a, b, module);

    cout << a << " " << b << " " << module;

    encryptTheMessage(a, b, module);
    decryptTheMessage(a, b, module);

    return 0;
}