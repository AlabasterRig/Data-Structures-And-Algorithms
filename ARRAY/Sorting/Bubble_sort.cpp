#include <iostream>
#include <algorithm>
using namespace std;

void Bubble_Sort(int arr[], int n)
{
    int i, j;

    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main ()
{
    int arr[] = {5,6,3,8,64,23,76,45};
    int n = sizeof(arr)/sizeof(arr[0]);

    Bubble_Sort(arr, n);
    printArray(arr, n);
}