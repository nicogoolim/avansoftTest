#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "Car.h"
#include "Buyer.h"
#include "DealerShip.h"


int main()
{
	setlocale(LC_ALL, "rus");
	
	Dealership Shop;

	Buyer b("Игорь");

	Shop.showAvailableCars();
}
