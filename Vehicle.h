#include <iostream>
#include <string>
#include <afx.h>
using namespace std;

#pragma once
class Vehicle : public CObject
{
public:
	DECLARE_SERIAL(Vehicle)
	Vehicle() {}
	Vehicle(string, int);
		
	Vehicle(const Vehicle& other)
	{
		cColor = other.cColor;
		cColorSize = other.cColorSize;
		cPrice = other.cPrice;
	}
	void setColor(const string& color) { this->cColor = color; }
	string getColor() { return cColor; }

	void setPrice(double price) { this->cPrice = price; }
	double getPrice() { return this->cPrice; }


	void Serialize(CArchive& ar)
	{
		CObject::Serialize(ar);

		if (ar.IsStoring())
		{
			ar << cColorSize;

			for (int i = 0; i < cColorSize; i++)
			{
				ar << cColor[i];
			}

			ar << cPrice;
		}

		else
		{
			ar >> cColorSize;
			cColor = new char[cColorSize + 1];
			for (int i = 0; i < cColorSize; i++) { ar >> cColor[i]; }
			cColor[cColorSize] = '\0';

			ar >> cPrice;
		}
	}

protected:
	string cColor;
	int cColorSize;

	double cPrice;
};

