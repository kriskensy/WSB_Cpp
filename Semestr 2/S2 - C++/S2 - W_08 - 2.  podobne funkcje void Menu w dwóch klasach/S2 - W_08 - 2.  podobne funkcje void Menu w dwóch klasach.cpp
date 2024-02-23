#include <iostream>
#include <cstdlib>

//Program napisany bez funkcji wirtualnych i klas abstrakcyjnych. Powtarzalność kodu funkcji Menu() niedopuszczalna (chociaż te funkcje się trochę różnią).

class Radio
{
    public:
        Radio()
        {
            nazwaStacji = "Zet";
            czestotliwosc = 123;
        }
        void zmien(std::string nowaStacja, double nowaCzestotliwosc)
        {
            nazwaStacji = nowaStacja;
            czestotliwosc = nowaCzestotliwosc;
        }
        void wyswietlajStan()
        {
            std::cout << std::endl << "Radio nadaje stacje: " << nazwaStacji << ", na czestotliwosci: " << czestotliwosc;
        }
        void Menu()
        {
            std::cout << std::endl;
            std::cout << std::endl << "========== Menu ==========";
            std::cout << std::endl << "1 - zmien stacje";
            std::cout << std::endl << "2 - wyswietl stan";
            std::cout << std::endl << "Wybor: ";
            int wybor;
            std::cin >> wybor;
            if(wybor == 1)
            {
                std::string a;
                double b;
                std::cout << std::endl << "Podaj nazwe nowej stacji: ";
                std::cin >> a;
                std::cout << std::endl << "Podaj nowa czestotliwosc: ";
                std::cin >> b;
                zmien(a,b);
            }
            if(wybor == 2)
            {
                wyswietlajStan();
            }
            Menu();
        }
    private:
        std::string nazwaStacji;
        double czestotliwosc;
};

class DVD
{
    public:
        DVD()
        {
            tytulFilmu = "ABC";
            pozycja = 0;
        }
        void zmien(std::string nowyTytulFilmu, double nowaPozycja)
        {
            tytulFilmu = nowyTytulFilmu;
            pozycja = nowaPozycja;
        }
        void wyswietlajStan()
        {
            std::cout << std::endl << "DVD nadaje film: " << tytulFilmu << ", na pozycji: " << pozycja;
        }
        void Menu()
        {
            std::cout << std::endl;
            std::cout << std::endl << "========== Menu ==========";
            std::cout << std::endl << "1 - zmien stacje";
            std::cout << std::endl << "2 - wyswietl stan";
            std::cout << std::endl << "Wybor: ";
            int wybor;
            std::cin >> wybor;
            if(wybor == 1)
            {
                std::string a;
                double b;
                std::cout << std::endl << "Podaj nowy tytul filmu: ";
                std::cin >> a;
                std::cout << std::endl << "Podaj nowa pozycje: ";
                std::cin >> b;
                zmien(a,b);
            }
            if(wybor == 2)
            {
                wyswietlajStan();
            }
            Menu();
        }
    private:
        std::string tytulFilmu;
        double pozycja;
};

int main(int argc, char* argv[])
{
//    Radio radio;
//    radio.Menu();
    DVD dvd;
    dvd.Menu();
}