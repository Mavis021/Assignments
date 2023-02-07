//lab2_4.cpp
//A program in c++ that has a function that passes two temperatures by reference and sets the larger of the two numbers to a value entered by user by using return by reference

#include<iostream>
using namespace std;

int& higher_replace(int &x, int &y)
{
	if (x > y)
		return x;
	else
		return y;
}
int main()
{
	int a = 5, b = 7,n;
	cout << "THE VALUE OF a = " << a << " AND THE VALUE OF b = " << b << "." << endl << "ENTER AN INTEGER THAT YOU WANT TO REPLACE WITH b:" << endl;
	cin >> n;

	//calling the function passing reference and return by reference
	higher_replace(a, b) = n;

	cout << "AFTER THE FUNCTION CALL: a = " << a << " AND b = " << b << "." << endl;
	return 0;
}