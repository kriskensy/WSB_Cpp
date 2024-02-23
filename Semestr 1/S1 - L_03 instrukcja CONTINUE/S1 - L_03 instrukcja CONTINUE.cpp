#include <iostream>

int main() {
    for(int x=1; x<7; x++) {
        std::cout << "x= " << x << std::endl;
        if(x==2 || x==3 || x==5) {
            std::cout << "Teraz x wynosi: " << x;
            std::cout << "  -> continue!" << std::endl;
            continue;
        }
        std::cout << "Koniec kroku x= " << x << std::endl;
    }
}