#include <iostream>
#include <cstdlib>

class Osoba
{
    public:
        Osoba(std::string imie, std::string nazwisko)
        : imie(imie), nazwisko(nazwisko)
        {
        }
        virtual void wyswietl() const//tutaj slowko 'virtual'
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
//ta funkcja jest wirtualna poniewaz w klasie rozliczenia jest funkcja drukujPIT, która ma wywoływać dochodyRoczne dla pracownikEtatowy z pracownikEtatowy, dla pracownikGodziny z pracownikGodzinowy. Gdyby ta funkcja nie byłą wirtualna to funkcja drukujPIT, funkcje dochodyRoczne wywoływałaby zawsze z pracownika, niezależnie od tego jakiego typu byłby rezcywiście pracownik
        virtual double dochodyRoczne()
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
};

int main(int argc, char* argv[])
{
    Rozliczenia rozliczenia;
    Pracownik pr("Adam", "Pracownik", "Kierownik");
    rozliczenia.drukujPIT(pr);
    
    PracownikEtatowy pe("Adam", "Etatowy", "Kierownik", 100);
    rozliczenia.drukujPIT(pe);
    PracownikGodzinowy pg("Adam", "Godzinowy", "Kierownik", 10, 20);
    rozliczenia.drukujPIT(pg);
}