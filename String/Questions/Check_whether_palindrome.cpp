#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isPalindrome(string &s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int left = 0; int right = s.length() - 1;

    while(left < right)
    {
        if(!isalnum(s[left]))
        {
            left++;
            continue;
        }
        
        if(!isalnum(s[right]))
        {
            right--;
            continue;
        }

        if(s[left++] != s[right--])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string s = "A man, a plan, a canal Panama"; 

    cout << boolalpha << isPalindrome(s);
}