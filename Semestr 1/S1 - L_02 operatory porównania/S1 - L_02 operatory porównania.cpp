#include <iostream>
#include <cstring>

int main() {
    int x = 5;
    int y = 2;

    std::cout << "x= " << x << std::endl <<"y= " << y << std::endl;
    std::cout << std::endl;

    std::cout << "(x większe niż y) x > y = " << (x > y) << std::endl;
    std::cout << "(x większe lub równe y) x >= y = " << (x >= y) << std::endl;
    std::cout << "(x mniejsze niż y) x < y = " << (x < y) << std::endl;
    std::cout << "(x mniejsze lub równe y) x <= y = " << (x <= y) << std::endl;
    std::cout << "(x różne niż y) x != y = " << (x != y) << std::endl;
    std::cout << "(x równe y) x == y = " << (x == y) << std::endl;

//tutaj wynik zapisany w zmiennych

    bool wynik1 = x < y;
    bool wynik2 = x > y;
    std::cout << "Wynik x < y: " << wynik1 << std::endl;
    std::cout << "Wynik x > y: " << wynik2 << std::endl;
}