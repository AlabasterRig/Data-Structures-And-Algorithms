#include <iostream>
#include <limits.h>
using namespace std;

struct StackNode
{
    int data;
    StackNode* next;
};

int isEmpty(StackNode* root)
{
    return !root;
}

void push(StackNode **root, int data)
{
    StackNode* new_node = new StackNode();
    new_node->data = data;
    new_node->next = *root;
    *root = new_node;
    cout << data << " Pushed to Stack\n";
}

int pop(StackNode** root)
{
    if(isEmpty(*root))
        return INT_MIN;
    
    StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

int peek(StackNode* root)
{
    if(isEmpty(root))
    {
        return INT_MIN;
    }

    return root->data;
}

int main() 
{ 
    StackNode* root = NULL; 
  
    push(&root, 10); 
    push(&root, 20); 
    push(&root, 30); 
  
    cout << pop(&root) << " popped from stack\n"; 
  
    cout << "Top element is " << peek(root) << endl; 
      
    cout <<"Elements present in stack : "; 
    while(!isEmpty(root)) 
    { 
        cout << peek(root) <<" "; 
        pop(&root); 
    } 
  
    return 0; 
} 