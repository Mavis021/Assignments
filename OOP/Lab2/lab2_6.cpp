//lab2_6.cpp
//A program in c++ that displays the current monthly salary of chief executive officer, information officer, and system analyst, programmer that has been increased by 9, 10, 12, and 12 percentages
// respectively in year 2010. Let us assume that the salaries in year 2009 are
//Chief executive officer Rs. 35000/m
//Information officer Rs. 25000/m
//System analyst Rs. 24000/m
//Programmer Rs. 18000/m
//Make a function that takes two arguments; one salary and the other increment. Use proper default argument.

#include<iostream>
#include<cmath>
using namespace std;

long salary_increment(float sa=216000, float in=0.12)
{
return (in*sa+sa);
}


int main()
{
    long temp;

    //calling the salary increment function and displaying it in the console
    temp = salary_increment(420000, 0.09);
    cout<<"THE INCREMENTED SALARY OF CEO FOR YEAR 2010 IS "<< temp<<endl;
    temp = salary_increment(300000, 0.1);
    cout<<"THE INCREMENTED SALARY OF IO FOR YEAR 2010 IS "<<temp<<endl;
     temp = salary_increment(288000);
    cout<<"THE INCREMENTED SALARY OF SA FOR YEAR 2010 IS "<< temp<<endl;
     temp = salary_increment();
    cout<<"THE INCREMENTED SALARY OF PRO FOR YEAR 2010 IS "<< temp<<endl;

    return 0;
}
