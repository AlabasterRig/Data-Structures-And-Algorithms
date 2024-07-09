#include <iostream>
using namespace std;

int Search(int arr[], int left, int right, int data)
{
    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(data == arr[mid])
        {
            return mid;
        }

        if(data < arr[mid])
        {
            right = mid - 1;
        }

        if(data > arr[mid])
        {
            left = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int result = Search(arr, 0, n, 9);
    
    cout << result;
}
