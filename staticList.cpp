//array implementation of linked list
#include<iostream>

const int max = 50;

struct nodeAssets
{
	int data, next;
};

class List
{
private:
	nodeAssets node[50];
	int avail,index,temp,list,delVal,q;
public:
	List()
	{
		//shorting for convenience
		for (int i = 0; i < max-1; i++)
		{
			node[i].next = i + 1;
		}
		node[max-1].next = -1;
		avail = 0;
		list = -1;
	}

	int getNode(int val)
	{
		if (avail == -1)
		{
			std::cout << "OverFlow";
			exit(1);
		}
		int p = avail;
		avail = node[avail].next;
		node[p].data = val;
		node[p].next = -1;
		return p;
	}
	void freeNode(int p)
	{
		node[p].next = avail;
		avail = p;
		if (p == list)
			list = -1;
	}
	void insertBeg(int val)
	{
		std::cout << "\n Inserting " << val << " at the beginning \n";
		index = getNode(val);
		node[index].next = list;
		list = index;
		showData(list);
	}
	void insertEnd(int val)
	{
		if (list == -1)
		{
			insertBeg(val);
		}
		else
		{
			index = getNode(val);
			temp = list;
			while (node[temp].next != -1)
			{
				temp = node[temp].next;
			}
			node[temp].next = index;
			std::cout << "\n Inserting " << val << " at the end \n";
			showData(list);
		}
	}
	void insertAfter(int val, int preVal)
	{
		temp = list;
		while (node[temp].data != preVal)
		{
			temp = node[temp].next;
		}
		index = getNode(val);
		node[index].next = node[temp].next;
		node[temp].next = index;
		std::cout << "\n Inserting " << val << " after "<<preVal;
		showData(list);
	}
	void delBeg()
	{
		if (list == -1)
		{
			std::cout << " UNDERFLOW ";
			exit(1);
		}
		index = list;
		list = node[list].next;
		std::cout << "\n Deleting " << node[index].data << " from the beginning \n";
		freeNode(index);
		showData(list);
	}
	void delEnd()
	{
		if (list == -1)
		{
			std::cout << " ERROR! ";
			exit(1);
		}
		else
		{
			temp = list;
			while (node[node[temp].next].next != -1)
			{
				temp = node[temp].next;
			}
			freeNode(node[temp].next);
			node[temp].next = -1;
			std::cout << "DELETING FROM THE END\n";
			showData(list);
		}
	}
	void delAfter(int preVal)
	{
		if (list == -1)
		{
			std::cout << "\n UNDERFLOW ";
			exit(1);
		}
		else
		{
			temp = list;
			while (node[temp].data != preVal)
			{
				temp = node[temp].next;
			}
			if (node[temp].next == -1)
			{
				std::cout << "\nError! NO DATA FOUND AFTER " << node[temp].data;
				exit(1);
			}
			index = node[temp].next;
			node[temp].next = node[index].next;
			std::cout << "\n Deleting " << node[index].data << " After "<<preVal<<std::endl; 
			freeNode(index);
			showData(list);
		}
	}

	void showData(int l)
	{
		std::cout << " DATA IN THE LIST: \n Data    Next\n";
		while (node[l].next != -1)
		{
			std::cout << "  "<<node[l].data << "        " << node[l].next << std::endl;
			l = node[l].next;
		}
		std::cout << "  " << node[l].data << "        " << node[l].next << std::endl;
	}
};

int main()
{
	List l;
	l.insertBeg(1);
	l.insertEnd(5);
	l.insertBeg(2);
	l.insertEnd(3);
	l.insertAfter(7, 2);
	l.insertAfter(10, 7);

	l.delBeg();
	l.delEnd();
	l.delAfter(10);
	l.delAfter(5);
	return 0;
}
