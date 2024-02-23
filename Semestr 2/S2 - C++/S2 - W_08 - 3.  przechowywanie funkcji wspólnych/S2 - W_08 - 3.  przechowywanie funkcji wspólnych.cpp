#include <iostream>
#include <cstdlib>

//utworzymy teraz klasę urządzenie tylko po to, żeby stworzyć w niej funkcję Menu(), która tym samym kodem będzie działała dobrze zarówno dla Radia jak i DVD
//ale funkcja Menu() jest trochę inna obu klasach
//ta klasa jest abstrakcyjna ponieważ zawiera co najmniej jedną (dwie) klasy abstrakcyjne
//nie wolno tworzyć obiektów klasy urządzenie bo to klasa abstrakcyjna

class Urzadzenie
{
    public:
        virtual void zmien(std::string nowaStacja, double nowaCzestotliwosc) = 0;
        virtual void wyswietlajStan() = 0;
//muszę z tej funkcji zrobić funkcję uniwersalną, któa będzie działała dobrze zarówno dla radia jak i dvd
        void Menu()
        {
            std::cout << std::endl;
            std::cout << std::endl << "========== Menu ==========";
            std::cout << std::endl << "1 - " << komunikatZmien;
            std::cout << std::endl << "2 - wyswietl stan";
            std::cout << std::endl << "Wybor: ";
            int wybor;
            std::cin >> wybor;
            if(wybor == 1)
            {
                std::string a;
                double b;
                std::cout << std::endl << komunikatNowaNazwa;
                std::cin >> a;
                std::cout << std::endl << nowaPozycjaCzestotliwosc;
                std::cin >> b;
                zmien(a,b);
            }
            if(wybor == 2)
            {
                wyswietlajStan();
            }
            Menu();
        }
    protected:
        std::string komunikatZmien;
        std::string komunikatNowaNazwa;
        std::string nowaPozycjaCzestotliwosc;
};

class Radio : public Urzadzenie
{
    public:
        Radio()
        {
            nazwaStacji = "Zet";
            czestotliwosc = 123;
            komunikatZmien = "zmien stacje";
            komunikatNowaNazwa = "Podaj nazwe nowej stacji: ";
            nowaPozycjaCzestotliwosc = "Podaj nowa czestotliwosc: ";
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
    private:
        std::string nazwaStacji;
        double czestotliwosc;
};

class DVD : public Urzadzenie
{
    public:
        DVD()
        {
            tytulFilmu = "ABC";
            pozycja = 0;
            komunikatZmien = "zmien stacje";
            komunikatNowaNazwa = "Podaj nowy tytul filmu: ";
            nowaPozycjaCzestotliwosc = "Podaj nowa pozycje filmu: ";
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
    private:
        std::string tytulFilmu;
        double pozycja;
};

int main(int argc, char* argv[])
{
    Radio radio;
    radio.Menu();
//    DVD dvd;
//    dvd.Menu();
}