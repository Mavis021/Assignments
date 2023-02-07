//lab7_1.cpp
//Write a program to create a class shape with functions to find the area of the shapesand display the names of the shapesand other essential components of the class.
//Create derived classes circle, rectangle, and trapezoid each having overriding functions area() and display().
//Write a suitable program to illustrate virtual functionsand virtual destructors.

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

class shape
{
public:
	virtual void Area()
	{
		
	}
	virtual void display()
	{

	}
	virtual ~shape()
	{
		cout << "\n destructor of shape invoked";
	}

};

class circle : public shape
{
private:
	float radius,area;
public:
	circle(float r=0)
	{
		radius = r;
	}
	~circle()
	{
		cout << "destructor of circle invoked";
	}
	 void Area()
	{
		 area = 3.1415 * radius * radius;
	}
	 void display()
	{
		 cout << endl << "CIRCLE:\n AREA = "<< area<<setw(10)<<" RADIUS: "<<radius;
	}
};
class rectangle : public shape
{
private:
	float length, breadth,area;
public:
	rectangle(float l=0, float b=0)
	{
		length = l;
		breadth = b;
	}
	~rectangle(){
		cout << "\n destructor of rectangle invoked";
	}
	void Area()
	{
		area = length *breadth;
	}
	void display()
	{
		cout << endl << "RECTANGLE:\n AREA = " << area << setw(10) << " LENGTH: " << length<<setw(10)<<"BREADTH: "<<breadth;
	}
};
class trapezoid : public shape
{
private:
	float baseA,baseB,height,area;
public:
	trapezoid(float ba = 0, float bb= 0,float h=0)
	{
		baseA = ba;
		baseB = bb;
		height = h;
	}
	~trapezoid(){
		cout << "\n destructor of trapezoid invoked";
	}
	void Area()
	{
		area = ((baseA+baseB)/2)*height;
	}
	void display()
	{
		cout << endl << "Trapezoid:\n AREA = " << area << setw(10) << " base a: " << baseA << setw(10) << "base b: " << baseB<<setw(10)<<" height: "<<height;
	}
};

int main()
{
	shape* ptr ;
	circle c(2);
	rectangle rec(2,3);
	trapezoid trap(4,5,2);

	ptr = new circle(2.2);
		ptr->Area();
		ptr->display();
	delete ptr;

	ptr= new rectangle(2,3);
	    ptr->Area();
		ptr->display();
	delete ptr;

	ptr= new trapezoid(2,3,4);
	    ptr->Area();
		ptr->display();
	delete ptr;

	return 0;
}
