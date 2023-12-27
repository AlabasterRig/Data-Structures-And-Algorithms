#include <iostream>
using namespace std;

class Node
{
public:
    int data;       // Declaration of an integer data member
    Node* next;     // Declaration of a pointer to the next Node (access specifier missing: private by default)
};

void push(Node** head, int new_data)
{
    Node *new_node = new Node();    // Create a new Node object

    // Set the data and next pointer of the new Node
    new_node->data = new_data;
    new_node->next = *head;         // Update next to point to the current head
    *head = new_node;               // Update head to the new Node
}

void rev(Node **head)
{
    Node *prev = NULL, *current = *head, *next = NULL; // Initialize three Node pointers

    // Reversing the linked list logic
    while(current != NULL)
    {
        next = current->next;       // Store the next node
        current->next = prev;       // Reverse the link
        prev = current;             // Move prev to the current node
        current = next;             // Move current to the next node
    }

    *head = prev;   // Set the head to the last node (previously the end)
}

void print(Node* Node)
{
    // Traverse the linked list and print the data of each Node
    while(Node != NULL)
    {
        cout << Node->data << "->"; // Print the data of the current Node
        Node = Node->next;          // Move to the next Node
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]); // Calculate the size of the array

    Node *head = NULL;  // Initialize an empty linked list

    // Create a linked list using the array elements
    for(int i = 0; i < n; i++)
    {
        push(&head, arr[i]);    // Insert each element of the array at the beginning of the linked list
    }

    cout << "Before Reverse: \n";
    print(head);    // Display the linked list before reversing it
    cout << "\n";

    cout << "After Reverse: \n";
    rev(&head);     // Reverse the linked list
    print(head);    // Display the reversed linked list
}
