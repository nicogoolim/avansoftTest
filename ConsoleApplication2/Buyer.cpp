
#include "Buyer.h"


void Buyer::addPurchasedCar(std::shared_ptr<Car> purchasedCar)
{
	ownedCars.emplace_back(purchasedCar);
}
	
