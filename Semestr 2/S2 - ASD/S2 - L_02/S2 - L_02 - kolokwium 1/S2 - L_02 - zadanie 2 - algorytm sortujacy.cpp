/*
Zadanie 2
Proszę o zaimplementowanie dowolnego algorytmu sortującego oraz opisanie zasady jego działania.
*/

/*
Sortowanie przez selekcję. Złożoność O(n^2)
W zbiorze szukam najmniejszego elementu i zamieniam go z elementem stojącym na pozycji pierwszej. Kolejno szukam następnego najmniejszego elementu ale tym razem w zbiorze pomniejszonym o pierwszy element i wstawiam go na pozycję drugą. Powtarzam operację na coraz to mniejszych zbiorach aż do uzyskania zbioru jednoelementowego. 
*/
#include <iostream>
#include <ctime>

int main()
{
    srand((unsigned)time(NULL)); //do losowania przypadkowych liczb
    const int n = 10;
    int array[n];

//wypełnienie tablicy losowymi liczbami

    std::cout << "before sorting" << std::endl;
    for(int i = 0; i < n; i++)
    {
        array[i] = rand()%100;
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;

//sortowanie
    for(int j = 0; j < n; j++)
    {
        int min = j; //przechowuję indeks z najmniejszą wartością
        for(int i = j + 1; i < n; i++)
            if(array[i] < array[min]) min = i; //w pętli wyszukuję min element w podzbiorze nieposortowanym

            std::swap(array[min], array[j]); //zamieniam element najmniejszy w podzbiorze z pierwszym nieposortowanym
    }

    std::cout << "after sorting" << std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
}