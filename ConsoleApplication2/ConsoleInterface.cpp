#include "ConsoleInterface.h"

#include "Filter.h"

ConsoleInterface::ConsoleInterface(Dealership shop, Buyer buyer) : Shop(shop), buyer(buyer) {};
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
		std::cout << "Введите команду:";
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
				std::cout << "Команда не найдена в списке." << std::endl;
			}
		}
		else if(command!="exit")
		{
			std::cout << "Команда не найдена в списке." << std::endl;
		}
		
		std::cout << std::endl;
	}
}

void ConsoleInterface::help()
{
	std::cout << "Список доступных комманд:" << std::endl
		<< "1: Просмотреть все доступные машины" << std::endl
		<< "2: Отфильтровать доступные к покупке машины" << std::endl
		<< "3: Купить автомобиль по ID" << std::endl
		<< "4: Просмотреть все приобретённые машины" << std::endl
		<< "exit: Выйти из программы" << std::endl
		<< "help: Вызвать справку заного" << std::endl;
		
}


void ConsoleInterface::filterCars()
{
	std::string choose;
	std::vector<std::shared_ptr<Car>> filteredCars;
	std::cout << "Доступны фильтры по:" << std::endl
		<< "1. По цене" << std::endl
		<< "2. По марке" << std::endl;
	std::cout << "Фильтр:";
	std::cin >> choose;
	std::cout << std::endl;
		if (isNumber(choose) && std::stoi(choose) == 1)
		{
			int maxPrice;
			std::cout << "Введите максимальную цену:";
			std::cin >> maxPrice;
			filteredCars = FilterCars::filterCarsByPrice(Shop.getAvailableCars(), maxPrice);
		}
		else if (isNumber(choose) &&  std::stoi(choose) == 2)
		{
			std::string brand;
			std::cout << "Введите бренд:";
			std::cin >> brand;
			filteredCars = FilterCars::filterCarsByBrand(Shop.getAvailableCars(), brand);
		}
		else
		{
			std::cout << "Не понял вашей команды."<<std::endl;
			return;
		}
	std::cout << "Фильтрованный список:" << std::endl;
	showCars(filteredCars);
}

void ConsoleInterface::showAvailableCars()
{
	std::cout << "Список доступных автомобилей:" << std::endl;
	showCars(Shop.getAvailableCars());
}

void ConsoleInterface::buyCar()
{
	int carId;
	std::shared_ptr<Car> curCar;
	std::cout << "Введите ID автомобиля который хотите купить:";
	std::cin >> carId;
	curCar = Shop.sellCar(carId);
	buyer.addPurchasedCar(curCar);
}

void ConsoleInterface::showOwnedCars()
{
	std::cout << "Список приобретённых автомобилей:" << std::endl;
	showCars(buyer.getOwnedCars());
}


void showCars(std::vector<std::shared_ptr<Car>> cars)
{
	for (const auto& car : cars)
	{
		std::cout << *car;
	}
}
