//assignmentOperator.cpp
//overloading assignment operator
#include <iostream>
#include <cstdlib>
#include<iomanip>
using namespace std;

class equate
{
private:
	int x, y;
public:
	equate(int a=0 , int b=0) : x(a), y(b) {}

	void operator = (equate& b)
	{
		x = b.x;
		y = b.y;
	}


	void display()
	{
		cout << "x = " << x << setw(5)<< "y = " << y << "\n";
	}
};



int main()
{
	equate e1(3,4), e2(5,6);

	cout << "e1 values :";
	e1.display();
	cout << "e2 values :";
	e2.display();

	e1 = e2;
	cout << "\n after assignment: e1 = ";
	e1.display();

	return 0;
}
