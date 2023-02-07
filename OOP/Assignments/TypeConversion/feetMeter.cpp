//Conversion from meter system to feet system.
//1 feet = 0.3048 meters
#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

class feet;
class meter
{
private:;
	   float m;
public:
	meter(float a =0.0):m(a) {}
	~meter(){}

	operator feet();

	void showData()
	{
		cout << m << " meters";
	}
};
class feet
{
private:;
	   float ft;
public:
	feet(float a =0) :ft(a) {}
	~feet() {}
	operator meter()
	{
		float x = static_cast<float> (ft*0.3048);
		return meter(x);
	}
	void showData()
	{
		cout <<ft << " feet ";
	}
};

meter::operator feet()
{
		float f = static_cast<float> (m/0.3048);
		return feet(f);
}

int main()
{
	feet f(2);
	meter m;
	
	cout << "FEET INTO METER:"<<endl;
	m = f;
	f.showData();
	cout << " = ";
	m.showData();
	cout << endl;

	m = meter(3);
	cout << "METER INTO FEET:"<<endl;
	f = m;
	m.showData();
	cout << " = ";
	f.showData();
	cout << endl;
	return 0;
}
