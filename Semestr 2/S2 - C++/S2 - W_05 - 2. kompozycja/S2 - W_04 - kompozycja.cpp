#include <iostream>
#include <cstdlib>

class Engine
{
private:
    double capacity;
    double enginePower;
public:
    Engine(double capacity, double enginePower)
    : capacity(capacity), enginePower(enginePower)
    {

    }

    void present()
    {
        std::cout << std::endl << "Capacity: " << capacity;
        std::cout << std::endl << "Engine power: " << enginePower;
    }
};
//Car nie może dziedziczyć po Engine!
class Car
{
private:
    std::string vin;
    Engine engine; //realizacja kompozycji - związku typu "ma"
public:
        Car(std::string vin, Engine engine)
        : vin(vin), engine(engine)
        {

        }
        
        void present()
        {
            std::cout << std::endl << "VIN: " <<vin;
            engine.present(); //to jest wywołanie z metody "present" z klasy Engine
        }
};

int main(int argc, char* argy[])
{
//    Engine eng1(100, 100);
//    Car c1("123456789", eng1);

//inny sposób
    Car c1("123456789", Engine(100, 100));
    c1.present();
}