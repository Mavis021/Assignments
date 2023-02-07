//b.cpp
//newAndDelete

#include <iostream>
#include <cstdlib>
using namespace std;

class coordinate
{
private:
	int x, y;
public:
	coordinate(int a=0 , int b=0) : x(a), y(b) {}

	void* operator new(size_t s);
	void operator delete(void* ptr);

	void* operator new[](size_t s);
	void operator delete[](void* ptr);
	void display()
	{
		cout << "\n (" << x << " , " << y << ")\n";
	}
};

void *coordinate:: operator new(size_t s)
{
	cout << "new called.\n";
	coordinate* cp = ::new coordinate;
	return cp;
}
void coordinate::operator delete(void* ptr)
{
	cout << "delete called.\n";
	::delete (coordinate*)ptr;
}

void* coordinate::operator new[](size_t s)
{
	cout << "new[] called. \n";
	coordinate* cp = ::new coordinate[s/sizeof(coordinate)];
	return cp;
}
void coordinate::operator delete[](void* ptr)
{
	cout << "delete[] called. \n";
	::delete[](coordinate*) ptr;
}


int main()
{
	coordinate *c1, *c2;
	c1 = new coordinate(6, 7);  //single object
	c1->display();
	c2 = new coordinate[3]; //multiple objects
	for (int i = 0; i < 3; i++)
		c2[i] = coordinate(i + 1, i + 2);
	for (int i = 0; i < 3; i++)
		c2[i].display();

	delete c1;
	delete[]c2;

	return 0;
}


