
#include<iostream>
#include<iomanip>

using namespace std;

struct node
{
    int data;
    node* prev,*next;
};

class doubleLinkedList
{
    private:
    node *ptr,*start,*newNode,*preptr;
    
    public:
    doubleLinkedList()
    {
        start = NULL;
    }
    void insertBeg(int val)
    {
        newNode = new node;

        if(start == NULL)
        {
            newNode->data = val;
            newNode->prev = NULL;
            newNode->next = NULL;
            start = newNode;
        }
        else
        {
            newNode->data =val;
            newNode->next = start;
            start = newNode;
        }
        std::cout << "\n     INSERTING " << val << " FROM THE BEGINNING: ";
        showList();
    }
        void insertEnd(int val)
    {
        newNode = new node;

        if(start == NULL)
        {
            newNode->data = val;
            newNode->prev = NULL;
            newNode->next = NULL;
            start = newNode;
        }
        else
        {
            newNode->data =val;
            newNode->next = NULL;
            ptr = start;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->prev = ptr; 
        }
            std::cout << "\n     INSERTING " << val << " AT THE END: ";
            showList();
    }
    void insertBefore(int postval,int val)
    {
        newNode = new node;
        if(start == NULL)
        {
            cout<<"ERROR!";
            exit(1);
        }
        else if(postval == (start->data))
         {
            insertBeg(val);
         }
        else
        {
            newNode->data = val;
            ptr = start;
            preptr = ptr;
            while(ptr->data != postval)
            {
                preptr = ptr;
                ptr = ptr->next;
            }
            preptr->next = newNode;
            newNode->prev = preptr;
            newNode->next = ptr;
            ptr->prev = newNode;
            std::cout << "\n     INSERTING " << val << " BEFORE " << postval;
            showList();
        }
    }
        void insertAfter(int preval,int val)
        {
        newNode = new node;
        if(start == NULL)
        {
            cout<<"ERROR!";
            exit(1);
        }
        else
        {
            newNode->data = val;
            ptr = start;
            preptr = ptr;
            while(preptr->data != preval)
            {
                if (ptr->next == NULL)
                {
                    insertEnd(val);
                    break;
                }
                preptr = ptr;
                ptr = ptr->next;
            }
            if (ptr->next != NULL)
            {
                if (start->data == preval)
                {
                    ptr = ptr->next;
                }
                preptr->next = newNode;
                newNode->prev = preptr;
                newNode->next = ptr;
                ptr->prev = newNode;
                std::cout << "\n     INSERTING " << val << " AFTER " << preval;
                showList();
            }
        }
        }
    void deleteEnd()
    {
        ptr = start;
        preptr = ptr;
        while(ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
       preptr->next = NULL;
       std::cout << "\n     DELETION FROM END: \n     DELETED DATA: " << ptr->data;
       delete ptr;
       showList();
    }
    void deleteBeg()
    {
        ptr = start;
        start = start->next;
        start->prev = NULL;
        std::cout << "\n     DELETION FROM BEGINNING: \n     DELETED DATA: " << ptr->data;
        delete ptr;
        showList();
    }
    void deleteAfter(int preval)
    {
        ptr = start;
        preptr = ptr;
        while (preptr->data != preval)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
            if (start->data == preval)
            {
                ptr = ptr->next;
                if (ptr->next != NULL)
                {
                    preptr->next = ptr->next;
                    ptr->next->prev = preptr;
                }
                else
                    preptr->next = NULL;
            }
            else
            {
                preptr->next = ptr->next;
                ptr->next->prev = preptr;
            }

            std::cout << "\n     DELETION AFTER "<<preval;
            delete ptr;
            showList();
    }
    void deleteBefore(int postval)
    {
        ptr = start;
        preptr = ptr;
        while (ptr->data != postval)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        if(preptr->prev != NULL)
        {
            ptr->prev = preptr->prev;
            preptr->prev->next = ptr;
            std::cout << "\n     DELETION BEFORE " << postval;
            delete preptr;
            showList();
        }
        else
        {
            deleteBeg();
        }
    }
        void showList()
    {
        std::cout << "\nTHE VALUES IN LINKED LIST: \n";
        ptr = start;
        std::cout << "PREVIOUS                          DATA               NEXT\n";
        while (ptr->next != NULL)
        {
            std::cout <<ptr->prev<<std::setw(20)<< ptr->data << std::setw(20) << ptr->next << std::endl;
            ptr = ptr->next;
        }
        std::cout << ptr->prev << std::setw(20) << ptr->data << std::setw(20) << " NULL " << std::endl;
    }
};

int main()
{
     doubleLinkedList LL;

    LL.insertBeg(2);
    LL.insertEnd(3);
    LL.insertAfter(2, 4);
    LL.insertBefore(3, 5);
    LL.insertBefore(3, 6);
    LL.insertAfter(4,7);
    LL.insertAfter(3, 8);

    LL.deleteBeg();
    LL.deleteEnd();
    LL.deleteAfter(4);
    LL.deleteBefore(6);

    return 0;
}