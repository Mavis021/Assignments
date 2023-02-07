#include<iostream>
#include<cmath>

using namespace std;

class curveFitting
{
private:
	float sumx, sumy, sumxy, sumx2,n,*x,*y, a,b;
public:
	curveFitting()
	{
		cout << "ENTER THE NUMBER OF DATAS: ";
		cin >> n;
		x = new float[n];
		y = new float[n];
		sumx = 0;
		sumy = 0;
		sumxy = 0;
		sumx2 = 0;
		a = 0;
		b = 0;
	}

	~curveFitting()
	{
		delete[] x;
		delete[] y;
	}

	int choice()
	{
		int ch;
		cout << " CHOOSE A FUNCTION: " << endl;
		cout << " 1. y = a + bx " << endl << " 2. y = ae^bx " << endl;
		cin >> ch;
		return ch;
	}
	void getData()
	{
		cout << endl << "ENTER THE VALUES OF x-COORDINATES: "<<endl;
		for (int i = 0; i < n; i++)
		{
			cout << "x[" << i + 1 << "] :";
			cin >> x[i];
		}

		cout << endl << "ENTER THE VALUES OF y-COORDINATES: "<<endl;
		for (int i = 0; i < n; i++)
		{
			cout << "y[" << i + 1 << "] :";
			cin >> y[i];
		}
	}

	float determinant(float p, float q, float r, float s)
	{
		return (p*s - q*r);
	}
	void solve()
	{
		getData();
		int c = choice();
			for (int i = 0; i < n; i++)
			{
				if (c == 2)
				{
					y[i] = log(y[i]);
				}
				sumx += x[i];
				sumy += y[i];
				sumxy += x[i] * y[i];
				sumx2 += x[i] * x[i];
			}

			if (determinant(n, sumx, sumx, sumx2) != 0)
			{
				a = determinant(sumy, sumx, sumxy, sumx2) / determinant(n, sumx, sumx, sumx2);
				b = determinant(n, sumy, sumx, sumxy) / determinant(n, sumx, sumx, sumx2);
			}
			else
				cout << endl << "INVALID DATA ENTRY." << endl;

			if (c == 2)
				cout << endl << "THE REQUIRED BEST FIT EQUATION IS : y = " << exp(a) << "e^(" << b<<"x)" << endl;
			else
			cout << endl << "THE REQUIRED BEST FIT EQUATION IS : y = " << a << " +" << b<<"x" << endl;
	}
};

int main()
{
	curveFitting cf;
	cf.solve();
	system("pause");
	return 0;
}
