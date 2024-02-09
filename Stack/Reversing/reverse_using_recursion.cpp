#include <iostream>
#include <stack>
using namespace std;

void insert_at_bottom(stack<int>& st, int x)
{
    if(st.top() == 0)
    {
        st.push(x);
    }
    else {
        int a = st.top();
        st.pop();
        insert_at_bottom(st, x);

        st.push(a);
    }
}

void reverse(stack<int>& st)
{
    if(st.top() > 0)
    {
        int x = st.top();
        st.pop();
        reverse(st);

        insert_at_bottom(st, x);
    }
}

int main()
{
    stack<int> st, st2;

    for(int i = 0; i < 5; i++)
    {
        st.push(i);
    }

    st2 = st;

    cout << "Original Stack" << endl;
    while(!st2.empty())
    {
        cout << st2.top() << " ";
        st2.pop();
    }
    cout << endl;

    reverse(st);

    cout << "Reversed Stack" << endl;
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}