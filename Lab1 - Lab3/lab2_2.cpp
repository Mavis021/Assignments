//lab2_2.cpp
//A program in c++ using the function overloading that converts feet to inches. Use function with no argument, one argument and two arguments. Decide yourself the types of arguments.
//Use pass by reference in any one of the function above.

//1 feet = 12 inches

#include <iostream>
#include<string>
using namespace std;

int conversion(int fe = 1, int i = 12)
{
	i *= fe;
	return(i);
}

void conversion(float &a, int &b)
{
	b *= a;
}

int main()
{
	int f=1, i=12;
	float f1;

	//calling the function
	i = conversion();
	cout << "CALLING WITH NO ARGUMENTS: "<<endl;
	cout<<f << " feet =" << i << " inch"<<endl;

	//prompting the user for data
	cout << "ENTER A HEIGHT IN FEET: ";
	cin >> f;

	i = 12;
	i = conversion(f);
	cout << "CALLING WITH ONE ARGUMENTS: "<<endl << f << " feet = " << i << " inch"<<endl;

	i = 12;
	i = conversion(f, i);
	cout << "CALLING WITH TWO ARGUMENTS: " <<endl<< f<< " feet = " << i << " inch"<<endl;

	i = 12;
	f1 = (float)f;
	
	conversion(f1, i);
	cout << "PASS BY REFERENCE: "<<endl << f1 << " feet = " << i << " inch"<<endl;



	return 0;
}