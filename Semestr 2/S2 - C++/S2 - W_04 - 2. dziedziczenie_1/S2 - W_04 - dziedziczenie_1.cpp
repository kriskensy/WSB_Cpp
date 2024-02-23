#include <iostream>
#include <cstdlib>

class Person
{
private:
    std::string name;
protected: //jeżeli jakieś pole jest chronione to może być używane zarówno w tej klasie w której jest ale również w klasach dziedziczących
    std::string surname;
public:
    Person(std::string name, std::string surname)
    : name(name), surname(surname)
    {

    }

    void present()
    {
        std::cout << std::endl << "Name: " << name;
        std::cout << std::endl << "Surname: " << surname;
    }
};

class Employee : public Person //dzięki temu Employee dziedziczy po osobie
{
private:
    std::string position;
public:
    Employee(std::string name, std::string surname, std::string position)
    : Person(name, surname), position(position) //tutaj wywołuję konstruktor z klasy 'Person' czyli inicjalizuję brakujące argumenty (name, surname) i dokładam pozostałe argumenty
    {

    }

    void present()
    {
        Person::present(); //wywołanie metody 'present' z klasy 'Person' czyli wyświetlenie name, surname
        std::cout << std::endl << "Position: " << position;
    }

    void presentNamePosition()
    {
        std::cout << std::endl << "Surname: " << surname;
        std::cout << std::endl << "Stanowisko: " << position;
    }
};

int main(int argc, char* argy[])
{
    Person p1("Adam", "Rak");
    p1.present();
    Employee e1("Adam", "Kot", "Kierownik");
    e1.present();
}