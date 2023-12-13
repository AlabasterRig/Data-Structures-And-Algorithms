#include <iostream>
using namespace std;

int find_element(int arr[], int n, int key)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int delete_ele(int arr[], int n, int key)
{
   int pos = find_element(arr, n, key);

   if(pos == -1)
   {
        cout << "Element Not Found";
        return n;
   }

    for(int i = pos; i < n-1; i++)
    {
        arr[i] = arr[i+1];
    }

    return (n-1);
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
    int arr[] = {5,7,2,3,87,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 7;

    n = delete_ele(arr, n, key);
    printArray(arr, n);
}