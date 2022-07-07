//lab4_2.cpp
// Write a program that has a class with a dynamically allocated character array as its data member. One object should contain "Engineers are" and another should contain " Creatures of logic".
// Member function join() should concatenate two strings by passing two objects as arguments.
// Display the concatenated string through a member function. Use constructors to allocate and initialize the data member.
//Also, write a destructor to free the allocated memory for the character array. Make your own function for the concatenation of two strings.

#include<iostream>
#include<cstring>
using namespace std;

class strings
{
private:
	char* str;
public:
	strings()
	{
		str = new char[1];
		str[0] = '\0';
	}
	strings(const char* string)
	{
		str = new char[strlen(string) + 1];
		strcpy(str, string);
	}

	void join(strings& s1, strings& s2)
	{
		str = new char[strlen(s1.str) + strlen(s2.str)];
		str = catStrcat(s1.str, s2.str);
		//concat(s1.str, s2.str);
	}

	char* catStrcat(char* s1, char* s2)      //using header function
	{
		strcat(s1, s2);
		return s1;
	}

	//void concat(char* s1, char* s2)      //user-defined concatination function
	//{
	//	int n = (strlen(s1) + strlen(s2));
	//	int j = 0;
	//	for (int i = 0; i <= n; i++)
	//	{
	//		if (i < strlen(s1))
	//		{
	//			str[i] = s1[i];
	//		}
	//		else
	//		{
	//			str[i] = s2[j];
	//			j++;
	//		}
	//	}
	//}

	void showData()
	{
		cout << str << endl;
	}
	~strings()
	{
		delete[]str;
	}
};

int main()
{/*
	char str1[] = "Engineers are ";
	char str2[] = "Creatures of Logic. ";
	char str3[] = "";*/
	//strings string1(str1), string2(str2), string3(str3);
	strings string1("Engineers are "), string2(" Creatures of logic."), string3("");
	cout << "Seperated strings: " << endl;
	string1.showData();
	string2.showData();

	string3.join(string1, string2); //concatinating the strings
	cout << "The concatinated string is" << endl;
	string3.showData();

	return 0;
}
