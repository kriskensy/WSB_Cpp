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
    
    std::cout << std::endl;
    std::cout << "zaczynam sortowanie przez wybieranie" << std::endl;

    for(int j = 0; j < n-1; j++)
    {
        int min = j;
        for(int i = j+1; i < n; i++)
        
            if(array[i] < array[min]) min = i;
                std::swap(array[min], array[j]);
    }

    std::cout << "Po sortowaniu: " << std::endl;

    for(int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
}