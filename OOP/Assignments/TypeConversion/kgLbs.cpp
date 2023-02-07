//Conversion from Kg to pound system.
//1kg = 2.20462lbs
#include<iostream>
#include<cstdlib>

class pound;
class kilogram
{
private:;
	   float kilo;
public:
	kilogram(float k =0):kilo(k){}
	~kilogram(){}

	kilogram(pound);

	float returnKilo()
	{
		return kilo;
	}
	void getData()
	{
		std::cout <<std::endl<< "ENTER THE WEIGHT IN KILOGRAM: ";
		std::cin >> kilo;
	}
	void showData()
	{
		std::cout << kilo << " kilograms "<<std::endl;
	}
	
};
class pound
{
private:;
	   float lbs;
public:
	pound(float p = 0) :lbs(p) {}
	~pound() {}

	pound(kilogram k);

	float returnPound()
	{
		return lbs;
	}

	void getData()
	{
		std::cout << std::endl << "ENTER THE WEIGHT IN POUND: ";
		std::cin >> lbs;
	}
	void showData()
	{
		std::cout << lbs << " Pounds "<<std::endl;
	}

};

kilogram::kilogram(pound p)
{
	kilo = p.returnPound()/ 2.20464; //lbs to kg
	std::cout << p.returnPound() << " Pounds = " <<kilo<<" kilograms" <<std::endl;
}

pound::pound(kilogram k)
{
	lbs = k.returnKilo() * 2.20464;  //kg to lbs
	std::cout << k.returnKilo() << " kilograms = " << lbs << " Pound" <<std::endl;
}


int main()
{
	kilogram k;
	pound p;
	
	std::cout << "KILOGRAM TO POUND:";
	k.getData();
	p = k;

	std::cout <<std::endl<< "POUND TO KILOGRAM:";
	p.getData();
	k = p;

	return 0;
}
