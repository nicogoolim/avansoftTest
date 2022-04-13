
#include "Car.h"
#include "Buyer.h"
#include "DealerShip.h"
#include "ConsoleInterface.h"
#include <functional>
int main()
{
	std::srand(time(NULL));
	setlocale(LC_ALL, "rus");
	auto Shop = std::make_shared<Dealership>();
	auto Buyer = std::make_shared<class Buyer>("Михаил");
	ConsoleInterface menu(Shop, Buyer);

	menu.start();
}
