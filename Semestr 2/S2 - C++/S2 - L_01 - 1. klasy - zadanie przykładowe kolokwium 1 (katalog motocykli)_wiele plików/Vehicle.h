#include "Headers.h"
#pragma once

class Vehicle
{
public:
	Vehicle(float weight, int weelsNumber);

	/// <summary>
	/// metoda zwracaj¹ca wagê 
	/// </summary>
	/// <returns></returns>
	float getWeight() const;

	/// <summary>
	/// metoda zwracaj¹ca iloœæ kó³ danego pojazdu
	/// </summary>
	/// <returns></returns>
	int getWeelsNumber() const;

private:
	float weight;
	int weelsNumber;
};