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
	for (const auto& car : availableCars)
	{
		std::cout << *car;
	}
}

std::vector<std::shared_ptr<Car>> Dealership::filterAvailableCarsByPrice(int price) const
{
	std::vector<std::shared_ptr<Car>> filteredCars;
	for (const auto& car: availableCars)
	{
		if (car->getPrice() < price)
		{
			filteredCars.push_back(car);
		}
	}
	return filteredCars;
}

std::vector<std::shared_ptr<Car>> Dealership::filterAvailableCarsByBrand(std::string Brand) const
{
	std::vector<std::shared_ptr<Car>> filteredCars;
	for (const auto& car : availableCars)
	{
		if (car->getBrand() == Brand)
		{
			filteredCars.push_back(car);
		}
	}
	return filteredCars;
}

void Dealership::showFilteredCars(std::vector<std::shared_ptr<Car>> filteredCars) const
{
	if (!filteredCars.empty())
	{
		std::cout << "Список отфильтрованных авто:" << std::endl;
		for(const auto& car: filteredCars)
		{
			std::cout << *car;
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
