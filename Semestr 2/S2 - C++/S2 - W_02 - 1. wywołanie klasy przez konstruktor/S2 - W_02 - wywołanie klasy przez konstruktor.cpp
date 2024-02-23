#include <iostream>
#include <cstdlib>

class Pracownik {
private:
	std::string imie;
	std::string nazwisko;
	double placa;
public:
	//to jest konstruktor
	Pracownik(std::string _imie, std::string _nazwisko, double _placa) {
		imie = _imie;
		nazwisko = _nazwisko;
		placa = _placa;
	}
	void wyswietl() {
		std::cout << std::endl << "Imie: " << imie;
		std::cout << std::endl << "Nazwisko: " << nazwisko;
		std::cout << std::endl << "Płaca: " << placa;
	}
};

int main(int argc, char* argv[]) {

	Pracownik p1("Krzyś", "Kensy", 15000); //tu wywoła się konstruktor
	p1.wyswietl();

}