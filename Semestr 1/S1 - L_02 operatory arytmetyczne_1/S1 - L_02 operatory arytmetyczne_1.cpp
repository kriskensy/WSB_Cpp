#include <iostream>
#include <cstring>

int main() {
    int x = 0;
    int y = 0;

    std::cout << "Podaj liczbę x: ";
    std::cin >> x;
    std::cout << "Podaj liczbę y (różną od 0): ";
    std::cin >> y;
    std::cout << "Wynik dodawania: " << x + y << std::endl;
    std::cout << "Wynik odejmowania: " << x - y << std:: endl;
    std::cout << "Wynik  dzielenia: " << x / y << std::endl;
    std::cout << "Wynik dzielenia modulo: " << x % y << std::endl;
    std::cout << "Wynik mnożenia: " << x * y << std::endl;
}