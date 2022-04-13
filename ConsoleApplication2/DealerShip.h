#pragma once
#include <vector>
#include "Car.h"

class Dealership
{
private:
	std::vector<std::shared_ptr<Car>> availableCars;

public:

	Dealership();
	void showAvailableCars() const;
	std::vector<std::shared_ptr<Car>> filterAvailableCarsByPrice(int price) const;
	std::vector<std::shared_ptr<Car>> filterAvailableCarsByBrand(std::string Brand)	const;
	void showFilteredCars(std::vector<std::shared_ptr<Car>> filteredCars) const;
	std::shared_ptr<Car> sellCar(int CarId);
};
