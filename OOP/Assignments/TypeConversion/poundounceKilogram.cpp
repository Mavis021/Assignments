//Conversion from the pound/ounce to Kg/gm
//1 gram = 0.035274 ounce
//1 pound = 16 ounce

#include<iostream>
#include<cmath>
using namespace std;

class kilo_gram;

class pound_ounce
{
private:
	float pound, ounce;
public:
	pound_ounce(float p = 0.0, float o= 0.0):pound(p),ounce(o){}

	operator kilo_gram();

	void display()
	{
		cout <<pound  << " pound " << ounce << " ounce ";
	}

};

class kilo_gram
{
private:
	float kilo, gm;
public:
	kilo_gram(float f = 0.0, float in = 0.0):kilo(f),gm(in){}

	operator pound_ounce()
	{
		float Tgram = static_cast<float>( kilo * 1000 + gm);
		float Tounce = Tgram * 0.035274;
		float pval = static_cast<int>(Tounce / 16);
		float oval = static_cast<int>(Tounce - (pval * 16));
		return pound_ounce(pval, oval);
	}

	void display()
	{
		cout << kilo << " kilo " << gm << " gram ";
	}
};

pound_ounce::operator kilo_gram()
{
	float Tounce = static_cast<float>(pound * 16 + ounce);
	float Tgram = Tounce / 0.035274;
	float kval = static_cast<int>(Tgram/ 1000);
	float gval = static_cast<int>(Tgram - (kval * 1000));
	return kilo_gram(kval, gval);
}

int main()
{
	pound_ounce PO(10, 15);
	kilo_gram KG;

	//pound_ounce to kilo_gram
	PO.display();
	KG= PO;
	cout << " = ";
	KG.display();
	cout << endl;

	//kilo_gram to pound_ounce
	KG = kilo_gram(5, 21);
	KG.display();
	PO = KG;
	cout << " = ";
	PO.display();
	cout << endl;

	return 0;
}
