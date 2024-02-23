#include<iostream>
#include<vector>

struct wierzcholki{
	//połączenia wychodzące z danego wierzchołka
	std::vector <unsigned int> polaczenia; 
	//okresla, czy wierzchołek został odwiedzony
	bool odwiedzony; 
	//dodatkowe dane dla danego wierzchołka
	//........................
	//........................
}*w;

void DFS(int k)
{
	std::cout<<"Odwiedzono "<<k<<" wierzcholek\n";
	w[k].odwiedzony = 1;
	for(int i=0; i<w[k].polaczenia.size(); i++)
	//jesli wierzchołek, do którego chcemy przejsć nie został
	//jeszcze odwiedzony
		if(!w[w[k].polaczenia[i]].odwiedzony) 
		//to przechodzimy do niego
			DFS(w[k].polaczenia[i]); 
}

int main()
{
	unsigned int n, pol, pocz, a, b;
	std::cout<<"Podaj liczbę wierzcholków w grafie: ";
	std::cin>>n;
	std::cout<<"Podaj liczbę połączeń w grafie: ";
	std::cin>>pol;
	std::cout<<"Podaj wierzchołek, z którego zaczynamy przeszukiwanie: ";
	std::cin>>pocz;
	
	w = new wierzcholki[n+1];
	
	std::cout<<"Podaj kolejne połączenia wierzchołków: \n";
	//wczytanie połączeń grafu
	for(int i=0; i<pol; i++)
	{
		std::cin>>a>>b;
		std::cout<<a<<" <--> "<<b<<std::endl;
		//tworzymy połączenie a --> b
		w[a].polaczenia.push_back(b);
		//tworzymy połączenie b --> a
		w[b].polaczenia.push_back(a);
	}
	std::cout<<"\nOdwiedzano wierzchołki w następującej kolejnosci:\n";
	DFS(pocz);
	
	delete [] w;
	
	return 0;
}