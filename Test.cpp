#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void push(Node** head, int val)
{
    Node* new_node = new Node();
    new_node->data = val;
    new_node->next = *head;
    *head = new_node;
}

void swap(Node** a, Node** b)
{
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void SwapNode(Node** head, int x, int y)
{
    Node** first = NULL;
    Node** second = NULL;

    while(*head)
    {
        if((*head)->data == x)
        {
            first = head;
        }
        else if((*head)->data == y)
        {
            second = head;
        }

        head = &((*head)->next);
    }

    if(first && second)
    {
        swap(*&first, *&second);
        swap(&(*first)->next, &(*second)->next);
    }
}

void print(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 2;
    int y = 7;

    Node* head = NULL;

    for(int i = 0; i < n; i++)
    {
        push(&head, arr[i]);
    }

    print(head);

    SwapNode(&head, x, y);
    cout << "\n";
    print(head);
}