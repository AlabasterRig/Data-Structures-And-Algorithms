#include <iostream>
using namespace std;

void rotate(int arr[], int n, int d)
{
    int temp[n];
    int j = 0;

    //store elements after d
    for(int i = d; i < n; i++)
    {
        temp[j] = arr[i];
        j++;
    }

    //Store elements before d
    for(int i = 0; i < d; i++)
    {
        temp[j] = arr[i];
        j++;
    }

    for(int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

void PrintArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int N = sizeof(arr) / sizeof(arr[0]);
    int d = 2;

    rotate(arr, N, d);
    PrintArray(arr, N);
}
#include <iostream>
using namespace std;

void rotate(int arr[], int n, int d)
{
    int temp[n];
    int j = 0;

    //store elements after d
    for(int i = d; i < n; i++)
    {
        temp[j] = arr[i];
        j++;
    }

    //Store elements before d
    for(int i = 0; i < d; i++)
    {
        temp[j] = arr[i];
        j++;
    }

    for(int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

void PrintArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int N = sizeof(arr) / sizeof(arr[0]);
    int d = 2;

    rotate(arr, N, d);
    PrintArray(arr, N);
}