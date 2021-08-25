#include "Motorcycle.h"

IMPLEMENT_SERIAL(Motorcycle, CObject, 1)

Motorcycle::Motorcycle(string gearBox, string model,
	int horsePower, string color, int price) : Vehicle(color, price)
{
	cout << "New Motorcycle" << endl;
	this->cGearBox = gearBox;
	this->cGearBoxSize = gearBox.length();
	this->cModel = model;
	this->cModelSize = model.length();
	this->cHorsePower = horsePower;
}