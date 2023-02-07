//lab4_3.cpp
//Write a class that can store Department ID and Department Name with constructors to initialize its members.
// Write destructor member in the same class and display the message "Object n goes out of the scope".
//Your program should be made such that it should show the order of constructor and destructor invocation

#include<iostream>
#include<cstring>
using namespace std;

class store
{
private:
	char* DepartmentID;
	char* DepartmentName;
	int n;
public:
	store()
	{
		cout << endl << "Default constructor invoked :" << endl;
		DepartmentID = new char[1];
		DepartmentName = new char[1];
		DepartmentID[0] = '\0';
		DepartmentName[0] = '\0';
		n = 0;
	}
	store(char* dId, char* DN, int i)
	{
		cout << endl << "Parameterized constructor invoked :" << endl;
		DepartmentID = new char[strlen(dId) + 1];
		DepartmentName = new char[strlen(DN) + 1];
		strcmp(DepartmentID, dId);
		strcmp(DepartmentName, DN);
		n = i + 1;
	}
	~store()
	{
		cout << endl << "Deconstructor invoked: " << "Object " << n << " goes out of scope." << endl;
		delete[]DepartmentID;
		delete[]DepartmentName;
	}
};

int main()
{
	store* d1;
	char di[10], dn[10];
	int n;
	cout << "ENTER THE NUMBER OF DATA YOU WANT TO REGISTER: ";
	cin >> n;

	d1 = new store[n]; //dynamic object array
	cout << "Objects created dynamically." << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "Object : " << i + 1 << endl << "ENTER THE DEPARTMENT ID: ";
		//cin.getline(di,10);
		cin >> di;
		cout << endl << "ENTER THE DEPARTMENT NAME: ";
		cin >> dn;
		cout << endl;
		d1[i] = store(di, dn, i); //initializing the dynamic object arrays in dynamic constructor
	}
	delete[]d1;
	return 0;
}
