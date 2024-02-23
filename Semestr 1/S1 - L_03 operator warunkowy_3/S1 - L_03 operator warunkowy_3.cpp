#include <iostream>

int main() {
    int x,y,z;
    x=0;
    y=1;

    std::cout << "Podaj wartość x: ";
    std::cin >> x;
    std::cout << "Podaj wartość y: ";
    std::cin >> y;
//wykonanie warunku po wprowadzeniu zmiennych x oraz y
    z=(x>y)?x:y;

    std::cout << "Wartość warunku: " << z << std::endl;
    std::cout << "Wynik: " << z << std::endl;
}