#include <iostream>

int main() {
    int licznik;

    std::cout << "Podaj licznik: ";
    std::cin >> licznik;

    while(licznik>=0) {
        std::cout << licznik << std::endl;
        --licznik;
    }
    std::cout << "Koniec odliczania!";
}