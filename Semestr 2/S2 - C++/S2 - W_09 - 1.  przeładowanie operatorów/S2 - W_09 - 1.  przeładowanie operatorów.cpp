#include <iostream>
#include <cstdlib>

class Postac
{
    public:
        Postac()
        {
        }
        Postac(std::string nazwa, int HP)
        : nazwa(nazwa), HP(HP)
        {
        }
//zaprzyjaźniamy operator (traktując go jako funkcję) tak by mógł korzystać ze składowyuch klasy Postac
        friend std::ostream& operator << (std::ostream& out, const Postac& jakasPostac);
        friend std::istream& operator >> (std::istream& in, Postac& jakasPostac);
//przeładujemy teraz operatror++ tak żeby zwiększał HP o 1
//wynikiem przeładowania operatora++ jest Postac o większej ilosci HP
//ten operator jest w klasie Postac a zatem nie musi dostawać Postaci której życie ma zwiększyć
        Postac& operator++()
        {
            HP++;
            return *this; // zwracamy tę postać w której jesteśmy
        }
        Postac& operator+=(const Postac& jakasPostac)
        {
            HP += jakasPostac.HP;
            return *this;
        }
    private:
        std::string nazwa;
        int HP;
};

//nauczymy teraz kompilator prezentowac Maga na konsoli, czyli przeładujemy operator strumieniowy <<
std::ostream& operator << (std::ostream& out, const Postac& jakasPostac)
{
    return out << jakasPostac.nazwa << " " << jakasPostac.HP;
}

std::istream& operator >> (std::istream& in, Postac& jakasPostac)
{
    in >> jakasPostac.nazwa;
    in >> jakasPostac.HP;
    return in;
}

int main(int argc, char* argv[])
{
    int a = 4;
    double b = 5;
    std::cout << std::endl << a;
    std::cout << std::endl << b;
    std::cout << std::endl;
    Postac p1("Mag Dobry", 5);
    std::cout << std::endl << p1;
    Postac p2("Mag Bardzo Dobry", 6);
    std::cout << std::endl << p2;
    ++p2;
    std::cout << std::endl << "Mag ++p2: " << p2;
    p1+=p2;
    std::cout << std::endl << p1;
    Postac p3; //tworzymy pusta postac
    std::cout << std::endl << "Podaj dane postaci: ";
    std::cin >> p3;
    std::cout << std::endl << p3;
}