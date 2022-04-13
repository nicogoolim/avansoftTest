#include "Car.h"
std::ostream& operator<<(std::ostream& os, Car car)
{
	return os << "Номер автомобиля: " << car.getId() << "\tБренд автомобиля: " << car.getBrand()
		<< "\t Цена: " << car.getPrice() << "$" << "\tЦвет: " << car.getColor() << std::endl;
}
Car::Car(int CarId)
{
	Brands Brand;
	Colors Color;
	id = CarId;
	brand = Brand.BrandsBank[rand() % Brand.BrandsBank.size()];
	color = Color.ColorsBank[rand() % Color.ColorsBank.size()];
	price = 10000 + rand();
}
