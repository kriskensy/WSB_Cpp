#pragma once
#include "Classes.h"

class MotorcycleCatalogue
{
public:
	MotorcycleCatalogue();

	/// <summary>
	/// metoda pozwalająca na dodawanie motocykli do tablicy
	/// </summary>
	/// <param name="motorcycle"></param>
	void addMotorcycle(Motorcycle motorcycle);

	/// <summary>
	/// metoda dodatkowa do wyświetlania całego katalogu motocykli
	/// </summary>
	void present();

private:
	Motorcycle motorcycles[20];
	int motorcycleCounter;
};