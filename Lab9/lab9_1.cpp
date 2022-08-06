//Lab9_1.cpp
//Create a function called sum() that returns the sum of the elements of an array.Make this function into a template so it will work with any numerical type.
//Write a program that applies this function to data of various types.

#include<iostream>
#include<cstring>

using namespace std;

template <class T>
T sum(T* arr,int count)
{
	T a=0;
	for (int i = 0; i < count; i++)
	{
		a += arr[i];
	}
	return a;
}

int main()
{
	int a[3] = { 1,2,3 };
	double d[2] = { 3.3,5.3 };
	float f[3] = { 2.2,3.3,4.44 };

	cout << "THE SUM OF ELEMENTS OF a = "<< sum(a, 3) <<endl;
	cout << "THE SUM OF ELEMENTS OF d = " << sum(d, 2) << endl;
	cout << "THE SUM OF ELEMENTS OF f = " << sum(f, 3) << endl;


	return 0;
}
