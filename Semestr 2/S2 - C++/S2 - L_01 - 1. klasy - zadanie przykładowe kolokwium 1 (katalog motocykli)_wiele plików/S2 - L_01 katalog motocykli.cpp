#include "Classes.h"

int main()
{
	MotorcycleCatalogue catalogue;

	for (int i = 0; i < 6; i++)
	{
		float weight;
		int weelsNumber, enginePower;
		std::string nrID;

		std::cin >> weight >> weelsNumber >> nrID >> enginePower;
		Motorcycle motorcycle(weight, weelsNumber, nrID, enginePower);
		catalogue.addMotorcycle(motorcycle);
	}

	catalogue.present();
}