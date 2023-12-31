#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key)
{
    if(high < low)
    {
        return -1;
    }

    int mid = (high + low) / 2;

    if(arr[mid] == key)
    {
        return mid;
    }

    if(key > arr[mid])
    {
        return binarySearch(arr, (mid + 1), high, key);
    }

    return binarySearch(arr, low, (mid - 1), key);
}

int deleteElement(int arr[], int n, int key)
{
    int pos = binarySearch(arr, 0, n-1, key);

    if(pos == -1)
    {
        cout << "Element Not Found\n";
        return n;
    }

    int i;
    for(i = pos; i < n-1; i++)
    {
        arr[i] = arr[i+1];
    }

    return n-1;
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
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 7;

    n = deleteElement(arr, n, key);
    printArray(arr, n);
}
#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key)
{
    if(high < low)
    {
        return -1;
    }

    int mid = (high + low) / 2;

    if(arr[mid] == key)
    {
        return mid;
    }

    if(key > arr[mid])
    {
        return binarySearch(arr, (mid + 1), high, key);
    }

    return binarySearch(arr, low, (mid - 1), key);
}

int deleteElement(int arr[], int n, int key)
{
    int pos = binarySearch(arr, 0, n-1, key);

    if(pos == -1)
    {
        cout << "Element Not Found\n";
        return n;
    }

    int i;
    for(i = pos; i < n-1; i++)
    {
        arr[i] = arr[i+1];
    }

    return n-1;
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
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 7;

    n = deleteElement(arr, n, key);
    printArray(arr, n);
}