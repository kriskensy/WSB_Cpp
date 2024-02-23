#pragma once
#include "Classes.h"

class Motorcycle : public Vehicle
{
public:
	Motorcycle();

	Motorcycle(float weight, int weelsNumber, std::string nrID, int enginePower);

	/// <summary>
	/// metoda zwracaj�ca nr rejestracyjny motocykla
	/// </summary>
	/// <returns></returns>
	std::string getIDNumber() const;

	/// <summary>
	/// metoda zwracaj�ca moc silnika motocykla
	/// </summary>
	/// <returns></returns>
	int getEnginePower() const;

	/// <summary>
	/// metoda wy�wietlaj�ca dane pojazdu (ID, moc, waga, liczba k�)
	/// </summary>
	void present() const;

private:
	std::string nrID;
	int enginePower;
};