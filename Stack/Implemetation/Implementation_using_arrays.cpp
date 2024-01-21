#include <iostream>
using namespace std;
#define MAX 1000
class Stack
{
private:
    int top;

public:
    Stack()
    {
        top = -1;
    }

    int a[MAX];
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x)
{
    if (top > MAX - 1)
    {
        cout << "Stack overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        cout << "Pushed into stack\n";
        return true;
    }
}

int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}

int Stack::peek()
{
    if (top < 0)
    {
        cout << "Stack is Empty";
        return 0;
    }
    else
    {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.pop() << " Popped from stack\n";

    cout << "Top element is: " << s.peek() << endl;
    cout << "Elements present in stack: ";

    while (!s.isEmpty())
    {
        cout << s.peek() << " ";
        s.pop();
    }

    return 0;
}