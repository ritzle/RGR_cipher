#include "functionAfin.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a, b, module;

    RandomParametersAfin(a, b, module);

    cout << a << " " << b << " " << module;

    encryptTheMessageAfin(a, b, module);
    decryptTheMessageAfin(a, b, module);

    return 0;
}