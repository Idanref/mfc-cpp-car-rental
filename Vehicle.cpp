#include "Vehicle.h"

IMPLEMENT_SERIAL(Vehicle, CObject, 1)

Vehicle::Vehicle(string color, int price)
{
	cout << "New vehicle" << endl;
	this->cColor = color;
	this->cColorSize = cColor.length();

	this->cPrice = price;
}