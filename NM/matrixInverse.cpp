#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

class matrix
{
private:
	float ** Aug,*ogmat,temp;
	int n;
public:
	matrix()
	{
		cout << setw(50)<<"MATRIX INVERSE USING GAUSS JORDAN ELIMINATION METHOD: \n ENTER THE SIZE OF MATRIX: ";
		cin >> n;
		Aug = new float*[n];
		for (int i = 0; i < n; i++)
		{
			Aug[i] = new float[2*n];
		}
		ogmat = new float[n*n];
	}
	~matrix()
	{
		delete[]* Aug;
		delete[] ogmat;
	}

	void getMat()
	{
		cout << " ENTER THE DATAS FOR ORIGINAL MATRAIX : \n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> *(ogmat + j + i * n);
			}
		}
	}
	void makeAug()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0;  j< 2*n; j++)
			{
				if (j == n + i)
					Aug[i][j] = 1;
				else if (j < n)
					Aug[i][j] = *(ogmat + j + i * n);
				else
					Aug[i][j] = 0;
			}
		}
		cout << " THE AUGMENTED MATRIX IS:";
		for (int i = 0; i < n; i++)
		{
			cout <<endl;
			for (int j = 0; j < 2 * n; j++)
			{
				if (j == n)
				{
					cout << " | ";
				}
				cout <<setw(5)<< Aug[i][j] << setw(5);
			}
		}
	}
	void gaussJordan()
	{
		for (int j = 0; j < n; j++)
		{
			if (abs(Aug[j][j]) < 0.00005)
			{
				cout << "ERROR!";
				exit(1);
			}
			for (int i = 0; i < n; i++)
			{
				if (i != j)
				{
					temp = Aug[i][j] / Aug[j][j];
					for (int k = 0; k < 2*n; k++)
					{
						Aug[i][k] = Aug[i][k] - temp * Aug[j][k];
					}
				}
			}
		}
	}
	void showInverse()
	{
		cout << " \n\n THE INVERSE OF MATRIX IS:";
		for (int i = 0; i < n; i++)
		{
			cout << endl;
			for (int j = n; j < 2*n; j++)
			{
				cout << setw(5) << Aug[i][j] << setw(5);
			}
		}
	}
	void inverse()
	{
		getMat();
		makeAug();
		gaussJordan();
		showInverse();
	}
};
int main()
{
	matrix m;
	m.inverse();
	return 0;
}
