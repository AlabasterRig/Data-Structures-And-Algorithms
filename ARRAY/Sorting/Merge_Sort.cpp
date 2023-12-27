#include <iostream>
#include <algorithm>
using namespace std;

void Merge(int arr[], int left, int mid, int right)
{
    // divide array to each halves
    auto const n1 = mid - left + 1;
    auto const n2 = right - mid;

    // Create subarrays
    int *sub_arr_one = new int[n1];
    int *sub_arr_two = new int[n2];

    // store elements from main array to the subarrays
    for (int i = 0; i < n1; i++)
    {
        sub_arr_one[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        sub_arr_two[i] = arr[mid + 1 + i];
    }

    // merge subarray back to main array
    auto leftIndex = 0, rightIndex = 0;
    int mainArrayIndex = left;

    while (leftIndex < n1 && rightIndex < n2)
    {
        if (sub_arr_one[leftIndex] <= sub_arr_two[rightIndex])
        {
            arr[mainArrayIndex] = sub_arr_one[leftIndex];
            leftIndex++;
        }
        else
        {
            arr[mainArrayIndex] = sub_arr_two[rightIndex];
            rightIndex++;
        }
        mainArrayIndex++;
    }

    // Copy Remaining Elements from Left to Main Array
    while (leftIndex < n1)
    {
        arr[mainArrayIndex] = sub_arr_one[leftIndex];
        leftIndex++;
        mainArrayIndex++;
    }

    // Copy Remaining Elements from Right to main Array
    while (rightIndex < n2)
    {
        arr[mainArrayIndex] = sub_arr_two[rightIndex];
        rightIndex++;
        mainArrayIndex++;
    }

    // Delete the SubArrays
    delete[] sub_arr_one;
    delete[] sub_arr_two;
}

void Merge_Sort(int arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;

    Merge_Sort(arr, left, mid);
    Merge_Sort(arr, mid + 1, right);
    Merge(arr, left, mid, right);
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
    int arr[] = {4, 7, 23, 9, 56, 23, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    Merge_Sort(arr, 0, n - 1);
    printArray(arr, n);
}