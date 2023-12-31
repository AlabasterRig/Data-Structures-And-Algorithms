#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
};

void Add_in_beginning(Node **head, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head;
    new_node->prev = NULL;

    if(*head != NULL)
    {
        (*head)->prev = new_node;
    }

    *head = new_node;
}

void print(Node *Node)
{
    while(Node != NULL)
    {
        cout << Node->data << "->";
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    Node* head = NULL;

    for(int i = 0; i < n; i++)
    {
        Add_in_beginning(&head, arr[i]);
    }

    print(head);
}