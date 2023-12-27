#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        // this->next = NULL;
    }
};

void push(Node **head, int new_data)
{
    Node *new_node = new Node(new_data);
    new_node->next = *head;
    *head = new_node;
}

void insert(Node **head, int new_data)
{
    Node *new_node = new Node(new_data);

    Node *last = *head;

    new_node->next = nullptr;

    if (*head == NULL)
    {
        *head = new_node;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
}

void print(Node *Node)
{
    while (Node != NULL)
    {
        cout << Node->data << "->";
        Node = Node->next;
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

    cout << "Before Insertion \n";
    print(head);
    cout << "\n";

    int data;
    cout << "Insert Data to End: \n";
    cin >> data;

    insert(&head, data);
    print(head);
}