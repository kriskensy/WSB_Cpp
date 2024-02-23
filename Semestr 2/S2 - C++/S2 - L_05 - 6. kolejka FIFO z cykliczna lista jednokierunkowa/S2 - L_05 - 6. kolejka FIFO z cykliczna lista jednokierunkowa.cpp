#include<iostream>
#include<memory>

// Napisz program, który realizuje kolejkę FIFO za pomocą jednokierunkowej listy cyklicznej.
// - ELement kolejki ma przechowywać wskaźniki klasy bazowej Vehicle i posiadać wskaźnik na następny element.
// - Klasa reprezentująca kolejkę posiada wskaźnik na ostatni element, funkcję push dodającą element do kolejki oraz pop, którra ściąga element z kolejki.
// - Utwórz dwie klasy, które dziedziczą po klasie bazowej: Car oraz Motorcycle, które zawierają przeciążone metody z klasy bazowej:
// dispVehicleParameters, dispVehicleType

class Vehicle
{
    public:
        virtual void dispVehicleParameters(std::ostream& out) const = 0;
        virtual std::string getVehicleType() const = 0;
};

std::ostream& operator<<(std::ostream& out, const Vehicle& toDisp)
{
    toDisp.dispVehicleParameters(out);
    return out;
}

class Car : public Vehicle
{
    public:
        unsigned int mNumberOfWheels;
        unsigned int mEnginePower;

        Car(unsigned int numberOfWheels, unsigned int enginePower)
        : mNumberOfWheels(numberOfWheels), mEnginePower(enginePower) {}

        void dispVehicleParameters(std::ostream& out) const override;
        std::string getVehicleType() const override;
};

void Car::dispVehicleParameters(std::ostream& out) const
{
    std::cout << "C: " << mNumberOfWheels << " " << mEnginePower;
}

std::string Car::getVehicleType() const
{
    return "Car";
}

class Motorcycle : public Vehicle
{
    public:
        unsigned int mNumberOfWheels;
        unsigned int mEnginePower;
        Motorcycle(unsigned int numberOfWheels, unsigned int enginePower)
        : mNumberOfWheels(numberOfWheels), mEnginePower(enginePower) {}

        void dispVehicleParameters(std::ostream& out) const override;
        std::string getVehicleType() const override;
};

void Motorcycle::dispVehicleParameters(std::ostream& out) const
{
    std::cout << "M: " << mNumberOfWheels << " " << mEnginePower;
}

std::string Motorcycle::getVehicleType() const
{
    return "Motorcycle";
}

class Element
{
    public:
        std::shared_ptr<Vehicle> m_pVal;
        std::shared_ptr<Element> m_pNext;
        Element(std::shared_ptr<Vehicle> pVal = nullptr, std::shared_ptr<Element> pNext = nullptr)
        : m_pVal(pVal), m_pNext(pNext) {}
};

class FIFO
{
    public:
        std::shared_ptr<Element> m_pLast;
        void push(std::shared_ptr<Vehicle> pToAdd);
        void pop();
        size_t size() const {return mCounter;}

        friend std::ostream& operator<<(std::ostream& out, const FIFO& toDisp);

    private:
        size_t mCounter{0};
};

void FIFO::push(std::shared_ptr<Vehicle> pToAdd)
{
    ++mCounter;
    if(m_pLast == nullptr)
    {
        m_pLast = std::make_shared<Element>(pToAdd);
        m_pLast -> m_pNext = m_pLast;
    }
    else
    {
        m_pLast -> m_pNext = std::make_shared<Element>(pToAdd, m_pLast -> m_pNext);
        m_pLast = m_pLast -> m_pNext;
    }
}

void FIFO::pop()
{
    --mCounter;
    if(m_pLast == m_pLast -> m_pNext)
    {
        m_pLast = nullptr;
    }
    else
    {
        m_pLast -> m_pNext = m_pLast -> m_pNext -> m_pNext;
    }
}

std::ostream& operator<<(std::ostream& out, const FIFO& toDisp)
{
    auto element = toDisp.m_pLast -> m_pNext;
    while(element != toDisp.m_pLast)
    {
        out << element -> m_pVal -> getVehicleType() << " " << *(element -> m_pVal) << ", ";
        element = element -> m_pNext;
    }
    return out << element -> m_pVal -> getVehicleType() << " " << *(element -> m_pVal) << std::endl;
}


int main()
{
    FIFO fifo;
    fifo.push(std::make_shared<Car>(1, 2));
    fifo.push(std::make_shared<Motorcycle>(2, 4));
    fifo.push(std::make_shared<Motorcycle>(8, 4));
    fifo.push(std::make_shared<Car>(7, 1));

    std::cout << fifo << std::endl;
    auto size = fifo.size();
    for(int i = 0; i < fifo.size(); ++i)
    {
        fifo.pop();
        std::cout << fifo << std::endl;
    }

    // std::shared_ptr<Vehicle> car = std::make_shared<Car>(1, 2);
    // std::cout << *car << std::endl;

    return 0;
}