#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cmath>

using namespace std;

class Gauss
{
private:
	float* data, * out, temp,sum;
	int i, j, n,k;
public:
	Gauss() :i(0), j(0), n(0), temp(0),k(0),sum(0)
	{
		cout << "ENTER THE SIZE OF THE MATRIX USED: ";
		cin >> n;
		data = new float[n * (n + 1)];
		out = new float[n];
	}
	~Gauss()
	{
		delete []data;
		delete[]out;
	}
	void getInput()
	{
		cout << "\n ENTER THE COEFFICIENTS: \n";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n+1; j++)
			{
				cout << "a[" << i + 1 << j + 1 << "]= ";
				cin >> *(data + j + i * (n + 1));
			}
		}
	}
	void jordan()
	{
		getInput();

		for (j = 0; j < n ; j++)
		{
			if (abs(*(data + j + (n + 1) * j)) <= 0.00005)
			{
				cout << "ERROR!";
				exit(1);
			}
			for (i = 0; i < n; i++)
			{
				if (i != j)
				{
					temp = (*(data + (n + 1) * i+j)) / (*(data + j + (n + 1) * j));
					for (k = 0; k < n + 1; k++)
					{
						(*(data + k + (n + 1) * i)) = (*(data + k + (n + 1) * i)) - (temp * (*(data + k + (n + 1) * j)));
					}
				}
			}
		}
		for (i = 0; i < n; i++)
		{
			(*(out + i)) = (*(data + (n + 1) * i + n)) / (*(data + (n + 1) * i + i));
			cout << "\nx[" << i + 1 << "]= " << (*(out + i));
		}
	}
	void elimination()
	{
		getInput();

		for (j = 0; j < n; j++)
		{
			if (abs(*(data + j + (n + 1) * j)) <= 0.00005)
			{
				cout << "ERROR!";
				exit(1);
			}
			for (i = 0; i < n; i++)
			{
				if (i > j)
				{
					temp = (*(data + (n + 1) * i + j)) / (*(data + j + (n + 1) * j));
					for (k = 0; k < n + 1; k++)
					{
						(*(data + k + (n + 1) * i)) = (*(data + k + (n + 1) * i)) - (temp * (*(data + k + (n + 1) * j)));
					}
				}
			}
		}
		for (i = n-1; i >= 0; i--)
		{
			for (j = i+1; j < n ; j++)
			{
				sum += (*(data +(n+1)*i+j)) * (*(out + j));
			}
			*(out + i) = ((*(data + (n + 1) * i + n)) - sum) / (*(data + (n + 1) * i + i));
			cout << "\nx[" << i + 1 << "]= " << (*(out + i));
			sum = 0;
		}
	}
	void choice()
	{
		char ch;
		cout << "\n CHOOSE A METHOD: \n 1.GAUSS JORDAN METHOD\n 2.GAUSS ELIMINATION METHOD\n : ";
		cin >> ch;
		if (ch == '1')
			jordan();
		else
			elimination();
	}
};

int main()
{
	Gauss g;
	g.choice();
	return 0;
}
