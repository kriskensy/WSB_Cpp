#include <iostream> 
#include <ctime>

const int N = 7;
int array[N];

struct List
{
    List *next;
    int data;
};

int addElement(List* &TempList, int number)
{
    List *ptr;
    ptr = new List;
    ptr->data = number;
    ptr->next = TempList;
    TempList = ptr;
}

void deleteElement(List* &TempList)
{
    List *ptr = TempList;
    if(ptr)
    {
        TempList = ptr->next;
    }
}

void displayAll(List *TempList)
{
    for (List *ptr = TempList; ptr !=NULL; ptr = ptr->next)
    {
        std::cout << ptr->data << " ";
    }
}

bool empty(List *ptr)
{
    while(ptr)
        return 0;
    return 1;
}

int main()
{
    srand((unsigned)time(NULL));
    int i;
    List *L1 = NULL; //powołanie listy i jej deklaracja

    for(i = 0; i < N; i++)
    {
        array[i] = addElement(L1, rand()%100);
    }
    displayAll(L1);
    std::cout << std::endl;

    deleteElement(L1); //usuwa ostatni dodany element
    deleteElement(L1); //usuwa ostatni dodany element

    displayAll(L1);

    if(!empty(L1) == 0)
        std::cout << "stos jest pusty";
}