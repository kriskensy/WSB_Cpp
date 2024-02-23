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

    Samochod s2("BMW 2", "2");
    s2.Wyswietl();

    {
    static Samochod s1("BMW 1", "1");   //tutaj obiekt lokalny statyczny
    s1.Wyswietl();
    }
    std::cout << std::endl << "tu konczy sie wewnetrzny blok";
}