#include "Classes.h"

Vehicle::Vehicle(float weight, int weelsNumber)
	: weight(weight), weelsNumber(weelsNumber) {};

float Vehicle::getWeight() const
{
	return weight;
}

int Vehicle::getWeelsNumber() const
{
	return weelsNumber;
}