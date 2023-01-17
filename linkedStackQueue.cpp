#include<iostream>

struct node
{
	char data;
	node* next;
};

class LinkedQueue
{
private:
	node* newNode, * front, * rear, * temp;
public:
	LinkedQueue()
	{
		front = NULL;
		rear = NULL;
	}
	bool isEmpty()
	{
		return (front == rear) ? true : false;
	}
	void enqueue(char val)
	{
		newNode = new node;
		newNode->data = val;
		newNode->next = NULL;
		if (front == NULL)
		{
			front = newNode;
			rear = newNode;
		}
		else
		{
			rear->next = newNode;
			rear = newNode;
		}
	}
	char dequeue()
	{
		if (isEmpty())
		{
			std::cout << "UNDERFLOW";
			exit(1);
		}
		char ch = front->data;
		temp = front;
		front = temp->next;
		delete temp;
		return ch;
	}
};
class LinkedStack
{
private:
	node* newNode, *top, *temp;
public:
	LinkedStack()
	{
		top = NULL;
	}
	bool isEmpty()
	{
		return (top == NULL) ? true : false;
	}
	void push(char val)
	{
		newNode = new node;
		newNode->data = val;
		if (top == NULL)
		{
			newNode->next = NULL;
			top = newNode;
		}
		else
		{
			newNode->next = top;
			top = newNode;
		}
	}
	char pop()
	{
		if (isEmpty())
		{
			std::cout << "UNDERFLOW";
			exit(1);
		}
		temp = top;
		char ch = temp->data;
		top = temp->next;
		delete temp;
		return ch;
	}
};



int main()
{
	std::cout << "\n LINKED STACK\n";
	LinkedStack ls;
	ls.push('1');
	ls.push('2');
	ls.push('3');
	ls.push('4');
	std::cout<<"\n THE DELETED ITEM IS "<<ls.pop();
	std::cout << "\n THE DELETED ITEM IS " << ls.pop() << std::endl;

	std::cout << "\n LINKED QUEUE\n";
	LinkedQueue lq;
	lq.enqueue('1');
	lq.enqueue('2');
	lq.enqueue('3');
	std::cout << "\n THE DELETED ITEM IS " << lq.dequeue();
	std::cout << "\n THE DELETED ITEM IS " << lq.dequeue() << std::endl;
	return 0;
}
