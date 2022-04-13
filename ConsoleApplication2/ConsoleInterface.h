#pragma once
#include "DealerShip.h"
#include "Buyer.h"
#include <map>



class ConsoleInterface
{
private:
	Dealership Shop;
	Buyer buyer;
	

public:
	ConsoleInterface(Dealership shop, Buyer buyer);
	void start();
	void help();
	void showAvailableCars();
	void filterCars();
	void buyCar();
	void showOwnedCars();
};

void showCars(std::vector<std::shared_ptr<Car>>);