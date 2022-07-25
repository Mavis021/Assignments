//Conversion from meter system to feet system.

#include<iostream>
#include<cmath>
using namespace std;


class meter_centimeter
{
private:
	float meter, centimeter;
public:
	friend class feet_inch;
	meter_centimeter(float m = 0.0, float cm = 0.0) //constructor
	{
		meter = m;
		centimeter = cm;
	}
	meter_centimeter(feet_inch);

	float returnTotalCentimeter()
	{
		return (meter * 100) + centimeter;
	}

	void display()
	{
		cout << meter << "m " << centimeter << "cm" << endl;
	}

};

class feet_inch
{
private:
	float feet, inch;
public:
	friend class meter_centimeter;
	feet_inch(float f = 0.0, float in = 0.0)
	{
		feet = f;
		inch = in;
	}


	float returnTotalInches()
	{
		return (feet * 12) + inch;
	}

	feet_inch(meter_centimeter);

	void display()
	{
		cout << feet << "ft " << inch << "inch " << endl;
	}
};


feet_inch::feet_inch(meter_centimeter mcm)
{
	inch = (mcm.returnTotalCentimeter() / 2.54);
	feet = (int)inch / 12;
	inch = ((inch / 12) - feet) * 12;
}

meter_centimeter::meter_centimeter(feet_inch fi)
{
	centimeter = fi.returnTotalInches() * 2.54;
	meter = (int)centimeter / 100;
	centimeter = ((centimeter / 100) - meter) * 100;
}

int main()
{
	meter_centimeter mcm(1, 0.5), mcm1;
	feet_inch fin, fin1(1, 0.5);

	//meter_centimeter into feet_inch
	cout << "DISTANCE IN METER_CENTIMETER:";
	mcm.display();
	fin = mcm;
	cout << "EQUIVALENT DISTANCE IN FEET_INCH: ";
	fin.display();

	//feet_inch into meter centimeter
	cout << "DISTANCE IN FEET_INCH: ";
	fin1.display();
	mcm1 = fin1;
	cout << "EQUVALENT DISTANCE IN METER_CENTIMETER:";
	mcm1.display();

	return 0;
}
