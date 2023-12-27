#include <iostream>
using namespace std;

class Node
{
public:
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

bool search(Node *head, int key)
{
    if (head == NULL)
    {
        return false;
    }

    if (head->data == key)
    {
        return true;
    }

    return search(head->next, key);
}

int main()
{
    Node *head = NULL;
    int data;
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter data: ";
        cin >> data;
        push(&head, data);
    }

    int key;
    cout << "Enter key: ";
    cin >> key;

    if (search(head, key) == true)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}