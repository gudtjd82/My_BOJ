#include <iostream>
#include <stack>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, temp;
    int command;
    deque<int> dq;

    cin >> n;
    for(int i =0; i < n; i++)
    {
        cin >> command;

        if(command == 1)
        {
            cin >> temp;
            dq.push_front(temp);
        }
        else if(command == 2)
        {
            cin >> temp;
            dq.push_back(temp);    
        }
        else if(command == 3)
        {
            if(dq.empty())
                cout << "-1\n";
            else{
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if(command == 4)
        {
            if(dq.empty())
                cout << "-1\n";
            else{
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if(command == 5)
        {
            cout << dq.size() << "\n";
        }
        else if(command == 6)
        {
            if(dq.empty())
                cout << "1\n";
            else   
                cout << "0\n";
        }
        else if(command == 7)
        {
            if(dq.empty())
                cout << "-1\n";
            else{
                cout << dq.front() << "\n";
            }
        }
        else if(command == 8)
        {
            if(dq.empty())
                cout << "-1\n";
            else{
                cout << dq.back() << "\n";
            }
        }
    }


    return 0;
}