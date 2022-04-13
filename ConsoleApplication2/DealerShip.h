#pragma once


class Dealership
{
private:
	std::vector<std::shared_ptr<Car>> availableCars;

	
public:
	Dealership()
	{
		for (int i = 0; i < 10; i++)
		{
			availableCars.push_back(std::shared_ptr<Car>(new Car(i + 1)));
		}
	}
	void showAvailableCars() const
	{
		for (int i = 0; i < availableCars.size(); i++)
		{
			std::cout << *availableCars[i];
		}
		
	}
	std::vector<std::shared_ptr<Car>> filterAvailableCarsByPrice(int price) const
	{
		std::vector<std::shared_ptr<Car>> filteredCars;
		for (int i = 0; i < availableCars.size(); i++)
		{
			if (availableCars[i]->getPrice() < price)
			{
				filteredCars.push_back(availableCars[i]);
			}
		}
		return filteredCars;
	}

	std::vector<std::shared_ptr<Car>> filterAvailableCarsByBrand(std::string Brand)	const
	{
		std::vector<std::shared_ptr<Car>> filteredCars;
		for (int i = 0; i < availableCars.size(); i++)
		{
			if (availableCars[i]->getBrand() == Brand)
			{
				filteredCars.push_back(availableCars[i]);
			}
		}
		return filteredCars;
	}

	void showFilteredCars(std::vector<std::shared_ptr<Car>> filteredCars)
	{
		if (filteredCars.size()!=0)
		{
			for (int i = 0; i < filteredCars.size(); i++)
			{
				std::cout << *filteredCars[i];
			}
		}
		else
		{
			std::cout << "Нет машин удовлетворяющих условию." << std::endl;
		}
		
	}
};