#include <iostream>
#include <cstdlib>

struct Pracownik {
	std:: string imie;
	std:: string nazwisko;
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

	Pracownik p;
	p.wpisz();
	p.wyswietl();
}