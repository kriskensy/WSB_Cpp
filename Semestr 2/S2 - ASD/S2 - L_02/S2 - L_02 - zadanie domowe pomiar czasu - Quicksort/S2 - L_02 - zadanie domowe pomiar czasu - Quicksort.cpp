#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <time.h>

const int N = 500000; //Liczebność zbioru.
int array[N];

//Procedura sortowania szybkiego
void quicksort(int left, int right)
{
    int i, j, pivot;

    i = (left + right) / 2;
    pivot = array[i];
    array[i] = array[right];

    for(j = i = left; i < right; i++)
        if(array[i] < pivot)
        {
            std::swap(array[i], array[j]);
            j++;
        }

    array[right] = array[j]; 
    array[j] = pivot;

    if(left < j - 1)  quicksort(left, j - 1);
    if(j + 1 < right) quicksort(j + 1, right);
}

int main()
{
    int i;

    srand((unsigned)time(NULL));

//wypełnienie tablicy losowymi liczbami
    for(i = 0; i < N; i++)
    {
        array[i] = rand() % 100;
//        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

//sortowanie + pomiar czasu
    clock_t start = clock();
    
    quicksort(0, N - 1);

    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("for loop took %f seconds to execute \n", cpu_time_used);
}