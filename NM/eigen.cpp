#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

class eigen
{
private:
	float ** A, * X, * Y, * Z, * D, max, Dmax,e;
	int n;
public:
	eigen() :n(0), e(0.0005), max(0), Dmax(0)
	{
		cout << "\n ENTER THE SIZE OF MATRIX: ";
		cin >> n;
		X = new float[n];
		Y = new float[n];
		Z = new float[n];
		D = new float[n];
		A = new float* [n];
		for (int i = 0; i < n; i++)
		{
			A[i] = new float[n];
			X[i] = 1;
		}
	}
	void getData()
	{
		cout << "ENTER THE DATAS OF GIVEN MATRIX: \n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> A[i][j];
			}
		}
	}
	void matMulVec()
	{
		for (int i = 0; i < n; i++)
		{
			Z[i] = 0;
			for (int j = 0; j < n; j++)
			{
				Z[i] += A[i][j] * X[j];
			}
		}
	}
	void divide(float m)
	{
		for (int i = 0; i < n; i++)
		{
			Y[i] = Z[i] / m;
		}
	}
	float getMax(float* temp)
	{
		float m = temp[0];
		for (int i = 0; i < n; i++)
		{
			if (abs(temp[i]) > abs(m))
				m = temp[i];
		}
		return m;
	}
	void compare()
	{
		for (int i = 0; i < n; i++)
		{
			D[i] = abs(X[i] - Y[i]);
		}
		Dmax = getMax(D);
		if (abs(Dmax) <= e)
		{
			showData();
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				X[i] = Y[i];
			}
			calc();
		}
	}
	void showData()
	{
		cout << "\n THE EIGEN VALUE IS " << max << "\n THE EIGEN VECTOR IS [ ";
		for (int i = 0; i < n; i++)
		{
			cout <<" "<< X[i];
		}
		cout << "]";
	}
	void calc()
	{
		matMulVec();
		max = getMax(Z);
		divide(max);
		compare();
	}
};

int main()
{
	eigen e;
	e.getData();
	e.calc();

	return 0;
}
