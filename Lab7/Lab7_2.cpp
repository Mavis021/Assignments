//lab7_2.cpp
//Create a class Personand two derived classes Employeeand Student, inherited from class Person.
//Now create a class Manager which is derived from two base classes Employeeand Student.Show the use of the virtual base class.

#include<iostream>
using namespace std;

class people
{
protected:
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
	void showData()
	{
		cout << "HELLO USER FROM class people.";
	}
};

class student : virtual public people
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
};

class employee :virtual public people
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
};

class Manager : public employee, public student
{

};

int main()
{
	Manager m;
	m.showData();
	return 0;
}