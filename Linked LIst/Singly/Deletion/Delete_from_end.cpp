#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void push(Node **head, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void delte(Node **head)
{
    Node *curr = *head;
    Node *prev = NULL;

    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = NULL;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *head = NULL;

    for (int i = 0; i < n; i++)
    {
        push(&head, arr[i]);
    }

    print(head);

    cout << "\n";

    delte(&head);
    print(head);
}