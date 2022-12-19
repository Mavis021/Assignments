//linear queue

#include<iostream>

const int size = 5;

template<class T>
class Queue
{
private:
	T queue[size];
	int front,rear;
public:
	Queue()
	{
		front = 0;
	     rear = 0;
	}
	bool isEmpty()
	{
		return (front == rear) ? true : false;
	}
	bool isFull()                  //overflow
	{
		if (front == size - 1)
			return true;
		else
			return false;
	}
	void enqueue(T data)
	{
			queue[rear++] = data;
	}
	char dequeue()
	{
		if (isEmpty()) throw "Stack Underflow";
			return queue[front++];
	}
};

int main()
{
	Queue<char> q;

	try 
	{
		q.enqueue('a');
		q.enqueue('b');

		while(!q.isEmpty())
			std::cout << q.dequeue();
	}
	catch (const char* erm)
	{
		std::cout << erm;
	}

	
	return 0;
}

