#include <iostream>
using namespace std;

int Search(int arr[], int n, int element)
{
    int start = 0;
    int end = n - 1;

    while (start < end && element >= arr[start] && element <= arr[end])
    {
        if (start == end)
        {
            if (arr[start] == element)
            {
                return start;
            }
            return -1;
        }

        int pos = start + (((end - start) / (arr[end] - arr[start])) * (element - arr[start]));

        if (arr[pos] == element)
        {
            return pos;
        }

        if (arr[pos] < element)
        {
            start = pos + 1;
        }

        if (arr[pos] > element)
        {
            end = pos - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = Search(arr, n, 20);

    if (result != -1)
    {
        cout << " Element Found at Index: " << result;
    }
    else
    {
        cout << "Element Not Found";
    }
}