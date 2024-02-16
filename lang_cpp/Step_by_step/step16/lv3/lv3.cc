#include <iostream>
#include <stack>

using namespace std;

string isVPS(string ps)
{
    stack<int> S;

    for(int j = 0, k = 1; j < ps.length(); j++)
    {
        if(ps[j] == '(')
        {
            S.push(k);
            k++;
        }
        else if(ps[j] == ')')
        {
            if(!S.empty())
            {
                S.pop();
            }
            else{
                return "NO";
            }
        }
    }
    if(S.empty())
    {
        return "YES";
    }
    else
        return "NO";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string ps;

    cin >> n;

    for(int i = 0; i < n; i ++)
    {
        cin >> ps;
        cout << isVPS(ps) << "\n";
    }

    return 0;
}