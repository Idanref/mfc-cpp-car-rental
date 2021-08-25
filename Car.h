#include "Vehicle.h"
#pragma once

class Car : public Vehicle
{
public:
	Car() {}
	Car(int, string, string, int, string, int);

	Car(const Car& other)
	{
		this->cColor = other.cColor;
		this->cPrice = other.cPrice;
		this->cNumOfSeats = other.cNumOfSeats;
		this->cGearBox = other.cGearBox;
		this->cGearBoxSize = other.cGearBoxSize;
		this->cModel = other.cModel;
		this->cModelSize = other.cModelSize;
		this->cHorsePower = other.cHorsePower;
	}

	void setNumOfSeats(int num_seats) { this->cNumOfSeats = num_seats; }
	int getNumOfSeats() { return this->cNumOfSeats; }

	void setGearBox(const string& gear_box) { this->cGearBox = gear_box; }
	string getGearBox() { return this->cGearBox; }

	void setModel(const string& model) { this->cModel = model; }
	string getModel() { return this->cModel; }

	void setHorsePower(int horse_power) { this->cHorsePower = horse_power; }
	int getHorsePower() { return this->cHorsePower; }


	DECLARE_SERIAL(Car)

	void Serialize(CArchive& ar)
	{
		Vehicle::Serialize(ar);

		if (ar.IsStoring()) // saving
		{
			ar << cNumOfSeats;

			ar << cGearBoxSize;
			for (int i = 0; i < cGearBoxSize; i++)
			{
				ar << cGearBox[i];
			}

			ar << cModelSize;
			for (int i = 0; i < cModelSize; i++)
			{
				ar << cModel[i];
			}

			ar << cHorsePower;
		}

		else // loading
		{
			ar >> cNumOfSeats;

			ar >> cGearBoxSize;
			cGearBox = new char[cGearBoxSize + 1];
			for (int i = 0; i < cGearBoxSize; i++) { ar >> cGearBox[i]; }
			cGearBox[cGearBoxSize] = '\0';

			ar >> cModelSize;
			cModel = new char[cModelSize + 1];
			for (int i = 0; i < cModelSize; i++) { ar >> cModel[i]; }
			cModel[cModelSize] = '\0';

			ar >> cHorsePower;
		}
	}

protected:
	int cNumOfSeats;

	string cGearBox;
	int cGearBoxSize;

	string cModel;
	int cModelSize;

	int cHorsePower;
};

