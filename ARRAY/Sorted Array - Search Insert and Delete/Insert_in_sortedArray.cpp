#include <iostream>
using namespace std;

int insert(int arr[], int n, int key)
{
    int i;
    for(i = n-1; (i >= 0 && arr[i] > key); i--)
    {
        arr[i+1] = arr[i];
    }

    arr[i+1] = key;
    return n+1;
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {1,2,4,5,6,7,8,9};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int key = 0;

    n = insert(arr, n, key);
    printArray(arr, n);
}