#include <iostream>
#include <cstdlib>

class Samochod {
    private:
        std::string marka;
        std::string numerRejestracyjny;
    public:
        Samochod(std::string marka, std::string numerRejestracyjny)
        :marka (marka), numerRejestracyjny (numerRejestracyjny) {

        }
        Samochod() {

        }
        void Wyswietl() {   //ta metoda nie zmienia obiektu, jedynie go wyświetla
            std::cout << std::endl << "Marka: " << marka;
            std::cout << std::endl << "Numer rejestracyjny: " << numerRejestracyjny;
        }
//teraz zaprzyjaźniamy funkcję z klasą, dzięki temu funkcja będzie mogła używać składowych prywatnych tej klasy
//
        friend void zmienNumerRejestracyjny(Samochod& s, std::string nowyNumer);
};
//tu jest koniec klasy

void zmienNumerRejestracyjny(Samochod& s, std::string nowyNumer) {
    s.numerRejestracyjny=nowyNumer; //pola prywatnego można używać tylko w klasie w której jest oraz w funkcjach zaprzyjaźnionych
}

int main(int argc, char* argv[]) {

    Samochod s1("BMW 1", "1");
    zmienNumerRejestracyjny(s1, "2");
    s1.Wyswietl();

}