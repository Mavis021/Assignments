//linear linked list
#include<iostream>
#include<cstdlib>
#include<iomanip>

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
    void insertBeg(int val)
    {
        newNode = new node;
        if(newNode == NULL)
        {
            std::cout<<"Can't be allocated.";
        }
        else
        {
                newNode->data = val;
                newNode->next = start;
                start = newNode;
        }
        std::cout << "\n     INSERTING " << val << " FROM THE BEGINNING: ";
        showList();
    }
    void insertEnd(int val)
    {
        newNode = new node;
        if (newNode == NULL)
        {
            std::cout << "Can't be allocated.";
        }
        else
        {
            newNode->data = val;
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            newNode->next = NULL;
            ptr->next = newNode;

            std::cout << "\n     INSERTING " << val << " AT THE END: ";
            showList();
        }
    }
    void insertAfter(int preVal, int val)
    {
        newNode = new node;
        if (newNode == NULL)
        {
            std::cout << "Can't be allocated.";
        }
        newNode->data = val;
        ptr = start;
        preptr = ptr;
            while (preptr->data != preVal)
            {
                preptr = ptr;
                ptr = ptr->next;
            }
            if (start->data == preVal)
            {
                ptr = ptr->next;
            }
            preptr->next = newNode;
            newNode->next = ptr;
            std::cout << "\n     INSERTING " << val << " AFTER " << preVal;
            showList();
    }
    void insertBefore(int postVal, int val)
    {
        newNode = new node;
        if (newNode == NULL)
        {
            std::cout << "Can't be allocated. ";
        }
        newNode->data = val;
        ptr = start;
        preptr = ptr;
        while (ptr->data != postVal)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = newNode;
        newNode->next = ptr;
        std::cout << "\n     INSERTING " << val << " BEFORE " << postVal;
        showList();
    }
    void deleteBeg()
    {
        ptr = start;
        start = start->next;
        std::cout << "\n     DELETION FROM BEGINNING: \n     DELETED DATA: " << ptr->data;
        delete ptr;
        showList();
    }
    void deleteEnd()
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL;
        std::cout << "\n     DELETION FROM END: \n     DELETED DATA: " << ptr->data;
        delete ptr;
        showList();
    }

    void deleteAfter(int preVal)
    {
        if (start == NULL)
        {
            std::cout << "THE LIST IS EMPTY. ";
            exit(1);
        }
        else
        {
            ptr = start;
            preptr = ptr;
            while (preptr->data != preVal)
            {
                preptr = ptr;
                ptr = ptr->next;
            }
            if (start->data == preVal)
            {
                ptr = ptr->next;
                if (ptr->next != NULL)
                    preptr->next = ptr->next;
                else
                    preptr->next = NULL;
            }
            else
            {
                preptr->next = ptr->next;
            }
            std::cout << "\n     DELETION AFTER "<<preVal;
            delete ptr;
            showList();
        }
    }


    void showList()
    {
        std::cout << "\nTHE VALUES IN LINKED LIST: \n";
        ptr = start;
        std::cout << "DATA        ADDRESS\n";
        while (ptr->next != NULL)
        {
            std::cout << ptr->data << std::setw(20) << ptr->next << std::endl;
            ptr = ptr->next;
        }
        std::cout << ptr->data << std::setw(20) << " NULL " << std::endl;
    }

};


int main()
{
    LinkedList LL;

    LL.insertBeg(2);
    LL.insertEnd(3);
    LL.insertAfter(2, 4);
    LL.insertBefore(3, 5);
    LL.insertBefore(3, 6);
    LL.insertAfter(4,7);

    LL.deleteBeg();
    LL.deleteEnd();
    LL.deleteAfter(4);

    return 0;
}

