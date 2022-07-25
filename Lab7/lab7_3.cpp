//lab7_3.cpp
//Write a program with an abstract class Studentand create derive classes Engineering, Medicineand Science from base class Student.
//Create the objects of the derived classesand process themand access them using an array of pointers of type base class Student.

#include<iostream>
#include<cstdlib>
using namespace std;

class student
{
protected:
	string name;
public:
	student() {};
	virtual void getData() = 0;
	virtual void showData() = 0;
	virtual ~student()
	{
		cout << endl << "destructor of class student.";
	}
};

class medical : public student
{
public:
	medical(){}
	~medical()
	{
		cout << endl << "destructor from medical class.";
	}
	void getData()
	{
		cout <<endl<< "ENTER YOUR MEDICAL ID: ";
		cin >> name;
	}
	void showData()
	{
		cout <<endl<< " from medical, name: " << name;
	}
};

class engineering :virtual public student
{
public:
	engineering(){}
	~engineering()
	{
		cout << endl << "Destructor from engineering class.";
	}
	void getData()
	{
		cout << endl << "ENTER YOUR ENGINEERING ID: ";
		cin >> name;
	}
	void showData()
	{
		cout <<endl<< " from engineering, name: " << name;
	}
};

class science : public student
{
public:
	science(){}
	~science()
	{
		cout << endl << "Destructor from science class.";
	}
	void getData()
	{
		cout << endl << "ENTER YOUR SCIENCE ID: ";
		cin >> name;
	}
	void showData()
	{
		cout <<endl<< " from science, name: " << name;
	}
};

int main()
{
	student* stu[3];
	stu[0] = new science();
	stu[1] = new engineering();
	stu[2] = new medical();


	stu[0]->getData();
	stu[1]->getData();
	stu[2]->getData();

	stu[0]->showData();
	stu[1]->showData();
	stu[2]->showData();

	delete stu[0];
	delete stu[1];
	delete stu[2];

	return 0;
}
