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
	int DepartmentID;
	char DepartmentName[20];
	
public:
	store()              //default constructor
	{
		cout << endl << "Default constructor invoked :" << endl;
		DepartmentID = 0;
		DepartmentName[0] = '\0';
		cout << "Object " << DepartmentID << " created."<<endl;
	}
	store(int dID, char* DN)      //parameterized constructor
	{
		cout << endl << "Parameterized constructor invoked :" << endl;
		DepartmentID = dID;
		strcmp(DepartmentName, DN);
		cout << "Object " << DepartmentID << " created.";
	}
	~store()
	{
		cout << endl << "Deconstructor invoked: " << "Object " << DepartmentID << " goes out of scope." << endl;
		
	}
};

int main()
{
	store* d1;
	int di;
	char dn[20];
	int n;
	cout << "ENTER THE NUMBER OF DATA YOU WANT TO REGISTER: ";
	cin >> n;

	d1 = new store[n]; //dynamic object array
	cout << "Objects created dynamically." << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "Object : " << i + 1 << endl << "ENTER THE DEPARTMENT ID: ";
		cin >> di;
		cout << endl << "ENTER THE DEPARTMENT NAME: ";
		cin >> dn;
		cout << endl;
		d1[i] = store(di, dn); //initializing the object arrays 
	}
	delete[]d1;
	return 0;
}
