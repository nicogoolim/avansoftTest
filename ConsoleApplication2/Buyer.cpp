
#include "Buyer.h"


void Buyer::addPurchasedCar(std::shared_ptr<Car>& purchasedCar)
{
	if (purchasedCar != nullptr)
	{
		ownedCars.emplace_back(purchasedCar);
	}
	
}
	
