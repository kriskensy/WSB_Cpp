#include <iostream>
#include <string>

//tu sobie sprawdzamy czy tablica rejestracyjna została poprawnie wprowadzona
bool checkID(std::string id)
{
    constexpr size_t noOfSymbolsInId{4};
    if(id.size() != noOfSymbolsInId)
        return false;

    for(size_t i = 0; i < id.size(); i++)
    {
        if (!((id[i] >= '0' && id[i] <= '9') || //tym ifem sprawdzam czy wprowadzony znak jest poprawny. Za pomocą tabeli znaków ASCII
            (id[i] >= 'a' && id[i] <= 'z') ||
            (id[i] >= 'A' && id[i] <= 'Z')))
            return false;
    }
    return true;
}

class Car
{
public:
    Car(std::string id, unsigned int enginePower, float weight, char engineType)
    : mID(id), mEnginePower(enginePower), mWeight(weight), mEngineType(engineType)
    {

    }
    ~Car() = default;

private:
    std::string mID;
    unsigned int mEnginePower; //unsigned bo moc silnika nie może być ujemna
    float mWeight;
    char mEngineType;
};

int main()
{
    std::string id;

/*
//ta pętla była tylko, żeby sobie sprawdzać poprawność wpisywanych znaków do tablicy rejestracyjnej
    for(size_t i = 0; i < 10; i++)
    {
        std::cin >> id;
        std::cout << checkID(id) << std::endl;
    }
*/
    do
    {
        std::cin >> id;
    }
    while (!checkID(id));
    std::cout << checkID(id) << std::endl;
}