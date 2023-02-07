
//Lab9_2.cpp
//Write a class template for queue class.Assume the programmer using the queue won't make mistakes, 
//like exceeding the capacity of the queue or trying to remove an item when the queue is empty.
//Define several queues of different data types and insert and remove data from them.

#include<iostream>
#include<cstring>
using namespace std;

const int Max = 20;

template<class T>
class queue
{
private:
	T arr[Max];
	int top ,size;
public:
	queue(int a = 0, int b = 0) :top(a), size(b) {};
	void insert(T t)
	{
		++size;
		arr[size - 1] = t;
	}
	T remove()
	{
		--size;
		return arr[top++];
	}
};

int main()
{
	queue<int> iqueue;

	iqueue.insert(0);
	iqueue.insert(3);
	iqueue.insert(2);
	cout << iqueue.remove() << endl;
	cout << iqueue.remove() << endl;

	queue<float> fqueue;

	fqueue.insert(0.1);
	fqueue.insert(3.2);
	fqueue.insert(2.3);
	cout << fqueue.remove() << endl;
	fqueue.insert(5.55);
	cout << fqueue.remove() << endl;

	return 0;
}
