#pragma once

class Buyer
{
private:
	std::string name;
	std::vector<std::shared_ptr<Car>> ownedCars;

public:
	Buyer(std::string name): name(name) {};
	void addPurchasedCar(std::shared_ptr<Car> purchasedCar)
	{
		ownedCars.push_back(purchasedCar);
	}

	void showOwnedCars() const
	{
		if (ownedCars.size() != 0)
		{
			std::cout << "В вашем владении:" << std::endl;
			for (int i = 0; i < ownedCars.size(); i++)
			{
				std::cout << *ownedCars[i];
			}
		}
		else
		{
			std::cout << "У вас пока что нет машин." << std::endl;
		}
	}
};