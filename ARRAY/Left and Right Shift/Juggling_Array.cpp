#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if(b==0)
        return a;
    else
        return gcd(b, a % b);
}

void rotate(int arr[], int n, int d)
{
    d = d % n;  //so that d does not exceed size of array
    int g_c_d = gcd(d, n);

    for(int i = 0; i < g_c_d; i++)
    {
        int temp = arr[i];
        int j = i;

        while(1)
        {
            int k = j + d;  

            if(k >= n)  //if k is greater than size then reduce by n
            {
                k = k - n;
            }

            if(k == i)  //if k equals iteration then breaak
            {
                break;
            }

            arr[j] = arr[k];  //ex - arr[0] = arr[k] for first iteration
            j = k;
        }
        arr[j] = temp; //if k = i then j is last then store temp in j;
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
    int d = 2;

    rotate(arr, n, d);
    printArray(arr, n);
}