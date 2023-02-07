//lab4_5.cpp
//Write a program that illustrates the following relationship and comment on them. 
//
//i) const_object.non_const_mem_function
//
//ii) const_object.const_mem_function
//
//iii) non_const_object.non_const_mem_function
//
//iv) non_const_object.const_mem_function


#include<iostream>
using namespace std;

class constCheck
{
private:
	//const int constMem;
    int nConstMem;
public:
	constCheck(){}
	constCheck (int ncm = 1)
	{
		nConstMem = ncm;
	}
	void constMemFun()const 
	{
		cout <<endl<<"non const datat : "<<nConstMem<<endl;
	}
	void nonConstMemFun()
	{
		cout <<endl<< "non const datat : " << nConstMem << endl;
	}
};

int main()
{
	const constCheck ccc(7);      //a constant object is created
	constCheck cc(7);             // a non constant object is created 

	//i) const_object.non_const_mem_function
	//ccc.nonConstMemFun();                     // error because a constant object cannot call a non constant mem function
	//ii) const_object.const_mem_function
	ccc.constMemFun();                          // constant object calls constant mem function : valid
	//iii) non_const_object.non_const_mem_function
	cc.nonConstMemFun();                        // non constant object non constant member function : valid
	//iv) non_const_object.const_mem_function
	cc.constMemFun();                           // non constant object calls constant mem function : valid

	return 0;
}