#include <iostream>
#include <cstring>

int main() {
    int wiek;
    std::string imie;
    std::string nazwisko;
    char plec;
    std::cout << "Podaj swoje dane\n";
    std::cout << "Imię: ";
    std::cin >> imie;
    std::cout << "Nazwisko: ";
    std::cin >> nazwisko;
    std::cout << "Wiek: ";
    std::cin >> wiek;
    std::cout << "Płeć K/M: "; //tylko na potrzeby przykładu
    std::cin >> plec;

    std::cout << "Cześć, " << imie << " " << nazwisko << "! " << "Masz " << wiek << " lat" << ", a Twoja płeć to: " << plec << std::endl;
}