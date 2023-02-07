//double ended queue

#include<iostream>
const int size = 20;

template<class T>
class Deque
{
private:
	T queue[size];
	int front, end;
public:
	Deque()
	{
		end = 0;
		front = -1;
	}
	bool isEmpty()
	{
		return (((front + 1) == end) || ((front == (size - 1)) && end == 0)) ? true : false;
	}
	bool isFull()
	{
		return (front == end) ? true : false;
	}
	void enqueueEnd(T data)
	{
		if (isFull()) throw "Stack Overflow";
		end %= size;
		queue[end++] = data;
	}
	T dequeueEnd()
	{
		if (isEmpty()) throw "Stack Underflow";
		(end < 0) ? end = (size - 1) : end--;
		return queue[end];
	}
	void enqueueFront(T data)
	{
		if (isFull()) throw "Stack Overflow";
		(front < 0) ? front = (size - 1) : front--;
		queue[front] = data;
	}
	T dequeueFront()
	{
		if (isEmpty()) throw "Stack Underflow";
		front %= size;
		return queue[front++];
	}
};
int main()
{
	Deque<char> q;
	try
	{
			q.enqueueEnd('a');
			q.enqueueEnd('b');
			q.enqueueFront('c');
			q.enqueueFront('d');
			std::cout << q.dequeueFront() << '\n';
			std::cout << q.dequeueFront() << '\n';
			std::cout << q.dequeueEnd() << '\n';
			std::cout << q.dequeueEnd() << '\n';
	}
	catch (const char* erm)
	{
	 std::cout << erm;
	}
	return 0;
}

