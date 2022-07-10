//lab6_4.cpp
//Write three derived classes inheriting functionality of base class person(should have a member function that asks to enter nameand age) and 
//with added unique features of student, and employee, and functionality to assign, changeand delete records of studentand employee.
//And make one member function for printing the address of the objects of classes(base and derived) using this pointer.Create two objects 
//of the base classand derived classes eachand print the addresses of individual objects.
//Using a calculator, calculate the address space occupied by each objectand verify this with address spaces printed by the program.

#include<iostream>
using namespace std;

class people
{
private:
	string name;
	int age;
public:
	void enterName()
	{
		cout << "ENTER YOUR NAME: ";
		cin >> name;
	}
	void enterAge()
	{
		cout << "ENTER YOUR AGE: ";
		cin >> age;
	}
	void printAddress()
	{
		cout << "Address: " << this << endl;
	}
};

class student:people
{
private:
	string studentID;
	char section;
public:
	void getData()
	{
	people::enterName();
	people::enterAge();
		cout << "ENTER YOUR STUDENTSID: ";
		cin >> studentID;
	}
	void getSection()
	{
		cout << "ENTER YOUR SECTION: ";
		cin >> section;
	}
	void printAddress()
	{
		cout << "Address: " << this << endl;
	}

};

class employee :people
{
private:
	string employeeID;
	int salary;
public:
	void getData()
	{
		people::enterName();
		people::enterAge();
		cout << "ENTER YOUR EMPLOYEEID: ";
		cin >> employeeID;
		cout << "ENTER YOUR SALARY: ";
		cin >> salary;
	}
	void printAddress()
	{
		cout << "Address: " << this << endl;
	}

};

int main()
{
	people p1, p2;
	student s1, s2;
	employee e1, e2;

	//s1.getData();
	//s2.getData();

	//e1.getData();
	//e2.getData();

	//Addresses of the objects
	p1.printAddress();
	p2.printAddress();
	s1.printAddress();
	s2.printAddress();
	e1.printAddress();
	e2.printAddress();

	// spaces occupied by the objects
	cout << "p1: " << sizeof(p1) << endl;
	cout << "p2: " << sizeof(p2) << endl;
	cout << "s1: " << sizeof(s1) << endl;
	cout << "s2: " << sizeof(s2) << endl;
	cout << "e1: " << sizeof(e1) << endl;
	cout << "e2: " << sizeof(e2) << endl;

	return 0;
}