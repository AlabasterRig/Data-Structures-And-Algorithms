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
    Node * newNode = new Node();
    newNode->data = new_data;
    newNode->next = *head;
    *head = newNode;
}

int calc(Node *Node)
{
    if(Node == NULL)
    {
        return 0;
    }
    else{
        return 1 + calc(Node->next);
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    Node* head = NULL;

    for(int i = 0; i < n; i++)
    {
        push(&head, arr[i]);
    }

    int count = calc(head);
    cout << count;
}