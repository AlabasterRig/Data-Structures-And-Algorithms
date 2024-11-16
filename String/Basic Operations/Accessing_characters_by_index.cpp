#include <iostream>
#include <string>
using namespace std;

int access(string str, char c)
{
    int left = 0;
    int right = str.size() - 1;

    while (left <= right)
    {
        if (str[left] == c)
        {
            return left;
        }
        if (str[right] == c)
        {
            return right;
        }
        left++;
        right--;
    }
    return -1;
}

int main()
{
    string str = "What a beautiful day!";
    char c;
    cout << "Enter the character you want to access: ";
    cin >> c;
    cout << "The index of the character is: " << access(str, c);

    return 0;
}