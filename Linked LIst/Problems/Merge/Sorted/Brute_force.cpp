#include <iostream>
#include <vector>
#include <algorithm>
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

Node *newNode(int key)
{
    Node *newNode = new Node();
    newNode->data = key;
    newNode->next = NULL;
    return newNode;
}

void MergeLinkedList(Node *a, Node *b)
{
    vector<int> mergedList;

    while (a != NULL)
    {
        mergedList.push_back(a->data);
        a = a->next;
    }

    while (b != NULL)
    {
        mergedList.push_back(b->data);
        b = b->next;
    }

    sort(mergedList.begin(), mergedList.end());

    Node *result = newNode(-1);
    Node *temp = result;

    for (int i = 0; i < mergedList.size(); i++)
    {
        result->next = newNode(mergedList[i]);
        result = result->next;
    }
    temp = temp->next;

    cout << "Merged LL is: \n";
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int arr2[] = {7, 8, 5, 3};

    int n1 = sizeof(arr) / sizeof(arr[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    Node *head = NULL;
    Node *head2 = NULL;

    for (int i = 0; i < n1; i++)
    {
        push(&head, arr[i]);
    }

    for (int i = 0; i < n2; i++)
    {
        push(&head2, arr2[i]);
    }

    MergeLinkedList(head, head2);
}