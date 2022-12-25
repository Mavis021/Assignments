#include<iostream>

using namespace std;

class Recursion
{
private:
	int n;
	int b, c;
public:
	Recursion() :n(0), c(0), b(1) {}

	void choose()
	{
		char ch;
		cout << "CHOOSE A RECURSION: \n 1 -> FACTORIAL\n 2 -> FIBONACCI\n 3 -> TAILFACTORIAL\n 4 -> TAILFIBONACCI \n 5 -> TOWER OF HANOI \n :";
		cin >> ch;

		switch (ch)
		{
		case '1':
			cout<<"THE FACTORIAL OF "<<n<<" IS "<<factorial();
			break;
		case '2':
			cout<<"THE "<<n<<"th FIBONACCI NUMBER IS " << fibonacci();
			break;
		case '3':
			tailfactorial();
			break;
		case '4':
			tailfibonacci();
			break;
		case '5':
			towerOfHanoi(0, 'A', 'C', 'B');
			break;
		default:
			cout << "FALSE SELECTION!";
			break;
		}
	}

	int factorial(int a = 0)
	{
		if (a == 0)
		{
			cout << "ENTER THE INTEGER: ";
			cin >> n;
			a = n;
		}
		if (a <= 1)
			return a;
		else
			return a * factorial(a - 1);
	}

	int fibonacci(int a=0)
	{
		if (a == 0)
		{
			cout << "ENTER THE INTEGER: ";
			cin >> n;
		}
		static int i = 0;
		c = b;
		b = a;
		if (i ==( n+1))
			return a;
		else
		{
			i++;
			return fibonacci(c+b);
		}
	}
	 void tailfactorial(int a = 0)
	 {
		 if (a == 0)
		 {
			 cout << "ENTER THE INTEGER: ";
			 cin >> n;
			 a = n;
		 }
		 if (a <= 1)
			 cout << "THE FACTORIAL VALUE " << b;
		 else
		 {
			 b *= a;
			 tailfactorial(a - 1);
		 }
	 }
	 void tailfibonacci(int a=0)
	 {
		 if (a == 0)
		 {
			 cout << "ENTER THE INTEGER: ";
			 cin >> n;
		 }
		 static int i = 0;
		 c = b;
		 b = a;
		 if (i == (n + 1))
			 cout<<"The "<<n<<"th Fibonacci number is "<<a;
		 else
		 {
			 i++;
			 tailfibonacci(c + b);
		 }
	 }
	 void towerOfHanoi(int disks,char source, char dest, char aux)
	 {
		 if (disks == 0)
		 {
			 cout << "ENTER THE NUMBER OF DISKS: ";
			 cin >> disks;
		 }
		 if (disks == 1)
		 {
			cout << "Move disk " << disks << " from " << source << " to " << dest << endl;
			 return;
		 }
		 else
		 {
			 towerOfHanoi(disks - 1, source, aux, dest);
			 cout << "Move disk " << disks << " from " << source << " to " << dest << endl;
			 towerOfHanoi(disks - 1, aux, dest, source);
		 }
	 }
};

int main()
{
	Recursion r;
	r.choose();
	return 0;
}
