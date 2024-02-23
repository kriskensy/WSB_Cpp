#include <iostream>

int main() {
    std::string wynik;
    int x,y;

    x=0;
    y=0;

    std::cout << "Podaj wartość x: ";
    std::cin >> x;
    std::cout << "Podaj wartość y: ";
    std::cin >> y;

    (x>y)? wynik="prawda":wynik="fałsz"; //prezentacja wyniku przy pomocy tekstu ze stringa

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "x > y = " << wynik << std::endl;
}