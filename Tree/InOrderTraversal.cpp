#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* mid;
    Node* right;

    Node(int element)
    {
        data = element;
        left = NULL;
        mid = NULL;
        right = NULL;
    }
};

void Insert(Node* Root, int data)
{
    if(!Root)
    {
        Root = new Node(data);
        return;
    }

    if(data < Root->data)
    {
        Insert(Root->left, data);
    }
    
    if(data > Root->data)
    {
        Insert(Root->mid, data);
    }

}