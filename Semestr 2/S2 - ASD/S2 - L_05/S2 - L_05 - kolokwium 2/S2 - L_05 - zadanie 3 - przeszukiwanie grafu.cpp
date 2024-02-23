/*
Do przejścia grafgu wykorzystuje się w tej implementacji macierz sąsiedztwa i kolejkę (lista jednokierunkowa). W kolejce umieszcza się numer wierzchołka startowego i oznacza go jako odwiedzony. W głównej pętli w funkcji BFS odczytuje się z kolejki numer wierzchołka i ten odczytaany numer usuwa z kolejki, po czym przegląda się jego sąsiadów  i szuka nieodwiedzonego sąsiada. Nnstępnie umieszcza się go w kolejce i oznacza jako odwiedzonego.
W funkcji main program tworzy tablicę wskaźników  i tablicę odwiedzin. Tworzy wierze macierzy i wypełnia je zerami (zeruje tablicę odwiedzin. Odczytuje kolejno zdefiniowane krawędzie podane przez wierzchołki startowe i końcowe. Algorytm BFS przechoodzi graf wszerz.
*/

#include <iostream>
#include <iomanip>

class slistEl
{
    public:
    slistEl * next;
    int data;
};

int n;// Liczba wierzchołków
char ** A;// Macierz sąsiedztwa
bool * visited;// Tablica odwiedzin

void BFS(int v)//przejście BFS
{
    int i;
    slistEl *q, *head, *tail; //kolejka
//wierzchołek umieszczony w kolejce i oznaczony jak odwiedzony
    q = new slistEl;
    q -> next = NULL;
    q -> data = v;
    head = tail = q;
    visited[v] = true;

    while(head)
    {
        v = head -> data;//odczytanie wierzchołka z kolejki i jego usunięcie
        q = head;
        head = head -> next;
        if(!head) tail = NULL;
        delete q;
        std::cout << std::setw(3) << v;

        for(i = 0; i < n; i++)
            if((A[v][i] == 1) && !visited[i])
            {
                q = new slistEl;//umieszczenie w kolejce nieodwiedzonych sąsiadów i oznaczenie jako odwiedzonych
                q -> next = NULL;
                q -> data = i;
                if(!tail) head = q;
                else tail -> next = q;
                tail = q;
                visited[i] = true;
            }
    }
}

int main()
{
    int m, i, j, v1, v2;
    std::cin >> n >> m;
    A = new char * [n];
    visited = new bool [n];
//utworzenie macierzy i następnie jej wyzerowanie
    for(i = 0; i < n; i++)
        A [i] = new char [n];

    for(i = 0; i < n; i++)
    {
        visited [i] = false;
        for(j = 0; j < n; j++) A [i][j] = 0;
    }

//odczytanie krawędzi
    for(i = 0; i < m; i++)
    {
        std::cin >> v1 >> v2;
        A [v1][v2] = 1;
    }
    std::cout << std::endl;

//przejście grafu
    BFS(0);

//usunięcie macierzy
    for(i = 0; i < n; i++)
        delete A[i];
    delete [] A;
    delete [] visited;
    std::cout << std::endl;
    return 0;
}