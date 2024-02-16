#include <iostream>
#include <stack>
#include <vector>

using namespace std;

string is_balance(string sentence)
{
    stack<char> st;

    for(auto c : sentence)
    {
        if(c == '(' || c == '[')
        {
            st.push(c);
        }
        else if(c == ')')
        {
            if(!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                return "no";
            }
        }
        else if(c == ']')
        {
            if(!st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                return "no";
            }
        }
    }
    if(st.empty())
        return "yes";
    else
        return "no";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string sentence;
    stack<char> st;
    vector<string> result;

    while(true)
    {
        getline(cin, sentence);

        if(sentence == ".")
            break;

        cout << is_balance(sentence) << endl;
    }

    return 0;
}