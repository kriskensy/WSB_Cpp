#include<iostream>
#include<memory>

class Element
{
    public:
        Element(int val, Element* next = nullptr)
        : mVal(val), mNext(next)
        {

        }

        Element* getNext() const {return mNext;}
        void setNext(Element* element) {mNext = element;}
        int getVal() const {return mVal;}

    private:
        Element* mNext;
        int mVal;
};

class List
{
    public:
        List(Element* first = nullptr, Element* last = nullptr)
        : mFirst(first), mLast(last)
        {

        }

        void push_back(int doAdd);
        void push_front(int doAdd);
        void pop_back();
        void pop_front();

        friend std::ostream& operator<<(std::ostream& out, const List& toDisp);

    private:
        Element* mFirst;
        Element* mLast;
};

std::ostream& operator<<(std::ostream& out, const List& toDisp)
{
    Element* listElement = toDisp.mFirst;
    while(listElement)
    {
//        out << "*mFirst = " << toDisp.mFirst ->getVal() << "*mLast = " << toDisp.mLast -> getVal() << listElement -> getVal() << " "; //to było tylko do testu
        out << listElement -> getVal() << " ";
        listElement = listElement -> getNext();
    }
    return out << std::endl;
}

void List::push_front(int toAdd)
{
    if(mFirst == nullptr)
    {
        mFirst = new Element(toAdd);
        mLast = mFirst;
    }
    else
    {
        mFirst = new Element(toAdd, mFirst);
    }
}

void List::pop_front()
{
    if(mFirst == nullptr)
        return;

        Element* toDelete = mFirst;
        mFirst = mFirst -> getNext();

        delete toDelete;
}

void List::push_back(int toAdd)
{
    if(mFirst == nullptr)
    {
        mFirst = new Element(toAdd);
        mLast = mFirst;
    }
    else
    {
        mLast -> setNext(new Element(toAdd));
        mLast = mLast -> getNext();
    }
}

void List::pop_back()
{
    if(mFirst -> getNext() == nullptr)
    {
        delete mFirst;
        mFirst = nullptr;
        mLast = nullptr;
    }
    Element* element = mFirst;
    while(element -> getNext() != mLast)
    {
        element = element -> getNext();
    }
//    std::cout << "------------->" << element -> getVal() << std::endl; //to było tylko do testu
    delete mLast;
    mLast = element;
    mLast -> setNext(nullptr);
}

int main()
{
    List myList;
    // myList.push_front(1);
    // myList.push_front(2);
    // myList.push_front(3);
    // std::cout << myList << std::endl;

    for(int i = 0; i < 5; ++i)
    {
        myList.push_back(i);
        std::cout << myList << std::endl;
    }

    myList.pop_back();
    myList.pop_back();

    std::cout << myList << std::endl;
}

// Napisz program, który realizuje listę jednokierunkową ze wskaźnikiem na początek i koniec listy przechowującą zmienne typu całkowitego.

// Klasa reprezentująca element listy zawiera:

// wskaźnik na następny element listy,
// zmienną typu całkowitego,
// konstruktor/konstruktory.
// Klasa reprezentująca listę zawiera:

// wskaźnik na pierwszy element listy,
// wskaźnik na ostatni element listy,
// metodą dodającą element na początek listy,
// metodę usuwającą element z początku listy,
// metodą dodającą element na koniec listy,
// metodę usuwającą element z koniec listy,
// metodą dodającą element do listy na pozycję wskazaną przez argument funkcji (licząc od zera),
// metodą usuwającą element z listy znajdujący się na pozycji wskazanej przez argument funkcji (licząc od zera),
// konstruktor/konstruktory.
// W funkcji main:

 

// stwórz obiekt reprezentujący listę jednokierunkową,
// dodaj M1 elementów na początek listy, gdzie M1 oraz wartości liczb wstawianych na listę są wprowadzane przez użytkownika,
// wyświetl listę,
// usuń N1 elementów z początku listy, gdzie N1 jest wprowadzane przez użytkownika,
// wyświetl listę,
// dodaj M2 elementów na koniec listy, gdzie M2 oraz wartości liczb wstawianych na listę są wprowadzane przez użytkownika,
// wyświetl listę,
// usuń N2 elementów z początku listy, gdzie N2 jest wprowadzane przez użytkownika,
// wyświetl listę.
// dodaj M3 elementów na koniec listy, gdzie M3, wartości liczb wstawianych na listę oraz pozycje, na które mają zostać wstawione są wprowadzane przez użytkownika,
// wyświetl listę,
// usuń N3 elementów z początku listy, gdzie N3 oraz pozycje, z których mają zostać usunięte są wprowadzane są wprowadzane przez użytkownika,
// wyświetl listę.