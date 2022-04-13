#pragma once
#include <string>
#include <vector>
#include <iostream>

struct Brands
{
	 std::vector<std::string> BrandsBank = {"BMW", "Audi", "Opel", "Skoda"};
};
struct Colors
{
	std::vector<std::string> ColorsBank = { "Красный","Зелёный","Синий","Чёрный" };
};

class Car
{
private:
	int id;
	std::string brand;
	std::string color;
	int price;

public:
	Car(int CarId);
	int getId() const { return id; }
	std::string getBrand() const { return brand; }
	std::string getColor() const { return color; }
	int getPrice() const { return price; }

};


std::ostream& operator<<(std::ostream& os, Car car);