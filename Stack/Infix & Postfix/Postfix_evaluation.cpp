#include <iostream>
#include <string>
#include <stack>
using namespace std;

int evaluate(string str)
{
    stack<int> st;

    for(int i = 0; i < str.length(); i++)
    {
        if(isdigit(str[i]))
        {
            st.push(str[i]);
        }

        else {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();

            switch(str[i])
            {
                case '+':
                    st.push(val2 + val1);
                    break;
                
                case '-':
                    st.push(val2 - val1);
                    break;

                case '*':
                    st.push(val2 * val1);
                    break;

                case '/':
                    st.push(val2 / val1);
                    break;
            }
        }
    }
    return st.top();
}

int main()
{
    string str = "5679*/+";

    int post = evaluate(str);

    cout << "Expression is: " << post;
}