/*
implementacja kolejki FIFO
Proszę o napisanie algorytmu odwzorowującego zachowanie kolejki FIFO(na omawianych listach).
Który będzie wykonywał następujące operacje:
- sprawdzenie, czy kolejka jest pusta.
- odczyt elementów kolejki
- zapis elementu na koniec kolejki
- usunięcie elementu z kolejki
*/

#include <iostream>

//lista jednokierunkowa
struct List
{
    List *next;
    int data;
};

//sprawdzanie czy kolejka jest pusta, jeśli tak to procedura zwraca 0, w przeciwnym przypadku zwraca ilość elementów
unsigned listSize(List *ptr)
{
    unsigned counter = 0; //licznik nie może być ujemny
    while(ptr)
    {
        counter++;
        ptr = ptr->next;
    }
    return counter;
}

//procedura wyświetlająca elementy listy
void present(List *TempList)
{
    for (List *ptr = TempList; ptr !=NULL; ptr = ptr->next)
    {
        std::cout << ptr->data << std::endl;
    }
}

//dodawanie elementów do końca listy
void elementsAddition(List* &front, int number)
{
    List *ptr, *element;
    element = new List; //utworzenie nowego elementu
    element->next = NULL; //inicjalizacja nowego elementu
    element->data = number;
    ptr = front;
    
    if(ptr)
    {
        while(ptr->next) ptr = ptr->next;
        ptr->next = element;
    }
    else
    {
    front = element;
    }
}

//usuwanie pierwszego dodanego elementu z listy
void deleteFrontElement(List* &front)
{
    List *ptr = front;
    if(ptr)
    {
        front = ptr->next;
        delete ptr;
    }
}

int main()
{
    List *L1 = NULL; //powołanie listy i jej deklaracja

    std::cout << "Ilosc elementow listy po utworzeniu: " << listSize(L1) << std::endl;

//dodanie kilku elementów do listy
    elementsAddition(L1, 1);
    elementsAddition(L1, 2);
    elementsAddition(L1, 3);
    elementsAddition(L1, 16);
    elementsAddition(L1, 99);
    elementsAddition(L1, 47);
    elementsAddition(L1, 13);

    present(L1);
    std::cout << "Ilosc elementow listy po dodaniu elementow: " << listSize(L1) << std::endl;

    std::cout << std::endl;

    deleteFrontElement(L1);
    present(L1);
    std::cout << "Ilosc elementow listy po usunieciu pierwszego elementu: " << listSize(L1) << std::endl;
}