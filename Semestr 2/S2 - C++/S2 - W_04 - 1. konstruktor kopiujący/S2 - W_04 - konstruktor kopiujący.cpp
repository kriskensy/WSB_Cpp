#include <iostream>
#include <cstdlib>

class Employee
{
private:
    std::string name;
    std::string surname;
    std::string position;
public:
    Employee(std::string name, std::string surname, std::string position)
    : name(name), surname(surname), position(position)
    {

    }
//konstruktor kopiujący, tworzy obiekt  identyczny jak ten którego dostaje jako wzór
    Employee(Employee &formula)
    {
        name=formula.name;
        surname=formula.surname;
        position=formula.position;
    }

    void present()
    {
        std::cout << std::endl << "Name: " << name;
        std::cout << std::endl << "Surname: " << surname;
        std::cout << std::endl << "Position: " << position;
    }
};

int main(int argc, char* argy[])
{
    Employee e1("Adam", "Kot", "Kierownik");
    e1.present();
    Employee e2(e1); //tutaj wywołanie konstruktora kopiującego, e2 jest identyczne jak e1
    e2.present();
}