#include <iostream>
using namespace std;

void selection_sort(int arr[], int n)
{
    int i, j, min_index;

    for (i = 0; i < n; i++)
    {
        min_index = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        if (min_index != i)
        {
            swap(arr[min_index], arr[i]);
        }
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
    int arr[] = {5, 7, 34, 98, 2, 1, 8, 3, 4, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    selection_sort(arr, n);
    printArray(arr, n);
}