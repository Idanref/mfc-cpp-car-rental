#include "Car.h"
#include "pch.h"

IMPLEMENT_SERIAL(Car, CObject, 1)

Car::Car(int numSeats, string gearBox, string model, int horsePower, string color, int price) : Vehicle(color, price)
{
	cout << "New Car" << endl;
	this->cNumOfSeats = numSeats;
	this->cGearBox = gearBox;
	this->cGearBoxSize = gearBox.length();
	this->cModel = model;
	this->cModelSize = model.length();
	this->cHorsePower = horsePower;
}