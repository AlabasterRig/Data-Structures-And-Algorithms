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
        return binarySearch(arr, mid+1, high, key);
    }
    else{
        return binarySearch(arr, 0, mid-1, key);
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 2;

    int position = binarySearch(arr, 0, n-1, key);

    cout << "Position is: " << position;
}