//lab2_1.cpp
//A program in c++ to set a structure to hold a date (mm,dd and yy), assign values to the members of the structure and print out the values in the format 11/28/2004 by function.
//Pass the structure to the function


#include <iostream>
#include<string>
using namespace std;

struct date
{
	int year, month, day;
};

void display(struct date fd)
{
	cout << "COMPLETE DATE: ";
	cout<< fd.day<< "/" << fd.month << "/" << fd.year << endl;
}

int main()
{
	struct date d1;

	//prompting the user to enter the date
	cout << "WHAT IS THE CURRENT YEAR?: ";
	cin >> d1.year;
	cout << "ENTER THE CURRENT MONTH IN INTEGER FORM: ";
	cin >> d1.month;
	cout << "ENTER TODAY'S DATE: ";
	cin >> d1.day;
	cout << endl;
	//calling a function for display
	cout << "DISPLAYING THE DATE USING A FUNCTION "<<endl;
	display(d1);

	return 0;
}