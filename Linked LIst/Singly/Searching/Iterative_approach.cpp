#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

void push(Node** head, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

bool search(Node *Node, int key)
{
    while(Node != NULL)
    {
        if(Node->data == key)
        {
            return true;
        }
        Node = Node->next;
    }
    return false;
}

int main()
{
    Node* head = NULL;
    int data;
    for(int i = 0; i < 4; i++)
    {
        cout << "Enter data: ";
        cin >> data;
        push(&head, data);
    }

    int key;
    cout << "Enter Key: ";
    cin >> key;

    if(search(head, key) == true)
    {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
}