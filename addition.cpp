//a program in cpp to add multiple polynomial equations using dynamic linkedList
#include<iostream>

struct node{
 float coef, expo;
 node* next;
};

class LinkedList
{
private:
    node* newNode, *ptr,*p,*start,*temp;
    int degree,n;
    float data;
public:
    LinkedList():degree(0),n(0),data(0)
    {
        start = nullptr;
    }
    ~LinkedList()
    {
    }
    void getData()
    {
        std::cout << "ENTER THE NUMER OF EXPRESSIONS TO BE ADDED : ";
        std::cin >> n;
        std::cout << "ENTER THE HIGHEST DEGREE AMONG THE EXPRESSIONS: ";
        std::cin >> degree;
        std::cout << "ENTER THE COEFFICIENTS OF ALL THE EXPRESSIONS IN MATRIX FORM: " << n << " x " << degree << std::endl;
    }
    void insertExp()
    {
        getData();
        for(int j =0;j<n;j++)
        {
        start = nullptr;
        for(int i=degree;i>0;i--)
        {
            std::cin>>data;
            newNode = new node;
            newNode->coef = data;
            newNode->expo = i;
            if(start == nullptr)
            {
                newNode->next = nullptr;
                start = newNode;
            }
            else
            {
                ptr = start;
                while(ptr->next != nullptr)
                {
                    ptr = ptr->next;
                }
                ptr->next = newNode;
                newNode->next = nullptr;
            }
        }
        if(j == 0)
        {
                temp = start;
        }
        else
        {
            Addition(start);
        }
        }
        showData(temp);
    }
    void Addition(node* q)
    {
        p = temp;
            while(p->next != nullptr)
            {
                  p->coef += q->coef;
                  p = p->next;
                  q = q->next;
            }
            if (p->expo == q->expo)
            {
                p->coef += q->coef;
                p = p->next;
                q = q->next;
            }
    }
    void showData(node* a)
    {
        std::cout << "\n ADDITION: ";
        while(a->next != nullptr)
        {
            std::cout<<a->coef<<"x^"<<a->expo;
            std::cout<<" + ";
            a = a->next;
        }
        std::cout<<a->coef<<"x^"<<a->expo;
    }
};

int main()
{
    LinkedList ll;
    ll.insertExp();
    return 0;
}

