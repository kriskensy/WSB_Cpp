#include <iostream>
#include <cstring>

int main() {
    int zmienna;

    std::cout << "Podaj liczbę: ";
    std::cin >> zmienna;
//uwaga na kolejność działań
    std::cout << "Obliczam: 3 + zmienna * 4 = " << 3 + zmienna * 4 << std::endl;
    std::cout << "Obliczam: (3 + zmienna) * 4 = " << (3 + zmienna) * 4 << std::endl;
}