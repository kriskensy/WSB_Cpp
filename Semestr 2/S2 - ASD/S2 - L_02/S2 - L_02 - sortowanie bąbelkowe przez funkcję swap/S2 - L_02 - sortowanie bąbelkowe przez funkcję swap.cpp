#include <iostream>
#include <ctime>

int main(int argc, char *argv[])
{
    srand(time(0));
    const int n = 10;
    int array[n];

    for(int i = 0; i < n; i++)
    {
        array[i] = rand() % 100;
        std::cout << array[i] << " ";
    }

    std::cout << "zaczynam sortowanie babelkowe" << std::endl;

    for(int j = 0; j < n-1; j++)
    {
        for(int i = 0; i < n-1; i++)
        {
            if(array[i] > array[i+1])
                std::swap(array[i], array[i+1]);
        }
    }

    std::cout << "Po sortowaniu: " <<std::endl;

    for(int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
}