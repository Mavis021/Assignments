
//Lab9_4.cpp
//Write any program that demonstrates the use of multiple catch handling, re - throwing an exception, and catching all exceptions.


#include <iostream>

using namespace std;


class Exception
{
private:
    bool check;
public:
    Exception();
    Exception(bool c):check(c){}
    

    void displayError()
    {
        if(check == true)
        cout << "THE STACK IS FULL." << endl;
        else
            cout << "THE STACK IS EMPTY" << endl;
    }
};


template <class T>

class Stack

{

private:

    T st[3];

    int top;

public:

    Stack();

    void push(T var);

    T pop();

};

template <class T>

 Stack<T>::Stack()

{

    top = -1;

}

template <class T>

void Stack<T>::push(T var)

{
    if (top >= 1)
    {
        throw Exception (true);
    }
    else
    {
        st[++top] = var;
    }

}

template <class T>

T Stack<T>::pop()

{
    if (top < 0)
    {
        throw Exception (false);
    }
    else
    {
        return st[top--];
    }

}

int main()

{

    Stack<float> s1;
    try
    {
        try
        {
            s1.push(111.1F);

            s1.push(222.2F);
            s1.push(222.2F);
        }

        catch (Exception e)
        {
            e.displayError();
        }
        cout << "1 : " << s1.pop() << endl;

        cout << "2 : " << s1.pop() << endl;

        cout << "3 : " << s1.pop() << endl;
        throw;

    }
    catch (...)
    {
        cout << "last catch" << endl;
    }

    return 0;

}
