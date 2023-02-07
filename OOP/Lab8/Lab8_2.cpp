//Lab8_1.cpp
//Write a program to create a user - defined manipulator that will format the output by setting the width,
//precision, and fill character at the same time by passing arguments.
//User-Defined Manipulator

#include <iostream>
#include<iomanip>

using namespace std;

class Manipulation
{
private:
	int width, prec;
	char fill;
public:
	Manipulation(int w=0,int p =0,char f= '0') :width(w), prec(p), fill(f) {}
	friend ostream& operator<<(ostream& , Manipulation);
};

ostream& operator<< (ostream& output, Manipulation mp)   //parameterized custom manipulator
{
	output << setw(mp.width) << setprecision(mp.prec) << setfill(mp.fill) << flush;
	return output;
}

Manipulation manipulate(int width, int precision, char fill)   //name given to the user defined manipulator
{
	return Manipulation(width, precision, fill);
}

int main()
{
	float f = 77.77888;

	cout<<manipulate(10,5,'#')<<f<< endl;

	return 0;
}
