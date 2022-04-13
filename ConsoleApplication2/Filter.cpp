#include "Filter.h"
#include <functional>



std::vector<std::shared_ptr<Car>> FilterCars::filterCarsByBrand(std::vector<std::shared_ptr<Car>> cars)
{
	std::vector<std::shared_ptr<Car>> filteredCars;
	std::string brand;
	std::cout << "¬ведите бренд:";
	std::cin >> brand;
	for (const auto& car : cars)
	{
		if (car->getBrand() == brand)
		{
			filteredCars.emplace_back(car);
		}
	}
	return filteredCars;
}

std::vector<std::shared_ptr<Car>> FilterCars::filterCarsByPrice(std::vector<std::shared_ptr<Car>> cars)
{
	std::vector<std::shared_ptr<Car>> filteredCars;
	int price;
	std::cout << "¬ведите максимальную цену:";
	std::cin >> price;
	for (const auto& car : cars)
	{
		if (car->getPrice() < price)
		{
			filteredCars.emplace_back(car);
		}
	}
	return filteredCars;
}
	
