//lab4_4.cpp
//Assume that one constructor initializes data member say num_vehicle, hour, and rate. 
//There should be a 10% discount if num_vehicle exceeds 10. Display the total charge. 
//Use two objects and show a bit-by-bit copy of one object to another (make your own copy constructor).

#include<iostream>
using namespace std;

class vehicle
{
private:
	int num_vehicle,hour;
	float rate;
public:
	vehicle(){}
	vehicle(int nv, int hrs,float rt)
	{
		num_vehicle = nv;
		hour = hrs;
		rate = rt;
	}
	void discount(float& r)
	{
		r -= 0.1 * r;
	}
	vehicle(vehicle &x)
	{
		num_vehicle = x.num_vehicle;
		hour =x.hour;
		rate = x.rate;
	}
	void display()
	{
		cout << endl << "number of vechile: " << num_vehicle << endl << "parked hour: " << hour <<endl<< "rate: " << rate<<endl;
	}
};

int main()
{
	vehicle v1;
	int n,h;
	float r;
	cout << "ENTER THE NUMBER OF VEHICLES PARKED: ";
	cin >> n;
	cout << "ENTER THE PARKED HOUR: ";
	cin >> h;
	cout << "ENTER THE TOTAL CHARGE: ";
	cin >> r;

	if (n > 10)
	{
		cout << endl << "DISCOUNT 10%" << endl;
		v1.discount(r);
	}
	v1= vehicle(n, h, r);
	vehicle v2(v1);                                  //copied v1 to v2

	cout << endl << "VALUES OF v1";
	v1.display();
	cout << endl << "VALUES OF v2";
	v2.display();

	return 0;
}

