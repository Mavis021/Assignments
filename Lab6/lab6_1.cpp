//lab6_1.cpp
//Write a program that can convert the Distance(meter, centimeter) to meters measurement in floatand vice versa.
//Make a class distance with two data members, meterand centimeter.
//You can add function members as per your requirement.

#include<iostream>

class distance
{
private:
	float meter, centimeter;
public:
	distance() //default constructor
	{
		meter = 0.0;
		centimeter = 0.0;
	}
	distance(float m , float cm) // parameterized constructor
	{
		meter = m;
		centimeter = cm;
	}

	distance(float val)
	{
		meter = (int)val;
		centimeter = (val - meter) * 100;
	}
	operator float()
	{
		meter += (centimeter / 100);
		return meter;
	}

	float return_meter()
	{
		return meter;
	}

	float return_centimeter()
	{
		return centimeter;
	}
	//void showData()
	//{
	//	std::cout << " Inmeters: " << meter <<std::endl<<"Incentimeter: "<<centimeter << std::endl;
	//}

};

int main()
{
	float m, cm,mt;
	std::cout << "ENTER THE DISTANCE IN METERS AND CENTIMETERS: "; 
	std::cin >> m >>cm;

	distance value(m, cm);
	m = value;
	std::cout << "THE EQUIVALENT DISTANCE IN METERS: " << m<<"m";
	

	std::cout <<std::endl<< "ENTER THE DISTANCE IN METERS: ";
	std::cin >>mt;
	value = mt;
	std::cout << "THE EQUIVALENT DISTANCE: " << value.return_meter() << "m "<<value.return_centimeter()<<"cm";

	return 0;
}