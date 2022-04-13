
#include "Buyer.h"


void Buyer::addPurchasedCar(std::shared_ptr<Car> purchasedCar)
{
	ownedCars.push_back(purchasedCar);
}

void Buyer::showOwnedCars() const
{
	if (ownedCars.size() != 0)
	{
		std::cout << "� ����� ��������:" << std::endl;
		for (int i = 0; i < ownedCars.size(); i++)
		{
			std::cout << *ownedCars[i];
		}
	}
	else
	{
		std::cout << "� ��� ���� ��� ��� �����." << std::endl;
	}
}
