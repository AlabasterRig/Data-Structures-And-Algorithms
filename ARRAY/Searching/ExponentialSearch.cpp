#include <iostream>
using namespace std;

int Search(int arr[], int n, int element)
{
    int index = 1;
    int start = 0;
    int end = 0;

    while (start <= n)
    {
        if (arr[0] == element)
        {
            return 0;
        }

        if (arr[index] == element)
        {
            return index;
        }

        if (arr[index] <= element)
        {
            index = index * index;
        }

        if (arr[index] >= element)
        {
            end = index;

            for (int i = end; i > start; i--)
            {
                if (arr[i] == element)
                {
                    return i;
                }
            }
        }

        index++;
        start++;
    }

    return -1;
}

int main()
{
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = Search(arr, n, 47);

    if (result != -1)
    {
        cout << result;
    }
    else
    {
        cout << "Error";
    }
}