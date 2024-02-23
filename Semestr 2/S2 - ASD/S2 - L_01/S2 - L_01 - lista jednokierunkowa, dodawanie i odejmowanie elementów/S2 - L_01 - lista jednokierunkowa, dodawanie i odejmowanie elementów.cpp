#include <iostream> 

//lista jednokierunkowa
struct List
{
    List *next;
    int data;
};

//dodawanie elementów do listy
void elementsAddition(List* &TempList, int number)
{
    List *ptr;
    ptr = new List;
    ptr->data = number;
    ptr->next = TempList;
    TempList = ptr;
}

//usuwanie elementu listy
void deleteFrontElements(List* &TempList)
{
    List *ptr = TempList;
    if(ptr)
    {
        TempList = ptr->next;
    }
}

//procedura wyświetlająca elementy listy, sposób 1
void present(List *TempList)
{
    for (List *ptr = TempList; ptr !=NULL; ptr = ptr->next)
    {
        std::cout << ptr->data << std::endl;
    }
}

//procedura wyświetlająca elementy listy, sposób 2
/*void present(List *TempList)
{
    List *ptr = TempList;
    while (ptr != NULL)
    {
        std::cout << ptr-> data << std::endl;
        ptr = ptr->next;
    }
}*/

int main()
{
    List *L1 = NULL; //powołanie listy i jej deklaracja

    elementsAddition(L1, 1);
    elementsAddition(L1, 2);
    elementsAddition(L1, 3);
    elementsAddition(L1, 16);
    elementsAddition(L1, 99);
    elementsAddition(L1, 47);
    elementsAddition(L1, 13);

    present(L1);
    std::cout << std::endl;
    deleteFrontElements(L1); //usuwa ostatni dodany element

    present(L1);
}