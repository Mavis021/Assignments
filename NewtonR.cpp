//Newton Raphson method and Secant method
#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

class FindRoots
{
private:
	float x1, x0, c;
	int i;

public:
	FindRoots():x1(0),x0(0),c(0),i(0){}

	float fun(float a)
	{
		//return 5 * pow(a, 3) + 6;
		return a * sin(a) + cos(a);
	}

	float derive(float a)
	{
		//return 15 * a * a;
		return a * cos(a);
	}

	void NewtonRaphsonMethod()
	{
		cout << "ENTER THE INITIAL VALUE x0:";
		cin >> x0;
		while (i < 100)
		{
			if (derive(x0) != 0)
			{
				x1 = (x0 - (fun(x0) / derive(x0)));
			}
			else
			{
				cout << "NO SOLUTION FOUND! ";
				exit(1);
			}

			if ((x1 - x0)<= 0.00005)
			{
				cout << "THE REQUIRED ROOT IS " << x1;
				break;
			}
			i++;
			x0 = x1;
		}
	}

	void SecantMethod()
	{
		cout << "ENTER THE INITIAL VALUE a and b:";
		cin >> x0>>x1;
		while (i < 100)
		{
			if ((fun(x1) - fun(x0)) > 0.0005)
			{
				c = ((x0*fun(x1) - x1*fun(x0)) / (fun(x1) - fun(x0)));
			}
			else
			{
				cout << "NO SOLUTION FOUND! ";
				exit(1);
			}

			if (fun(abs(c)) <= 0.00005)
			{
				cout << "THE REQUIRED ROOT IS " << c;
				break;
			}
			i++;
			x0 = x1;
			x1 = c;
		}
	}
};

int main()
{
	FindRoots fr;
	char ch;

	cout << "ENTER YOUR CHOICE:\n 1. Newton-Raphson Method \n 2. Secant Method \n: ";
	cin >> ch;
	if(ch == '1')
		fr.NewtonRaphsonMethod();
	else
	fr.SecantMethod();

	return 0;
}
