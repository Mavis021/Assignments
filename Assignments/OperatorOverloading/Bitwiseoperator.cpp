// Bitwise operators

#include <iostream>
#include <cstdlib>
using namespace std;

class coordinate
{
private:
	float x, y;
public:
	coordinate(float a = 0, float b = 0) : x(a), y(b) {}

	friend istream& operator>>(istream& i, coordinate& c);
	friend ostream& operator<<(ostream& o, coordinate& c);
};
    
    istream& operator>>(istream& i, coordinate& c)
	{
		i >> c.x >> c.y;
		return i;
	}
	ostream& operator<<(ostream& o, coordinate& c)
	{
		o <<"( "<<c.x << " , " << c.y<<" )";
		return o;
	}


int main()
{
	coordinate c1;
	cout << "Enter the value of coordinates: ";
	cin >> c1;
	cout << "The entered coordinate: \n" << c1;
	return 0;
}
