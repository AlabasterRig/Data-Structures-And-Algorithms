#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void Insert(Node *&Root, int data)
{
    if (!Root)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        Root = newNode;
        return;
    }

    if (data < Root->data)
    {
        Insert(Root->left, data);
    }
    else
    {
        Insert(Root->right, data);
    }
}

void Print(Node *Root)
{
    if (Root == NULL)
    {
        return;
    }
    
    Print(Root->left);
    cout << Root->data;
    if (Root->right != NULL || Root->left != NULL)
    {
        cout << "->";
    }
    Print(Root->right);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *Root = NULL;

    for (int i = 0; i < n; i++)
    {
        Insert(Root, arr[i]);
    }

    Print(Root);
}