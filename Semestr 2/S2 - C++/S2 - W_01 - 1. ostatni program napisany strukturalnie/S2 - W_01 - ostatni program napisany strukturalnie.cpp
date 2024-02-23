#include <iostream>
#include <cstdlib>

struct Pracownik {
	std::string imie;
	std::string nazwisko;
	double placa;
};

void wpisz(Pracownik& p) {
	std::cout << "Podaj imie: ";
	std::cin >> p.imie;
	std::cout << "Podaj nazwisko: ";
	std::cin >> p.nazwisko;
	std::cout << "Podaj płacę: ";
	std::cin >> p.placa;
}

void wyswietl(Pracownik p) {
	std::cout << std::endl << "Imie: " << p.imie;
	std::cout << std::endl << "Nazwisko: " << p.nazwisko;
	std::cout << std::endl << "Płaca: " << p.placa;
}

int main(int argc, char* argv[]) {
	std::cout << "Dzień dobry!\n";

	Pracownik p;
	wpisz(p);
	wyswietl(p);
}