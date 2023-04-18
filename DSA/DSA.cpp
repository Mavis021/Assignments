/*
//stack as an ADT

//value defination
abstract typedef<elementType,indexType> STACK

definition clause:
elementType st[maxSize]
indexType tos

condition clause:
indexType == int

//operator definition
abstract typedef<elementType> push(st,tos,value)
definition clause:
STACK st
elementType value
int tos

precondition: tos < maxSize

postcondition: 
   tos = tos+1
   st[tos] = value

abstract typedef<elementType> pop(st, vlaue, tos)
definition clause:
STACK st
elementType value
int tos

precondition: tos > -1

postcondition:
   value = st[tos]
   tos = tos - 1

*/

#include<iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;

#define max 5

template <class T>
class STACK {
private:
	int tos;
	T st[max];

public:
	STACK<T>():tos(-1){}

	bool isEmpty()
	{
		return(tos >= ( - 1)) ? false : true;
	}

	bool isFull()
	{
		return(tos < max) ? false : true;
	}

	void push(T val)
	{
		tos++;
		if (isFull())
		{
			cout << "THE STACK IS FULL" << endl;
			exit(1);
		}
		else
		{
			st[tos] = val;
			cout << "THE DATA IN STACK: ";
			showData();
		}
	}
	void pop()
	{
		if (isEmpty())
		{
			cout << "THE STACK IS EMPTY" << endl;
			exit(1);
		}
		else
		{
			cout << "THE POPED DATA: " << st[tos--] << endl << "THE DATA IN STACK: ";
			showData();
		}
	}
	void showData()
	{
		for (int i = 0; i <= tos; i++)
		{
			cout << st[i] << setw(3);
		}
		cout<<endl;
	}
};

int main()
{
	STACK <int> st;
	st.push(1);
	st.push(2);
	st.pop();
	st.push(4);
	st.push(5);
    st.push(7);
	st.push(8);
	st.push(9);
	return 0;
}

/*
QUEUE AS ADT

//value defination
abstract typedef<elementType, indexType> QUEUE
definition clause:
elementType Q[maxSize]
indexType front, rear

condition clause:
indexType == int

//operator definition
abstract <elementType> enqueue(Q,rear,value)
/*
QUEUE AS ADT

//value defination
abstract typedef<elementType, indexType> QUEUE
definition clause:
elementType Q[maxSize]
indexType front, rear

condition clause:
indexType == int

//operator definition
abstract <elementType> enqueue(Q,rear,value)
definition clause:
QUEUE Q
integer rear
elementType value

precondition:
 rear < maxSize

postcondition:
 rear = rear + 1
 Q[rear] = value

abstract <elementType> dequeue(Q,front,value)
 definition clause
 QUEUE Q
 elementType value
 integer front

 precondition:
 front < rear

 postcondition:
 value = Q[front]
 front = front+1
*/

#include<iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;

#define max 5

template <class T>
class QUEUE {

private:
	int front, rear;
	T Q[max];
public:
	QUEUE<T>() :front(-1),rear(-1){}

	bool isFull();
	bool isEmpty();
	void enqueue(T val)
	{
		rear++;
		if (isFull())
		{
			cout << "THE QUEUE IS FULL";
			exit(1);
		}
		else
		{
			Q[rear] = val;
			cout << "THE QUEUE: ";
			showData();
		}
	}

	void dequeue()
	{
		front++;
		if (isEmpty())
		{
			cout << "THE QUEUE IS EMPTY!";
			exit(1);
		}
		else
		{
			cout << "THE DEQUEUED DATA: " << Q[front] << endl<< "THE QUEUE: ";
			front++;
			showData();
		}
	}
	void showData()
	{
		for (int i = front; i <= rear; i++)
		{
			cout << Q[i] << setw(3);
		}
		cout << endl;
	}
};

bool QUEUE<char>::isFull()
{
	return((rear < max) && rear != -1) ? false : true;
}

bool QUEUE<char>::isEmpty()
{
	return(front < rear) ? false : true;
}

int main()
{
	QUEUE<char> Que;
	Que.enqueue('a');
	Que.enqueue('b');
	Que.dequeue();
	Que.enqueue('a');
	Que.enqueue('b');
	Que.enqueue('a');
	Que.enqueue('b');

	return 0;
}
//infix to postfix expression
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<cassert>

using namespace std;

#define max 10

template<class T>
class stack
{
private:
	int tos;
	T st[max];
	friend class intopost;

public:
	stack<T>():tos(-1){}
	void push(T val);
	T pop();
	bool isEmpty();
	bool isFull();
};

bool stack<char>::isEmpty()
{
	return(tos > -1) ? false : true;
}

bool stack<char>::isFull()
{
	return(tos < max) ? false : true;
}

void stack<char>::push(char value)
{
	tos++;
	if (!isFull())
	{
		st[tos] = value;
	}
	else
	{
		cout << "\n the stack is full! exiting..." << endl;
		exit(1);
	}
}

char stack<char>::pop()
{
	if (!isEmpty())
	{
		return st[tos--];
	}
	else
	{
		cout << "\n the stack is empty. exiting..." << endl;
		exit(1);
	}
}


class intopost {
private:
	char* postfix;
	string infix;
	stack<char> stk;
	int i, j,index;
public:
	intopost():i(0), j(0), index(0){}
	~intopost()
	{
		delete[] postfix;
	}
	bool checkOperator(char);
	int precedence(char);
	void getInfix();
	void process();
	void showData();
};

int intopost::precedence(char opt)
{
	switch(opt)
	{
	case '+':
		return 3;
		break;
	case '-':
		return 3;
		break;
	case '^':
		return 7;
		break;
	case '*':
		return 5;
		break;
	case '/':
		return 5;
		break;
	default:
		assert("invalid operator");
	}
}

bool intopost::checkOperator(char op)
{
	return(op == '+' || op == '^' || op == '*' || op == '-' || op == '/') ? true : false;
}

void intopost::getInfix()
{
	cout << "\n ENTER THE INFIX OPERATION: ";
	cin >> infix;

	 postfix =new char[infix.length()];
}

void intopost::process()
{
	for (i = 0; i < infix.length(); i++)
	{
		if ((infix[i] > 64 && infix[i] < 91) || (infix[i] > 96 && infix[i] < 123))
		{
			postfix[index++] = infix[i];
		}
		else if (checkOperator(infix[i]))
		{
			if (!stk.isEmpty())
			{
				while (!stk.isEmpty() && (precedence(stk.st[stk.tos]) >= precedence(infix[i])))
				{
					postfix[index++] = stk.pop();
				}

				stk.push(infix[i]);
			}
			else
				stk.push(infix[i]);
		}
		else if (infix[i] == '(')
		{
			stk.push(infix[i]);
		}
		else if (infix[i] == ')')
		{
			while ((stk.st[stk.tos] != '(') && (!stk.isEmpty()))
			{
				postfix[index++] = stk.pop();
			}
			if(stk.st[stk.tos] == '(')
			   stk.pop();
		}
		else
		{
			assert("AN INVALID EXPRESSION!");
		}
	}
	while (!stk.isEmpty())
	{
		postfix[index++] = stk.pop();
	}
}

void intopost::showData()
{
	cout << "\n the required postfix: ";
	for (i = 0; i < index; i++)
	{
		cout <<postfix[i];
	}
}

int main()
{
	intopost ip;
	ip.getInfix();
	ip.process();
	ip.showData();

	return 0;
}
