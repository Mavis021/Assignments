
//Conversion from Cartesian coordinate to the polar coordinate system.
//x = r costheta, y= r sintheta
//r square = x square + y square, angle = tan inverse (y/x)
#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

class Polar;
class Cartesian
{
private:;
	   float x,y;
public:
	Cartesian(float a =0.0,float b = 0.0):x(a),y(b) {}
	~Cartesian(){}

	operator Polar();

	void showData()
	{
		cout << "( " << x << " , " << y << " )";
	}
};
class Polar
{
private:;
	   float angle,radius;
public:
	Polar(float r = 0.0,float a =0) :radius(r),angle(a) {}
	~Polar() {}
	operator Cartesian()
	{
		float x = static_cast<int> (radius * cos(angle));
		float y = static_cast<int> (radius * sin(angle));
		return Cartesian(x, y);
	}
	void showData()
	{
		cout << "( " << radius << " , " << angle << " )";
	}
};

Cartesian::operator Polar()
{
		float rad = static_cast<float> (atan(y / x));
		float radius = static_cast<float> (sqrt(x * x + y * y));
		return Polar(radius, rad);
}

int main()
{
	Polar p(12.2,1.047197551);
	Cartesian c;
	
	cout << "POLAR TO CARTESIAN:"<<endl;
	c = p;
	p.showData();
	cout << " = ";
	c.showData();
	cout << endl;

	c = Cartesian(2, 3);
	cout << "CARTESIAN TO POLAR:"<<endl;
	p = c;
	c.showData();
	cout << " = ";
	p.showData();
	cout << endl;
	return 0;
}
