#include <iostream>

int main() {
    int a=1;

    do {
        std::cout << "Podaj liczbę (różną od zera): ";
        std::cin >> a;
    } while (a==0); //pętla będzie się wykonywać tak długo, jak długo wprowadzane będzie 0.
}