#include "Car.h"
std::ostream& operator<<(std::ostream& os, Car car)
{
	return os << "����� ����������: " << car.getId() << "\t����� ����������: " << car.getBrand()
		<< "\t ����: " << car.getPrice() << "$" << "\t����: " << car.getColor() << std::endl;
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
