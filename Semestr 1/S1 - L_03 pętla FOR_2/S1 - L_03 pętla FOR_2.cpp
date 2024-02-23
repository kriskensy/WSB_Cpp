#include <iostream>

int main() {
    int liczba;
    std::cout << "Podaj liczbę (1-10): ";
    std::cin >> liczba;

    for(int i=1; i<=liczba; i++) {
        std::cout << "i: " << i << std::endl;
    }
}