#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>
#include <functional> //std::greater

class Point
{
    public:
        Point(std::string name_, float x_, float y_)
        : name(name_), x(x_), y(y_)
        {
            std::cout << "create a point with data" << std::endl;
        }

        Point()
        {
            std::cout << "create a point" << std::endl;
        }
        float calcDistance(const Point& toCalc) const;//pierwszy const zabrania modyfikacji obiektu 'toCalc', drugi const - zabrania modyfikacji atrybutów obiektu na którym wywoływana jest ta funkcja

//inline czasem przyśpiesza działanie programu bo kompilator nie działa przez wstaźnik tylko wrzuca taki krótki kod. Jeśli funkcje są krótkie to można używać 'inline'
        inline std::string getname() const { return name;}
        inline float getX() const {return x;}
        inline float getY() const {return y;}

//a < b
        bool operator<(const Point& toCompare) const;
        bool operator>(const Point& toCompare) const;

    protected:
        std::string name;
        float y;

    private:
        float calcDistance() const;
        float x;
};

float Point::calcDistance() const
{
    return sqrt(x*x + y*y); //wzór od środka układu współrzędnych: sqrt((x-0)*(x-0) + (y-0)*(y-0))
}

//tu odległośc dwóch punktów:
//Point point;
//point.calcDistance(point2)
float Point::calcDistance(const Point& toCalc) const
{
    return sqrt((x-toCalc.getX())*(x-toCalc.getX()) + (y-toCalc.getY())*(y-toCalc.getY()));
}

//operator, jeśli odległłości od początku ukł wsp są równe to zwraca mniejsze imię najpierw
//a < b
bool Point::operator<(const Point& toCompare) const
{
    if (calcDistance() == toCompare.calcDistance())
        return name < toCompare.getname();
    return calcDistance() < toCompare.calcDistance();
}

    bool Point::operator>(const Point& toCompare) const
    {
//        return this -> operator<(toCompare); //this -> to wskaźnik na obiekt dla którego jest wywoływany ten operator
        return !operator<(toCompare); //operator < juz jest przeciążony dlatego mogę tutaj zrobić po prostu negację i mam łatwo operator przeciwny też przeciążony
    }

std::ostream& operator << (std::ostream& out, const Point& point)
{
    return out << "Point: " << point.getname() << "(" << point.getX() << ", " << point.getY() << ")";
}

class Circle : public Point
{
    public:
        Circle(std::string nameCircle_, float radius_, std::string namePoint_, float x_, float y_)
            : Point(namePoint_, x_, y_), name(nameCircle_), radius(radius_)
        {
            std::cout << "create circle with data" << std::endl;
        }
        Circle()
        {
            std::cout << "create circle" << std::endl;
        }
        std::string getName() const { return name; }
        float getRadius() const { return radius; }

    private:
        std::string name;
        float radius;
};

std::ostream& operator << (std::ostream& out, const Circle& circle)
{
    return out << static_cast<const Point&>(circle) << ", circle: " << circle.getName() << ", radius = " << circle.getRadius(); //ten cast uwzględni tylko to co jest w punkcie
};
//static_cast - rzutowanie statyczne, czyli konwersja na inny typ zmiennej, np:
//int a{5};
//a = a + 0.5;
//float y{static_cast<float>(a)};
//czyli jak np zrzutuję int na float to będzie uwzględniona część po przecinku

class CoordinateSystem
{
    public:
        void addPoint(const Point& toAdd) { points.insert(toAdd); }
        bool arePointsInsideCircle(const Circle& circle);

    private:
        std::set<Point, std::greater<Point>> points; //greater to sortowanie rosnące

        friend std::ostream& operator<<(std::ostream& out, const CoordinateSystem &toDisp)
        {
            for (const auto& point : toDisp.points)
                out << point << " ";
                return out;
        }
};

bool CoordinateSystem::arePointsInsideCircle(const Circle& circle)
{
    for (const auto& point : points)
    {
        if (point.calcDistance(circle) > circle.getRadius())
            return false;
    }
    return true;
}

int main()
{
    CoordinateSystem myCoordinateSystem;

//constexpr wstawia zadaną wartość wszędzie gdzie występuje zmienna już na etapie kompilacji, "stała stała"
    constexpr size_t noOfPoints{4};

//wczytanie punktów z konsoli
    for(size_t i = 0; i < noOfPoints; i++)
    {
        std::string namePoint;
        float x, y;
        std::cin >> namePoint >> x >> y;
        myCoordinateSystem.addPoint(Point(namePoint, x, y));
    }

    std::cout << myCoordinateSystem << std::endl;

    std::string namePoint, nameCircle;
    float x, y, radius;
    std::cin >> namePoint >> x >> y >> nameCircle >> radius;

    Circle myCircle(nameCircle, radius, namePoint, x, y);

    std::cout << myCoordinateSystem.arePointsInsideCircle(myCircle) << std::endl;
}