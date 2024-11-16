#include <iostream>
#include <string>
using namespace std;

int substring(string str1, string str2)
{
    int ans = 0;

    for(int i = 0; i < str1.size(); i++)
    {
        string s;
        for(int j = i; j < str1.size(); j++)
        {
            s += str1[j];

            if(str2.find(s) != string::npos)
            {
                ans++;
            }
            cout << s << endl;
        }
    }
    return ans;
}

int main()
{
    string str1 = "aab";
    string str2 = "aaaab";
    cout << "The number of substrings are: " << substring(str1, str2);

    return 0;
}