#include <iostream>
#include <cstdlib>

class Osoba
{
    public:
        Osoba(std::string imie, std::string nazwisko)
        : imie(imie), nazwisko(nazwisko)
        {
        }
        void wyswietl() const
        {
            std::cout << std::endl << imie << " " << nazwisko;
        }
    private:
        std::string imie;
        std::string nazwisko;
};
class Pracownik : public Osoba
{
    public:
        Pracownik(std::string imie, std::string nazwisko, std::string stanowisko)
        : Osoba(imie, nazwisko), stanowisko(stanowisko)
        {
        }
        void wyswietl() const
        {
            Osoba::wyswietl();
            std::cout << std::endl << stanowisko;
        }
    private:
        std::string stanowisko;
};
int main(int argc, char* argv[])
{
    Osoba o1 ("Adam", "Osoba");
//    o1.wyswielt();
    Pracownik p1("Adam", "Pracownik", "Kierownik");
//    p1.wyswietl();
    Osoba *ow;//to jest wskaznik na obiekt typu osoba
    Pracownik * pw; // to jest wskaznik na obiekt typu pracownik
    ow = &o1; //wskazuje na osobe o1
    ow -> wyswietl();
    ow = &p1; //wskaznik na osobe moze wskazywac na pracownika bo pracownik dziedziczy po osobie
    ow -> wyswietl(); //tu wywoła się metoda z Osoby a nie z Pracownika!!
//    pw = &o1; //tu jest błąd bo wskaznik na pracownika nie moze wskazywac na osobe
}
