#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Merge(int arr1[], int arr2[], int n1, int n2)
{
    vector<int> sorted;
    
    for(int i = 0; i < n1; i++)
    {
        sorted.push_back(arr1[i]);
    }

    for(int i = 0; i < n2; i++)
    {
        sorted.push_back(arr2[i]);
    }

    sort(sorted.begin(), sorted.end());

    return sorted;
}

int main()
{
    int arr1[] = {2, 4, 6, 7, 8, 2};
    int arr2[] = {1, 5, 7, 8, 9, 10};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    vector<int> recieve = Merge(arr1, arr2, n1, n2);

    for(int i = 0; i < recieve.size(); i++)
    {
        cout << recieve[i] << " ";
    }

}