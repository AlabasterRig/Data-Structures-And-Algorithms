#include <iostream>
#include <algorithm>
using namespace std;

class Node 
{
    public:
    int data;
    Node *next;
};

void insert_after(Node* prev_node, int new_data)
{
    if(prev_node == NULL)
    {
        cout << "Previous Node cannot be NULL";
        return;
    }

    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = prev_node->next;

    prev_node->next = new_node;
}

void push(Node** head, int new_data)
{
    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = *head;

    *head = new_node;
}

void print(Node *Node)
{
    while(Node != NULL)
    {
        cout << " " << Node->data;
        Node = Node->next;
    }
    cout << "\n";
}

int main()
{
    int data;
    Node* head = NULL;
    cout << "Enter data: ";
    
    for(int i = 0 ; i < 4; i++)
    {
        cin >> data;
        push(&head, data);
    }
    cout << "\n";
    cout << "Before Insertion: \n"; 
    print(head);

    insert_after(head, 2);
    cout << "After Insertion: \n";
    print(head);

}