#include <iostream>

int main() {
    for(int x=0; x<10; x++) {
        if (x==7) {
            std::cout << "Jestem w pętli!" << std::endl;
            std::cout << "Teraz 'x'= " << x << std::endl;
            std::cout << "Przerywam pętlę!" << std::endl;
            break; //instrukcja przerywająca pętlę
        }
        std::cout << "Po przerwaniu pętli 'x'= " << x << std::endl;
    }
    std::cout << "A teraz jestem poza pętlą!" <<std::endl;
}