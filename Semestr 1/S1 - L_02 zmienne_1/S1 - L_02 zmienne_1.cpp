#include <iostream>

int main() {
    
    int zmiennaPierwsza;
    int zmiennaDruga = -2;
    unsigned int zmiennaTylkoDodatnia;
    float ulamek;
    ulamek = 12.45;
    char a,b;
    a = 'a';
    b = 'b';
    std::string napis = "To jest napis!";

    std::cout << "Zmienne o nazwie: " << std::endl;
    std::cout << "zmiennaPierwsza = " << zmiennaPierwsza << std::endl;
    std::cout << "zmiennaDruga = " << zmiennaDruga << std::endl;
    std::cout << "zmiennaTylkoDodatnia = " << zmiennaTylkoDodatnia << std::endl;
    std::cout << "ulamek = " << ulamek << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "napis = " << napis << std::endl;
    std::cout << "Można też wypisać tak. Zmienna ulamek = " << ulamek << ", a zmienna zmiennaDruga = " << zmiennaDruga << "." << std::endl;
}