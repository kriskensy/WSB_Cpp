#include <iostream>
#include <cstdlib>

class Data
{
    public:
        Data(int dzien, int miesiac, int rok)
        : dzien(dzien), miesiac(miesiac), rok(rok)
        {
        }
        void wyswietl()
        {
            std::cout << std::endl << dzien << "." << miesiac << "." << rok;
        }
    private:
        int dzien;
        int miesiac;
        int rok;
};

class Osoba
{
    public:
        Osoba(std::string imie, std::string nazwisko)
        : imie(imie), nazwisko(nazwisko)
        {
        }
        void wyswietl()
        {
            std::cout << std::endl << imie << " " << nazwisko;
        }
    private:
        std::string imie;
        std::string nazwisko;
};

//to jest klasa abstrakcyjna ponieważ zawiera co najmniej jedną (jedną) funkcję abstrakcyjną
//nie woelno tworzyć obiektów klasy abstrakcyjnej
class Umowa
{
    public:
        Umowa(std::string numer, Osoba pracownik, Data dataWystawienia, Data dataOd, Data dataDo, double wartoscUmowy)
        : numer(numer), pracownik(pracownik), dataWystawienia(dataWystawienia), dataOd(dataOd), dataDo(dataDo), wartoscUmowy(wartoscUmowy)
        {
        }
//to jest funkcja czysto wirtualna, inaczej abstrakcyjna  czyli taka, która nie ma bloku
//jest ona abstrakcyjna bo w umowie nie wiemy jak ją napisać (w naszej firmie nie ma umów ogólnych)
//jak tą funkcję napisać wiemy dopiero w klasach dziedziczących
//zatem funkcja abstrakcyjna stanowi obietnicę tego, że zostanie napisana w klasach dziedziczących
        virtual double obliczPodatek() = 0;
        void wyswietl()
        {
            std::cout << std::endl;
            std::cout << std::endl << "=========== Umowa ===========";
            std::cout << std::endl << "Numer: " << numer;
            std::cout << std::endl << "Strony umowy: ";
            std::cout << std::endl << "Pracodawca: " << "WSB-NLU";
            std::cout << std::endl << "Pracownik: ";
            pracownik.wyswietl(); //to jest wywołanie metody wyswietl() z Osoba
            std::cout << std::endl << "Data wystawienia: ";
            dataWystawienia.wyswietl(); //to jest wywołanie metody wyswietl() z Data
            std::cout << std::endl << "Data obowiazywania od: ";
            dataOd.wyswietl(); //to jest wywołanie metody wyswietl() z Data
            std::cout << std::endl << "Data obowiazywania do: ";
            dataDo.wyswietl(); //to jest wywołanie metody wyswietl() z Data
            std::cout << std::endl << "Wartosc: " << wartoscUmowy;
            std::cout << std::endl << "Podatek: " << obliczPodatek();
        }
    protected:
        double wartoscUmowy; //bo używane w klasie UmowaZlecenie
    private:
        std::string numer;
        Osoba pracownik;
        Data dataWystawienia;
        Data dataOd;
        Data dataDo;
};

class UmowaZlecenie : public Umowa
{
    public:
        UmowaZlecenie(std::string numer, Osoba pracownik, Data dataWystawienia, Data dataOd, Data dataDo, double wartoscUmowy)
        : Umowa(numer, pracownik, dataWystawienia, dataOd, dataDo, wartoscUmowy)
        {
        }
        double obliczPodatek()
        {
            return wartoscUmowy * 12 / 100;
        }
};

class UmowaAutorska : public Umowa
{
    public:
        UmowaAutorska(std::string numer, Osoba pracownik, Data dataWystawienia, Data dataOd, Data dataDo, double wartoscUmowy)
        : Umowa(numer, pracownik, dataWystawienia, dataOd, dataDo, wartoscUmowy)
        {
        }
        double obliczPodatek()
        {
            return (wartoscUmowy * 50 / 100) *12 / 100; //to jest tylko przykładowy algorytm
        }
};

int main(int argc, char* argv[])
{
//nie można tworzyć obiektów klasy abstrakcyjnej, zatem poniższe dwie linie są nieprawidłowe
//    Umowa u1("Umowa1", Osoba("Jan", "Zwykly"), Data(1, 1, 1111), Data(1, 1, 1111), Data(1, 1, 1111), 1);
//    u1.wyswietl();
    UmowaZlecenie uz2("UmowaZlecenie2", Osoba("Jan", "Zlecenie"), Data(2, 2, 2222), Data(2, 2, 2222), Data(2, 2, 2222), 2);
    uz2.wyswietl();
    UmowaAutorska ua3("UmowaAutorska3", Osoba("Jan", "Autorski"), Data(3, 3, 3333), Data(3, 3, 3333), Data(3, 3, 3333), 3);
    ua3.wyswietl();
}