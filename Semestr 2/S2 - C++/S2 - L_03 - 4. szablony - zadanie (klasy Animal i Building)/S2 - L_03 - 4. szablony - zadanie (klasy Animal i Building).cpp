#include <iostream>
#include <set>
#include <string>
#include <functional>

class Animal
{
    public:
        Animal(std::string name, float weight, int year, std::string ID)
        : name(name), weight(weight), year(year), ID(ID) {}

        Animal()
        {
            std::cout << "create animal";
        }

    friend std::ostream& operator<<(std::ostream& out, const Animal& toDisp);
    bool operator>(const Animal& toCompare) const;

    private:
        std::string name;
        float weight;
        int year;
        std::string ID;

};

    bool Animal::operator>(const Animal& toCompare) const
    {
        if(year == toCompare.year)
            return weight > toCompare.weight;
        return year < toCompare.year;
    }

    std::ostream& operator<<(std::ostream& out, const Animal& toDisp)
    {
        return out << toDisp.name << " " << toDisp.weight << " " << toDisp.year << " " << toDisp.ID;
    }

class Building
{
    public:
        Building(std::string bName, float firstGPS, float secondGPS, float bHeight)
        : bName(bName), firstGPS(firstGPS), secondGPS(secondGPS), bHeight(bHeight) {}

    friend std::ostream& operator<<(std::ostream& out, const Building& toDisp);

    private:
        std::string bName;
        float firstGPS;
        float secondGPS;
        float bHeight;
};

    std::ostream& operator<<(std::ostream& out, const Building& toDisp)
    {
        return out << toDisp.bName << " " << toDisp.firstGPS << " " << toDisp.secondGPS << " " << toDisp.bHeight;
    }

template<class T>
class Container
{
    public:
        void addElement(const T& toAdd) {elements.insert(toAdd);}
        void removeElement(size_t index);

        template<typename T1> friend std::ostream& operator<<(std::ostream& out, const Container<T1>& toDisp);

    private:
        std::multiset<T, std::greater<T>> elements;
};

template<class T> void Container<T>::removeElement(size_t index)
{
    if(index >= elements.size())
        return;
    auto it = elements.begin();
    std::advance(it, index); //std::advance -> funkcja przesuwająca iterator po indeksie
    elements.erase(it); //erase przyjmuje iterator i usuwa element pod indexem
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Container<T>& toDisp)
{
    for(const auto& element : toDisp.elements)
        out << element << " ";
    return out;
}

//funkcja do sprawdzania poprawności wprowadzonych danych (dla int, druga dla float)
//15 23 25 -> ok
//12.5 asd !@12 98A -> nok
bool validateInt(std::string val)
{
    for(const auto& symbol : val)
    {
        if (!(symbol >= '0' && symbol <= '9'))
            return false;
    }
    return true;
};

bool validateFloat(const std::string val)
{
//prześledzenie kolejnych iteracji pętli:
// 12.4.3 -> false (przykładowe wprowadzenie)

// iter 1 = -> symbol = '1'
// counter = 0
// if (false)
// if (false)

// iter 2 = -> symbol = '2'
// counter = 0
// if (false)
// if (false)

// iter 3 = -> symbol = '.'
// counter = 0
// if (true) counter =1
// if (false)

// iter 4 = -> symbol = '4'
// counter = 1
// if (false)
// if (false)

// iter 5 = -> symbol = '.'
// counter = 1
// if (true) counter = 2

// iter 6 = -> symbol = '3'
// counter = 2
// if (false)
// if (true)
//         return false


    unsigned int counter{0};

    for(const auto& symbol : val)
    {
        if(symbol == '.')
        {
            if(++counter > 1)
                return false;
            continue;
        }

        if (!(symbol >= '0' && symbol <= '9'))
            return false;
    }
    return true;
};

int main()
{

    Container<Animal> animals;
    constexpr size_t noOfElementsToAdd{4};

    for(size_t i = 0; i < noOfElementsToAdd; i++)
    {
        std::string name, weight, year, ID;
        std::cin >> name;

        do
        {
            std::cin >> weight;
        } while (!validateFloat(weight));

//w tej pętli uzytownik wprowadza ciąg znaków i kompilator puszcza je kolejno przez funkcję sprawdzającą poprawność 'validateInt' i jeśli są same cyfry to funkcja zwraca true a std::stoi konwertuje tego stringa na inta
        do
        {
            std::cin >> year;
        } while (!validateInt(year));

        std::cin >> ID;
        animals.addElement(Animal(name, std::stof(weight), std::stoi(year), ID));
    }
    std::cout << animals << std::endl;

    size_t toRemove{};
    std::cin >> toRemove;
    animals.removeElement(toRemove);
    std::cout << animals << std::endl;


//=======================================================
// //to było tylko do testu struktury multiset
//     std::multiset<int> c = {1, 2, 3, 4, 1, 2, 3, 4};

//     for(auto &&i : c)
//     {
//         std::cout << i << " ";
//     }

//     auto it = c.begin();
//     std::advance(it, 2);

//     c.erase(it);
//     std::cout << std::endl;
//     for(auto &&i : c)
//     {
//         std::cout << i << " ";
//     }
}
