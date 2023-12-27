#include <iostream>
using namespace std;

int insert(int arr[], int n, int key, int position)
{
    for(int i = n-1; i >= position; i--)
    {
        arr[i+1] = arr[i];
    }

    arr[position] = key;
    return (n+1);
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<< arr[i] << " ";
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 20;
    int position = 6;

    n = insert(arr, n, key, position);
    printArray(arr, n);
}