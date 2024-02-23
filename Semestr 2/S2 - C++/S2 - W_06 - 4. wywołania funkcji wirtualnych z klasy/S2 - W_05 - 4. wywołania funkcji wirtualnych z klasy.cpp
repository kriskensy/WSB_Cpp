#include <iostream>
#include <cstdlib>

class Osoba
{
    public:
        Osoba(std::string imie, std::string nazwisko)
        : imie(imie), nazwisko(nazwisko)
        {
        }
        virtual void wyswietl() const
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
        virtual double dochodyRoczne()
        {
            return 0;
        }
//jezeli funkcje dochodRoczne oraz wyswietl nie byłyby wirtualne to funkcje drukujPIT, wyswietl i dochodyRoczne wywołają się z Pracownik bo drukujPIT jest w Pracownik
//jezeli funkcje dochodRoczne oraz wyswietl są wirtualne to w drukujPIT, te funkcje wywołają się z tej klasy dla której stworzyliśmy obiekt, dla którego wywołaliśmy drukujPIT
        void drukujPIT()
        {
            std::cout << std::endl;
            std::cout << std::endl << "PIT";
            std::cout << std::endl << "Podatnik: ";
            wyswietl();
            std::cout << std::endl << "Zarobil: " << dochodyRoczne();
            std::cout << std::endl;
        }
    private:
        std::string stanowisko;
};

class PracownikEtatowy : public Pracownik
{
    public:
        PracownikEtatowy(std::string imie, std::string nazwisko, std::string stanowisko, double placa)
        : Pracownik(imie, nazwisko, stanowisko), placa(placa)
        {
        }
        void wyswietl() const
        {
            Pracownik::wyswietl();
            std::cout << std::endl << "Placa: " << placa;
        }
        double dochodyRoczne()
        {
            return placa * 12;
        }
    private:
        double placa;
};

class PracownikGodzinowy : public Pracownik
{
    public:
        PracownikGodzinowy(std::string imie, std::string nazwisko, std::string stanowisko, double liczbaGodzin, double stawkaZaGodzine)
        : Pracownik(imie, nazwisko, stanowisko), liczbaGodzin(liczbaGodzin), stawkaZaGodzine(stawkaZaGodzine)
        {
        }
        void wyswietl() const
        {
            Pracownik::wyswietl();
            std::cout << std::endl << "Liczba godzin: " << liczbaGodzin;
            std::cout << std::endl << "Stawka za godzine: " << stawkaZaGodzine;
        }
        double dochodyRoczne()
        {
            return stawkaZaGodzine * liczbaGodzin;
        }
    private:
        double liczbaGodzin;
        double stawkaZaGodzine;
};

int main(int argc, char* argv[])
{
    Pracownik pr("Adam", "Pracownik", "Kierownik");
    pr.drukujPIT();
    
    PracownikEtatowy pe("Adam", "Etatowy", "Kierownik", 100);
    pe.drukujPIT();
    PracownikGodzinowy pg("Adam", "Godzinowy", "Kierownik", 10, 20);
    pg.drukujPIT();
}