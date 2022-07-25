//overloading logical operator
#include <iostream>
#include <cstdlib>
using namespace std;

class coordinate
{
private:
	float x, y;
public:
	coordinate(float a=0 , float b=0) : x(a), y(b) {}

	bool operator==(coordinate b)
	{
		if (x == b.x && y == b.y)
			return true;
		else
			return false;
	}
	coordinate operator &&(coordinate b)
	{
		//overloading the && operator as product operator (dot product)
		x *= b.x;
		y *= b.y;
		return *this;
	}
	coordinate operator ||(coordinate b)
	{
		//overloading the && operator as plus operator 
		x += b.x;
		y += b.y;
		return *this;
	}

	void display()
	{
		cout << "\n (" << x << " , " << y << ")\n";
	}
};

int main()
{
	coordinate c1(1,2), c2(1,2), c3;

	if (c1 == c2)
		cout << " c1 is equal to c2. \n";
	else 
		cout << " c1 is not equal to c2. \n";

	c3 = c1 && c2;
	cout << "\n dot product (&&) of c1 and c2 = ";
	c3.display();

	c3 = c1 || c2;
	cout << "\n adding (||) c1 and c2 = ";
	c3.display();

	return 0;
}