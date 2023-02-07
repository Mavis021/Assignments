//overloading function call operator
#include <iostream>
#include <cstdlib>
using namespace std;

class coordinate
{
private:
	float x, y;
public:
	coordinate(float a=0 , float b=0) : x(a), y(b) {}

	coordinate operator ()(float a, float b)
	{
		x += a;
		y += b;
		return *this;
	}
	coordinate operator ()(float a)
	{
		x += a;
		return *this;
	}

	void display()
	{
		cout << "\n (" << x << " , " << y << ")\n";
	}
};

int main()
{
	coordinate c1, c2,c3;
	c1 = c2(3.4, 3); //two argument function call operator
	c2(5, 7.8);
	c3(3);//single argument function call operator

	c1.display();
	c2.display();
	c3.display();

	return 0;
}
