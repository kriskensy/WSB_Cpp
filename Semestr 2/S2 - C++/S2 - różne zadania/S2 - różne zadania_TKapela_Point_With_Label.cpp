#include <iostream>

class Point
{
    public:
        Point() {}
        Point(double x, double y)
        : x(x), y(y) {}

        void display() const
        {
            std::cout << "(" << x << "," << y << ")";
        }

    private:
        double x;
        double y;
};

class PointWithLabel : public Point
{
    public:
        PointWithLabel() {}
        PointWithLabel(double x, double y, std::string label = basicLabel)
        : Point(x, y), label(label) {}

        std::string getLabel() {return label;}
        void setLabel(std::string label)
        {
            this -> label = label;
        }

        static std::string getBasiclabel() { return basicLabel;}
        static void setBasicLabel(std::string basicLabel)
        {
            basicLabel = basicLabel;
        }

        void display() const
        {
            std::cout << label;
            Point::display();
            std::cout << std::endl;
        }

    private:
        std::string label;
        static std::string basicLabel;
};

std::string PointWithLabel::basicLabel = "A";

int main()
{
    // PointWithLabel a(5, 4);
    // a.display();

    // PointWithLabel::getBasiclabel();
    // PointWithLabel::setBasicLabel("666");

    PointWithLabel::setBasicLabel("A");
    PointWithLabel a(1,2);
    a.setBasicLabel("Z");
    a.display(); // A(1,2)
    PointWithLabel b(3,4,"B");
    b.display(); // B(3,4)
    b.setLabel("C");
    b.display(); // C(3,4)
    PointWithLabel z(5,6);
    z.display(); // Z(
}