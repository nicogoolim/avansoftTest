
#include "Buyer.h"


void Buyer::addPurchasedCar(std::shared_ptr<Car> purchasedCar)
{
	ownedCars.emplace_back(purchasedCar);
}
	
void Buyer::showOwnedCars() const
{
	if (!ownedCars.empty())
	{
		std::cout << "В вашем владении:" << std::endl;
		for (const auto& car: ownedCars)
		{
			std::cout << *car;
		}
	}
	else
	{
		std::cout << "У вас пока что нет машин." << std::endl;
	}
}
