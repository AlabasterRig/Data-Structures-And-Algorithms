#include <iostream>
using namespace std;

struct Node
{
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

void del(Node **head, int pos)
{
    Node* curr = *head;
    Node* prev = *head;

    for(int i = 0; i < pos; i++)
    {
        if(i == 0 && pos == 1)
        {
            curr = curr->next;
            *head = curr;
            free(curr);
            free(prev);
        }
        else {
            if(i == pos - 1 && curr != NULL)
            {
                prev->next = curr->next;
                free(curr);
            }
            else {
                prev = curr;
                if(prev == NULL)
                    break;
                
                curr = curr->next;
            }
        }
    }
}

void print(Node *node)
{
    while(node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
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

    print(head);

    cout << "\n";

    del(&head, 6);
    print(head);
}