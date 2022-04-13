#pragma once
#include <memory>
#include <string>
#include <vector>
#include "Car.h"
#include <iostream>
class Buyer
{
private:
	std::string name;
	std::vector<std::shared_ptr<Car>> ownedCars;

public:
	Buyer(std::string name): name(name) {};
	void addPurchasedCar(std::shared_ptr<Car> purchasedCar);

	void showOwnedCars() const;
};
