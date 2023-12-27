#include <iostream>
using namespace std;

int findElement(int arr[], int n, int key)
{
	int i = 0;

	if(key > arr[i])
	{
		for(i = 0; i < n; i++)
		{
			if(arr[i] == key)
			{
				return i;
			}
		}
	}

	return i;
}

int insert(int arr[], int n, int key)
{
	int pos = findElement(arr, n, key);

	if(pos > n)
	{
		arr[pos] = key; 
	}

	for(int i = n-1; i >= pos; i--)
	{
		arr[i+1] = arr[i];
	}

	arr[pos] = key;

	return n+1;
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
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(arr)/sizeof(arr[0]);
	int key = 36;

	n = insert(arr, n, key);
	printArray(arr, n);
}