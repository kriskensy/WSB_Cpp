#include <iostream>

int main() {
    std::string napis1;
    napis1 = "pierwszy napis"; //inicjalizacja
    std::string napis2 ("drugi napis"); //inicjalizacja w miejscu tworzenia
    std::string napis3 = "trzeci napis"; //definicja + inicjalizacja

    std::cout << napis1 << std::endl
        << napis2 << std::endl
        << napis3 << std::endl;

    std::string napis4 (6, 'X');    //6 to tutaj zmienna określająca ilość znaków  z pojedynczego cudzysłowu'X'
    std::cout << napis4;
}