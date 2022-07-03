////lab3_5.cpp
////Assume that an object represents an employee report that contains information like employee id, total bonus, total overtime in a particular year.Use an array of objects to represent n employees' reports. Write a program that displays the report. Use setpara() member function to set report attributes by passing the arguments and member function displayreport() to show the report according to the parameter passed. Display the report in the following format.
////
////An employee with ... ... ... has received Rs ... ... ...as a bonus
////
////and
////
////had worked ... ... ... hours as overtime in the year ... ... ...
//
//#include<iostream>
//using namespace std;
//
//class employee_report
//{
//private:
//	int employee_id;
//	int year;
//	int total_bonus;
//	int total_overtime;
//public:
//	void setpara(int eid,int y, int tb, int tot)
//	{
//		employee_id = eid;
//		year = y;
//		total_bonus = tb;
//		total_overtime = tot;
//	}
//	void displayreport()
//	{
//		cout << endl << "An employee with id-" << employee_id << " has received Rs " << total_bonus << " as a bonus " << endl << "and" << endl << "had worked " << total_overtime << " hours as overtime in the year " << year;
//	}
//
//};
//
//int main()
//{
//	employee_report* er;
//	int n,e,y,tb,to;
//	cout << "ENTER THE NUMBER OF EMPLOYEES YOU WANT TO REGISTER: ";
//	cin >> n;
//
//	er = new employee_report[n];
//	for (int i = 0; i < n; i++)
//	{
//		cout <<endl<< "employee_id = ";cin>> e;
//		cout <<"year = ";cin>> y;
//		cout << "total_bonus = ";cin>> tb;
//		cout <<"total_overtime = ";cin>> to;
//		er[i].setpara(e, y, tb, to);
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		er[i].displayreport();
//		cout << endl;
//	}
//
//
//	delete[]er;
//	return 0;
//}