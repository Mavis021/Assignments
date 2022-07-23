////lab6_5.cpp
//Write a base class that asks the user to enter a complex numberand make a derived class that adds the complex number of its own with the base.
//Finally, make a third class that is a friend of derivedand calculate the difference of the base complex numberand its own complex number.

#include<iostream>
#include<cmath>
using namespace std;

class base
{
protected:
	int real, imaginary;
public:
	base(int re = 0, int im = 0)
	{
		real = re;
		imaginary = im;
	}
	void getData()
	{
		cout << "ENTER THE REAL AND IMAGINARY PART FOR BASE CLASS: ";
		cin >> real >> imaginary;
	}
	void showData()
	{
		cout << "BASE CLASS: " << "(" << real << "," << imaginary << ")" << endl;
	}
};

class friend1;
class derived :public base
{
private:
	int real, imaginary;
public:
	derived(int re = 0, int im = 0)
	{
		real = re;
		imaginary = im;
	}
	void getData()
	{
		base::getData();
		cout << endl << "ENTER THE SAME FOR DERIVED CLASS: ";
		cin >> real >> imaginary;
	}
	void addwithbase()
	{
		cout << endl << "ADDITION: ( " << base::real + real << " , " << base::imaginary + imaginary << " <<endl)";
	}
	void showData()
	{
		base::showData();
		cout << "DERIVED CLASS: " << "(" << real << "," << imaginary << ")" << endl;
	}
	friend class friend1;
};

class friend1
{
private:
	int freal, fimaginary;
public:
	friend1(int re = 0, int im = 0)
	{
		freal = re;
		fimaginary = im;
	}
	void getData()
	{
		cout << "ENTER THE REAL AND IMAGINARY PART: ";
		cin >> freal >> fimaginary;
	}
	void subtractwithbase(derived d)
	{
		cout << "SUBTRACTTION: " << "(" << (freal - d.base::real) << "," << (fimaginary - d.base::imaginary) << ")" << endl;
	}
	void showData()
	{
		cout << "FRIEND" << "(" << freal << "," << fimaginary << ")" << endl;
	}
};

int main()
{
	base b;
	derived d(3, 4);
	friend1 f(4, 5);

	d.base::getData();
	d.showData();
	f.showData();

	d.addwithbase();

	f.subtractwithbase(d);

	return 0;
}
