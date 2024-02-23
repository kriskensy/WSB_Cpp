#include <iostream>

int main() {
    int zmiennaPierwsza = 1;
    int zmiennaDruga = 2;
    char a, b;
    a = 'x';
    b = 'y';
    std::string napis = "To jest napis!";

    std::cout << "Zmienna o nazwie zmiennaPierwsza = \n";
    std::cout << zmiennaPierwsza << "\n";
    std::cout << "\tZmienna o nazwie zmiennaDruga = " << zmiennaDruga << "\n";
    std::cout << "\vZmienna o nazwie zmiennaPierwsza = ";
    std::cout << zmiennaPierwsza << "\n";
    std::cout << "Zmienne o nazwie a i b wypisane pojedynczo = ";
    std::cout << a << " " << b << std::endl;
    std::cout << "Zmienne o nazwie a i b wypisane razem = \n";
    std::cout << a << b << std::endl;
    std::cout << "Zmienna o nazwie napis = ";
    std::cout << napis;
}