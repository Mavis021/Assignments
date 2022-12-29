//Numerical Solution of Initial value problems involving 1st order ODE using
//Eulers Method
//RK2 Method
//RK4 Method

#include<iostream>
#include<iomanip>
using namespace std;

class ODE
{
private:
	float x0, y0, h, k1, k2, k3, k4,k,y1;
public:
	ODE():x0(0),y0(0),h(0),k1(0),k2(0),k3(0),k4(0), k(0), y1(0) {}

	void getInput()
	{
		cout << " ENTER THE VALUE OF \n x0 = ";
		cin >> x0;
		cout << " y0 = ";
		cin >> y0;
		cout << " h = ";
		cin >> h;
	}

	float fun(float x, float y)
	{
		//return x+y*y;
		//return x*x+2*x-b;
		return x + y;
	}
	void eulers()
	{
		cout << " x " << setw(20) << " y \n";
		cout << x0 << setw(20) << y0<<endl;
		for (int i = 0; i < (1 / h); i++)
		{
			y1 = y0 + h * fun(x0, y0);
			x0 += h;
			y0 = y1;
			cout << x0 << setw(20) << y0<<endl;
		}
	}
	void RK2()
	{
		cout << " x " << setw(20) << " y \n";
		cout << x0 << setw(20) << y0 << endl;
		for (int i = 0; i < (1 / h); i++)
		{
			k1 = h * fun(x0, y0);
			k2 = h * fun(x0 + h, y0 + k1);
			k = (k1 + k2) / 2;
			y1 = y0 + k;
			x0 += h;
			y0 = y1;
			cout << x0 << setw(20) << y0 << endl;
		}
	}
	void RK4()
	{
		cout << " x " << setw(20) << " y \n";
		cout << x0 << setw(20) << y0 << endl;
		for (int i = 0; i < (1 / h); i++)
		{
			k1 = h * fun(x0, y0);
			k2 = h * fun(x0 + h/2, y0 + k1/2);
			k3 = h * fun(x0 + h / 2, y0 + k2 / 2);
			k4 = h * fun(x0 + h, y0 + k3);
			k = (k1 +2* k2+2*k3+k4) / 6;
			y1 = y0 + k;
			x0 += h;
			y0 = y1;
			cout << x0 << setw(20) << y0 << endl;
		}
	}
	void choice()
	{
	char ch;
	cout << "ENTER YOUR CHOICE:\n 1. Euler's Method \n 2. RK2\n 3. RK4 \n: ";
	cin >> ch;
	if (ch == '1')
		eulers();
	else if (ch == '2')
		RK2();
	else
		RK4();
	}
};


int main()
{
	ODE o;
	o.getInput();
	o.choice();
}
