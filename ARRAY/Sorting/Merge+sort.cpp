#include<iostream>
using namespace std;

void sorti(int arr[],int size1, int arr2[], int size2, int mergedArr[])
{
    int i= 0, j = 0, k = 0;

    while(i < size1 && j < size2)
    {
        if(arr[i] <= arr2[j])
        {
            mergedArr[k++] = arr[i++];
        }
        else {
            mergedArr[k++] = arr2[j++];
        }
    }

    while(i < size1)
    {
        mergedArr[k++] = arr[i++];
    }

    while(j < size2)
    {
        mergedArr[k++] = arr2[j++];
    }

    for(i = 0; i < size1 + size2; i++)
    {
        int key = mergedArr[i];
        j = i - 1;

        while(j >= 0 && mergedArr[j] > key)
        {
            mergedArr[j+1] = mergedArr[j];
            j = j - 1;
        }

        mergedArr[j+1] = key;
    }

}

int main()
{
    int arr[] = {1,3,6,4,8,7,9};
    int arr2[] = {2,3,6,4,8,1,9,0};
    int size1 = sizeof(arr)/sizeof(arr[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    int mergedArr[size1 + size2];

    sorti(arr, size1, arr2, size2, mergedArr);

    for(int i = 0; i < size1 + size2; i++)
    {
        cout << mergedArr[i] << " ";
    }
}