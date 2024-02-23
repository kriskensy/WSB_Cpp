#include <iostream>
#include <cstdlib>

class Pracownik {
private:
	std::string imie;
	std::string nazwisko;
	double placa;
public:
	//to jest konstruktor 1.
	Pracownik()
		:imie(""), nazwisko(""), placa(0)
	{
	}
	//to jest konstruktor 2.
	Pracownik(std::string _imie, std::string _nazwisko, double _placa)
		:imie(_imie), nazwisko(_nazwisko), placa(_placa)
	{
	}

	//to jest konstruktor 3.
	Pracownik(std::string _imie, std::string _nazwisko)
		:imie(_imie), nazwisko(_nazwisko), placa(0)
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