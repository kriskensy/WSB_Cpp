#include <iostream>
#include <cstdlib>

class Character
{
private:
    std::string name;
    int healthPoints;
public:
    Character(std::string name)
    : name(name), healthPoints(5)
    {

    }
    std::string sayYourName()
    {
        return "My name is " +name;
    }

    int getHealthPoints()
    {
        return healthPoints;
    }

    void HPlos()
    {
        healthPoints--;
    }
};

class Witcher: public Character
{
private:
    double elixir;
public:
    Witcher(std::string name)
    : Character(name), elixir(10)
    {

    }

    void cureWithElixir(double number)
    {
        elixir-=number;
    }

    std::string battleShout()
    {
        return "uaaaaaaa!!";
    }

    double getElixir()
    {
        return elixir;
    }

};

int main(int argc, char* argy[])
{
    Character ch1("Zoltan");
    std::cout << std::endl << ch1.sayYourName();
    std::cout << std::endl << "HP: " << ch1.getHealthPoints();
    ch1.HPlos();
    std::cout << std::endl << "HP after los: " << ch1.getHealthPoints();

    std::cout << std::endl;
    Witcher w1("Geralt");
    std::cout << std::endl << w1.sayYourName();
    std::cout << std::endl << "Elixir: " << w1.getElixir();
    w1.cureWithElixir(2);
    std::cout << std::endl << "Elixir: " << w1.getElixir();
    std::cout << std:: endl << w1.battleShout();

    std::cout << std::endl;
    Witcher w2("Thorgal");
    std::cout << std::endl << w2.sayYourName();
    std::cout << std::endl << "Elixir: " << w2.getElixir();
    w2.cureWithElixir(4);
    std::cout << std::endl << "Elixir: " << w2.getElixir();
    std::cout << std:: endl << w2.battleShout();
}