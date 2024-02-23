#include <iostream>
#include <string>

enum class Unit {gram, piece};

class Product //mała literka m przed nazwą zmiennej aby łatwo rozpoznać że zmienna pochodzi z jakiejś klasy - member
{
public: // w klasie u góry zaczynamy od największego dostępu czyli public
    std::string mName;
    double mNetPrice;
    double mWeight;
    Unit mUnit;

    Product()
    {
        std::cout << "Creating a product." << std:: endl;
    }
    Product(std::string name, double netPrice, double weight, Unit unit, double grossPrice)
    : mName(name), mNetPrice(netPrice), mWeight(weight), mUnit(unit), mGrossPrice(grossPrice)
    {
        std::cout << "Creating a product with data." << std::endl;
    }
    ~Product()
    {
        std::cout << "Destroying the product." << std::endl;
    }

    double getGrossPrice() const //ten const to zabezpieczenie, żeby funkcja nie robiła nic więcej, nic nie zmieniała - tylko zwracała
    {
        return mGrossPrice;
    }

    Product(const Product& toCopy) = default;//konstruktor kopiujący
    Product& operator = (const Product&) = default; //operator przypisania

private:
    double mGrossPrice;
};

//ProductCatalogue.h
//#pragma once
class ProductCatalogue
{
public:
    static const size_t noOfProducts = 10;
    Product mProducts[noOfProducts];

    void dispProducts() const;
    bool addProducts(Product toAdd);
//    bool removeProducts(Product toRemove);

private:
    size_t mCounter{0};
};

//ProductCatalogue.cpp
//#include "Productcatalogue.h"
void ProductCatalogue::dispProducts() const
{
    for(size_t i = 0; i < mCounter; i++)
    {
        std::cout << mProducts[i].mName << " ";
    }
}

bool ProductCatalogue::addProducts(Product toAdd)
{
    if (mCounter < noOfProducts)
    {
        mProducts[mCounter++] = toAdd;
        return true;
    }
    return false;
}

int main()
{
/*
    Product avocado("myAvo", 4.23, 1, Unit::piece, 5);
    std::cout << avocado.getGrossPrice() << std::endl;

    std::cout << ProductCatalogue::noOfProducts << std::endl;
    ProductCatalogue myCatalogue;
    std::cout << myCatalogue.noOfProducts << std::endl;
*/
        ProductCatalogue myCatalogue;
        constexpr size_t noOfProductsToAdd{3};

        std::string name;
        double netPrice, grossPrice, weight;
        std::string unitS;
        Unit unit;

        for(size_t i = 0; i < noOfProductsToAdd; i++)
        {
            std::cin >> name >> netPrice >> weight >> unitS >> grossPrice;
            Unit unit = unitS == "gram" ? Unit::gram : Unit::piece; //instrukcja warunkowa, jeśli prawda to przypisuję gram, jeśli fałsz to przypisuję piece

            Product toAdd(name, netPrice, weight, unit, grossPrice);
            myCatalogue.addProducts(toAdd);
        }

        myCatalogue.dispProducts();
}