#include <iostream>
#include <math.h>
using namespace std;

int Search(int arr[], int n, int data)
{
    int JumpSize = sqrt(n);
    int Begin = 0;

    while (arr[JumpSize] < data && Begin < n)
    {
        Begin = JumpSize;
        JumpSize += JumpSize + sqrt(n);

        if (JumpSize > n - 1)
        {
            JumpSize = n;
        }
    }

    for (int i = JumpSize; i > Begin; i--)
    {
        if (arr[i] == data)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {11, 23, 53, 65, 74, 78, 91, 99, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = Search(arr, n, 99);

    cout << result;
}