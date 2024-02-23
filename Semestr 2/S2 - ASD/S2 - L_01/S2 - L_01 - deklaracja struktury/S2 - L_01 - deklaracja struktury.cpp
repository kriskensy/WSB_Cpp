#include <iostream> 

struct car 
{
    std::string brand;
    int productionYear;
    double engineCapacity;
};

int main()
{
    car c1;
    car *ptr = &c1;

    c1.brand = "Audi";
    ptr->productionYear = 2023;
    ptr->engineCapacity = 2.0;

    std::cout << "Marka: " << ptr->brand << std::endl;
    std::cout << "Rok produkcji: " << ptr->productionYear << std::endl;
    std::cout << "Pojemność silnika: " << ptr->engineCapacity << std::endl;
}