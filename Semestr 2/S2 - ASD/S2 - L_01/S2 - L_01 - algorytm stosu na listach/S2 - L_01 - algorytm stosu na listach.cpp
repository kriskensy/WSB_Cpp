#include <iostream> 

const int MAXINT = -2147483647;

class stack
{
private:
    int n; //rozmiar tablicy
    int sptr; //wskaźnik stosu
    int *S; //tablica dynamiczna

public:
    stack(int x); //konstruktor
    ~stack(); //destruktor
    bool empty(void);
    int top(void);
    void push(int v);
    void pop(void);
    void displayAll();
};

stack::stack(int x)
{
    n = x;
    S = new int [x];
    sptr = 0;
}

stack::~stack()
{
    delete [] S;
}

bool stack::empty()
{
    return !sptr;
}

int stack::top(void)
{
    if(sptr)
    return S[sptr-1];

    return -MAXINT;
}

void stack::push(int v)
{
    if(sptr < n)
    S[sptr++] = v;
}

void stack::pop()
{
    if(sptr) sptr--;
}

void stack::displayAll()
{
    for(int i=0; i < n; i++) //rozmiar tablicy  jest znany - n. Dlatego pętla for
    {
        std::cout << S[i] << " ";
    }
}

int main()
{
    stack Temp(7);

    for(int i = 1; i <= 7; i++)
        Temp.push(i);

    Temp.pop();
    Temp.pop();
    Temp.pop();
    std::cout << Temp.top() <<std::endl;

    Temp.displayAll();
}