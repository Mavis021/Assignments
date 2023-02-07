//lab2_5.cpp
//A program in c++ to display the net salary paid by the company to the employee after the deducting 10 percent tax

#include<iostream>
using namespace std;

inline float net_salary(float s)
{
	float n = (s - 0.1 * s);
	return n;
}

int main()
{
	int n;

	cout << "ENTER THE EMPLOYEE SALARY: " << endl;
	cin >> n;
	//inline function

	cout << endl << "THE NET SALARY GIVEN BY THE COMPANY TO THE EMPLOYEE IS " << net_salary(n) << ".";


	return 0;
}
