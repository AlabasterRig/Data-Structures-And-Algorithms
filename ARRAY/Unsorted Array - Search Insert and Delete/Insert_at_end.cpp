#include <iostream>
using namespace std;

int insert(int arr[], int n, int key)
{
    int position = n + 1;
    
    arr[position] = key;

    return position;
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
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 65;

    n = insert(arr, n, key);
    printArray(arr, n);

}