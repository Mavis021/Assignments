//lab4_1.cpp
//a program in c++ to calculate time and display in 12 hours or 24 hours format. using a constructor
//The class should have a member function to add time objects and return the result as a time object.

#include<iostream>
using namespace std;

class Time
{
private:
	int hrs,min,sec;

public:

	Time()                             //default constructor
	{
		hrs = 0;
		min = 0;
		sec = 0;
	}
	Time(int h, int m, int s)         //parameterized constructor
	{
		hrs = h;
		min = m;
		sec = s;
	}

	Time sum(Time t)
	{
		Time addtime;            //adding time objects
		addtime.hrs = hrs + t.hrs;
		addtime.min = min + t.min;
		addtime.sec = sec + t.sec;

		if (addtime.sec >= 60)            //calculations
		{
			addtime.min += addtime.sec / 60;
			addtime.sec = addtime.sec % 60;
		}
		if (addtime.min >= 60)
		{
			addtime.hrs += addtime.min / 60;
			addtime.min = addtime.min % 60;
		}

		return addtime;
	}
	void display12()
	{
		//12 hours format
	
		if (hrs >= 12 && min >= 0)
		{
			hrs -= 12;
			cout << "12 hours format: " << endl << hrs << ":" << min << ":" << sec << " PM"<<endl;
		}
		else  
		{
			cout << "12 hours format: " << endl << hrs << ":" << min << ":" << sec << " AM" << endl;
		}
	}
	void display24()
	{
		//24 hours format
			cout << "24 hours format: " << endl << hrs << ":" << min << ":" << sec << endl;
	}
};

int main()
{
	Time t1, t2(2,50,51),t3(13,40,17), ati;

	cout << "ENTERED TIME DATA t1,t2 & t3 respectively: " << endl<<endl;
	t1.display24();
	t2.display24();
	t3.display24();

	// addition data 
	ati = t1.sum(t2);
	cout <<endl<< "t1 + t2: "<<endl;
	ati.display24();
	ati.display12();

	ati = t2.sum(t3);
	cout << endl<<"t2 + t3: " << endl;
	ati.display24();
	ati.display12();
	
	return 0;
}