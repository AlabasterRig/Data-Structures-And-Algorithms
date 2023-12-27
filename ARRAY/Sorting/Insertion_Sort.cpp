#include <iostream>
#include <algorithm>
using namespace std;

void Insertion_sort(int arr[], int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            swap(arr[j + 1], arr[j]);
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {4, 7, 22, 37, 5, 98, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    Insertion_sort(arr, n);
    printArray(arr, n);
}