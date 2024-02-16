#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int temp;
    stack<int> line;

    cin >> n;

    int seq = 1;
    for(int i =0; i < n; i++)
    {
        cin >>temp;

        if(temp != seq)
        {
            line.push(temp);
        }
        else
            seq++;
        
        while (!line.empty())
        {
            if(line.top() == seq)
            {
                line.pop();
                seq++;
            }
            else
                break;
        }
    }

    if(line.empty())
        cout << "Nice\n";
    else
        cout <<"Sad\n";
    

    return 0;
}