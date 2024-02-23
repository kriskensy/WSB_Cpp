#include <iostream>

class Stack
{
    public:
        Stack() {stackCounter = 0; flag = 1; lastElement = NULL;} //konstruktor
        ~Stack() //destruktor, zwolnienie pamięci dla elementów stosu
        {
            while(lastElement != NULL)
            {
                temp = lastElement -> prev;
                delete lastElement;
                lastElement = temp;
            }
        }
        const int error = 99999999999; //wartość do przypisania błędu
        unsigned int size() {return stackCounter;} //zwraca liczbę elementów w kolejce

        void push(int head) //dodaje element nas szczyt stosu
        {
            if(flag)
            {
                flag = 0;
                lastElement = new knot;
                lastElement -> element = head;
                lastElement -> prev = NULL;
            }
            else
            {
                temp = new knot;
                temp -> element = head;
                temp -> prev = lastElement;
                lastElement = temp;
            }
            ++stackCounter;
        }

        int pop() //usunięcie elementu ostatniego
        {
            if(lastElement == NULL) return 0; //gdy stos jest pusty metoda nie ma co usuwać

            temp = lastElement -> prev;
            delete lastElement;
            lastElement = temp;
            --stackCounter;

            return 1;
        }

        int valueOfHead() //zwraca ostatni element na stosie
        {
            if(!empty())
                return lastElement -> element;
            return error;
        }

        bool empty()
        {
            if(stackCounter == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

    private:
        bool flag; //flaga określająca czy w kolejce już coś się pojawiło
        unsigned int stackCounter; //licznik elementów na stosie
        struct knot
        {
            int element; //wartość elementu stosu
            knot *prev; //wskaźnik na poprzedni element
        };
        knot *lastElement; //ostatni element na stosie
        knot *temp; //zmienna pomocnicza
        int *array; //tablica dynamiczna

};

int main()
{
    Stack stack; //utworzenie stosu

    stack.push(9);
    stack.push(14);
    stack.push(65);
    stack.push(8);
    stack.push(17);
    stack.push(22);
    stack.push(77);
    stack.push(26);

    std::cout << "elements on stack: " << stack.size() << std::endl;
    std::cout << "stack head is: " << stack.valueOfHead() << std::endl;

    stack.pop();
    stack.pop();
    stack.pop();

    std::cout << "now stack head is: " << stack.valueOfHead() << std::endl;

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

    if(stack.empty())
        std::cout << "stack is empty!" << std::endl;
    else
        std::cout << "there are " << stack.size() << " elements on stack" << std::endl;

    if(!stack.pop())
        std::cout << "you cannot delete any elements, stack is empty" << std::endl;

}