#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Point
{
    public:
        Point(std::string name, double x, double y, double z)
        : name(name), x(x), y(y), z(z) {}

        std::string getname() const { return name;}
        double getX() const {return x;}
        double getY() const {return y;}
        double getZ() const {return z;}

    private:
        std::string name;
        double x;
        double y;
        double z;
};

std::ostream& operator << (std::ostream& out, const Point& point)
{
    return out << point.getname() << " " << point.getX() << " " << point.getY() << " " << point.getZ();
};

class CoordinateSystem
{
    public:
        CoordinateSystem(std::string name) : name(name) {}
        CoordinateSystem() = default;

    void addPoint(const Point& point)
    {
    points.push_back(point);
    }

    friend std::ostream& operator << (std::ostream& out, const CoordinateSystem& toDisp)
    {
        for(const auto& point : toDisp.points)
            out << point << "; ";
            return out;
    }

    void operator+=(const CoordinateSystem& toAdd);
    void operator-=(const CoordinateSystem& toRemove);

    private:
        std::string name;
        std::vector<Point> points;
};

void CoordinateSystem::operator+=(const CoordinateSystem& toAdd)
{
    for(const auto& point : toAdd.points)
        points.push_back(point);
}

void CoordinateSystem::operator-=(const CoordinateSystem& toRemove)
{
// x -= y
    for(auto iter = toRemove.points.cbegin(); iter != toRemove.points.cend();)
    {
        if(auto it = std::find_if(points.cbegin(), points.cend(), //funkcja find_if ze standardowej biblioteki przeszukuje punkty od początku do końca i zwraca iterator
            [&iter](const Point& toCompare) //przekazujemy iterator
            {
                return iter->getX() + iter->getY() + iter->getZ() == toCompare.getX() + toCompare.getY() + toCompare.getZ();
            });
            it != points.cend()) //jeżeli iterator jest różny od elementu końcowego to został znaleziony
            {
                points.erase(it); //znaleziony więc można iterator usunąć
            }
        else
        {
            ++iter;
        }
    }
}
//a = b + c dlatego przy zwykłym dodawaniu tworzę wynikowy system koordynatów 'result'
//a = b
//a += c
CoordinateSystem operator+(const CoordinateSystem& oxyzL, const CoordinateSystem& oxyzR)
{
    CoordinateSystem result{oxyzL};
    result += oxyzR; //tu implementuję już przeładowany operator
    return result;
}

CoordinateSystem operator-(const CoordinateSystem& oxyzL, const CoordinateSystem& oxyzR)
{
    CoordinateSystem result{oxyzL};
    result -= oxyzR; //tu implementuję już przeładowany operator
    return result;
}

int main()
{
    CoordinateSystem oxyzA, oxyzB;
    size_t numberOfPointInOxyzA{2};
    size_t numberOfPointInOxyzB{1};

    for(size_t i = 0; i < numberOfPointInOxyzA; i++)
    {
        std::string name;
        double x, y, z;
        std::cin >> name >> x >> y >> z;
        oxyzA.addPoint(Point(name, x, y, z));
    }

    for(size_t i = 0; i < numberOfPointInOxyzB; i++)
    {
        std::string name;
        double x, y, z;
        std::cin >> name >> x >> y >> z;
        oxyzB.addPoint(Point(name, x, y, z));
    }

    std::cout << oxyzA << std::endl << oxyzB << std::endl;
    oxyzA += oxyzB;
    std::cout << oxyzA << std::endl << oxyzB << std::endl;
    oxyzA -= oxyzB;
    std::cout << oxyzA << std::endl << oxyzB << std::endl;

}