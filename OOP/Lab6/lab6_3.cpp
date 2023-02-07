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
protected:
	string baseString[5], baseWind[5], basePerc[4];
public:
	void String()
	{
		//baseString data
		baseString[0] = "veena";
		baseString[1] = "guitar";
		baseString[2] = "sitar";
		baseString[3] = "sarodand mandolin";
	}
	void Wind()
	{
		//Wind data
		baseWind[0] = "flute";
		baseWind[1] = "clarinet saxophone";
		baseWind[2] = "nadhaswaram";
		baseWind[3] = "piccolo";
	}
	void Perc()
	{
		//Perc data
		basePerc[0] = "tabla";
		basePerc[1] = "mridangam";
		basePerc[2] = "bangos";
		basePerc[3] = "drumsand tambour";
	}
};

class TypeIns :protected Musicians
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
			Musicians::String();
			for (int i = 0; i < 4; i++)
			{
				cout << Musicians::baseString[i] << ",";
			}
			cout << endl;
			break;
		}
		case 'b':
		{
			Musicians::Wind();
			for (int i = 0; i < 4; i++)
			{
				cout << Musicians::baseWind[i] << ",";
			}
			cout << endl;
			break;
		}
		case 'c':
		{
			Musicians::Perc();
			for (int i = 0; i < 4; i++)
			{
				cout << Musicians::basePerc[i] << ",";
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