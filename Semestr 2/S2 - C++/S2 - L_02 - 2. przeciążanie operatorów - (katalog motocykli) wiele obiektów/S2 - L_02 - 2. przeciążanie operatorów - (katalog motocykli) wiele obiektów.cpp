#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

//======================================================
// O(n^2) bubble sort       -> 50 * (64*64) = 204800
// O(n*log_2(n)) heap sort  -> 50 * 64 * 6 = 19200

// O(n)                     -> 50 * 64 = 3200
// O(log_2(n))              -> 50 * 6 = 300
//======================================================

class Motorcycle
{
    public:
        Motorcycle() = default;
        Motorcycle(int numberOfWeels, int einginePower, float weight, std::string ID)
        : numberOfWeels(numberOfWeels), enginePower(enginePower), weight(weight), ID(ID)
        {

        }
//deklaracja przeciążenia operatora w klasie bo porównuję do obiektu z tej klasy
        bool operator<(const Motorcycle& toCompare) const;

    //private:
        int numberOfWeels;
        int enginePower;
        float weight;
        std::string ID;
};

//sama definicja już poza klasą
bool Motorcycle::operator<(const Motorcycle& toCompare) const //ten drugi const powoduje, że nie da się zmienić atrybutów obiektu do którego przyrównuję
{
    if(enginePower == toCompare.enginePower)
        return weight < toCompare.weight;
    return enginePower < toCompare.enginePower;
}

//przeciążenie całkowicie poza klasą -> potrzeba wtedy dwóch argumentów do porównania (np. L, R), deklaracja + definicja poza klasą
bool operator>(const Motorcycle& toCompareL, const Motorcycle& toCompareR)
{
//pełny zapis przeciążenia
//    if(toCompareL.enginePower == toCompareR.enginePower)
//        return toCompareL.weight < toCompareR.weight;
//    return toCompareL.enginePower < toCompareR.enginePower;

//jako, że operator < jest też już przeciążony można tutaj ewentualnie zastąpić te 3 linijki kodu takim zapisem:
    return !(toCompareL < toCompareR);
}

class Catalogue
{
    public:
        std::multiset<Motorcycle> Motorcycles; //multiset, żeby wstawić kilka motocykli o tej samej mocy silnika
        void addMotorcycle(Motorcycle toAdd);
};

void Catalogue::addMotorcycle(Motorcycle toAdd)
{
    Motorcycles.insert(toAdd);
}
//==========================================================

class CatalogueVector
{
    public:
//        static constexpr size_t numberOfMotorcycles = 5000;
//        Motorcycle Motorcycles[numberOfMotorcycles];
        std::vector<Motorcycle> Motorcycles; //zakomentuj jeśli TEST sortowania bąbelkowego
        void addMotorcycle(Motorcycle toAdd);
        void dispMotorcycles() const;

    private:
        size_t counter{0}; //licznik tylko do tego sortowania bąbelkowego do testowania
};

void CatalogueVector::addMotorcycle(Motorcycle toAdd)
{
/*
//tu inny sposób z dodawaniem i sortowaniem bąbelkowym do przetestowania
    if(counter < numberOfMotorcycles)
        Motorcycles[counter++] = toAdd;

    for(size_t i = 0; i < counter - 1; i++)
    {
        for(size_t j = 0; j < counter - 2; j++)
        {
            if(Motorcycles[j] < Motorcycles[j + 1])
            {
                std::swap(Motorcycles[j], Motorcycles[j + 1]);
            }
        }
    }
*/
    Motorcycles.push_back(toAdd);
    std::sort(Motorcycles.begin(), Motorcycles.end()); //sortowanie w wektorze
}

void CatalogueVector::dispMotorcycles() const
{
    for(size_t i = 0; i < counter - 1; i++)
    {
        std::cout << "{" << Motorcycles[i].enginePower << ", " << Motorcycles[i].weight << "}, ";
    }
}

int main()
{
    Catalogue mycatalogueMutliSet;
    CatalogueVector myCatalogueVector;

    std::chrono::microseconds timeMultiSet{0};
    std::chrono::microseconds timeVector{0};

    size_t numberOfMotorcyclesToAdd = 1000;
    unsigned int seed = 10;
    srand(time(NULL));

//pomiar długości czasu dodawania motocykli do katalogu multiset
    for(size_t i = 0; i < numberOfMotorcyclesToAdd; i++)
    {
        int enginePower = rand()%1000;
        int weight = rand()%2000;
        Motorcycle toAdd = Motorcycle(2, enginePower, weight, "xxxx");

        auto start = std::chrono::high_resolution_clock::now();
        mycatalogueMutliSet.addMotorcycle(toAdd);
        auto stop = std::chrono::high_resolution_clock::now();
        timeMultiSet += std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
    }
    std::cout << timeMultiSet.count() <<std::endl; //czas dodawania do multiset


//pomiar długości czasu dodawania motocykli do katalogu vector
    for(size_t i = 0; i < numberOfMotorcyclesToAdd; i++)
    {
        int enginePower = rand()%1000;
        int weight = rand()%2000;
        Motorcycle toAdd = Motorcycle(2, enginePower, weight, "xxxx");

        auto start = std::chrono::high_resolution_clock::now();
        myCatalogueVector.addMotorcycle(toAdd);
        auto stop = std::chrono::high_resolution_clock::now();
        timeVector += std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
    }
    std::cout << timeVector.count() <<std::endl; //czas dodawania do vector


/*
//TEST: pomiar długości czasu dodawania motocykli do katalogu vector + sortowanie bąbelkowe -> odkomentuj sortowanie w metodzie addMotorcycle
    for(size_t i = 0; i < numberOfMotorcyclesToAdd; i++)
    {
        int enginePower = rand()%100;
        int weight = rand()%20;
        Motorcycle toAdd = Motorcycle(2, enginePower, weight, "xxxx");

        auto start = std::chrono::high_resolution_clock::now();
        myCatalogueVector.addMotorcycle(toAdd);
        auto stop = std::chrono::high_resolution_clock::now();
        timeVector += std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
    }
    std::cout << timeVector.count() <<std::endl;

    myCatalogueVector.dispMotorcycles(); //wypisanie motocykli z katalogu vector
*/
}