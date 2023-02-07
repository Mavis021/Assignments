//A program in cpp to evaluate postfix expression
//1,2,5,3,4,2,/,-,^,*,6,*,+,5,-
//5,6,2,+,*,12,4,/,-
#include<iostream>
#include<cstdlib>

const int size = 15;
class Stack
{
private:
	int top;
	char stack[size];
	friend class Evaluate;

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
	float POP()
	{
		if (top == -1)
			std::cout << std::endl << "STACK UNDERFLOW";
		else
			return stack[top--];
	}

};

class Evaluate
{
private:
	Stack s;
	char temp[5];
	std::string expression;
	float num;

public:
	Evaluate()
	{
		num = 0;
		std::cout << "ENTER THE EXPRESSION: " << std::endl;
		std::cin >> expression;
	}
	~Evaluate()
	{
	}

	bool operatorCheck(char ch)
	{
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
			return true;
		else
			return false;
	}

	float calc(char op)
	{
		float op1 = s.POP(), op2 = s.POP();
		switch (op)
		{
		case '+':
			return (op2 + op1);
			break;
		case'-':
			return (op2 - op1);
			break;
		case '*':
			return (op2 * op1);
			break;
		case '/':
			return (op2 / op1);
			break;
		case '^':
			return (pow(op2, op1));
			break;
		default:
			return 0;
			break;
		}
	}

	void postfix()
	{
		for (int i = 0; i < expression.length(); i++)
		{
			char ch = expression[i];

			if (operatorCheck(ch))
			{
				num = calc(ch);
				s.PUSH(num);
			}
			else if (ch != ',')
			{
				int multiplier = 1, number = 0, k;

				for (k = 0; (ch >= '0' && ch <= '9'); k++)
				{
					temp[k] = ch;
					i++;
					ch = expression[i];
				}

				for (int j = k - 1; j >= 0; --j)
				{
					number += multiplier * (temp[j] - '0');
					multiplier *= 10;
				}
				num = number;

				s.PUSH(num);
			}
			else
				continue;
		}

		num = s.POP();
		std::cout << std::endl << "THE EVALUATED RESULT: " << num << std::endl;
	}
};

int main()
{
	Evaluate e;
	e.postfix();
	system("pause");
	return 0;
}

