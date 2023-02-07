//Lab8_1.cpp
//Write a program to demonstrate the use of different ios flagsand functions to format the output.
//Create a program to generate the bill invoice of a department store by using different formatting.


#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdlib>
using namespace std;

class Sales
{
private:
	int* cost, num;
	string* productName;
public:
	Sales()
	{
		num = 0;
		cost = new int;
		cost = 0;
		productName = new string{ "NONE" };
	}
	Sales(int n)
	{
		num = n;
		cost = new int[n];
		productName = new string[n];
	}
	~Sales()
	{
		cout << endl << "destructor called" << endl;
		delete[]cost;
		delete[]productName;
	}

	void getData()
	{
		for (int i = 0; i < num; i++)
		{
			cout << "PRODUCT " << i + 1 << ": " << endl << "Product Name: ";
			cin >> productName[i];
			cout << "Cost Price: ";
			cin >> cost[i];
		}
	}
	void showData()
	{
		int total = 0;
		cout.width(50);
		cout << endl << "MOMO DEPARTMENT STORE INVOICE: " << endl;
		cout.setf(ios::right, ios::adjustfield);
		cout << " S.N" << setw(20) << "PRODUCT NAME" << setw(20) << "COST" << setw(20) << "DISCOUNTED PRICE" << endl;
		for (int i = 0; i < num; i++)
		{

			cout.width(4);
			cout.fill(' ');
			cout << i + 1;
			cout.width(20);
			cout << productName[i];
			cout.width(20);
			cout << cost[i] << setw(20) << (cost[i] * 0.9);
			cout << endl;
			total += (cost[i] * 0.9);
		}
		cout.width(55);
		cout << "TOTAL: " << setw(9) << total << endl;
	}

};

int main()
{
	int n;
	cout << "ENTER THE NUMBER OF PRODUCTS SOLD: ";
	cin >> n;

	Sales s(n);

	s.getData();
	system("cls");  //clearing the console
	s.showData();
	system("pause");

	return 0;
}