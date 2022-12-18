#include<iostream>
#include<cmath>

using namespace std;

class BisectionMethod
{
private:
	float x, y, n, a, b,c;

public:
	BisectionMethod()
	{
		cout << "ENTER THE VALUES OF a AND b: "<<endl<<"a = ";
		cin >> a;
		cout << "b = ";
		cin >> b;
		n = (log(abs(b - a)) - log(0.0005)) / log(2);
	}

	float fun(float x)
	{
		return(x * sin(x) + cos(x));
	}

	void calculation()
	{
		if (fun(a) * fun(b) > 0)
		{
			if (fun(a) > 0)
				cout << endl << "BOTH THE FUNCTIONAL VALUES ARE POSITIVE.";
			else
				cout << endl << "BOTH THE FUNCTIONAL VALUES ARE NEGATIVE.";
		}
		else if (fun(a) * fun(b) == 0)
		{
			if (fun(a) == 0)
				cout << endl << "THE ANSWER IS " << a;
			else
				cout << endl << "THE ANSWER IS " << b;
		}
		else
		{
			int N = 2*n;
			do
			{
				c = (a + b) / 2;
				if (fun(a) * fun(c) > 0)
					a = c;
				else
					b = c;

				N--;
			} while (abs(fun(c)) >0.0005 &&  N!=0);

			cout << endl << "THE INTERSECTION POINT IS " << c << endl;
		}

	}
};



int main()
{
	BisectionMethod BM;
	BM.calculation();
	return 0;
}
