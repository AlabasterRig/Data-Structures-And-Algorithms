#include <iostream>
#include <stack>
using namespace std;

// Define a class for implementing two stacks in a single array
class TwoStack
{
    int size;    // Total size of the array
    int *arr;    // Dynamic array to store elements
    int top1, top2;  // Top indices for two stacks

public:
    // Constructor to initialize the size and top indices
    TwoStack(int x)
    {
        size = x;
        arr = new int[x];  // Dynamic allocation of array
        top1 = (x / 2) + 1; // Initial top index for stack 1
        top2 = x / 2;       // Initial top index for stack 2
    }

    // Function to push an element onto stack 1
    void push1(int x)
    {
        if (top1 > 0)
        {
            top1--;
            arr[top1] = x;  // Store the element at the top index of stack 1
        }
        else
        {
            cout << "Stack Overflow by element: " << x << endl;
            return;
        }
    }

    // Function to push an element onto stack 2
    void push2(int x)
    {
        if (top2 < size - 1)
        {
            top2++;
            arr[top2] = x;  // Store the element at the top index of stack 2
        }
        else
        {
            cout << "Stack Overflow by element: " << x << endl;
        }
    }

    // Function to pop an element from stack 1
    int pop1()
    {
        if (top1 <= size / 2)
        {
            int x = arr[top1];  // Retrieve the element from the top index of stack 1
            top1++;
            return x;
        }
        else
        {
            cout << "Stack Underflow" << endl;
            exit(1);
        }
    }

    // Function to pop an element from stack 2
    int pop2()
    {
        if (top2 >= size / 2 + 1)
        {
            int x = arr[top2];  // Retrieve the element from the top index of stack 2
            top2--;
            return x;
        }
        else
        {
            cout << "Stack Underflow" << endl;
            exit(1);
        }
    }
};

// Main function
int main()
{
    // Create an object of the TwoStack class with a total size of 5
    TwoStack obj(5);

    // Push elements onto both stacks
    obj.push1(2);
    obj.push1(3);
    obj.push1(4);
    obj.push2(8);
    obj.push2(1);
    obj.push2(5);

    // Pop elements from both stacks and display
    cout << "Popped Element from stack 1 is: " << obj.pop1() << endl;
    cout << "Popped Element from stack 2 is: " << obj.pop2() << endl;

    // Push more elements onto both stacks
    obj.push1(7);
    obj.push1(9);
    obj.push2(10);
    obj.push2(11);

    return 0;
}
