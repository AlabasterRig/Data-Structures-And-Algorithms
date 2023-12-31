#include <iostream>
using namespace std;

// Defining structure of the linked list node
struct Node {
    int data; // variable to store the value
    Node* next; // pointer to the next node in the linked list
};

// Function to push new node to the start of the linked list
void push(Node** head, int new_data)
{
    // allocate new node
    Node* new_node = new Node();

    // assign new data to new node
    new_node->data = new_data;

    // make next of new node as head
    new_node->next = (*head);

    // move the head to point to new node
    (*head) = new_node;
}

// Function to reverse the linked list
void rev(Node** head)
{
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;

    // iterate over the linked list
    while(current != NULL)
    {
        // store next node
        next = current->next;

        // reverse current node's pointer
        current->next = prev;

        // move pointers forward to proceed to next node in original linked list
        prev = current;
        current = next;
    }

    // update the head to be the last node of the original linked list
    *head = prev;
}

// Function to print the linked list
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
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    Node *head = NULL;

    // create a new linked list by pushing nodes into it
    for(int i = 0; i < n; i++)
    {
        push(&head, arr[i]);
    }

    cout << "Before Reverse: \n";
    print(head);
    cout << "\n";

    // reverse the linked list
    rev(&head);

    cout << "After Reverse: \n";
    print(head);

    return 0;
}