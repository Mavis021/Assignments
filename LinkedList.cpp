
#include<iostream>
#include<cstdlib>
const int size =5;

struct node
{
    int data;
    node *next;
};


class LinkedList
{
    private:
    node *newNode,*start,*preptr,*ptr;
    int i;

    public:
    LinkedList()
    {
        start = NULL;
        i=0;
    }
    ~LinkedList(){}
    void insert(int a)
    {
        newNode = new node;
        if(newNode == NULL)
        {
            std::cout<<"Can't be allocated.";
        }

        if(start == NULL)
        {
            start = newNode;
            newNode->data = a;
            newNode->next = NULL;
        }
        else
            {
                newNode->data = a;
                newNode->next = start;
                start = newNode;
            }

    }

    void deleteList(int index)
    {
        preptr = start;
        ptr = start->next;
        while(i < index-1)
        {
            if (ptr->next == NULL)
            {
                std::cout << "DELETEING THE LAST NODE.";
                std::cout << "\n DELETED ITEM = " << ptr->data;
                ptr = NULL;
                preptr->next = NULL;
                exit(1);
            }
            std::cout << "ptr : " << ptr->data << std::endl;

            preptr = ptr;
            ptr = ptr->next;
            i++;
        }
        std::cout<<"DELETED ITEM = "<<ptr->data;
        preptr->next = ptr->next;
        ptr = NULL;
    }
};


int main()
{
    LinkedList LL;
    LL.insert(1);
    LL.insert(7);
    LL.insert(8);
    LL.insert(9);
    LL.deleteList(3);

    return 0;
}

