#include "Filter.h"

std::vector<std::shared_ptr<Car>> FilterCars::filterCarsByBrand(std::vector<std::shared_ptr<Car>> cars, std::string Brand)
{
	std::vector<std::shared_ptr<Car>> filteredCars;
	for (const auto& car : cars)
	{
		if (car->getBrand() == Brand)
		{
			filteredCars.push_back(car);
		}
	}
	return filteredCars;
}

std::vector<std::shared_ptr<Car>> FilterCars::filterCarsByPrice(std::vector<std::shared_ptr<Car>> cars, int price)
{
	std::vector<std::shared_ptr<Car>> filteredCars;
	for (const auto& car : cars)
	{
		if (car->getPrice() < price)
		{
			filteredCars.push_back(car);
		}
	}
	return filteredCars;
}
