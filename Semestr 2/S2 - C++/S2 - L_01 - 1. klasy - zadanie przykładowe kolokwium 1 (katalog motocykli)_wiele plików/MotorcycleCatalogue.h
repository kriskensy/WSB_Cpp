#pragma once
#include "Classes.h"

class MotorcycleCatalogue
{
public:
	MotorcycleCatalogue();

	/// <summary>
	/// metoda pozwalaj¹ca na dodawanie motocykli do tablicy
	/// </summary>
	/// <param name="motorcycle"></param>
	void addMotorcycle(Motorcycle motorcycle);

	/// <summary>
	/// metoda dodatkowa do wyœwietlania ca³ego katalogu motocykli
	/// </summary>
	void present();

private:
	Motorcycle motorcycles[20];
	int motorcycleCounter;
};