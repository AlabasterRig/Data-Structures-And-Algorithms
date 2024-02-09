#include <iostream>
#include <string>
#include <stack>
using namespace std;

void reverseWords(string str)
{
    stack<char> c;

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] != ' ')
        {
            c.push(str[i]);
        }
        else {
            while(!c.empty())
            {
                cout << c.top();
                c.pop();
            }
        }
        cout << " ";
    }

    while(!c.empty())
    {
        cout << c.top();
        c.pop();
    }
}

int main()
{
    string str = "Hello World";
    reverseWords(str);
}