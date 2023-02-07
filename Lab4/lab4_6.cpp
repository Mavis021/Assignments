//lab4_6.cpp
//Create a class with a data member to hold a "serial number" for each object created from the class.
//That is, the first object created will be numbered 1, the second 2, and so on by using the basic concept of static data members.
//Use static member function if it is useful in the program. Otherwise, make a separate program that demonstrates the use of static member function.
//
#include<iostream>
using namespace std;

class objects
{
private:
	static int serialNumber;
	int count;
public:
	objects()
	{
		serialNumber++;
		count = serialNumber;
	}
	~objects()
	{
		serialNumber--;
		cout << " Destroying the data with value: " << count << endl;
        showTotal();
	}
	static void showTotal()
	{
		cout << "NUMBER OF OBJECTS ARE " << serialNumber << endl;
	}
	void showData()
	{
		cout << " THE NUMBER IS " << count << endl;
	}
};

int objects::serialNumber = 0;
int main()
{
	objects o1;
	objects o2, o3;

	o1.showData();
	o2.showData();
	o3.showData();
	objects::showTotal();
    objects o4;
    o4.showData();
    o1.showTotal();
	return 0;
}
