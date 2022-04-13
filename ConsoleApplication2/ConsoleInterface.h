#pragma once
#include "DealerShip.h"
#include "Buyer.h"
#include <map>
#include <functional>


class ConsoleInterface
{
private:
	std::shared_ptr<Dealership> Shop;
	std::shared_ptr<Buyer> buyer;

public:
	ConsoleInterface(std::shared_ptr<Dealership> shop, std::shared_ptr<Buyer> buyer);
	void start();
	void help();
	void showAvailableCars();
	void filterCars();
	void buyCar();
	void showOwnedCars();
	
};

