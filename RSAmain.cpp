#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


vector<int> vector_Prime_Nums;

void Eratosthenes(vector<int>& vector_Prime_Nums) {  //решето Эратосфена 2- 1000 диапазон
    for (int i = 2; i < 1000; i++) {  
        vector_Prime_Nums.push_back(i);
    }

    for (int i = 0; i <= sqrt(vector_Prime_Nums.size()); i++) {
        int j = i + 1;
        while (j < vector_Prime_Nums.size()) {
            if (vector_Prime_Nums[j] % vector_Prime_Nums[i] == 0) {
                for (int k = j; k < vector_Prime_Nums.size() - 1; k++) { //не простое 
                    vector_Prime_Nums[k] = vector_Prime_Nums[k + 1]; 
                }
                vector_Prime_Nums.pop_back(); //удаляем его 
            }
            else {
                j++;                  //если простое, идем дальше
            }
        }
    }
}

int GetRandomNumber(int min, int max)// генерация рандомных чисел в заданном диапазоне
{
    random_device rd;//random_device, который является источником недетерминированных случайных чисел.
    //Затем мы используем это устройство для заполнения генератора std::minstd_rand. Затем функция генератора() используется для генерации случайного числа
    minstd_rand generator(rd());

    uniform_int_distribution<int> distribution(min, max);// функция destribition для задания диапозона значений
    int random_number = distribution(generator);
    return random_number;
}

int GenerationSimpleRandomNumber()
{
    Eratosthenes(vector_Prime_Nums);
    int simpleNumber = vector_Prime_Nums[GetRandomNumber(0, vector_Prime_Nums.size())];//ввод случайного числа из массива простых чисел
    return simpleNumber;
}


int GenerationOpenKeyRSA()
{
    int p =0, q = 0,n =0;
    p = GenerationSimpleRandomNumber();
    q = GenerationSimpleRandomNumber();
    n = p*q;
    
    
}



int main()
{
    



    return 0;
}