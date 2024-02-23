#include "Classes.h"

Motorcycle::Motorcycle()
	: Vehicle(0,2), nrID("brak"), enginePower(0) {}

Motorcycle::Motorcycle(float weight, int weelsNumber, std::string nrID, int enginePower)
	: Vehicle(weight, weelsNumber), nrID(nrID), enginePower(enginePower) {}

std::string Motorcycle::getIDNumber() const
{
	return nrID;
}

int Motorcycle::getEnginePower() const
{
	return enginePower;
}

void Motorcycle::present() const
{
	std::cout << nrID << " " << enginePower << " " << getWeight() << " " << getWeelsNumber() << " ";
}