#include <iostream>
#include <map>
#include <string>


//======================================================
// O(n^2) bubble sort       -> 50 * (64*64) = 204800
// O(n*log_2(n)) heap sort  -> 50 * 64 * 6 = 19200

// O(n)                     -> 50 * 64 = 3200
// O(log_2(n))              -> 50 * 6 = 300
//======================================================

class Motorcycle
{
    public:
        Motorcycle(int numberOfWeels, int einginePower, float weight, std::string ID)
        : numberOfWeels(numberOfWeels), enginePower(enginePower), weight(weight), ID(ID)
        {

        }

    private:
        int numberOfWeels;
        int enginePower;
        float weight;
        std::string ID;
};

class Catalogue
{
    public:
        std::map <std::string, Motorcycle> Motorcycles; //mapa pomaga dodać po jednej zmiennej (klucz) i posortować po innej wartości
        void addMotorcycle(Motorcycle toAdd);

    private:
};

//metody pisane poza klasą - metoda nie dokończona, zostawiłem ten kod tak specjalnie, żeby mieć przykład dodawania w mapie po kluczu
void Catalogue::addMotorcycle(Motorcycle toAdd)
{

}

int main()
{
    std::map<std::string, int> myMap;

    myMap.insert({"c", 11});
    myMap.insert({"a", 3});
    myMap.insert({"d", 7});
    myMap.insert({"a", 7}); //już nie wstawi bo "a" już było

    for(const auto& i : myMap)
    {
        std::cout << i.first << " " << i.second << std::endl;
    }
}