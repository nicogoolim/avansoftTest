#include <iostream>
#include "DealerShip.h"
#include <memory>

Dealership::Dealership()
{
	
		for (int i = 0; i < 10; i++)
		{
			availableCars.push_back(std::shared_ptr<Car>(new Car(i + 1)));
		}
	
}
void Dealership::showAvailableCars() const
{
		for (int i = 0; i < availableCars.size(); i++)
		{
			std::cout << *availableCars[i];
		}
}

std::vector<std::shared_ptr<Car>> Dealership::filterAvailableCarsByPrice(int price) const
{
	std::vector<std::shared_ptr<Car>> filteredCars;
	for (int i = 0; i < availableCars.size(); i++)
	{
		if (availableCars[i]->getPrice() < price)
		{
			filteredCars.push_back(availableCars[i]);
		}
	}
	return filteredCars;
}

std::vector<std::shared_ptr<Car>> Dealership::filterAvailableCarsByBrand(std::string Brand) const
{
	std::vector<std::shared_ptr<Car>> filteredCars;
	for (int i = 0; i < availableCars.size(); i++)
	{
		if (availableCars[i]->getBrand() == Brand)
		{
			filteredCars.push_back(availableCars[i]);
		}
	}
	return filteredCars;
}

void Dealership::showFilteredCars(std::vector<std::shared_ptr<Car>> filteredCars) const
{
	if (!filteredCars.empty())
	{
		std::cout << "Список отфильтрованных авто:" << std::endl;
		for (int i = 0; i < filteredCars.size(); i++)
		{
			std::cout << *filteredCars[i];
		}
	}
	else
	{
		std::cout << "Нет машин удовлетворяющих условию." << std::endl;
	}
}

std::shared_ptr<Car> Dealership::sellCar(int CarId)
{
	std::shared_ptr<Car> carForSale;
	auto iter = std::find_if(availableCars.begin(), availableCars.end(), [&](std::shared_ptr<Car> car) {return car->getId() == CarId; });

	carForSale = *iter;
	availableCars.erase(iter);

	return carForSale;
}
