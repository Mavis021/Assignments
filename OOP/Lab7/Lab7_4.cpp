//Lab7_4.cpp
//Use of RTTI to print the datas in runtime
// Create a polymorphic class Vehicle and create other derived classes Bus, Car, and Bike from Vehicle. 
// Illustrate RTTI by the use of dynamic_cast and typeid operators in this program.


#include<iostream>
using namespace std;

class Vehicle   //polymorphic class
{
private:
	int engineNumber;
public:
	Vehicle(int engineN = 0000):engineNumber(engineN){}
	virtual ~Vehicle(){}
	virtual void getData()
	{
		cout << "ENTER THE ENGINE-NUMBER :";
		cin >> engineNumber;
	}
	virtual void showData()
	{
		cout << "ENGINE NUMBER: " << engineNumber << endl;
	}

};

class Bus : virtual public Vehicle
{
private:
	string name;
public:
	Bus(string n = "Marcopolo") :name(n){}
	~Bus(){}
	void getData()
	{
		cout << endl << "ENTER THE COMPANY NAME OF THE BUS: ";
		cin >> name;
		Vehicle::getData();
	}
	void showData()
	{
		cout << "BRAND NAME: " << name << endl;
		Vehicle::showData();
	}
};

class Car : virtual public Vehicle
{
private:
	string name;
public:
	Car(string n = "Tesla") :name(n) {}
	~Car(){}
	void getData()
	{
		cout << endl << "ENTER THE COMPANY NAME OF THE CAR: ";
		cin >> name;
		Vehicle::getData();
	}
	void showData()
	{
		cout << "BRAND NAME: " << name << endl;
		Vehicle::showData();
	}
};

class Bike : virtual public Vehicle
{
private:
	string name;
public:
	Bike(string n = "Kawasaki") :name(n) {}
	~Bike(){}
	void getData()
	{
		cout << endl << "ENTER THE COMPANY NAME OF THE BIKE: ";
		cin >> name;
		Vehicle::getData();
	}
	void showData()
	{
		cout << "BRAND NAME: " << name<< endl;
		Vehicle::showData();
	}
};

int main()
{

	//creating an array of pointers
	Vehicle** V = new Vehicle*[3];
	
	Bus *b = new Bus;
	b->getData();
	Car *c = new Car;
	c->getData();
	Bike *bi = new Bike;
	bi->getData();

	//casting to derived types
	V[0] = dynamic_cast<Bus*>(b);
	V[1] = dynamic_cast<Car*>(c);
	V[2] = dynamic_cast<Bike*>(bi);

	//printing the typeIds of the classes
	cout <<endl<< "Type IDs of base class pointers after casting them to derived class: " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << typeid(*V[i]).name() << " : Brand Name : ";
		V[i]->showData();
		cout << endl;
	}


	delete b;
	delete c;
	delete bi;
	delete[]V;
	return 0;
}
