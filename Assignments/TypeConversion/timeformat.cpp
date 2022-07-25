
//Conversion from the 24-hour clock to 12 hour
#include<iostream>
using namespace std;

class Time12
{
private:
	int hrs, min, sec;
public:
	Time12(int h = 0, int m = 0, int s = 0):hrs(h),min(m),sec(s){}         //parameterized constructor
    
	void display()
	{
		cout << "12 hours format: " << endl << hrs << ":" << min << ":" << sec << endl;
	}
};

class Time24
{
private:
	int hrs, min, sec;

public:
	Time24(int h = 0, int m = 0, int s = 0) :hrs(h), min(m), sec(s) {}

	operator Time12()
	{
		int h;
		if (hrs >= 12 && min >= 0)
		{
			h = hrs-12;
			return Time12(h, min, sec);
		}
		else
		{
			return Time12(hrs, min, sec);
		}

	}
	void display()
	{
		//24 hours format
		cout << "24 hours format: " << endl << hrs << ":" << min << ":" << sec << endl;
	}
};

int main()
{
	Time24 t24(10, 10, 2);
	Time12 t12;

	t12 = t24; // 24 hours format to 12 hours format
	t24.display();
	cout << "EQUIVALENT TO: " << endl;
	t12.display();

	return 0;
}
