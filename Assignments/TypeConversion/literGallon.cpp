//Conversion from liter to gallons
//1 gallon = 4.54609 Liter

#include<iostream>
using namespace std;

class Liter;
class Gallon
{
private:
	float gvol;
public:
	Gallon(float v = 0):gvol(v) {}     

	operator Liter();
    
	void display()
	{
		cout << gvol << " Gallons ";
	}
};

class Liter
{
private:
	float lvol;

public:
	Liter(float l = 0) :lvol(l) {}

	operator Gallon()    //CONVERSION IN SOURCE OBJECT
	{
		float gvol = static_cast<float>(lvol / 4.54609);
		return Gallon(gvol);
	}
	void display()
	{
		//24 hours format
		cout << lvol << " Liter ";
	}
};

Gallon ::operator Liter()
{
	float v = static_cast<float>( gvol * 4.54609);
	return Liter(v);
}

int main()
{
	Liter l(10);
	Gallon g;

	g = l; // Liter to gallon
	l.display();
	cout << " = ";
	g.display();
	cout << endl;

	g = Gallon(5);
	l = g; //gallon to liter
	g.display();
	cout << " = ";
	l.display();
	cout << endl;

	return 0;
}
