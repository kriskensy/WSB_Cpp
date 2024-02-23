#include "Classes.h"

MotorcycleCatalogue::MotorcycleCatalogue()
	: motorcycleCounter(0) {}

void MotorcycleCatalogue::addMotorcycle(Motorcycle motorcycle)
{
	if (motorcycleCounter < 20)
	{
		int i = motorcycleCounter;
		while (i > 0 && (motorcycle.getEnginePower() > motorcycles[i - 1].getEnginePower()
			|| (motorcycle.getEnginePower() == motorcycles[i - 1].getEnginePower()
				&& motorcycle.getWeight() < motorcycles[i - 1].getWeight())))
		{
			motorcycles[i] = motorcycles[i - 1];
			--i;
		}
		motorcycles[i] = motorcycle;
		motorcycleCounter++;
	}
}

void MotorcycleCatalogue::present()
{
	for(int i = 0; i < motorcycleCounter; i++)
	{
		motorcycles[i].present();
	}
}