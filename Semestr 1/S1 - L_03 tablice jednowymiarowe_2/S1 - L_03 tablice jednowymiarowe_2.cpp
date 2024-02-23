#include <iostream>

int main()
{
    int array[3];

    std::cout << "Podaj liczbę 1: ";
    std::cin >> array[0];
    std::cout << "Podaj liczbę 2: ";
    std::cin >> array[1];
    std::cout << "Podaj liczbę 3: ";
    std::cin >> array[2];

    std::cout << "Liczba [0] wynosi: " << array[0] << std::endl;
    std::cout << "Liczba [1] wynosi: " << array[1] << std::endl;
    std::cout << "Liczba [2] wynosi: " << array[2] << std::endl;

    int sumOfElements = array[0] + array[1] + array[2];
    std::cout << "Suma tych trzech liczb wynosi: " << sumOfElements << std::endl;
}