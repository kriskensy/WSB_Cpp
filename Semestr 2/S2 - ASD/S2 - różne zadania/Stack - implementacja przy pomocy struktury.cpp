#include <iostream>

class Stack
{
    public:
        Stack(int newOne); //konstruktor całego stosu
        ~Stack(); //destruktor całego stosu
        bool empty(void);
        void displayAll();
        int push(int newElement);
        void pop();
        int top();

    private:
        int N; //rozmiar tablicy
        int sptr; //wskaźnik stosu
        int *Array; //tablica dynamiczna
        int *temp; //zmienna pomocnicza
};

Stack::Stack(int newOne)
{
    N = newOne;
    Array = new int [newOne];
    sptr = 0;
}
Stack::~Stack()
{
    delete [] Array;
}

    bool Stack::empty(void)
    {
        return !sptr;
    }

    void Stack::displayAll()
    {//TODO: napisz poprawnie
        while(sptr)
        std::cout << Array[sptr] << " ";
    }
/*    void Stack::displayAll()
    {
        for(int i = 0; i < N; i++)
        {
            std::cout << Array[i] << " ";
        }
    std::cout << std::endl;
    }*/

    int Stack::push(int newElement)
    {
        if(sptr < N)
            Array[sptr++] = newElement;
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
    Stack S1(7);

    S1.push(5);
    S1.push(49);
    S1.push(13);
    S1.push(2);
    S1.push(84);
    S1.push(42);
    S1.push(63);
    S1.push(21);

    S1.displayAll();
    std::cout << S1.top() << std::endl;

    S1.pop();
    S1.pop();
    S1.pop();
    std::cout << S1.top() << std::endl;
    S1.displayAll();
}