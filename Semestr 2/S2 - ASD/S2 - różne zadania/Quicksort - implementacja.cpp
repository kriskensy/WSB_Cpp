/*
Technika "dziel i zwyciężaj". Wg ustalonego schematu wybierany jest jeden element w sortowanej tablicy, pivot. Może on być elementem środkowym, pierwszym, ostatnim, losowym lub wybranym według jakiegoś innego schematu dostosowanego do zbioru danych. Następnie ustawiamy elementy nie większe na lewo tej wartości, natomiast nie mniejsze na prawo. W ten sposób powstaną  dwie części tablicy (niekoniecznie równe), gdzie w pierwszej części znajdują się elementy nie większe od drugiej. Następnie każdą z tych podtablic sortujemy osobno według tego samego schematu. 
*/
#include <iostream>
#include <ctime>

const int N = 20;
int array[N];

void quicksort(int left, int right)
{
    int i, j, pivot;

    i = (left + right) / 2;
    pivot = array[i]; //wyznaczam środkowy element na pivot
    array[i] = array[right]; //przesuwam pivot na sam koniec

    for(j = i = left; i < right; i++)
        if(array[i] < pivot)
        {
            std::swap(array[i], array[j]);
            j++;
        }

    array[right] = array[j]; 
    array[j] = pivot;

    if(left < j - 1)  quicksort(left, j - 1);
    if(j + 1 < right) quicksort(j + 1, right);
}

int main()
{
    int i;

    srand((unsigned)time(NULL));

//wypełnienie tablicy losowymi liczbami
    for(i = 0; i < N; i++)
    {
        array[i] = rand() % 100;
        std::cout << array[i] << " ";
    }

//sortowanie
    quicksort(0, N - 1);
  
    std::cout << std::endl;
    std::cout << "Po sortowaniu" << std::endl;

    for(i = 0; i < N; i++)
    {
        std::cout << array[i] << " ";
    }
}