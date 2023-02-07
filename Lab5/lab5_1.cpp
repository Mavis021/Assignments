//lab5_1.cpp
/*Write a class for instantiating the objects that represent the two - dimensional Cartesian coordinate system.

A.Make a particular member function of one class as a friend function of another class for addition.

B.Make the other three functions to work as a bridge between the classes for multiplication, division, and subtraction.

C.Also write a small program to demonstrate that all the member functions of one class are the friend functions of another class if the former class is made friend to the latter.

Make least possible classes to demonstrate all the above in a single program without conflict.*/

#include<iostream>
#include<cmath>

using namespace std;

class coordinateY;
//coordinateY coordinateY::coordinateY(int a = 0){}
class coordinateX
{
private:
	int x;
public:
	coordinateX(int a = 0)   //constructor
	{
		x = a;
	}
	friend class coordinateY;
	friend int add(coordinateX, coordinateY);        //friend function declaration

	void multiplication(int t)
	{
		x = x * t;
	}
	void division( int b)
	{
		x = x/b;
	}

	void subtraction(int a )
	{
		x = x- a;
	}

};

class coordinateY
{
private:
	int y;
public:
	coordinateY(int a = 0)   //constructor
	{
		y = a;
	}

	void showMultiplication(coordinateX a)
	{
		a.multiplication(y);
		cout << endl << "MULTIPLICATION: " << a.x;
	}
	void showDivision(coordinateX a)
	{
		a.division(y);
		cout << endl << "Division: " << a.x;
	}
	void showSubtraction(coordinateX a)
	{
		a.subtraction(y);
		cout << endl << "SUBTRACTION: " << a.x;
	}

	friend class coordinateX;
	friend int add(coordinateX, coordinateY);
};



int add(coordinateX a, coordinateY b)
{
	int r;
	r = a.x + b.y;
	return r;
}


int main()
{
	coordinateX x1(7);
	coordinateY y1(3);

	cout<<endl<<"ADDITION: "<<add(x1, y1);

	
	y1.showMultiplication(x1);

	y1.showDivision(x1);

	y1.showSubtraction(x1);

	return 0;
}