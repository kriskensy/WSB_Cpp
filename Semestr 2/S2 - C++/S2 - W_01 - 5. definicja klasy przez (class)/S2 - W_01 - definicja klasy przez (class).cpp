#include <iostream>
#include <cstdlib>

class Pracownik {
private: // może być używane tylko wewnątrz klasy
	std::string imie;
	std::string nazwisko;
	double placa;
public: // to co jet publiczne moze być używane w klasie i poza klasą
	void wpisz() {
		std::cout << "Podaj imie: ";
		std::cin >> imie;
		std::cout << "Podaj nazwisko: ";
		std::cin >> nazwisko;
		std::cout << "Podaj płacę: ";
		std::cin >> placa;
	}
	void wyswietl() {
		std::cout << std::endl << "Imie: " << imie;
		std::cout << std::endl << "Nazwisko: " << nazwisko;
		std::cout << std::endl << "Płaca: " << placa;
	}
};
//tu jest koniec klasy

int main(int argc, char* argv[]) {

	Pracownik p1;
	p1.wpisz();
	p1.wyswietl();
}