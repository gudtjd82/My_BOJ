#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, command;
    int temp;
    stack<int> S;

    cin >> n;

    for(int i = 0; i < n; i ++)
    {
        cin >> command;

        if(command == 1)
        {
            cin >> temp;
            S.push(temp);
        }
        else if(command == 2)
        {
            if(S.size() > 0)
            {
                temp = S.top();
                S.pop();
                cout << temp << "\n";
            }
            else
                cout << -1 << "\n";
        }
        else if(command == 3)
        {
            cout << S.size() << "\n";
        }
        else if(command == 4)
        {
            if(S.size() == 0)
                cout << 1 << "\n";
            else   
                cout << 0 <<"\n";
        }
        else if(command == 5)
        {
            if(S.size() > 0)
            {
                temp = S.top();
                cout << temp << "\n";
            }
            else
                cout << -1 << "\n";
        }
    }

    return 0;
}