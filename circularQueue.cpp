//circular queue

#include<iostream>

const int size = 5;

template<class T>
class Cqueue
{
private:
	T queue[size];
	int front, rear;
public:
	Cqueue()
	{
		front = 0;
		rear = 0;
	}
	bool isEmpty()
	{
		return (front == rear) ? true : false;
	}
	void enqueue(T data)
	{
		rear %= (size - 1);
		queue[rear++] = data;
	}
	T dequeue()
	{
		if (isEmpty()) throw "Stack Underflow";
		front %= size;
		return queue[front++];
	}
};


int main()
{
	Cqueue<char>q;

	try
	{
		q.enqueue('a');
		q.enqueue('b');
		q.enqueue('a');
		

		while (!q.isEmpty())
			std::cout << q.dequeue();
	}
	catch (const char* erm)
	{
		std::cout << erm;
	}

	return 0;
}
