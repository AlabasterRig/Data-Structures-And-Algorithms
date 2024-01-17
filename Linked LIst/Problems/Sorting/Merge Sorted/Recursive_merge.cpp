#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void push(Node **head, int val)
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

Node *RecursiveMerge(Node *a, Node *b)
{
    if (a == NULL)
    {
        return b;
    }

    if (b == NULL)
    {
        return a;
    }

    Node *result = NULL;

    if (a->data <= b->data)
    {
        result = a;
        result->next = RecursiveMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = RecursiveMerge(a, b->next);
    }

    return (result);
}

void print(Node *head)
{
    Node *current = head;
    while (current)
    {
        cout << current->data << "->";
        current = current->next;
    }
    cout << "NULL";
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int arr2[] = {0, 7, 8, 9};

    int n1 = sizeof(arr) / sizeof(arr[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    Node *head = NULL;
    Node *head2 = NULL;

    for (int i = 0; i < n1; i++)
    {
        push(&head, arr[i]);
    }

    for (int i = 0; i < n2; i++)
    {
        push(&head2, arr2[i]);
    }

    Node *mergedList = RecursiveMerge(head, head2);

    print(mergedList);
}