#include <iostream>
#include <iomanip>

class slistEl
{
    public:
        slistEl * next;
        int v;
};

slistEl ** graf; // Tablica list sąsiedztwa grafu
slistEl ** T;    // Tablica list sąsiedztwa drzewa rozpinającego
bool * visited;  // Tablica odwiedzin

// Rekurencyjna funkcja tworzenia drzewa rozpinającego w głąb
// v - numer wierzchołka startowego, reszta zmiennych jest globalna
void DFSTree(int v)
{
    slistEl *p, *r;
    int u;

    visited[v] = true;      // Oznaczamy wierzchołek jako odwiedzony
    for(p = graf[v]; p; p = p -> next) // Przeglądamy sąsiadów
    {
        u = p -> v;                // u - numer sąsiada
        if(!visited[u])     // Interesują nas tylko nieodwiedzeni sąsiedzi
        {
            r = new slistEl;       // Dodajemy u do listy T [ v ] 
            r -> v = u;
            r -> next = T[v];
            T[v] = r;
            DFSTree(u);         // Rekurencyjnie tworzymy drzewo
        }
    }
}

int main()
{
    int n, m, i, v1, v2;
    slistEl *p, *r;

    std::cin >> n >> m;              // Czytamy liczbę wierzchołków i krawędzi
    graf = new slistEl * [n]; // Tworzymy tablicę list sąsiedztwa grafu
    T = new slistEl * [n]; // Tworzymy tablicę list sąsiedztwa drzewa rozpinającego
    visited = new bool [n];   // Tworzymy tablicę odwiedzin

// Tablice wypełniamy pustymi listami
    for(i = 0; i < n; i++)
    {
        graf [i] = T [i] = NULL;
        visited [i] = false;
    }

// Odczytujemy kolejne definicje krawędzi
    for(i = 0; i < m; i++)
    {
        std::cin >> v1 >> v2;         // Wierzchołek startowy i końcowy krawędzi
        p = new slistEl;         // Tworzymy nowy element
        p -> v = v2;           // Numerujemy go jako v2
        p -> next = graf [v1];  // Dodajemy go na początek listy A [ v1 ] 
        graf [v1] = p;
        p = new slistEl;         // Teraz krawędź w odwrotną stronę
        p -> v = v1;
        p -> next = graf [v2];
        graf [v2] = p;
    }

// Tworzymy drzewo rozpinające w głąb
    std::cin >> v1;                 // Czytamy wierzchołek startowy
    DFSTree(v1);

// Wyświetlamy tablicę list sąsiedztwa drzewa rozpinającego
    std::cout << std::endl;
    for(i = 0; i < n; i++)
    {
        std::cout << std::setw(2) << i << ":";
        for(p = T [i]; p; p = p -> next) std::cout << std::setw(3) << p -> v;
        std::cout << std::endl;
    }

// Usuwamy dynamiczne struktury danych
    for(i = 0; i < n; i++)
    {
        p = graf [i];
        while(p)
        {
            r = p;
            p = p->next;
            delete r;
        }

        p = T [i];
        while(p)
        {
            r = p;
            p = p -> next;
            delete r;
        }
    }

    delete [] graf;
    delete [] T;
    delete [] visited;
    std::cout << std::endl;
    return 0;
}