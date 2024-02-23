#include <iostream>

int main() {
    int a, b, c;
    a = 2;
    b = 7;

    std::cout << "a= " << a;
    std::cout << std::endl;
    std::cout << "b= " << b;

    c = (a > b) ? a: b; //operator warunkowy, jeśli warunek jest prawdziwy to wykona się instrukcja 1, jeśli fałszywy to instrukcja 2
    std::cout << std::endl;
    std::cout << "Wynik warunku (większe a czy b): " << c << std::endl;
}