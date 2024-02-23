#include <iostream>
#include <iomanip>

class slistEl
{
    public:
    slistEl * next;
    int data;
};

int n;                   // Liczba wierzchołków
char ** A;               // Macierz sąsiedztwa
bool * visited;          // Tablica odwiedzin

void BFS(int v)//przejście BFS
{
    int i;
    slistEl *q, *head, *tail; // Kolejka

    q = new slistEl;        // W kolejce umieszczamy v
    q -> next = NULL;
    q -> data = v;
    head = tail = q;
    visited[v] = true;   // Wierzchołek v oznaczamy jako odwiedzony

    while(head)
    {
        v = head -> data;       // Odczytujemy v z kolejki
        q = head;             // Usuwamy z kolejki odczytane v
        head = head -> next;
        if(!head) tail = NULL;
        delete q;
        std::cout << std::setw(3) << v;

        for(i = 0; i < n; i++)
            if((A[v][i] == 1) && !visited[i])
            {
                q = new slistEl; // W kolejce umieszczamy nieodwiedzonych sąsiadów
                q -> next = NULL;
                q -> data = i;
                if(!tail) head = q;
                else tail -> next = q;
                tail = q;
                visited[i] = true; // i oznaczamy ich jako odwiedzonych
            }
    }
}

int main()
{
    int m, i, j, v1, v2;
    std::cin >> n >> m;              // Czytamy liczbę wierzchołków i krawędzi
    A = new char * [n];       // Tworzymy tablicę wskaźników
    visited = new bool [n];   // Tworzymy tablicę odwiedzin

    for(i = 0; i < n; i++)
        A [i] = new char [n]; // Tworzymy wiersze

// Macierz wypełniamy zerami
    for(i = 0; i < n; i++)
    {
        visited [i] = false; // Zerujemy tablicę odwiedzin
        for(j = 0; j < n; j++) A [i][j] = 0;
    }

// Odczytujemy kolejne definicje krawędz
    for(i = 0; i < m; i++)
    {
        std::cin >> v1 >> v2;    // Wierzchołek startowy i końcowy krawędzi
        A [v1][v2] = 1; // Krawędź v1->v2 obecna
    }
    std::cout << std::endl;

// Przechodzimy graf wszerz
    BFS(0);

// Usuwamy macierz
    for(i = 0; i < n; i++)
        delete A[i];
    delete [] A;
    delete [] visited;
    std::cout << std::endl;
    return 0;
}