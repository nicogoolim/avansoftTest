#include "DealerShip.h"
#include <memory>

Dealership::Dealership()
{
	
	for (int i = 0; i < 10; i++)
	{
		availableCars.emplace_back(std::make_shared<Car>(i + 1));
	}
}

std::shared_ptr<Car> Dealership::sellCar(int CarId)
{
	std::shared_ptr<Car> carForSale = nullptr;
	auto iter = std::find_if(availableCars.begin(), availableCars.end(), [&](std::shared_ptr<Car> car) {return car->getId() == CarId; });

	if (iter != availableCars.end())
	{
		carForSale = *iter;
		availableCars.erase(iter);
	}

	return carForSale;
}
