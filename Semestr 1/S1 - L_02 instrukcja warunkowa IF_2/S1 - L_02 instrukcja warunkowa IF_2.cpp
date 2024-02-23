#include <iostream>
#include <cstring>

int main () {
    std::cout << "Podaj liczbę posiadanych dzieci: ";
    int liczba;
    std::cin >> liczba ;

    if (liczba == 1)
    std::cout << "Masz jedno dziecko.";
        else if (liczba > 1) //instrukcja zagnieżdżona
        std::cout << "Masz więcej niż jedno dziecko.";
            else
            std::cout << "Nie masz dzieci.";
}