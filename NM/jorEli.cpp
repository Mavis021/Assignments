#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

class Gauss
{
private:
	int i,n, j, k;
	float temp, sum,x[20][20],out[10];
public:
	Gauss()
	{}
	void elimination()
	{
		cout << "enter the size of the matrix: ";
		cin >> n;
		cout << "enter the element of the augmented matrix: \n";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n + 1; j++)
			{
				cin >> x[i][j];
			}
		}

		for (j = 0; j < n; j++)
		{
			if (abs(x[j][j]) < 0.00005)
			{
				cout << "error!";
				exit(1);
			}
			for (i = 0; i < n; i++)
			{
				if (i != j)
				{
					temp = x[i][j] / x[j][j];
					for (k = 0; k < n + 1; k++)
					{
						x[i][k] -= temp * x[j][k];
					}
				}

			}

		}
		for (i = n - 1; i >= 0; i--)
		{
			sum = 0;
			for (j = i + 1; j < n; j++)
			{
				sum += x[i][j] * out[j];
			}
			out[i] = (x[i][n] - sum) / x[i][i];
			cout << out[i] << endl;
			
		}
	}
	void jordan()
	{
		cout << "enter the size of the matrix: ";
		cin >> n;
		cout << "enter the element of the augmented matrix: \n";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n + 1; j++)
			{
				cin >> x[i][j];
			}
		}

		for (j = 0; j < n; j++)
		{
			if (abs(x[j][j]) < 0.00005)
			{
				cout << "error!";
				exit(1);
			}
			for (i = 0; i < n; i++)
			{
				if (i != j)
				{
					temp = x[i][j] / x[j][j];
					for (k = 0; k < n +1; k++)
					{
						x[i][k] -= temp * x[j][k];
					}
				}

			}

		}
		for (i = 0; i<n; i++)
		{
			out[i] = x[i][n] / x[i][i];
			cout << out[i] << endl;

		}
	}
};


int main()
{

	Gauss g;
	//g.elimination();
	g.jordan();
	return 0;
}
