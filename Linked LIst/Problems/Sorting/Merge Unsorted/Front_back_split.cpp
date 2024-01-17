#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void push(Node **head, int val)
{
    Node *new_node = new Node();
    new_node->data = val;
    new_node->next = *head;
    *head = new_node;
}

void front_back_split(Node *source, Node **frontref, Node **backref)
{
    Node *slow = source;
    Node *fast = source->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontref = source;
    *backref = slow->next;
    slow->next = NULL;
}

Node *SortedMerge(Node *a, Node *b)
{
    Node *result = NULL;

    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;

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

void MergeSort(Node **headref)
{
    Node *head = *headref;
    Node *a;
    Node *b;

    if (head == NULL || head->next == NULL)
        return;

    front_back_split(head, &a, &b);

    MergeSort(&a);
    MergeSort(&b);

    *headref = SortedMerge(a, b);
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL";
}

int main()
{
    int arr[] = {66, 4, 2, 88, 1, 22, 37, 91, 23, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *head = NULL;

    for (int i = 0; i < n; i++)
    {
        push(&head, arr[i]);
    }

    MergeSort(&head);

    print(head);
}