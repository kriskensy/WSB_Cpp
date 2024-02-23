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
};

//to jest klasa, która będzie zawierała tablicę obiektów klasy Samochod
class Samochody {
    private:
        Samochod* tab;  //wskaźnik do pierwszego elementu tablicy
        int liczbaSamochodow;
    public:
        Samochody(int max) {
            tab = new Samochod[max];    //tworzzymy pustą tablicę samochodow o max rozmiarze
            liczbaSamochodow=0;
        }
        void Dodaj(Samochod nowy) {
            tab[liczbaSamochodow]=nowy;
            liczbaSamochodow++;
        }
        void WyswietlWszystkie() const {
            for (int i=0; i<liczbaSamochodow; i++)
                tab[i].Wyswietl();  //tab[i] to jest samochod "i", dla niego wywołujemy metodę Wyswietl z klasy Samochod
        }
};

int main(int argc, char* argv[]) {

    Samochody bazaSamochodow(20);

    Samochod s1("BMW 1", "1");
    bazaSamochodow.Dodaj(s1);

    Samochod s2("BMW 2", "2");
    bazaSamochodow.Dodaj(s2);

    Samochod s3("BMW 3", "3");
    bazaSamochodow.Dodaj(s3);

    Samochod s4("BMW 4", "4");
    bazaSamochodow.Dodaj(s4);

    bazaSamochodow.WyswietlWszystkie();
}