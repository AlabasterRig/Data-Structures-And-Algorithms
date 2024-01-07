#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void push(Node **head, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void deleteKey(Node** head, int key)
{
    Node* curr = *head;
    Node* prev = NULL;

    if(curr != NULL && curr->data == key)
    {
        *head = curr->next;
        delete(curr);
        return;
    }

    while(curr != NULL && curr->data != key)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    delete(curr);
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

    deleteKey(&head, 6);
    print(head);
}