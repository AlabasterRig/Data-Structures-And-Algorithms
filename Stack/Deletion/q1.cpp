/*
Question:
Write a C++ program to implement a stack and perform the following operations:
1. Push an element onto the stack.
2. Pop an element from the stack.
3. Display the elements of the stack.

Your program should handle stack underflow and overflow conditions appropriately.
*/

#include <iostream>
#include <vector>
using namespace std;

struct Stack
{
    int data;
    Stack* next;
};

void push(Stack** root, int data)
{
    Stack* new_node = new Stack();
    new_node->data = data;
    new_node->next = *root;
    *root = new_node;
    cout << data << " Pushed to Stack\n";
}

void pop(Stack** root)
{
    if(root == NULL)
    {
        cout << "Stack is empty\n";
    }

    Stack* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    cout << popped << " popped from stack\n";
}

void print(Stack* root)
{
    if(root == NULL)
    {
        cout << "Stack is empty\n";
    }

    while(root != NULL)
    {
        cout << root->data << " ";
        root = root->next;
    }
}

int main()
{
    int N;
    cout << "Enter the size of the stack: ";
    cin >> N;
    vector<int> arr(N);
    
    for(int i = 0; i < N; i++)
    {
        cout << "Enter values for stack: ";
        cin >> arr[i];
    }

    Stack* root = NULL;

    for(int i =0; i < N; i++)
    {
        push(&root, arr[i]);
    }

    pop(&root);

    print(root);

    return 0;
}