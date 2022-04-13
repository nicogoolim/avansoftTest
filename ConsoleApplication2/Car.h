#pragma once


struct Brands
{
	 std::vector<std::string> BrandsBank = {"BMW", "Audi", "Mercedes", "Skoda"};
};
struct Colors
{
	std::vector<std::string> ColorsBank = { "red","green","blue","black" };
};

class Car
{
private:
	int id;
	std::string brand;
	std::string color;
	int price;

public:
	Car(int CarId)
	{
		Brands Brand;
		Colors Color;
		id = CarId;
		brand = Brand.BrandsBank[rand() % Brand.BrandsBank.size()];
		color = Color.ColorsBank[rand() % Color.ColorsBank.size()];
		price = 1000000 + rand() % 1000000;
	}
	
	int getId() const { return id; }
	std::string getBrand() const { return brand; }
	std::string getColor() const { return color; }
	int getPrice() const { return price; }

};
std::ostream& operator<<(std::ostream& os, Car car)
{
	return os << "Номер автомобиля: " << car.getId() << "\tБренд автомобиля: " << car.getBrand() << std::endl;
}