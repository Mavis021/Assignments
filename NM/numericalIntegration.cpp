#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

class NumericalIntegration
{
private:
	int n;
	float* x,*y,x0,xn,h,res,sum1,sum2;
public:
	NumericalIntegration():x0(0),xn(0),n(0),h(0),res(0),sum1(0),sum2(0)
	{
	}
	~NumericalIntegration()
	{
		delete[] x;
		delete[] y;
	}
	void getData()
	{
		cout << "\n ENTER THE LIMIT FOR THE EQUATION (x0 - xn): ";
		cin >> x0 >> xn;
		cout << "\n ENTER THE NUMBER OF PARTS YOU WANT TO DIVIDE THE INTERVEL TO: ";
		cin >> n;
		x = new float[n];
		y = new float[n+1];
		h = (xn - x0) / n;
		x[0] = x0;

		for (int i = 1; i < n ; i++)
		{
			x[i] =x[i-1]+ h;
		}
		y[0] = fun(x0);
		for (int i = 1; i < n; i++)
		{
			y[i] = fun(x[i]);
			cout << y[i] << endl;
		}
		y[n] = fun(xn);
	}
	float fun(float a)
	{
		//return exp(-pow(a, 2)); // e^-x^2
		return (1 / (1 + 2 * a + a * a));
	}
	void calc()
	{
		//trapezoidal
		for (int i = 1; i < n; i++)
		{
			sum1 += y[i];
		}
		res = (h / 2)*(y[0] + y[n] + 2 * sum1);
		cout << "\nTRAPEZOIDAL: \n THE APPROXIMATE VALUE OF ABOVE INTEGRAL IS " << res;
		sum1 = 0; res = 0;

		//simpson 1/3 rule
		for (int i = 1; i < n; i++)
		{
			if (i % 2 == 0)
				sum1 += y[i];
			else
				sum2 += y[i];
		}
		res = (h / 3) * (y[0] + y[n] + 2 * sum1 + 4 * sum2);
		cout << "\nSIMPSON 1/3 RULE: \n THE APPROXIMATE VALUE OF ABOVE INTEGRAL IS " << res;
		sum1 = 0; res = 0; sum2 = 0;

		//simpson 3/8 rule
		for (int i = 1; i < n; i++)
		{
			if (i % 3 == 0)
				sum2 += y[i];
			else
				sum1 += y[i];
		}
		res = (3*h / 8) * (y[0] + y[n] + 2 * sum2 + 3 * sum1);
		cout << "\nSIMPSON 3/8 RULE: \n THE APPROXIMATE VALUE OF ABOVE INTEGRAL IS " << res;
		sum1 = 0; res = 0; sum2 = 0;
	}
};

int main()
{
	NumericalIntegration ni;
	ni.getData();
	ni.calc();
	return 0;
}
