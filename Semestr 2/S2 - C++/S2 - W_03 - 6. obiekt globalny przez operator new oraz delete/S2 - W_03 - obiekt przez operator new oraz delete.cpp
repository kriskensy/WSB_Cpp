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

        ~Samochod() {
            std::cout << std::endl << "To ja destruktor samochodu: " << numerRejestracyjny;
        }
};
int main(int argc, char* argv[]) {

//to jest utworzenie obiektu za pomocą operatora "new"
    Samochod* s1=new Samochod("BMW 1", "1");
    s1->Wyswietl();
//likwiduję obiekt za pomocą operatora delete, przed likwidacją wywołuje się destruktor
    delete s1;
    std::cout << std::endl << "obiekt zlikwidowany ";
}