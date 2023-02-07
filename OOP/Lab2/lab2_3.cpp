//lab2_3.cpp
//A program in c++ that Defines two namespaces: Square and Cube.
//In both the namespaces, define an integer variable named "num" and a function named "fun". The "fun" function in "Square" namespace,
//should return the square of an integer passed as an argument while the "fun" function in "Cube" namespace, should return the cube of an integer passed as an argument.
//In the main function, set the integer variables "num" of both the namespaces with different values. Then, compute and print the cube of the integer variable "num" of 
//the "Square" namespace using the "fun" function of the "Cube" namespace and the square of the integer variable "num" of the "Cube" namespace using the "fun" function of the "Square" namespace.

#include<iostream>
#include<string>

using namespace std;
namespace Square
{
	int num;

	int fun(int n)
	{
		return(n * n);
	}
}

namespace Cube
{
	int num;

	int fun(int n)
	{
		return(n * n * n);
	}
}

int main()
{
	Square::num=7;
	Cube::num = 5;

	int n = Cube::fun(Square::num);
	int m = Square::fun(Cube::num);

	cout << "THER CUBE OF 7 IS: " << n << endl;
	cout << "THER SQUARE OF 5 IS: " << m << endl;

	return(0);
}

