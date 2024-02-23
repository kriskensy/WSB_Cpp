#include <iostream>
#include <cstdlib>

class Rachunek {
private:
	std::string numer;
	std::string daneWlasciciela;
	double stan;
	static int liczbaRachunkow; // to jest składnik statyczny, ma tą samą wartość dla wszystkich rachunków
	//jeżeli wszystkie rachunki miałyby te samo oprocentowanie to wtedy pole byłoby static
	static double oprocentowanie;
public:
	Rachunek(std::string _numer, std::string _daneWlasciciela, double _stan)
		:numer(_numer), daneWlasciciela(_daneWlasciciela), stan(_stan)
	{
		liczbaRachunkow++;
	}
	void zmienStan(double nowyStan)
	{
		stan = nowyStan;
	}
	void wyswietl()
	{
		std::cout << std::endl << "Numer: " << numer;
		std::cout << std::endl << "Dane wlasciciela: " << daneWlasciciela;
		std::cout << std::endl << "Stan: " << stan;
	}
	//to są funkcje statyczne, bo operują tylko na składowych statycznych
	static int pobierzLiczbeRachunkow() {
		return liczbaRachunkow;
	}
	static double pobierzOprocentowanie() {
		return oprocentowanie;
	}
};

int Rachunek::liczbaRachunkow = 0;
double Rachunek::oprocentowanie = 5;

int main(int argc, char* argv[]) {

	Rachunek r1("1111", "Wlasciciel 1", 1);
	r1.wyswietl();

	Rachunek r2("222", "Wlasciciel 2", 2);
	r2.wyswietl();

	Rachunek r3("333", "Wlasciciel 3", 3);
	r3.wyswietl();

	std::cout << std::endl << "Liczba rachunkow z r1: " << r1.pobierzLiczbeRachunkow();
	std::cout << std::endl << "Oprocentowanie z r1: " << r1.pobierzOprocentowanie();

	std::cout << std::endl << "Liczba rachunkow z r2: " << r2.pobierzLiczbeRachunkow();
	std::cout << std::endl << "Oprocentowanie z r2: " << r2.pobierzOprocentowanie();

	//tylko funkcje statyczne możemy wywoływać dla całej klasy
	std::cout << std::endl << "Liczba rachunkow z klasy Rachunek: " << Rachunek::pobierzLiczbeRachunkow();
	std::cout << std::endl << "Oprocentowanie z klasy Rachunek: " << Rachunek::pobierzOprocentowanie();
}