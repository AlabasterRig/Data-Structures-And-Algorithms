#include <stack>
#include <iostream>
#include <queue>
using namespace std;

// Define a class for implementing a stack using two queues
class StackQueue
{
    queue<int> q1, q2;  // Two queues for stack implementation

public:
    // Function to push an element onto the stack
    void push(int x)
    {
        q2.push(x);  // Push the new element onto the second queue

        // Move elements from the first queue to the second queue
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap the names of the two queues
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    // Function to pop the top element from the stack
    void pop()
    {
        if (q1.empty())
        {
            return;
        }
        q1.pop();
    }

    // Function to return the top element of the stack
    int top()
    {
        if (q1.empty())
        {
            return -1;
        }

        return q1.front();
    }

    // Function to return the current size of the stack
    int size()
    {
        return q1.size();
    }
};

// Main function
int main()
{
    // Create an object of the StackQueue class
    StackQueue s;

    // Push elements onto the stack
    s.push(1);
    s.push(2);
    s.push(3);

    // Display the current size and top element of the stack
    cout << "Current Size: " << s.size() << endl;
    cout << s.top() << endl;

    // Pop elements from the stack and display the new top element
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    // Display the current size of the stack
    cout << "Current Size: " << s.size() << endl;

    return 0;
}
