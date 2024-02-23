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

//klasa Pracownik jest abstrakcyjna ponieważ zawiera jedną (conajmniej jedną) funkcję abstrakcyjną (funkcję dochodyRoczne)
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
//jezeli nie wiemy jak napisac funkcje dochodyRoczne w Pracownik a dopiero wiemy jak ja napisac PracownikEtatowy i PracownikGodzinowy to:
// - mozzemy ta funkcje wyrzucic z klasy Pracownik ale wtedy nie skompiluje nam sie drukujPIT, ktora tej funkcji uzywa
// - mozemy ja zostawic bez bloku jako funkcje abstrakcyjna (virtual z przodu, porównaną do 0 i bez bloku)
//Taka funkcja stanowi obietnicę, że zostanie ona zrealizowana w klasach dziedziczących
        virtual double dochodyRoczne() = 0;
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
//nie wolno tworzyć obiektów klasy Pracownik bo ta klasa jest abstrakcyjna
//    Pracownik pr("Adam", "Pracownik", "Kierownik");
//    pr.drukujPIT();
    
//klasa PE też jest abstrakcyjna bo funkcja asbtrakcyjna dochodRoczny nie jest zrealizowana
//    PracownikEtatowy pe("Adam", "Etatowy", "Kierownik", 100);
//    pe.drukujPIT();
    PracownikGodzinowy pg("Adam", "Godzinowy", "Kierownik", 10, 20);
    pg.drukujPIT();
}