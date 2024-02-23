#include <iostream>
#include <cstdlib>

class Pracownik {
private:
	std::string imie;
	std::string nazwisko;
	double placa;
public:
	Pracownik(std::string _imie, std::string _nazwisko, double _placa)
		:imie(_imie), nazwisko(_nazwisko), placa(_placa)
	{
	}

	Pracownik()
		:Pracownik("", "", 0) // to jest wywołanie powyższego konstruktora na konkretnych parametrach
		//:imie(""), nazwisko(""), placa(0)
	{
	}
	Pracownik(std::string _imie, std::string _nazwisko)
		:Pracownik(_imie, _nazwisko, 0) // to jest wywołanie pierwszego konstruktora na konkretnych parametrach
	{
	}
	void wyswietl() {
		std::cout << std::endl << "Imie: " << imie;
		std::cout << std::endl << "Nazwisko: " << nazwisko;
		std::cout << std::endl << "Płaca: " << placa;
	}
};

int main(int argc, char* argv[]) {

	Pracownik p1;	//tu wywoła się konstruktor 1.
	p1.wyswietl();

	Pracownik p2("Krzyś", "Kensy", 15000); //tu wywoła sie konstruktor 2.
	p2.wyswietl();

	Pracownik p3("Ździchu", "Wiertara"); //tu wywoła sie konstruktor 2.
	p3.wyswietl();
}