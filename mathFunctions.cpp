#include "mathFunctions.h"

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