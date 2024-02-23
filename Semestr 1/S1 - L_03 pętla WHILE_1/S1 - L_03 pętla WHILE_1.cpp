#include <iostream>

int main() {
    int licznik=10;

    while(licznik>0) {
        std::cout << licznik << std::endl;
        --licznik;
    }
    std::cout << "Koniec odliczania!" <<std::endl;
}