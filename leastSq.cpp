#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

class curveFitting
{
private:
	float sum, *x, *y, A[20][20],temp;
	int n,d;
public:
	curveFitting():sum(0),n(0){}

	~curveFitting()
	{
		delete[] x;
		delete[] y;
	}
	void getData()
	{
		std::cout << "ENTER THE DEGREE OF EXPERSSION: ";
		std::cin >> d;
		std::cout << "ENTER THE NUMBER OF DATAS PROVIDED: ";
		std::cin >> n;
		x = new float[n];
		y = new float[n];
		std::cout << "ENTER THE VALUES OF X: \n";
		for (int i = 0; i < n; i++)
		{
			std::cout << " x[" << i + 1 << "]: ";
			std::cin >> x[i];
		}
		std::cout << "ENTER THE VALUES OF y: \n";
		for (int i = 0; i < n; i++)
		{
			std::cout << " y[" << i + 1 << "]: ";
			std::cin >> y[i];
		}
	}
	void makeAugMat()
	{
		cout << "\n THE AUGMENTED MATRIX: \n"<<setw(4);
		for (int i = 0; i < d+1 ; i++)
		{
			for (int j = 0; j < d+1 ; j++)
			{
				for (int k = 0; k < n; k++)
				{
					sum += pow(x[k], i + j);
				}
				A[i][j] = sum;
				cout << A[i][j] <<setw(4);
				sum = 0;
			}
			for (int k = 0; k < n; k++)
			{
				sum += pow(x[k], i) * y[k];
			}
			A[i][d + 1] = sum;

			cout << A[i][d + 1] <<setw(4) << endl;
			sum = 0;
		}
	}
	void gaussJordan()
	{
		for (int j = 0; j < d+1; j++)
		{
			if (abs(A[j][j]) < 0.00005)
			{
				cout << "ERROR!";
				exit(1);
			}
			for (int i = 0; i < d+1; i++)
			{
				if (i != j)
				{
					temp = A[i][j] / A[j][j];
					for (int k = 0; k < d + 2; k++)
					{
						A[i][k] = A[i][k] - temp * A[j][k];
					}
				}
			}
		}

		for (int i = 0; i < d+1; i++)
		{
			cout << "\nC[" << i << "]= " << A[i][d+1]/A[i][i];
		}
	}
	void leastSquare()
	{
		getData();
		makeAugMat();
		gaussJordan();
	}
};


int main()
{
	curveFitting cf;
	cf.leastSquare();
	return 0;
}
