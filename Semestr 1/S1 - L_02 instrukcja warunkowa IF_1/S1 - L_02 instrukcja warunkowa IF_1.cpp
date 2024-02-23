#include <iostream>
#include <cstring>

int main () {
    int wiek;
    std::cout << "Podaj swój wiek: ";
    std::cin >> wiek;

    if(wiek >= 18) {
        std::cout << "Masz co najmniej 18 lat!" << std::endl;
    } else { //jeśli warunek jest fałszywy wykona się tylko ta instrukcja
        std::cout << "Nie jesteś pełnoletni!" << std::endl;
    }
}