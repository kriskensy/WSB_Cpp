#include <iostream>
#include <ctime>

int main()
{
    srand(time(0));
    const int n = 10;
    int array[n];

    for(int i = 0; i < n; i++)
    {
        array[i] = rand() % 100;
        std::cout << array[i] << " ";
    }

    int temp, j;

    for (int i = 1; i < n; i++)
    {
        
        temp = array[i];
        j = i-1;

        //przesuwanie elementów większych od temp
        while(j >= 0 && array[j] > temp)
        {
            array[j+1] = array[j]; //przesuwanie elementów
            --j;
        }
        array[j+1] = temp; //wstawienie temp w odpowiednie miejsce
    }
    
    std::cout << std::endl;
    std::cout << "Posortowane" << std::endl;

    for(int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
}