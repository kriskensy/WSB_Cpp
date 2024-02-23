#include <iostream>
#include <string>

class Vehicle {
    private:
        float weight;
        int weelsNumber;

    public:
        Vehicle(float weight, int weelsNumber)
        : weight(weight), weelsNumber(weelsNumber) {}

        float getWeight () const
        {
            return weight;
        }
        int getWeelsNumber() const
        {
            return weelsNumber;
        }
};

class Motorcycle : Vehicle {
    private:
        std::string nrID;
        int enginePower;

    public:
        Motorcycle() : Vehicle(0, 2), nrID("brak"), enginePower(0) {}
        Motorcycle(float weight, int weelsNumber, std::string nrID, int enginePower)
        : Vehicle(weight, weelsNumber), nrID(nrID), enginePower(enginePower) {}

        std::string getnrID() const
        {
            return nrID;
        }

        int getEnginePower() const
        {
            return enginePower;
        }

        void present() const
        {
            std::cout << nrID << " " << enginePower << " " << getWeight() << " " << getWeelsNumber();
        }
};

class MotorcycleCatalogue {
    private:
        Motorcycle motorcycles [20];
        int motorcycleCounter;
    public:
        MotorcycleCatalogue()
        : motorcycleCounter(0) {}

        void motorcycleAdd()
        {
//TODO: napisz metodę
        }

        void present() const
        {
            for(int i = 0; i < motorcycleCounter; i++)
            {
                motorcycles[i].present();
            }
        }

};

int main(int argc, char *argv[])
{
    
}