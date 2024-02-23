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
//destruktor
        ~Samochod() {
            std::cout << std::endl << "To ja destruktor samochodu: " << numerRejestracyjny;
        }
};
int main(int argc, char* argv[]) {

    Samochod s1("BMW 1", "1");  //tu wywoła się konstruktor samochodu
    s1.Wyswietl();

}//tu wywoła się destruktor samochodu