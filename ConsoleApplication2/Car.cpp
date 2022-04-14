#include "Car.h"
std::ostream& operator<<(std::ostream& os, Car car)
{
	return os << "����� ����������: " << car.getId() << "\t����� ����������: " << car.getBrand()
		<< "\t ����: " << car.getPrice() << "$" << "\t����: " << car.getColor() << std::endl;
}
Car::Car(int CarId)
{

	auto Brand = std::make_shared<Brands>();
	auto Color = std::make_shared<Colors>();
	id = CarId;
	brand = Brand->BrandsBank[rand() % Brand->BrandsBank.size()];
	color = Color->ColorsBank[rand() % Color->ColorsBank.size()];
	price = 10000 + rand();
}
void showCars(std::vector<std::shared_ptr<Car>> cars)
{
	for (const auto& car : cars)
	{
		std::cout << *car;
	}
}
