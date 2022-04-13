#include "ConsoleInterface.h"
#include "Filter.h"

ConsoleInterface::ConsoleInterface(std::shared_ptr<Dealership> shop, std::shared_ptr<Buyer> buyer)
{
	this->Shop = shop;
	this->buyer = buyer;
	
}



bool isNumber(const std::string& str)
{
	for (char const& c : str) {
		if (std::isdigit(c) == 0) return false;
	}
	return true;
}

void ConsoleInterface::start()
{
	std::string command = "";
	help();
	while(command!="exit")
	{
		std::cout << "������� �������:";
		std::cin >> command;
		std::cout << std::endl;
		if(command == "help")
		{
			help();
		}
		else if(isNumber(command))
		{
			switch (std::stoi(command))
			{
			case 1:
				showAvailableCars();
				break;
			case 2:
				filterCars();
				break;
			case 3:
				buyCar();
				break;
			case 4:
				showOwnedCars();
				break;
			default:
				std::cout << "������� �� ������� � ������." << std::endl;
			}
		}
		else if(command!="exit")
		{
			std::cout << "������� �� ������� � ������." << std::endl;
		}
		help();
		std::cout << std::endl;
	}
}

void ConsoleInterface::help()
{
	std::cout << "������ ��������� �������:" << std::endl
		<< "1: ����������� ��� ��������� ������" << std::endl
		<< "2: ������������� ��������� � ������� ������" << std::endl
		<< "3: ������ ���������� �� ID" << std::endl
		<< "4: ����������� ��� ������������ ������" << std::endl
		<< "exit: ����� �� ���������" << std::endl
		<< "help: ������� ������� ������" << std::endl;
		
}


void ConsoleInterface::filterCars()
{
	std::string choose;
	std::vector<std::shared_ptr<Car>> filteredCars;
	
	std::cout << "�������� ������� ��:" << std::endl
		<< "1. �� ����" << std::endl
		<< "2. �� �����" << std::endl;

	std::cout << "������:";
	std::cin >> choose;
	std::cout << std::endl;

	if (isNumber(choose) && std::stoi(choose) == 1)
	{
		filteredCars = FilterCars::filterCarsByPrice(Shop->getAvailableCars());
	}
	else if (isNumber(choose) &&  std::stoi(choose) == 2)
	{
		filteredCars = FilterCars::filterCarsByBrand(Shop->getAvailableCars());
	}
	else
	{
		std::cout << "�� ����� ����� �������."<<std::endl;
		return;
	}

	std::cout << "������������� ������:" << std::endl;
	showCars(filteredCars);
}

void ConsoleInterface::showAvailableCars()
{
	std::cout << "������ ��������� �����������:" << std::endl << std::endl;
	showCars(Shop->getAvailableCars());
}

void ConsoleInterface::buyCar()
{
	int carId;
	std::shared_ptr<Car> curCar;
	showCars(Shop->getAvailableCars());
	std::cout << "������� ID ���������� ������� ������ ������:";
	std::cin >> carId;
	curCar = Shop->sellCar(carId);
	buyer->addPurchasedCar(curCar);
}

void ConsoleInterface::showOwnedCars()
{
	std::cout << "������ ������������ �����������:" << std::endl;
	showCars(buyer->getOwnedCars());
}


