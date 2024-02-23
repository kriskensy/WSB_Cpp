#include <iostream>
#include <cstdlib>

class Person
{
private:
    std::string name;
protected:
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

class Employee: public Person
{
private:
    std::string position;
public:
    Employee(std::string name, std::string surname, std::string position)
    : Person(name, surname), position(position)
    {

    }

    void present()
    {
        Person::present();
        std::cout << std::endl << "Position: " << position;
    }
};

//to jest dziedziczenie kilkupokoleniowe, FullTimeEmployee dziedziczy po Employee a przez niego po Person
class FullTimeEmployee: public Employee //bo fullTimeEmployee jest też Employee
{
private:
    double salaryBrutto;
public:
    FullTimeEmployee(std::string name, std::string surname, std::string position, double salaryBrutto)
    : Employee(name, surname, position), salaryBrutto(salaryBrutto)
    {

    }

    void present()
    {
        Employee::present(); //to jest wywołanie metody z klasy EMployee, czyli wyświetlenie: name, surname, position
        std::cout << std::endl << "Salary brutto: " << salaryBrutto;
    }
};

int main(int argc, char* argy[])
{
    Person p1("Adam", "Rak");
    p1.present();

    Employee e1("Adam", "Kot", "Kierownik");
    e1.present();

    FullTimeEmployee f1("Adam", "Etatowy", "Dyrektor", 15000);
    f1.present();
}