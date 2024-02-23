/*
Zadanie 1
Proszę o napisanie algorytmu odwzorowującego zachowanie STOSu (na omawianych listach).
Który będzie wykonywał następujące operacje:
- sprawdzenie, czy lista jest pusta.
- odczyt elementów listy
- zapis elementu do listy
- usunięcie elementu z listy
*/

#include <iostream>

const int arraySize = 10; //przypisanie rozmiaru tablicy

class Stack
{
    public:
        Stack(int S); //konstruktor
        ~Stack(); //destruktor
        bool isEMpty(); //sprawdzenie czy stos jest pusty, jeśli tak to nie mogę nic więcej z niego ściągać
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
        Array = new int[arraySize];
        sptr = 0;
    }

    Stack::~Stack()
    {
        delete [] Array;
    }

    bool Stack::isEMpty()
    {
        if(top() == 0)
        std::cout << "stack is empty!" << std::endl;
        return !sptr;
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
        return Array[sptr - 1];
    }

int main()
{
    Stack S1(arraySize); //utworzenie stosu
    S1.isEMpty(); //tu stos jest jeszcze pusty

    S1.push(5);
    S1.push(8);
    S1.push(13);
    S1.push(44);
    S1.push(1);
    S1.push(79);
    S1.push(56);
    S1.push(23);
    S1.push(67);
    S1.push(19);

    S1.push(99); //element się nie doda bo stos jest już pełny
    S1.isEMpty(); //nie wywoła się bo na stosie leżą już elementy
    S1.displayAll();
}