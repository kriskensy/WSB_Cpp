#include <iostream>

int main() {
    int i=5;
    ++i;
    goto koniec;
//poniższe podstawienie nowej wartości do zmiennej 'i' oraz tekst zostaną pominięte, instrukcja GOTO przerzuca nas od razu do KONIEC
    i=0;
    std::cout << "Ten tekst zostanie pominięty, ponieważ GOTO przejdzie do KONIEC." << std::endl;

    koniec:
    std::cout << "Tutaj zmienna i ma wartość: " << i << std::endl;
    std::cout << std::endl << "Naciśnij ENTER aby zakończyć!" << std::endl;
    getchar();
}