//a.cpp
	//index operator overloading
#include <iostream>
#include <cstdlib>
using namespace std;
const int M = 7;


class Array
{
private:
	int * arr;
public:

	Array()            //deffault constructor to asign the members of the array
	{
		arr = new int[M];
		for (int i = 0; i < M; i++)
		{
			arr[i] = i + 1;
		}
	}
	~Array()
	{
		delete[]arr;
	}

	void showData()
	{
		cout << endl << "THE DATAS STORED IN THE ARRAY."<<endl;
		for (int i = 0; i < M; i++)
			cout << arr[i] << endl;
	}

	//index operator overloading
	int& operator [] (int index)
	{
		if (index < 0 || index >= M)
		{
			cout << "\n Error: Provided array index is out of bound.";
			exit(1);
		}
		return arr[index];
	}

};


int main()
{
	//Index operator
	Array ar;
	ar.showData();
	cout << "ar[2] =" << ar[2];
	ar[M] = 10; //array index out of bound
	return 0;
}