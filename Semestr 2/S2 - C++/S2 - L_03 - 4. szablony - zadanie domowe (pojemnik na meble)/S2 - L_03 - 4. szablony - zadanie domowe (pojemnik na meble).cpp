#include <iostream>

template <class T>
class Container
{
    public:
        T furnitureContainer[20];
        int elementsCounter;

        Container() : elementsCounter(0) {}

        void addElement(const T& elementToAdd)
        {
            if(elementsCounter < 20)
            {
                furnitureContainer[elementsCounter] = elementToAdd;
                ++elementsCounter;
            }
            else
            {
                std::cout << "Container is full." << std::endl;
            }
        }

        friend std::ostream& operator<<(std::ostream& out, const Container<T>& toDisp)
        {
            for(int i = 0; i < toDisp.elementsCounter; i++)
            {
                out << toDisp.furnitureContainer[i] << " ";
            }
            return out;
        }
};

class Furniture
{
    public:
        Furniture() {}

        Furniture(float weight, float width, float depth, float height)
        : mWeight(weight), mWidth(width), mDepth(depth), mHeight(height) {}

        ~Furniture() {}

        float getWeight() const {return mWeight;}

    protected:
        float mWeight;
        float mWidth;
        float mDepth;
        float mHeight;
};

class Table : public Furniture
{
    public:
        Table() {}

        Table(float weight, float width, float depth, float height, std::string numberID, int numberOfLegs)
        : Furniture(weight, width, depth, height), mNumberID(numberID), mNumberOfLegs(numberOfLegs) {}

        ~Table() {}

        std::string getNumberID() const {return mNumberID;}
        int getNumberOfLegs() const {return mNumberOfLegs;}

        friend std::ostream& operator<<(std::ostream& out, const Table& toDisp);
        bool operator==(const Table& toCompare) const;

    private:
        std::string mNumberID;
        int mNumberOfLegs;
};

std::ostream& operator<<(std::ostream& out, const Table& toDisp)
{
    return out << toDisp.getNumberID() << " " << toDisp.getNumberOfLegs() << " " << toDisp.getWeight();
}

bool Table::operator==(const Table& toCompare) const
{
    if(mNumberOfLegs == toCompare.getNumberOfLegs())
        return true;
    return false;
}

int main()
{
    Container<Table> tables;
    size_t noOfElementsToAdd{5};

    for(size_t i = 0; i < noOfElementsToAdd; i++)
    {
        float weight, width, depth, height;
        std::string numberID;
        int numberOfLegs;

        std::cin >> weight;
        std::cin >> width;
        std::cin >> depth;
        std::cin >> height;
        std::cin >> numberID;
        std::cin >> numberOfLegs;

        tables.addElement(Table(weight, width, depth, height, numberID, numberOfLegs));
    }

    std::cout << tables;

    if(tables.furnitureContainer[3] == tables.furnitureContainer[4])
    {
        std::cout << " equal";
    }
    else
    {
        std::cout << " different";
    }
}