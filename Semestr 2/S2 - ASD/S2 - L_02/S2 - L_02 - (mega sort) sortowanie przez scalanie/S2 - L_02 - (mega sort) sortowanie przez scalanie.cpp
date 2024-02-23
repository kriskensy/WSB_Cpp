#include<iostream>

int *tempArray; //tablica pomocnicza, potrzebna przy scalaniu

//funkcja scalająca posortowane podtablice
void merge(int array[], int left, int middle, int right) 
{
	int i = left, j = middle + 1;
 
//kopiujemy lewą i prawą część tablicy do tablicy pomocniczej
    for(int i = left; i <= right; i++)
    {
    tempArray[i] = array[i];  
    }

//scalenie dwóch podtablic pomocniczych i zapisanie ich we własciwej tablicy
    for(int k = left; k <= right; k++)
    {
        if(i <= middle)
    {

    if(j <= right)
    {
        if(tempArray[j] < tempArray[i])
        {
            array[k] = tempArray[j++];
        }
        else
        {
            array[k] = tempArray[i++];
        }
    }
    else
    {
        array[k] = tempArray[i++];
    }
    }
    else
    {
        array[k] = tempArray[j++];
    }
    }
}

//funkcja sortująca tablice
void sortFunction(int array[], int left, int right)
{
//gdy mamy jeden element, to jest on już posortowany
	if(right <= left) return; 

//znajdujemy środek podtablicy
	int middle = (right + left)/2;

//dzielimy tablice na część lewą i prawą
	sortFunction(array, left, middle); 
	sortFunction(array, middle+1, right);

//scalamy dwie już posortowane tablice
	merge(array, left, middle, right);
}

int main()
{
    srand(time(0));
	int *array,
	n = 10; //liczba elementów tablicy
	
	array = new int[n]; //przydzielenie pamięci na tablicę liczb
	tempArray = new int[n]; //przydzielenie pamięci na tablicę pomocniczą

//wczytanie elementów tablicy
	for(int i = 0; i < n; i++)
    {
		array[i] = rand() % 100;
    }
		
	for(int i = 0; i < n; i++)
    {
		std::cout << array[i] << " ";
    }
	
//sortowanie wczytanej tablicy
	sortFunction(array, 0, n-1);

	std::cout << std::endl;

//wypisanie wyników
	for(int i = 0; i < n; i++)
    {
		std::cout << array[i] << " ";
    }
}