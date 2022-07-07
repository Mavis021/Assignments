////lab5_2.cpp
//Write a class to store x, y, and z coordinates of a point in three - dimensional space.
//Overload addition and subtraction operators for additionand subtraction of two coordinate objects.
//Implement the operator functions as non - member functions(friend operator functions).

#include<iostream>
#include<cmath>
using namespace std;

class coordinate
{
private:
	int data;
public:
	coordinate(int a = 0)
	{
		data = a;
	}

	friend void operator+ (coordinate, coordinate);
	friend void operator- (coordinate, coordinate);
};

void operator +(coordinate c1, coordinate c2)
{
	int a = c1.data + c2.data;
	cout << "ADDITION: " << a << endl;
}

void operator -(coordinate c1, coordinate c2)
{
	int s = c1.data - c2.data;
	cout << "SUBTRACTION: " << s << endl;
}

int main()
{
	coordinate x(1), y(3), z(2);
	x + y;
	y - z;

	return 0;
}