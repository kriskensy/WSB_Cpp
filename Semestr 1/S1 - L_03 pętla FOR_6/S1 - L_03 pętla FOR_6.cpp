#include <iostream>

int main () {
    int y;
    std::cout << "Podaj y: ";
    std::cin >> y;

    for(int i=y; i!=-100; i--) { //odliczanie wsteczne aż do i równego -100
        std::cout << i << " ";
    }
}