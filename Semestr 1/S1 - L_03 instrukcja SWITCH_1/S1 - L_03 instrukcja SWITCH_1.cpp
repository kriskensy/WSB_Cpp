#include <iostream>

int main() {
    std::cout << "Podaj swoją ocenę z informatyki: ";
    int ocena;
    std::cin >> ocena;

    switch(ocena) {
        case 1: std::cout << "Masz niedostateczny!"; break;
        case 2: std::cout << "Dwója słabeuszu!"; break;
        case 3: std::cout << "Trója - ledwo zaliczyłeś!"; break;
        default: std::cout << "Lepiej niż 3 - mocarz!"; break;
    }
}