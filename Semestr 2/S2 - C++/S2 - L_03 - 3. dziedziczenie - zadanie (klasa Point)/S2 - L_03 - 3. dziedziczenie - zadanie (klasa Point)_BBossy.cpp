#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>
#include <functional>
//to było zadanie od prowadzącego wrzucone do materiałów

class Point
{
    public:
        Point(std::string name_, float x_, float y_)
        : name(name_), x(x_), y(y_)
        {
            std::cout << "Tworze punkt z danymi" << std::endl;
        }

        Point()
        {
            std::cout << "Tworze punkt" << std::endl;
        }
        float calcDistance(const Point& toCalc) const;

        inline std::string getname() const { return name;}
        inline float getX() const {return x;}
        inline float getY() const {return y;}

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
    return sqrt(x*x + y*y);
}
float Point::calcDistance(const Point& toCalc) const
{
    return sqrt((x-toCalc.getX())*(x-toCalc.getX()) + (y-toCalc.getY())*(y-toCalc.getY()));
}

bool Point::operator<(const Point& toCompare) const
{
    if (calcDistance() == toCompare.calcDistance())
        return name < toCompare.getname();
    return calcDistance() < toCompare.calcDistance();
}

bool Point::operator>(const Point& toCompare) const
{
    return !operator<(toCompare);
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
            std::cout << "Tworze kolo z danymi" << std::endl;
        }
        Circle()
        {
            std::cout << "Tworze kolo" << std::endl;
        }
        std::string getName() const { return name; }
        float getRadius() const { return radius; }
    private:
        std::string name;
        float radius;
};

std::ostream& operator<<(std::ostream& out, const Circle& circle)
{
    return out << static_cast<const Point&>(circle) << ", circle: " << circle.getName() << ", radius = " << circle.getRadius();
};

class CoordinateSystem
{
    public:
        void addPoint(const Point& toAdd) { points.insert(toAdd); }
        bool arePointsInsideCircle(const Circle& circle);
    private:
        std::set<Point, std::greater<Point>> points;

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
    CoordinateSystem oxy;

    constexpr size_t noOfPoints{6};

    for (size_t i = 0; i < noOfPoints; i++)
    {
        std::string namePoint;
        float x, y;
        std::cin >> namePoint >> x >> y;
        oxy.addPoint(Point(namePoint, x, y));
    }

    std::cout << oxy << std::endl;
    
    std::string namePoint, nameCircle;
    float x, y, radius;
    std::cin >> namePoint >> x >> y >> nameCircle >> radius;
    
    Circle myCircle(nameCircle, radius, namePoint, x, y);
    std::cout << oxy.arePointsInsideCircle(myCircle) << std::endl;
}