#include <iostream>
#include <cstdlib>

class Samochod {
    private:
        std::string marka;
        std::string numerRejestracyjny;
    public:
        Samochod(std::string marka, std::string numerRejestracyjny)
        :marka (marka), numerRejestracyjny (numerRejestracyjny) {
            std::cout << std::endl << "To ja konstruktor samochodu: " << numerRejestracyjny;
        }

        void Wyswietl() {
            std::cout << std::endl << "Marka: " << marka;
            std::cout << std::endl << "Numer rejestracyjny: " << numerRejestracyjny;
        }
};
int main(int argc, char* argv[]) {
//jawne wywołanie konstruktora, tworzymy obiekt bez nazwy tylko po żeby go wyświetlić
    Samochod("BMW 1", "1").Wyswietl();

}