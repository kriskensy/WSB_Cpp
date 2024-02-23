//Cykl jest ścieżką zamkniętą prowadzącą przez wierzchołki grafu w taki sposób, iż rozpoczyna się i kończy w tym samym wierzchołku.
//Proszę o zaimplementowanie kodu, który będzie rozpoznawał cykle w grafie.

#include <iostream>

class ElementList
{
    public:
        ElementList* next;
        int value;
};

class Stack
{
    public:
        Stack() {listOfElements = NULL;}
        ~Stack() {while(listOfElements) pop();}

        bool empty()
        {
            return !listOfElements;
        }

        int top()//szczyt stosu
        {
            return listOfElements -> value;
        }

        void push(int value)//dodaje na stos
        {
            ElementList* element = new ElementList;
            element -> value = value;
            element -> next = listOfElements;
            listOfElements = element;
        }

        void pop()//usuwa ze stosu
        {
            if(listOfElements)
            {
                ElementList* element = listOfElements;
                listOfElements = listOfElements -> next;
                delete element;
            }
        }

    private:
        ElementList * listOfElements;
};

//wyszukiwanie cyklu w grafie
bool findCycle(ElementList** graph, int value, int node, Stack& listOfElements, bool* visited)
{
    int u;
    ElementList* p;

    visited [node] = true;
    p = graph [node];
    while(p)
    {
        u = p -> value;
        if(u != listOfElements.top())//wierzchołek, z którego przyszliśmy jest wyłączony
        {
            listOfElements.push(node);//wierzchołek bieżący trrafia na stos
            if(u == value) return true;//cykl znaleziony
            if(!visited [u] && findCycle(graph, value, u, listOfElements, visited)) return true;
            listOfElements.pop();
        }
        p = p -> next;
    }
    return false;
}

int main()
{
    int nodes, edges, i, j, u, v1, v2;
    ElementList* p, *r, **Array;
    bool* visited;
    Stack listOfElements;

    std::cin >> nodes >> edges;
//tablica list sąsiedztwa jest wypełniona pustymi listami
    Array = new ElementList* [nodes];
    for(i = 0; i < nodes; i++) Array [i] = NULL;

//odczytanie definicji krawędzi
    for(i = 0; i < edges; i++)
    {
        std::cin >> v1 >> v2;//wierzchołek startowy i końcowy krawędzi
        p = new ElementList;
        p -> value = v2;
        p -> next = Array [v1];
        Array [v1] = p;
        p = new ElementList;//krawędź w drugą stronę, bo graf jest nieskierowany
        p -> value = v1;
        p -> next = Array [v2];
        Array [v2] = p;
    }
    std::cout << std::endl;

//utworzenie tablicy odwiedzin, przejście przez wierzchołki i wyzerowanie tablicy
    visited = new bool [nodes];      
    for(i = 0; i < nodes; i++)
    {
        for(j = 0; j < nodes; j++)
            visited [ j ] = false;

        listOfElements.push (-1);//znacznik początku ścieżki

        std::cout << i;//wierzchołek startowy cyklu

        if(!findCycle(Array, i, i, listOfElements, visited))
        {
            listOfElements.pop();
            std::cout << " - there is no cycle" << std::endl;
        }
        else
//wypisanie cyklu
        while(!listOfElements.empty())
        {
            u = listOfElements.top(); listOfElements.pop();
            if(u > -1) std::cout << " " << u;
            else
            std::cout << std::endl;
        }
    }
    delete [] visited;

    for(i = 0; i < nodes; i++)
    {
        p = Array [i];
        while(p)
        {
            r = p;
            p = p -> next;
            delete r;
        }
    }
    delete [] Array;
    return 0;
}