#include <iostream>

int main()
{
    srand(time(0)); //powoduje losowe przypisanie wartości do zmiennych po funkcji 'rand'
    
    int array[5];
    int number = 0;
    int counter = 0;

    for(int i = 0; i < 5; i++)
    {
        array[i] = rand() % 100;
        std::cout << array[i] << " ";
    }

    std::cin >> number;

    for(int i = 0; i < 5; i++)
    {
        if( array[i] == number)
        {
        std::cout << "Twoja liczba " << array[i] << " jest w tablicy pod indeksem: " << i << std::endl;
        counter++;
        }
    }

    if( counter == 0)
    {
    std::cout << "Twojej liczby nie ma w tablicy. Koniec!";
    }
}