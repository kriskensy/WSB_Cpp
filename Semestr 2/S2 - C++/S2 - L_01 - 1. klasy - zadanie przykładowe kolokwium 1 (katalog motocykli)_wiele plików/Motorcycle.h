#pragma once
#include "Classes.h"

class Motorcycle : public Vehicle
{
public:
	Motorcycle();

	Motorcycle(float weight, int weelsNumber, std::string nrID, int enginePower);

	/// <summary>
	/// metoda zwracaj¹ca nr rejestracyjny motocykla
	/// </summary>
	/// <returns></returns>
	std::string getIDNumber() const;

	/// <summary>
	/// metoda zwracaj¹ca moc silnika motocykla
	/// </summary>
	/// <returns></returns>
	int getEnginePower() const;

	/// <summary>
	/// metoda wyœwietlaj¹ca dane pojazdu (ID, moc, waga, liczba kó³)
	/// </summary>
	void present() const;

private:
	std::string nrID;
	int enginePower;
};