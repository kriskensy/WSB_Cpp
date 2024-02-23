#include<iostream>
#include<string>

enum Unit {gram, piece};

class Product 
{
    public:
        std::string name_;
        double netPrice_;
        double weight_;
        Unit unit_;

        Product()
        {
            std::cout << "Creating a product." << std::endl;
        }

        Product(std::string, double, double, Unit, double);

        ~Product()
        {
            std::cout << "Destroying the product " << name_ << std::endl;
        }
        
        double getGrossPrice() const
        {
            return grossPrice_;
        }

        double calcTotalPrice();

        bool operator+=(const Product& toAdd);

        friend std::ostream& operator << (std::ostream& out, const Product& toDisp);

    private:
        double grossPrice_;
};

Product::Product(std::string name, double netPrice, double weight, Unit unit, double grossPrice)
: name_(name), netPrice_(netPrice), weight_(weight), unit_(unit), grossPrice_(grossPrice)
{
    std::cout << "Creating a product with data." << std::endl;
}

double Product::calcTotalPrice()
{
    constexpr unsigned int gramsInKg = 1000;
    if (unit_ == Unit::gram)
    {
        return weight_ / gramsInKg * netPrice_;
    }
    else
        return weight_ * netPrice_;
}

bool Product::operator+=(const Product& toAdd)
{
    if(unit_ != toAdd.unit_)
    {
        std::cout << "different units, cannot add" << std::endl;
        return false;
    }

    name_ = name_ + " + " + toAdd.name_;
    netPrice_ += toAdd.netPrice_;
    weight_ += toAdd.weight_;
    grossPrice_ += toAdd.getGrossPrice();
        return true;
}

std::ostream& operator << (std::ostream& out, const Product& toDisp)
{
    return out << toDisp.name_ << ": " << toDisp.netPrice_ << ", " << toDisp.weight_ << ", " << toDisp.getGrossPrice() << std::endl;
}

//dodawanie dwóch produktów
Product operator + (const Product& toAddL, const Product& toAddR)
{
    if(Product result = toAddL; result += toAddR)
        return result;
    return Product();
}

int main()
{

    Product tomato("MyTomato", 1.99, 2, Unit::gram, 0.99);
    Product avocado("MyAvacado", 4.99, 2, Unit::piece, 2.5);
    std::cout << tomato;
    std::cout << "------------------" << std::endl;

    Product banana("MyBanana", 2.49, 2, Unit::gram, 1.19);
    std::cout << banana;

    tomato += banana;
    std::cout << tomato;
    std::cout << "------------------" << std::endl;

    Product kiwi("MyKiwi", 3.29, 3, Unit::piece, 1.99);

    tomato += kiwi;
    std::cout << tomato;

    std::cout << "------------------" << std::endl;
    Product result = tomato + avocado;
    std::cout << result;
    return 0;
}