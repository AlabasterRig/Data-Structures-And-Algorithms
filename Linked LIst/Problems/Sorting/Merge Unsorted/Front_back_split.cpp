#include <iostream>
using namespace std;

// Node structure for a singly linked list
struct Node
{
    int data;         // Data of the node
    Node *next;       // Pointer to the next node
};

// Function to insert a new node at the beginning of the linked list
void push(Node **head, int val)
{
    Node *new_node = new Node();    // Create a new node
    new_node->data = val;           // Set its data
    new_node->next = *head;         // Point it to the current head
    *head = new_node;               // Update the head to the new node
}

// Function to split a linked list into front and back halves
void front_back_split(Node *source, Node **frontref, Node **backref)
{
    Node *slow = source;            // Slow pointer
    Node *fast = source->next;      // Fast pointer

    // Move fast two steps and slow one step until fast reaches the end
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontref = source;             // Front half
    *backref = slow->next;          // Back half
    slow->next = NULL;              // Disconnect the front and back halves
}

// Function to merge two sorted linked lists
Node *SortedMerge(Node *a, Node *b)
{
    Node *result = NULL;

    // Base cases: if either list is empty, return the other
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;

    // Choose the smaller value and recursively merge the remaining lists
    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }

    return result;
}

// Function to perform merge sort on a linked list
void MergeSort(Node **headref)
{
    Node *head = *headref;
    Node *a;
    Node *b;

    // Base case: if the list is empty or has only one element, it is already sorted
    if (head == NULL || head->next == NULL)
        return;

    // Split the list into front and back halves
    front_back_split(head, &a, &b);

    // Recursively sort the two halves
    MergeSort(&a);
    MergeSort(&b);

    // Merge the sorted halves
    *headref = SortedMerge(a, b);
}

// Function to print the elements of a linked list
void print(Node *head)
{
    // Traverse the linked list and print each element
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL"; // Print NULL at the end
}

// Main function
int main()
{
    int arr[] = {66, 4, 2, 88, 1, 22, 37, 91, 23, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *head = NULL;

    // Insert elements into the linked list
    for (int i = 0; i < n; i++)
    {
        push(&head, arr[i]);
    }

    // Perform merge sort on the linked list
    MergeSort(&head);

    // Print the sorted linked list
    print(head);
}
