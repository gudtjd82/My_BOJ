#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    int temp;
    int sum = 0;
    stack<int> S;

    cin >> k;

    for(int i = 0; i < k; i ++)
    {
        cin >> temp;
        if(temp == 0)
        {
            S.pop();
        }
        else{
            S.push(temp);
        }
    }

    while(!S.empty())
    {
        sum += S.top();
        S.pop();
    }

    cout << sum << "\n";

    return 0;
}