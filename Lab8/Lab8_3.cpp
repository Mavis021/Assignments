//Lab8_3.cpp
//Write a program to overload stream operators to read a complex numberand display the complex number in a + ib format.
//Streamoperator overloading

#include <iostream>
#include <cstdlib>
using namespace std;

class Complex
{
private:
	float a, b;
public:
	Complex(float x = 0, float y = 0) : a(x), b(y) {}

	friend istream& operator>>(istream& i, Complex& c);
	friend ostream& operator<<(ostream& o, Complex& c);
};

istream& operator>>(istream& i, Complex& c)
{
	i >> c.a >> c.b;
	return i;
}
ostream& operator<<(ostream& o, Complex& c)
{
	o << c.a << " + i" << c.b;
	return o;
}


int main()
{
	Complex c1;
	cout << "Enter the real and imaginary part of a complex number: ";
	cin >> c1;
	cout << "The entered coordinate: " << c1;
	return 0;
}
