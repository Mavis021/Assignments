#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

class interpolation
{
private:
	float* x, * y,xp,sum,pro;
	int n;
public:
	interpolation()
	{
		sum = 0;
		pro = 1;
		cout << "ENTER THE NUMEBER OF DATAS PROVIDED: ";
		cin >> n;

		x = new float[n];
		y = new float[n];
		getData();
	}
	~interpolation()
	{
		delete[]x;
		delete[]y;
	}
	void getData()
	{
		cout << "\n ENTER THE VALUES OF x AND Y: \n";
		for (int i = 0; i < n; i++)
		{
			cout << "x[" << i + 1 << "] and y[" << i + 1 << "] = ";
			cin >> x[i] >> y[i];
		}
		cout << "\n ENTER THE INPOLATING DATA xp = ";
		cin>>xp;
	}
	void clac()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i != j)
				{
					pro *= (xp - x[j]) / (x[i] - x[j]);
				}
			}
			sum += pro * y[i];
			pro = 1;
		}
		showData();
	}

	  void showData()
	  {
		cout << "\n y[" << xp << "] = " << sum;
	   }
};

class ODE2
{
private:
	float h, x0, y0, k, l, k1, k2, k3, l1, l2, l3,k4,l4,y1,z0,xn;
public:
	ODE2() :x0(0), y0(0), h(0), k1(0), k2(0), k3(0), k4(0), k(0), l1(0), l2(0), l3(0), l4(0), l(0), y1(0),z0(0) {}

	float der1(float a, float b, float c)
	{
		return c;
	}
	float der2(float a, float b, float c)
	{
		//return 6*a+3*b-2*c;
		return 3 * a * a - 2 * c;
	}
		void getInput()
	{
		cout << "d2y/dx2 = x*dy/dx+y, y(1) = 2\n";
		cout << " ENTER THE VALUE OF \n x0 = ";
		cin >> x0;
		cout << " y0 = ";
		cin >> y0;
		cout << " z0 = ";
		cin >> z0;
		cout << " xn = ";
		cin >> xn;
		cout << " h = ";
		cin >> h;
	}
	void RK4()
	{
		getInput();
		cout << " x " << setw(20) << " y "<<setw(20)<<" z \n";
		cout << x0 << setw(20) << y0 << setw(20) << z0 << endl;
		for (int i = 0; i < (xn / h); i++)
		{
			k1 = h * der1(x0, y0,z0);
			l1 = h * der2(x0, y0, z0);
			k2 = h * der1(x0 + h / 2, y0 + k1 / 2,z0 + l1/2);
			l2 = h * der2(x0 + h / 2, y0 + k1 / 2, z0 + l1 / 2);
			k3 = h * der1(x0 + h / 2, y0 + k2 / 2, z0 + l2 / 2);
			l3 = h * der2(x0 + h / 2, y0 + k2 / 2, z0 + l2 / 2);
			k4 = h * der1(x0 + h, y0 + k3, z0 + l3);
			l4 = h * der2(x0 + h, y0 + k3, z0 + l3);
			k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
			l = (l1 + 2 * l2 + 2 * l3 + l4) / 6;

			x0 += h;
			y0 += k;
			z0 += l;
			cout << x0 << setw(20) << y0 << setw(20) << z0 << endl;
		}
	}

};
int main()
{
	//interpolation ip;
	//ip.clac();
	ODE2 o;
	o.RK4();
	return 0;
}
