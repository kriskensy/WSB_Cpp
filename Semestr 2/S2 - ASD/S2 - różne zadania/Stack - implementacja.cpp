#include <iostream>

const int arraySize = 7;

class Stack
{
    public:
        Stack(int S); //konstruktor całego stosu
        ~Stack(); //destruktor całego stosu
        bool isEmpty();
        bool isFull();
        void displayAll();
        int push(int element);
        void pop();
        int top();

    private:
        int sptr; //wskaźnik stosu
        int *Array; //tablica dynamiczna
};

Stack::Stack(int S)
{
    Array = new int [arraySize];
    sptr = 0;
}
Stack::~Stack()
{
    delete [] Array;
}

    bool Stack::isEmpty()
    {
        if(top() == 0)
        std::cout << "stack is empty" << std::endl;
        return !sptr;
    }

    bool Stack::isFull()
    {
        if(top() == Array[arraySize - 1])
        std::cout << "stack is full" << std::endl;
        return sptr;
    }

    void Stack::displayAll()
    {
        for(int i = 0; i < arraySize; i++)
        {
            std::cout << Array[i] << " ";
        }
    std::cout << std::endl;
    }

    int Stack::push(int element)
    {
        if(sptr < arraySize)
            Array[sptr++] = element;
    }

    void Stack::pop()
    {
        if(sptr) sptr--;
    }
    int Stack::top()
    {
        if(sptr)
        return Array[sptr-1];
    }

int main()
{
    Stack S1(arraySize);
    S1.isEmpty();

    S1.push(5);
    S1.push(49);
    S1.push(13);
    S1.push(2);
    S1.push(84);
    S1.push(42);
    S1.push(63);

    S1.displayAll();
    S1.isFull();

    std::cout << S1.top() << std::endl;

    S1.pop();
    S1.pop();
    S1.pop();
    std::cout << S1.top() << std::endl;

}