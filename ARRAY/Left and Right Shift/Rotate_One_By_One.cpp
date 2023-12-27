#include <iostream>
using namespace std;

void rotate(int arr[], int n, int d)
{
    int p = 1;
    while(p <= d)
    {
        int last = arr[0];
        for(int i = 0; i < n-1; i++)
        {
          arr[i] = arr[i + 1];
        }
        arr[n-1] = last;
        p++;
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}


int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 2;  //Shift Amount

    rotate(arr, n, d);
    printArray(arr, n);

}
