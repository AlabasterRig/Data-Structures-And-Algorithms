//After a Node

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

void push(Node** head, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head;
    new_node->prev = NULL;

    if(*head != NULL)
    {
        (*head)->prev = new_node;
    }

    *head = new_node;
}

void InsertInMiddle(Node* prev_node, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;

    new_node->prev = prev_node;

    if(new_node->next != NULL)
    {
        new_node->next->prev = new_node;
    }
}

void print(Node* Node)
{
    while(Node != NULL)
    {
        cout << Node->data << "->";
        Node = Node->next;
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    Node* head = NULL;

    for(int i = 0; i < n; i++)
    {
        push(&head, arr[i]);
    }

    print(head);

    cout << "\n";

    Node* curr = head;

    while(curr != NULL && curr->data != 6)
    {
        curr = curr->next;
    }

    if(curr != NULL)
    {
        InsertInMiddle(curr, 6);
        print(head);
    }
    else {
        cout << "Num does not exist";
    }

}