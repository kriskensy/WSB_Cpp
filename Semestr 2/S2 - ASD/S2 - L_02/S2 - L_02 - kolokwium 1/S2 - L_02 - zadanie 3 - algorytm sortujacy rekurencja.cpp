/*
Zadanie 3
Proszę o zaimplementowanie dowolnego algorytmu sortującego działającego przy pomocy rekurencji oraz opisanie zasady jego działania.
*/

/*
Quicksort. Złożoność O(n*logn) ale w sytuacji pesymistycznej może wynosić O(n^2).
Technika "dziel i zwyciężaj". Wg ustalonego schematu wybieram jeden element w sortowanej tablicy, tzw. pivot. Może to być element losowym. Następnie ustawiam elementy nie większe na lewo tej wartości, natomiast nie mniejsze na prawo. W ten sposób powstaną  dwie części tablicy (niekoniecznie równe), gdzie w pierwszej części znajdują się elementy nie większe od drugiej. Następnie każdą z tych podtablic sortuję osobno wg tego samego schematu. 
*/
#include <iostream>
#include <ctime>

const int N = 10;
int array[N];

void quicksort(int left, int right)
{
    int i, j, pivot; //i, j to wskaźniki

    i = (left + right) / 2;
    pivot = array[i]; //wyznaczam "środkowy" element na pivot
    array[i] = array[right]; //przesuwam pivot na sam koniec, "zabezpieczam" go

    for(j = i = left; i < right; i++)
        if(array[i] < pivot)
        {
            std::swap(array[i], array[j]); //zamieniam elementy
            j++; //przesuwam wskaźnik
        }

    array[right] = array[j]; 
    array[j] = pivot;

//rekurencyjnie sortuję obie części, podzbiory
    if(left < j - 1)  quicksort(left, j - 1); //część lewa, elementy nie większe od pivotu
    if(j + 1 < right) quicksort(j + 1, right); //część prawa, elementy nie mniejsze od pivotu
}

int main()
{
    int i;

    srand((unsigned)time(NULL));

//wypełnienie tablicy losowymi liczbami

    std::cout << "before sorting" << std::endl;
    for(i = 0; i < N; i++)
    {
        array[i] = rand() % 100;
        std::cout << array[i] << " ";
    }

//sortowanie
    quicksort(0, N - 1);

    std::cout << std::endl;
    std::cout << "after sorting" << std::endl;
    for(i = 0; i < N; i++)
    {
        std::cout << array[i] << " ";
    }
}