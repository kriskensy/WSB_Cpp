#include <iostream>

int main() {
    int i;
    std::cout << "Wybierz jedną z opcji: " << std::endl;
    std::cout << "1. Komputery " << std::endl;
    std::cout << "2. Aparaty fotograficzne " << std::endl;
    std::cout << "3. Konsole " << std::endl;

    std::cin >> i;

    switch(i) {
        case 1: std::cout << "Jesteś w menu Komputery."; break;
        case 2: std::cout << "Jesteś w menu Aparaty fotograficzne."; break;
        case 3: std::cout << "Jesteś w menu Konsole."; break;
        default: std::cout << "Niepoprawny wybór!";

    }
}