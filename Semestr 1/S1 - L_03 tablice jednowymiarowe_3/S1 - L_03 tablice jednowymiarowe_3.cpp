#include <iostream>

int main()
{
    int array[5];
    array[0]=43;
    array[4]=100;

//array[5]=101 //taki zapis nie jest możliwy, nie ma indeksu 5, jesteś  poza tablicą

    std::cout << "Pierwszy element tablicy: " << array[0] << std::endl;
    std::cout << "Ostatni element tablicy: " << array[4] << std::endl;
}