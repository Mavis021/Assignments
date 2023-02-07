#include<iostream>
#include<cmath>

const int max = 20;
struct queue
{
	int next, data;
};

class staticQueue
{
private:
	queue node[max];
	int front, rear,index;

public:
	staticQueue()
	{
				//shorting for convenience
		for (int i = 0; i < max-1; i++)
		{
			node[i].data = 0;
			node[i].next = i + 1;
		}
		node[max-1].next = -1;
		rear = -1;
		front = -1;
	}
	bool isEmpty()
	{
		return((front == -1 && rear == -1)|| front>=rear) ? true : false;
	}
	bool isFull()
	{
		return(rear == max - 1) ? true : false;
	}

	void enqueue(int val)
	{
		if (isEmpty())
		{
			front = 0;
			rear = 0;
			node[rear].data = val;
			node[rear].next = -1;
			std::cout << "\n inserting " << node[rear].data << std::endl;
			rear++;
		}
		else
		{
			node[rear].data = val;
			node[rear].next = -1;
			std::cout << "\n inserting " << node[rear].data << std::endl;
			rear++;
		}
	}
		int dequeue()
	    {
		if (isEmpty())
		{
			std::cout << " ERROR! ";
			exit(1);
		}
		else
		{
			index = front;
			front++;
			return node[index].data;
		}
	    }
};

int main()
{
	staticQueue sq;
	sq.enqueue(1);
	sq.enqueue(2);
	sq.enqueue(3);
	std::cout << "\n Deleting " << sq.dequeue()<< " \n";
	std::cout << "\n Deleting " << sq.dequeue() << "\n";
	std::cout << "\n Deleting " << sq.dequeue() << " \n";
	return 0;
}
