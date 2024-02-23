#include <iostream>
#include <cstdlib>

//to jest klasa zdefiniowana za pomocą słowa kluczowego struct
struct Pracownik {
	std::string imie;
	std::string nazwisko;
	double placa;
	void wpisz() {	//ta funkcja jest w Pracowniku
		std::cout << "Podaj imie: ";
		std::cin >> imie;
		std::cout << "Podaj nazwisko: ";
		std::cin >> nazwisko;
		std::cout << "Podaj płacę: ";
		std::cin >> placa;
	}
	void wyswietl() {	//ta funkcja jest w Pracowniku
		std::cout << std::endl << "Imie: " << imie;
		std::cout << std::endl << "Nazwisko: " << nazwisko;
		std::cout << std::endl << "Płaca: " << placa;
	}
};
//tu jest koniec klasy

int main(int argc, char* argv[]) {
	std::cout << "Dzień dobry!\n";

	//p jest obiektem klasy Pracownik
	// Klasa może mieć wiele obiektów
	Pracownik p1;
	p1.wpisz();
	p1.wyswietl();

	Pracownik p2;
	p2.wpisz();
	p2.wpisz();
	p2.wyswietl();
}