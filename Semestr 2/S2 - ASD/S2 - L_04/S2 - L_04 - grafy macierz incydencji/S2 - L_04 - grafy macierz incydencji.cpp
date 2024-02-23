#include <iostream>
#include <iomanip>

int main()
{
    int n, m, i, j, v1, v2;
    signed char ** A;

    std::cin >> n >> m;               // Czytamy liczbę wierzchołków i krawędzi
    A = new signed char * [n]; // Tworzymy tablicę wskaźników

    for(i = 0; i < n; i++)
        A [i] = new signed char [m]; // Tworzymy wiersze

// Macierz wypełniamy zerami
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++) A [i][j] = 0;

// Odczytujemy kolejne definicje krawędzi
    for(i = 0; i < m; i++)
    {
        std::cin >> v1 >> v2;    // Wierzchołek startowy i końcowy krawędzi
        A [v1][i] = 1;  // Wierzchołek startowy
        A [v2][i] = -1; // Wierzchołek końcowy
    }
    std::cout << std::endl;

// Wypisujemy zawartość macierzy incydencji
    std::cout << "   ";
    for(i = 0; i < m; i++) std::cout << std::setw(3) << i;
    std::cout << std::endl << std::endl;
    for(i = 0; i < n; i++)
    {
        std::cout << std::setw ( 3 ) << i;
        for(j = 0; j < m; j++) std::cout << std::setw(3) << (int) A [i][j];
        std::cout << std::endl;
    }

// Usuwamy macierz
    for(i = 0; i < n; i++) delete [] A [i];
    delete [] A;
    return 0;
}