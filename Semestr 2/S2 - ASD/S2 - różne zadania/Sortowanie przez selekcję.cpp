/*
Szukam najmniejszego elementu w zbiorze i zamieniam go z elementem stojącym na pozycji pierwszej. Następnie szukam znowu elementu najmniejszego w zbiorze pominiętym o pierwszy element i wstawiam go na pozycję drugą. Powtarzam do momentu otrzymania jednoelementowego podzbioru. 
*/
#include <iostream>
#include <ctime>

int main()
{
    srand((unsigned)time(NULL));
    const int n = 10;
    int array[n];

    for(int i = 0; i < n; i++)
    {
        array[i] = rand() % 100;
        std::cout << array[i] << " ";
    }
    
    std::cout << std::endl;
    std::cout << "Zaczynam sortowanie przez selekcje" << std::endl;

    for(int j = 0; j < n-1; j++)
    {
        int min = j;
        for(int i = j+1; i < n; i++)
        
            if(array[i] < array[min]) min = i;
                std::swap(array[min], array[j]);
    }

    std::cout << "Po sortowaniu: " << std::endl;

    for(int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
}