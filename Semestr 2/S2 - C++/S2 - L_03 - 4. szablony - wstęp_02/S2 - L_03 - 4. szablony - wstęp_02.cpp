#include <iostream>

template<class T>
class Pair
{
    public:
        T mFirst;
        T mSecond;
        Pair(T first, T second)
        : mFirst(first), mSecond(second)
        {
        }

        void dispSum() const; //definicja poza klasą
        // {
        //     std::cout << mFirst + mSecond << std::endl;
        // }
};

template<class T> void Pair<T>::dispSum() const
{
    std::cout << mFirst + mSecond << std::endl;
}

int main()
{
    int first, second;
    std::cin >> first >> second;
    Pair pairInt(first, second);
    pairInt.dispSum();

    float firstFloat, secondFloat;
    std::cin >> firstFloat >> secondFloat;
    Pair pairFloat(firstFloat, secondFloat);
    pairFloat.dispSum();

//    Pair pair(2, 3.5); //musimy mu powiedzieć jaka ma być zmienna
    Pair<int> pair(2, 3.5);
}