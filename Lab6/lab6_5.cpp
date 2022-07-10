////lab6_5.cpp
//Write a base class that asks the user to enter a complex numberand make a derived class that adds the complex number of its own with the base.
//Finally, make a third class that is a friend of derivedand calculate the difference of the base complex numberand its own complex number.

#include<iostream>
#include<cmath>
using namespace std;

class base
{
public:
	int real, imaginary;
	base(int re = 0, int im = 0)
	{
		real = re;
		imaginary = im;
	}
	void getData()
	{
		cout << "ENTER THE REAL AND IMAGINARY PART: ";
		cin >> real >> imaginary;
	}
	void showData()
	{
		cout <<"BASE CLASS: "<< "("<<real << "," << imaginary << ")" << endl;
	}
};

class friend1;
class derived: base
{
private:
	int real, imaginary;
public:
	derived(int re = 0, int im = 0)
	{
		real = re;
		imaginary = im;
	}
	int returnBaseReal()
	{
		return base::real;
	}
	int returnBaseimag()
	{
		return base::imaginary;
	}
	void addwithbase(base b)
	{
		cout << "ADDITION: " << "(" << (real + b.real)<< "," << (imaginary + b.imaginary) << ")" << endl;
	}
	void showData()
	{
		cout <<"DERIVED: "<< "(" << real << "," << imaginary << ")" << endl;
	}
	friend class derived2;
};

class friend1
{
private:
	int real, imaginary;
public:
	friend1(int re = 0, int im = 0)
	{
		real = re;
		imaginary = im;
	}
	void getData()
	{
		cout << "ENTER THE REAL AND IMAGINARY PART: ";
		cin >> real >> imaginary;
	}
	void subtractwithbase(base b)
	{
		cout << "SUBTRACTTION: " << "(" << (real - b.real) << "," << (imaginary - b.imaginary) << ")" << endl;
	}
	void showData()
	{
		cout <<"FRIEND"<< "(" << real << "," << imaginary << ")" << endl;
	}
	friend class derived2;
};

int main()
{
	base b(2, 3);
	derived d(3, 4);
	friend1 f(4, 5);
	
	b.showData();
	d.showData();
	f.showData();

	d.addwithbase(b);

	f.subtractwithbase(b);

	return 0;
}
