#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Point
{
    public:
        Point(std::string name, float x, float y)
        : name(name), x(x), y(y)
        {
            std::cout << "create a point with data" << std::endl;
        }

        Point()
        {
            std::cout << "create a point" << std::endl;
        }

        std::string getname() const { return name;}
        float getX() const {return x;}
        float getY() const {return y;}

        void disp() const
        {
            std::cout << "Point: " << name << "(" << x << ", " << y << ")";
        }

    protected:
        std::string name;
        float y;

    private:
        float x;
};

std::ostream& operator << (std::ostream& out, const Point& point)
{
    return out << "Point: " << point.getname() << "(" << point.getX() << ", " << point.getY() << ")";
};

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

        void disp() const
        {
            Point::disp();
            std::cout << ", circle: " << name << ", radius = " << radius;
        }

        double circumreferenceOfCircle() const
        {
            double pi = 3.14;
            return 2 * pi * radius;
        }

        std::string getName() const {return name;}
        float getRadius() const {return radius;}

    private:
        std::string name;
        float radius;
};

std::ostream& operator << (std::ostream& out, const Circle& circle)
{
    return out << static_cast<const Point&>(circle) << ", circle: " << circle.getName() << ", radius = " << circle.getRadius() << ", circumreference = " << circle.circumreferenceOfCircle();
};

int main()
{
    std::string namePoint, nameCircle;
    float x, y, radius;
    std::cin >> namePoint >> x >> y >> nameCircle >> radius;
    Circle myCircle(nameCircle, radius, namePoint, x ,y);

//    myCircle.Point::disp();

    std::cout << static_cast<const Point&>(myCircle) << std::endl;
    std::cout << myCircle << std::endl;
//    myCircle.disp();
}