#include <iostream>

int main() {
    int i=0;
    int j;

    while(i<=10) {
        std::cout << "Wartość i: " << i << std::endl;
        j=5;

            while(j==i) {//pętla zagnieżdżona. Jej instrukcje wykonają się TYLKO WTEDY gdy j zrówna się z i
                std::cout << "Jestem w zagnieżdżonej pętli. j = " << j << std::endl;
                j=--j;
            }
        ++i;
        std::cout << "Wartość i: " << i << std::endl;
        getchar();  //czeka na naciśnięcie ENTER
    }
}