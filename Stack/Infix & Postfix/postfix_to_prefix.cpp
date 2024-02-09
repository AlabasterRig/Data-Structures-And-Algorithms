#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isExpression(char x)
{
    switch (x)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}

string posTopre(string post_exp)
{
    stack<string> s;
    int length = post_exp.size();

    for(int i = 0; i < length; i++)
    {
        if(isExpression(post_exp[i]))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            string temp = post_exp[i] + op2 + op1;

            s.push(temp);
        }
        else {
            s.push(string(1, post_exp[i]));
        }
    }

    string ans = "";
    while(!s.empty())
    {
        ans += s.top();
        s.pop();
    }

    return ans;
}

int main()
{
    string post_exp = "ABC/-AK/L-*";
    cout << "Prefix Expression: " << posTopre(post_exp);
}