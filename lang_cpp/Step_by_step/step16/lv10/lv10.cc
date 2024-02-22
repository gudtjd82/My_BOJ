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
    deque<int> dq1, dq2;

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> temp;
        dq1.push_back(temp);
        dq2.push_back(i);
    }

    while (!dq1.empty())
    {
        if(dq1.front() > 0)
        {
            temp = dq1.front();
            cout << dq2.front() << " ";
            dq1.pop_front();
            dq2.pop_front();
            for(int i =1; i < temp; i++)
            {
                dq1.push_back(dq1.front());
                dq2.push_back(dq2.front());
                dq1.pop_front();
                dq2.pop_front();
            }
        }
        else{
            temp = dq1.front() * (-1);
            cout << dq2.front() << " ";
            dq1.pop_front();
            dq2.pop_front();
            for(int i =0; i < temp; i++)
            {
                dq1.push_front(dq1.back());
                dq2.push_front(dq2.back());
                dq1.pop_back();
                dq2.pop_back();
            }
        }
    }
    cout <<  "\n";
    
    return 0;
}