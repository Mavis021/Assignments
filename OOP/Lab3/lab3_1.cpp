////lab3_1.cpp
////A program in c++ to use the basic concept of class
//
//#include<iostream>
//#include<iomanip>
//using namespace std;
//
//class Celsius
//{
//private:
//	float temp;
//public:
//	void getData()
//	{
//		cout << "ENTER THE TEMPERATURE IN CELSIUS: ";
//		cin >> temp;
//	}
//	void setData(float t)
//	{
//		temp = t;
//	}
//	float toFahrenheit()
//	{
//		return (temp * ((float)9 / 5)) + 32;
//	}
//	void showData()
//	{
//		cout <<endl<< temp;
//	}
//};
//
//class Fahrenheit
//{
//private:
//	float temp;
//public:
//	void getData()
//	{
//		cout << "ENTER THE TEMPERATURE IN FAHRENHEIT: ";
//		cin >> temp;
//	}
//	void setData(float t)
//	{
//		temp = t;
//	}
//	float toCelsius()
//	{
//		return (temp -32) * ((float)5/9);
//	}
//	void showData()
//	{
//		cout << endl << temp;
//	}
//};
//
//int main()
//{
//	Celsius c1;
//	Fahrenheit f1;
//	cout << setw(17) << "CONVERSION BETWEEN FAHERENHEIT AND CELSIUS " << endl;
//	c1.getData();
//	f1.getData();
//
//	c1.showData();
//	cout << " DEGREE CELSIUS = " << c1.toFahrenheit() << " DEGREE FAHRENHEIT" << endl;
//	f1.showData();
//	cout << " DEGREE FAHRENHEIT = " << f1.toCelsius() << " DEGREE CELSIUS" << endl;
//
//	return 0;
//}