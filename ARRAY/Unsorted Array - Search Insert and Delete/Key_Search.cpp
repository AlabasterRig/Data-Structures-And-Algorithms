#include <iostream>
using namespace std;

int search(int arr[], int n, int key)
{
    int position = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}


int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 5;

    int position = search(arr, n, key);

    if(position == -1)
        cout << "Element Not found";
    else 
        cout << position;
    
    return 0;
}