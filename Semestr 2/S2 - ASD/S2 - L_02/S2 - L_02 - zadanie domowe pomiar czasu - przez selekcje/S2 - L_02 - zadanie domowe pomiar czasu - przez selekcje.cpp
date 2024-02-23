#include <iostream>
//#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <time.h>

int main()
{
    srand(time(0));
    const int n = 500000;//liczebność zbioru
    int array[n];

    for(int i = 0; i < n; i++)
    {
        array[i] = rand() % 100;
//        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

//sortowanie + pomiar czasu
    clock_t start = clock();
    for(int j = 0; j < n-1; j++)
    {
        int min = j;
        for(int i = j+1; i < n; i++)
        
            if(array[i] < array[min]) min = i;
                std::swap(array[min], array[j]);
    }

    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("for loop took %f seconds to execute \n", cpu_time_used);
    std::cout << std::endl;
}