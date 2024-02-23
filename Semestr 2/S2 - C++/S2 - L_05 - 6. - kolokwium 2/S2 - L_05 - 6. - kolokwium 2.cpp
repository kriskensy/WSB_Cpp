#include<iostream>

class ListElement
{
    public:
      ListElement* mNext;

        ListElement(double variable, ListElement* next = nullptr)
        : mVariable(variable), mNext(next) {}

        ListElement* getNext() const {return mNext;}
        double getValue() const {return mVariable;}

    private:
        double mVariable;
};

class List
{
    public:
        List(ListElement* first = nullptr)
        : mFirst(first) {}

        friend std::ostream& operator<<(std::ostream& out, const List& toDisp);
        void addElement(double toAdd);
        void deleteElement(double toDelete);

    private:
        ListElement* mFirst;
};

std::ostream& operator<<(std::ostream& out, const List& toDisp)
{
    ListElement* listEement = toDisp.mFirst;
    while(listEement)
    {
        out << listEement -> getValue() << " ";
        listEement = listEement -> getNext();
    }
    return out;
}

void List::addElement(double toAdd)
{
    ListElement* element = new ListElement(toAdd);

    if (mFirst == nullptr)
    {
        mFirst = element;
    }
    else if(toAdd < mFirst -> getValue())
    {
        element -> mNext = mFirst;
        mFirst = element;
    }
    else
    {
        ListElement* temp = mFirst;
        while(temp -> getNext() != nullptr && toAdd > temp -> getNext() -> getValue())
        {
            temp = temp -> getNext();
        }
        element -> mNext = temp -> getNext();
        temp -> mNext = element;
    }
}

void List::deleteElement(double toDelete)
{
    while (mFirst != nullptr && mFirst -> getValue() == toDelete)
    {
        mFirst = mFirst -> getNext();
    }

    ListElement*  temp = mFirst;

    while (temp != nullptr && temp -> getNext() -> getValue() == toDelete)
    {
        if(temp -> getNext() -> getValue() == toDelete)
        {
            temp -> mNext = temp -> getNext() -> getNext();
        }
        else
        {
            temp = temp -> getNext();
        }
    }
}

int main()
{
    List myList;
    int M = 0;
    int N = 0;

    std::cin >> M;

    for(int i = 0; i < M; ++i)
    {
        double variable;
        std::cin >> variable;
        myList.addElement(variable);
    }
//    std::cout << myList << std::endl;

    std::cin >> N;

    for(int i = 0; i < N; ++i)
    {
        double variable;
        std::cin >> variable;
        myList.deleteElement(variable);
    }
    std::cout << myList << std::endl;
}

// Napisz program, który realizuję listę jednokierunkową przechowującą zmienne typu double w rosnącej kolejności. W ramach programu należy zaimplementować dwie klasy.

// Pierwsza z nich reprezentuję element listy i zawiera:
// • wskaźnik na następny element listy,
// • zmienną typu double,
// • konstruktor ustawiający powyższe atrybuty.

// Druga klasa reprezentuję listę zawiera:
// • wskaźnik na pierwszy element listy,
// • metodę wyświetlającą wszystkie elementy na znajdujące się na liście,
// • metodę dodającą element do listy zgodnie z przyjętą kolejnością,
// • metodę usuwającą element o podanej wartości. W przypadku braku elementów o podanej wartości metoda nic nie robi. Natomiast w przypadku kilku elementów o takiej samej wartości metoda usuwa wszystkie występującą na liście.

// W funkcji main należy:
// 1. Stworzyć obiekt klasy przedstawiającej listę.
// 2. Dodać M (podane przez użytkownika) elementów do listy. Informacje dotyczące kolejnych elementów są wprowadzane przez użytkownika BEZ poprzedzających komunikatów.
// 3. Usunąć N elementów o wartościach podanych przez użytkownika. Informacje dotyczące kolejnych elementów są wprowadzane przez użytkownika BEZ poprzedzających komunikatów.
// 4. Wyświetlić zwartość listy używając odpowiedniej metody z klasy reprezentującej listę.
// Używanie wbudowanych struktur danych jest zabronione.
// Sprawdzanie poprawności wprowadzanych danych nie jest wymagane.
// Przykładowo dla argumentów wejściowych:
// 4 1 2 3 4 2 2 3
// program powinien wyświetlić
// 1 4