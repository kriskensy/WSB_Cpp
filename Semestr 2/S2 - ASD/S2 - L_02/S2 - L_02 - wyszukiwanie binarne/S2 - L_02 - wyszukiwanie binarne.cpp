#include <iostream>
#include <ctime>

//wyszukiwanie binarne
    int number;
    int binarySearch(int array[], int left, int right, int number)
    {
    int middle;
    if(left <= right)
    {
        middle = (left + right)/2;

        if(array[middle] == number)
        {
            return middle;
        }

        if(array[middle] > number)
        {
            return binarySearch(array, left, middle - 1, number);
        }
        else
        {
            return binarySearch(array, middle + 1, right, number);
        }
    }
    return -1; //do wyświetlania komunikatu jeśli szukanej nie ma w tablicy
    }

int main(int argc, char *argv[])
{
//wypełnienie tablicy losowymi liczbami
    srand(time(0));
    int const n = 20;
    int array[n];

    for(int i = 0; i < n; i++)
    {
        array[i] = rand() % 100;
        std::cout << array[i] << " ";
    }
//sortowanie przez wybieranie
    for(int j = 0; j < n-1; j++)
    {
        int min = j;
        for(int i = j + 1; i < n; i++)
        
            if(array[i] < array[min]) min = i;
                std::swap(array[min], array[j]);
    }
    
    std::cout << std::endl;
    std::cout << "Po sortowaniu: " << std::endl;

    for(int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
//wyszukiwanie binarne
    std::cout << "zaczynam wyszukiwanie binarne!" <<std::endl;

    int number;

    std::cout << "Podaj szukana liczbe: ";
    std::cin >> number;

    int index = binarySearch(array, 0, n-1, number);
    if(index == -1)
    {
        std::cout << "Szukanej liczby " << number << " nie ma w tablicy." << std::endl;
    }
    else
    {
    std::cout << "Szukana liczba " << number << " znajduje sie w tablicy pod indeksem: " << index;
    }
}