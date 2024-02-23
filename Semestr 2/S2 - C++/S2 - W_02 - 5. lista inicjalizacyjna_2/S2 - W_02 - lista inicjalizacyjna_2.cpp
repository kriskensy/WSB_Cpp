#include <iostream>
#include <cstdlib>

class Pracownik {
private:
	std::string imie;
	std::string nazwisko;
	double placa;
public:
	Pracownik(std::string imie, std::string nazwisko, double placa)
		:imie(imie), nazwisko(nazwisko), placa(placa)
	{
	}

	void wyswietl() {
		std::cout << std::endl << "Imie: " << imie;
		std::cout << std::endl << "Nazwisko: " << nazwisko;
		std::cout << std::endl << "Płaca: " << placa;
	}
};

int main(int argc, char* argv[]) {

	Pracownik p1("Krzyś", "Kensy", 15000);
	p1.wyswietl();

}