#include <iostream>
#include <vector>
#include <string>
#include "Car.h"
#include <memory>


int main()
{
	setlocale(LC_ALL, "rus");
	std::vector<std::shared_ptr<Car>> Cars;
  for (int i = 0; i<10;i++)
  {
	  Cars.push_back(std::shared_ptr<Car>(new Car(i+1)));
	  std::cout << *Cars[i];
  }

}
