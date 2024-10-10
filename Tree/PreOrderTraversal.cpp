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

void PreOrder(Node *Root)
{
    if (Root)
    {
        cout << Root->data << " ";
        PreOrder(Root->left);
        PreOrder(Root->right);
    }
}

int main()
{
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *Root = NULL;

    for (int i = 0; i < n; i++)
    {
        Insert(Root, arr[i]);
    }

    PreOrder(Root);
}