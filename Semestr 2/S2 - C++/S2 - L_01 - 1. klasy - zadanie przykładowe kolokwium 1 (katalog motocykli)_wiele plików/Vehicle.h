#include "Headers.h"
#pragma once

class Vehicle
{
public:
	Vehicle(float weight, int weelsNumber);

	/// <summary>
	/// metoda zwracaj�ca wag� 
	/// </summary>
	/// <returns></returns>
	float getWeight() const;

	/// <summary>
	/// metoda zwracaj�ca ilo�� k� danego pojazdu
	/// </summary>
	/// <returns></returns>
	int getWeelsNumber() const;

private:
	float weight;
	int weelsNumber;
};