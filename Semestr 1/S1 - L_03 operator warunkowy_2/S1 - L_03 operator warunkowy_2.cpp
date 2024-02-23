#include <iostream>

int main() {
    int x, y, z;
    x = 0;
    y = 1;
    z = (x > y) ? x:y;
//jeśli wprowadzimy x=4 oraz y=8 to wynik teoretycznie będzie wynosił y(false) ale o wartości 1. Dlaczego?

    std::cout << "Podaj wartość x: ";
    std::cin >> x;
    std::cout << std::endl;
    std::cout << "Podaj wartość y: ";
    std::cin >> y;
    std::cout << std::endl;

    std::cout << "Wynik: " << z << std::endl;
}
//dzieje się tak dlatego, że operator wykonuje sie przed realizacją podania nowych wartości x oraz y. To następuje później.