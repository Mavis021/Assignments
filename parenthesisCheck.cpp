#include<iostream>

const int size = 10;

class Stack
{
private:
	int top;
	char stack[size];

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

	void POP()
	{
		if (top == -1)
			std::cout << std::endl << "STACK UNDERFLOW";
		else
			top--;
	}

	bool isEmpty()
	{
		if (top == -1)
			return true;
		else
			return false;
	}
};

class expression
{
private:
	Stack s;
	std::string exp;
public:
	expression()
	{
		std::cout << "\n ENTER THE EXPRESSION :";
		std::cin >> exp;
	}
	void checkParenthesis()
	{
		for (int i = 0; i < exp.length(); i++)
		{
			char ch = exp[i];

			if (ch == '(')
			{
				s.PUSH(ch);
			}
			else if (ch == ')')
			{
				if (s.isEmpty())
				{
					std::cout << "\n INVALID EXPRESSION. " << std::endl;
					exit(1);
				}
				else
				{
					s.POP();
				}
			}
			else
				continue;
		}
		if (s.isEmpty())
			std::cout << "THE EXPRESSION IS VALID. ";
		else
			std::cout << "\n INVALID EXPRESSION. " << std::endl;
	}
};

int main()
{
	expression e;
	e.checkParenthesis();
	system("pause");
	return 0;
}
