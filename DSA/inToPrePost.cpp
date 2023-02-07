//A program in cpp to convert the infix to postfix or prefix
//a+b*c^(d-f/g)*h-i

#include<iostream>

const int size = 10;

class Conversion;
class Stack
{
private:
	int top;
	char stack[size];
	friend class Conversion;

public:
	Stack()
	{
		top = -1;
	}

	void PUSH(char data)
	{
		if (top == size - 1)
			std::cout << std::endl << "STACK OVERFLOW ";
		else
		{
			top++;
			stack[top] = data;
		}
	}
	char POP()
	{
		if (top == -1)
			std::cout << std::endl << "STACK UNDERFLOW";
		else
			return stack[top--];
	}

};


class Conversion
{
private:
	int eindex;
	char* expression;
	std::string infix;
	Stack s;

public:
	Conversion()
	{
		std::cout << "ENTER THE EXPRESSION: " << std::endl;
		std::cin >> infix;
		expression = new char[infix.length()+1];
		eindex = 0;
	}
	~Conversion()
	{
		delete[] expression;
	}

	std::string reverse(std::string in)
	{
		std::string revOfInfix;
		for (int i = 0; i < in.length(); i++)
		{
			revOfInfix += in[in.length() - 1 - i];

			if (revOfInfix[i] == '(')
				revOfInfix[i] = ')';
			else if (revOfInfix[i] == ')')
				revOfInfix[i] = '(';
		}

		return revOfInfix;
	}
	bool operatorCheck(char ch)
	{
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/'||ch == '^')
			return true;
		else
			return false;
	}

	int precedence(char a)
	{
		switch (a)
		{
		case '+':
			return 3;
			break;
		case'-':
			return 3;
			break;
		case '*':
			return 5;
			break;
		case '/':
			return 5;
			break;
		case '^':
			return 7;
			break;
		default:
			return 0;
			break;
		}
	}

	void toPostfix(int p=0)
	{
		for (int i = 0; i < infix.length(); i++)
		{
			char ch = infix[i];
			if (operatorCheck(ch))
			{
				if (s.top == -1)
				{
					s.PUSH(ch);
				}
				else if (precedence(ch) > precedence(s.stack[s.top]))
				{
					s.PUSH(ch);
				}
				else if (precedence(ch) == precedence(s.stack[s.top]) && ch == '^')
				{
					expression[eindex] = s.POP();
					eindex++;
					s.PUSH(ch);
				}
				else
				{
						while (s.top != -1 && (precedence(ch) <= precedence(s.stack[s.top])))
						{
							expression[eindex] = s.POP();
							eindex++;
						}
						s.PUSH(ch);
				}
				
			}
			else if (ch == '(')
			{
				s.PUSH(ch);
			}
			else if (ch == ')')
			{
				while (s.stack[s.top] != '(' && s.top != -1)
				{
					expression[eindex] = s.POP();
					eindex++;
				}
				if (s.stack[s.top] == '(')
					s.POP();
			}
			else
			{
					expression[eindex] = ch;
					eindex++;
			}
		}
		while (s.top != -1)
		{
			expression[eindex] = s.POP();
			eindex++;
		}
		expression[eindex] = '\0';

		if (p == 2)
			showExpression(reverse(expression));
		else
			showExpression(expression);

	}

	void toPrefix()
	{
		infix = reverse(infix);
		toPostfix(2);
	}

	void showExpression(std::string s)
	{
		std::cout << std::endl << "THE REQUIRED EXPRESSION : " << s << std::endl;
	}

};


int main()
{
	Conversion co;

	char prom;
	std::cout << "CHOSE AN OPERATION: \n 1. Infix to Postfix \n 2. Infix to Prefix \n : ";
	std::cin >> prom;

	if (prom == '1')
		co.toPostfix(1);
	else
		co.toPrefix();

	return 0;
}
