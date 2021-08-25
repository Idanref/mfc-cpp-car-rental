
#include "Vehicle.h"
#pragma once

class Motorcycle : public Vehicle
{
public:
	Motorcycle() {}
	Motorcycle::Motorcycle(string, string, int, string, int);

	Motorcycle(const Motorcycle& other)
	{
		this->cColor = other.cColor;
		this->cPrice = other.cPrice;
		this->cGearBox = other.cGearBox;
		this->cGearBoxSize = other.cGearBoxSize;
		this->cModel = other.cModel;
		this->cModelSize = other.cModelSize;
		this->cHorsePower = other.cHorsePower;
	}


	virtual void setGearBox(const string& gear_box) { this->cGearBox = gear_box; }
	virtual string getGearBox() { return this->cGearBox; }

	virtual void setModel(const string& model) { this->cModel = model; }
	virtual string getModel() { return this->cModel; }

	virtual void setHorsePower(int horse_power) { this->cHorsePower = horse_power; }
	virtual int getHorsePower() { return this->cHorsePower; }


	DECLARE_SERIAL(Motorcycle)

	void Serialize(CArchive& ar)
	{
		Vehicle::Serialize(ar);

		if (ar.IsStoring()) // saving
		{
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
	string cGearBox;
	int cGearBoxSize;

	string cModel;
	int cModelSize;

	int cHorsePower;
};