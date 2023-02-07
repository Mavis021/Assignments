//lab3_2.cpp
//A program in c++ to check weather the number is prime or not

#include<iostream>
#include<string>
using namespace std;

class number
{
private:
	int num;
public:
	void getNum()
	{
		cout << "ENTER THE NUMBER: ";
		cin >> num;
	}
	void setNum(int n)
	{
		num = n;
	}
	bool checkPrime()
	{
		
		for (int i = 2; i <= (num / 2); i++)
		{
			if (num % i == 0)
			{
				return false;
			}
		}
		if (num == 1)
		{
			return false;
		}
		return true;
	}
	void showData()
	{
		cout << endl << num;
	}

};

int main()
{
	number n1;
	char ch;
	n1.getNum();

	do 
	{
		if (n1.checkPrime() == true)
		{
			n1.showData();
			cout << " is a Prime number." << endl;
		}
		else
		{
			n1.showData();
			cout << " is not a Prime number." << endl;
		}

		cout << endl << "DO YOU WANT TO CHECK ANOTHER INTEGER? (y/n): ";
		cin >> ch;

	} while (ch == 'y');

	return 0;
}