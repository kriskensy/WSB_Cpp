#include <iostream>

int main() {
    int x,y;

    std::cout << "Podaj x (START): ";
    std::cin >> x;
    std::cout << "Podaj y (META): ";
    std::cin >> y;

    for(int i=x; i<=y; i++) {
        std::cout << i << " ";
    }
}