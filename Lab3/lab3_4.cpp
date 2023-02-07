////lab3_4.cpp
////a program with classes to represent a circle, rectangle, and triangle. 
//// Each class should have data members to represent the actual objects and member functions to read and display objects, find perimeter and area of the objects, and other useful functions. 
////Use the classes to create objects in your program.
//
//#include<iostream>
//using namespace std;
//
//class circle
//{
//private:
//	float radius;
//public:
//	void get_data()
//	{
//		cout << "ENTER THE RADIUS OF THE CIRCLE: ";
//		cin >> radius;
//	}
//	void display()
//	{
//		cout << endl << "Circle radius: " << radius << endl << "AREA: " << 3.1413 * radius * radius << endl << "PERIMETER: " << 2 * 3.1415 * radius << endl;
//	}
//};
//
//class rectangle
//{
//private:
//	int length;
//	int breadth;
//public:
//	void get_data()
//	{
//		cout << "ENTER THE LENGTH AND BREADTH OF THE RECTANGLE: ";
//		cin >> length>>breadth;
//	}
//	void display()
//	{
//		cout << endl << "RECTANGLE LENGTH: " << length << endl << "RECTANGLE BREADTH: " << breadth << endl << "AREA: " << length * breadth << endl << "PERIMETER : " << 2*(length + breadth) << endl;
//	}
//};
//
//class triangle
//{
//private:
//	int s1,s2,s3;
//public:
//	void get_data()
//	{
//		cout << "ENTER THE SIDES OF A TRIANGLE: ";
//		cin >> s1>>s2>>s3;
//	}
//	void display()
//	{
//		float s = (s1 + s2 + s3)/2;
//		if (s1 + s2 >= s3)
//		{
//			if (s1 + s3 >= s2)
//			{
//				if (s3 + s2 >= s1)
//				{
//					cout << endl << "TRIANGLE: " <<endl<< "AREA OF THE TRIANGLE: " << sqrt(s*(s-s1)*(s-s2)*(s-s3))<<endl<<"PERIMETER: "<<2*s << endl;
//				}
//			}
//		}
//		else
//			cout<<"INVALID VALUES OF TRIANGLE SIDES. ";
//		
//	}
//};
//
//int main()
//{
//	circle c1;
//	triangle t1;
//	rectangle r1;
//
//	c1.get_data();
//	t1.get_data();
//	r1.get_data();
//
//	c1.display();
//	t1.display();
//	r1.display();
//
//
//	return 0;
//}