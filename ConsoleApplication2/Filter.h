#pragma once
#include <vector>
#include <memory>
#include "Car.h"

 class FilterCars
{
public:
	static std::vector<std::shared_ptr<Car>> filterCarsByPrice(std::vector<std::shared_ptr<Car>> cars);
	static std::vector<std::shared_ptr<Car>> filterCarsByBrand(std::vector<std::shared_ptr<Car>> cars);
};
 