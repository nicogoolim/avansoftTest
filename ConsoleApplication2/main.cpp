
#include "Car.h"
#include "Buyer.h"
#include "DealerShip.h"
#include "ConsoleInterface.h"
int main()
{
	setlocale(LC_ALL, "rus");
	
	Dealership Shop;

	Buyer Buyer("Михаил");

	ConsoleInterface menu(Shop, Buyer);
	menu.start();

}
