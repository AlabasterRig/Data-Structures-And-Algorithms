#include <iostream>
using namespace std;

void Merge(int arr[], int left, int mid, int right)
{
    int subarray1 = mid - left + 1;
    int subarray2 = right - mid;

    int *leftArray = new int[subarray1];
    int *rightArray = new int[subarray2];

    for (int i = 0; i < subarray1; i++)
    {
        leftArray[i] = arr[left + i];
    }

    for (int i = 0; i < subarray2; i++)
    {
        rightArray[i] = arr[mid + 1 + i];
    }

    int indexOfSubarray1 = 0, indexOfSubarray2 = 0;
    int indexofMergedArray = left;

    while (indexOfSubarray1 < subarray1 && indexOfSubarray2 < subarray2)
    {
        if (leftArray[indexOfSubarray1] <= rightArray[indexOfSubarray2])
        {
            arr[indexofMergedArray] = leftArray[indexOfSubarray1];
            indexOfSubarray1++;
        }
        else
        {
            arr[indexofMergedArray] = rightArray[indexOfSubarray2];
            indexOfSubarray2++;
        }

        indexofMergedArray++;
    }

    while (indexOfSubarray1 < subarray1)
    {
        arr[indexofMergedArray] = leftArray[indexOfSubarray1];
        indexOfSubarray1++;
        indexofMergedArray++;
    }

    while (indexOfSubarray2 < subarray2)
    {
        arr[indexofMergedArray] = rightArray[indexOfSubarray2];
        indexofMergedArray++;
        indexOfSubarray2++;
    }

    delete leftArray;
    delete rightArray;
}

void MergeSort(int arr[], int begin, int end)
{
    if (begin >= end)
    {
        return;
    }

    int mid = begin + (end - begin) / 2;
    MergeSort(arr, begin, mid);
    MergeSort(arr, mid + 1, end);
    Merge(arr, begin, mid, end);
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int arr[] = {8, 6, 33, 5, 70, 23, 12, 64, 78, 7, 5, 4, 3, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort(arr, 0, size - 1);

    print(arr, size);
}