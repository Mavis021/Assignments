//A program in cpp to evaluate postfix expression
//125342/-^*6*+5-
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
			return (op2-op1);
			break;
		case '*':
			return (op2*op1);
			break;
		case '/':
			return (op2/op1);
			break;
		case '^':
			return (pow(op2,op1));
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
			else
			{
				s.PUSH(ch - '0');
			}
		}

		num = s.POP();
		std::cout << std::endl << "THE EVALUATED RESULT: " <<num << std::endl;
	}
};

int main()
{
	Evaluate e;
	e.postfix();
	system("pause");
	return 0;
}
