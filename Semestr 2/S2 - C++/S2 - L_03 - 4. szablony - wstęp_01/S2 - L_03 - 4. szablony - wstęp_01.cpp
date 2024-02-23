#include <iostream>

// //taka sama funkcja dla int
// void dispTab(int tab[], const size_t kSize)
// {
//     for(size_t i = 0; i < kSize; i++)
//         std::cout << tab[i] << " ";
//     std::cout << std::endl;
// }

// //taka sama funkcja dla float
// void dispTab(float tab[], const size_t kSize)
// {
//     for(size_t i = 0; i < kSize; i++)
//         std::cout << tab[i] << " ";
//     std::cout << std::endl;
// }

//jeden szablon dla różnych typów 'T' w zależności co potrzeba
template<class T>
void dispTab(T tab[], const size_t kSize)
{
    for(size_t i = 0; i < kSize; i++)
        std::cout << tab[i] << " ";
    std::cout << std::endl;
}

template<class T>
T sumTab(T tab[], const size_t kSize)
{
    T sum{};
    for(size_t i = 0; i < kSize; i++)
        sum += tab[i];
    return sum;
}

//szablonów można też używać do typów stworzonych przez nas
class Product
{
    public:
        std::string mName;
        float mNetPrice;
        Product(std::string name = "", float netPrice = 0)
        : mName(name), mNetPrice(netPrice)
        {}

        friend std::ostream& operator<<(std::ostream& out, const Product& toDisp)
        {
            return out << toDisp.mName << "; " << toDisp.mNetPrice;
        }

        void operator+=(const Product& toAdd)
        {
            if(mName == "")
            {
                mName = toAdd.mName;
                mNetPrice = toAdd.mNetPrice;
                return;
            }
            mName = mName + ", " + toAdd.mName;
            mNetPrice += toAdd.mNetPrice;
        }
};

int main()
{
    constexpr size_t kSize{5};

//zapis dla funkcji bez szablonu:
    // int tabInt[kSize]{1, 2, 3, 4, 5};
    // dispTab<int>(tabInt, kSize);

    int tabInt[kSize]{1, 2, 3, 4, 5};
    dispTab(tabInt, kSize);
    std::cout << sumTab(tabInt, kSize) << std::endl;

    float tabFloat[kSize]{1.1, 2.2, 3.3, 4.4, 5.5};
    dispTab(tabFloat, kSize);
    std::cout << sumTab(tabFloat, kSize) << std::endl;

    std::string tabString[kSize]{"1.1", "2.2", "3.3", "4.4", "5.5"};
    dispTab(tabString, kSize);
    std::cout << sumTab(tabString, kSize) << std::endl;

    Product tabProduct[kSize]{{"a", 1}, {"b", 2}, {"c", 3}, {"d", 4}, {"e", 5}};
    dispTab(tabProduct, kSize);
    std::cout << sumTab(tabProduct, kSize) << std::endl;
}