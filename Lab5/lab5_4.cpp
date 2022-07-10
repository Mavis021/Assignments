//lab5_4.cpp
//Write a class Date that overloads prefixand postfix operators to increase the Date object by one day, 
//while causing appropriate increments to the monthand year(use the appropriate condition for leap year).
//The prefixand postfix operators in the Date class should behave exactly like the built - in increment operators.

#include<iostream>
using namespace std;


class Date
{
private:
	int year, month, day;
public:
	int monthsData[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	Date(int y = 0, int m = 0, int d = 0)
	{
		year = y;
		month = m;
		day = d;
	}
	void SolveLeapYear(int year)
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			monthsData[1] = 29;
	}

	//prefix
	Date operator ++()
	{
		SolveLeapYear(year);
		if (day < monthsData[month-1])
		{
			day++;
		}
		else if (day == monthsData[month-1] || day == monthsData[month-1]+1)
		{
			day = 1;
			month++;
			if (month == 12)
			{
				day = 1;
				month = 1;
				year++;
			}
		}
		else
		{
			cout << "THE GIVEN DATE IS INVALID." << endl;
			exit(0);
		}

		return *this;
	}

	Date operator ++(int)
	{
		SolveLeapYear(year);
		Date* temp;
		temp->year = this->year;
		temp->month = this->month;
		temp->day = this->day;

		if (day < monthsData[month - 1])
		{
			day++;
		}
		else if (day == monthsData[month - 1] || day == monthsData[month - 1] + 1)
		{
			day = 1;
			month++;
			if (month == 12)
			{
				day = 1;
				month = 1;
				year++;
			}
		}
		else
		{
			cout << "THE GIVEN DATE IS INVALID." << endl;
			exit(0);
		}

		return *temp;
	}

	void showData()
	{
		cout << endl << year << "/ " << month << "/ " << day << endl;
	}

};

int main()
{
	Date d1(2000,2,28), d2(1999,3,31),postfixTest;
	
	d1.showData();
	d2.showData();
	++d1;
	postfixTest = d2++;
	
	cout << endl << "PREFIX:";
	d1.showData();

	cout << endl << "POSTFIX: ";
	postfixTest.showData();
	d2.showData();

	return 0;
}