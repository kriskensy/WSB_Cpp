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
        double dochodyRoczne()
        {
            return 0;
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
        double placa; //miesieczna placa brutto
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
class Rozliczenia
{
    public:
        void drukujPIT(Pracownik& p)
        {
            std::cout << std::endl;
            std::cout << std::endl << "PIT";
            std::cout << std::endl << "Podatnik: ";
            p.wyswietl();
            std::cout << std::endl << "Zarobil: " << p.dochodyRoczne();
            std::cout << std::endl;
        }
        void drukujPIT(PracownikEtatowy& p)
        {
            std::cout << std::endl;
            std::cout << std::endl << "PIT";
            std::cout << std::endl << "Podatnik: ";
            p.wyswietl();
            std::cout << std::endl << "Zarobil: " << p.dochodyRoczne();
            std::cout << std::endl;
        }
        void drukujPIT(PracownikGodzinowy& p)
        {
            std::cout << std::endl;
            std::cout << std::endl << "PIT";
            std::cout << std::endl << "Podatnik: ";
            p.wyswietl();
            std::cout << std::endl << "Zarobil: " << p.dochodyRoczne();
            std::cout << std::endl;
        }
};

int main(int argc, char* argv[])
{
    Rozliczenia rozliczenia;
    Pracownik p("Adam", "Pracownik", "Kierownik");
    rozliczenia.drukujPIT(p);
    
    PracownikEtatowy pe("Adam", "Etatowy", "Kierownik", 100);
    rozliczenia.drukujPIT(pe);
    PracownikGodzinowy pg("Adam", "Godzinowy", "Kierownik", 10, 20);
    rozliczenia.drukujPIT(pg);
}