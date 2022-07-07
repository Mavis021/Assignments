//la5_3.cpp
//Write a program to compare two objects of a class that contains an integer value as its data member. 
//Make overloading functions to overload equality(==), less than(<), greater than(>), not equal (!=), 
//greater than or equal to (>=), and less than or equal to(<=) operators using member operator functions.

#include<iostream>
using namespace std;

class compare
{
private:
	int data;
public:

	compare(int a = 0)
	{
		data = a;
	}
	void operator ==(compare next)
	{
		if (data == next.data)
		{
			cout << " THE DBJECTS ARE EQUAL." << endl;
		}
		else
		{
			cout << "THE OBJECTS ARE NOT EQUAL. " << endl;
		}
	}
	void operator <(compare next)
	{
		if (data < next.data)
		{
			cout << data<< " less than "<<next.data << endl;
		}
		else
		{
			cout <<next.data<< " less than "<<data << endl;
		}
	}
	void operator >(compare next)
	{
		if (data > next.data)
		{
			cout << data << " greater than " << next.data << endl;
		}
		else
		{
			cout << next.data << " greater than " << data << endl;
		}
	}
	void operator !=(compare next)
	{
		if (data != next.data)
		{
			cout << data << " IS NOT EQUAL TO " << next.data << endl;
		}
		else
		{
			cout << next.data << " IS EQUAL TO " << data << endl;
		}
	}
	void operator <=(compare next)
	{
		if (data <= next.data)
		{
			cout << data << " less than or equal to " << next.data << endl;
		}
		else
		{
			cout << next.data << " less than or equal to " << data << endl;
		}
	}
	void operator >=(compare next)
	{
		if (data >= next.data)
		{
			cout << data << " greater than or equal to " << next.data << endl;
		}
		else
		{
			cout << next.data << " greater than or equal to " << data << endl;
		}
	}
};

int main()
{
	compare c1(7), c2(3);

	c1 == c2;
	c1 != c2;
	c1 < c2;
	c1 > c2;
	c1 <= c2;
	c1 >= c2;

	return 0;
}