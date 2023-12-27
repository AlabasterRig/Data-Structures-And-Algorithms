#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
    }
};

void push(Node** head, int new_data)
{
    Node* new_node = new Node(new_data);
    new_node->next = *head;
    *head = new_node;
}

void print(Node* Node)
{
    while(Node != NULL)
    {
        cout << Node->data << "->xxxxxxxxxxx";
        Node = Node->next;
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    Node* head = NULL;

    for(int i = 0; i < n; i++)
    {
        push(&head, arr[i]);
    }

    print(head);
}