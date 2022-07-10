//lab6_3.cpp
//Create a class called Musicians to contain three methods string(), wind(), and perc().Each of these methods should initialize a string array to contain the following instruments
//
//- veena, guitar, sitar, sarodand mandolin under string()
//
//- flute, clarinet saxophone, nadhaswaram, and piccolo under wind()
//
//- tabla, mridangam, bangos, drumsand tambour under perc()
//
//It should also display the contents of the arrays that are initialized.Create a derived class called TypeIns to contain a method called get() and show().The get() method must display a  menu as follows
//
//Type of instruments to be displayed
//
//a.String instruments
//
//b.Wind instruments
//
//c.Percussion instruments
//
//The show() method should display the relevant detail according to our choice.The base class variables must be accessible only to their derived classes.

#include<iostream>
using namespace std;

class Musicians
{
public:
	string baseString[4] = { "veena","guitar","sitar","sarodand mandolin" };
	string baseWind[4] = { "flute","clarinet saxophone","nadhaswaram","piccolo"};
	string basePerc[4] = {"tabla","mridangam","bangos","drumsand tambour"};
};

class TypeIns : public Musicians
{
public:
	void get()
	{
		cout << "Type of instruments to be displayed" << endl
			 << "a.String instruments" << endl 
			 << "b.Wind instruments" << endl
			 << "c.Percussion instruments" << endl;
	}
	void show(char ch)
	{
		switch (ch)
		{
		case 'a':
		{
			for (int i = 0; i < 4; i++)
			{
				cout << baseString[i] << ",";
			}
			cout << endl;
			break;
		}
		case 'b':
		{
			for (int i = 0; i < 4; i++)
			{
				cout << baseWind[i] << ",";
			}
			cout << endl;
			break;
		}
		case 'c':
		{
			for (int i = 0; i < 4; i++)
			{
				cout << basePerc[i] << ",";
			}
			cout << endl;
			break;
		}
		default:
		{
			cout << "Invalid character entry.";
			break;
		}
		}
	}

};

int main()
{
	TypeIns ti;
	char ch;
	ti.get();

	cout << "CHOOSE AN INSTRUMENT LIST TO DISPLAY: ";
	cin >> ch;
	ti.show(ch);

	return 0;
}